Set-Location -Path "${env:BUILD_HOME}"
$ctest_cmd = "ctest.exe --build-config ""${env:CONFIGURATION}"" --verbose"
if (${env:COVERAGE_BUILD} -ne "True") {
  $test_cmd = "${ctest_cmd}"
} else {
  $coverage_report_folder = "${env:COVERAGE_WORK_FOLDER}\report"
  $coverage_report_archive = "${env:COVERAGE_WORK_FOLDER}\report.zip"
  New-Item -Path "${env:COVERAGE_WORK_FOLDER}" -ItemType "directory" | out-null
  $test_cmd = "OpenCppCoverage.exe --quiet --export_type ""html:${coverage_report_folder}"" --export_type ""cobertura:${env:COBERTURA_COVERAGE_FILE}"" --sources ""${env:APPVEYOR_BUILD_FOLDER}"""
  $test_cmd = "${test_cmd} --excluded_sources ""${env:APPVEYOR_BUILD_FOLDER}\extern"""
  $test_cmd = "${test_cmd} --excluded_sources ""${env:APPVEYOR_BUILD_FOLDER}\src\task1\"""
  $test_cmd = "${test_cmd} --excluded_sources ""${env:APPVEYOR_BUILD_FOLDER}\src\task2\"""
  $test_cmd = "${test_cmd} --excluded_sources ""${env:APPVEYOR_BUILD_FOLDER}\src\oxbridge2camford\"""
  $test_cmd = "${test_cmd} --excluded_sources ""${env:APPVEYOR_BUILD_FOLDER}\tests"""
  $test_cmd = "${test_cmd} --modules ""${env:BUILD_HOME}\tests"" --cover_children --working_dir ""${env:BUILD_HOME}"" -- ${ctest_cmd}"
}

Invoke-Expression "${test_cmd}"
if (${LastExitCode} -ne 0) {
  throw "Tests failed with exit code ${LastExitCode}"
}

Set-Location -Path "${env:APPVEYOR_BUILD_FOLDER}"

if (${env:COVERAGE_BUILD} -eq "True") {
  7z.exe a -tzip "${coverage_report_archive}" "${coverage_report_folder}" | out-null
  if (${LastExitCode} -ne 0) {
    throw "Failed to archive coverage report located at ${coverage_report_folder} with exit code ${LastExitCode}"
  }
  Push-AppveyorArtifact "${coverage_report_archive}" -DeploymentName "${env:COVERAGE_ARTIFACT_NAME}"
  Push-AppveyorArtifact "${env:COBERTURA_COVERAGE_FILE}" -DeploymentName "${env:COVERAGE_ARTIFACT_NAME}"

  $codecov_coverage_file = ${env:COBERTURA_COVERAGE_FILE} -replace "\\", "/"
  $codecov_root_folder = ${env:APPVEYOR_BUILD_FOLDER} -replace "\\", "/"
  appveyor-retry codecov --required --token "${env:CODECOV_TOKEN}" --file "${codecov_coverage_file}" --flags "${env:CODECOV_FLAG}" -X gcov --root "${codecov_root_folder}"
  if (${LastExitCode} -ne 0) {
    throw "Codecov failed with exit code ${LastExitCode}"
  }
}
