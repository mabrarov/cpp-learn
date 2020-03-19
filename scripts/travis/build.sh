#!/bin/bash

set -e

# shellcheck source=travis_retry.sh
source "${TRAVIS_BUILD_DIR}/scripts/travis/travis_retry.sh"

echo "Preparing build dir at ${BUILD_HOME}"
rm -rf "${BUILD_HOME}"
mkdir -p "${BUILD_HOME}"
cd "${BUILD_HOME}"

generate_cmd="cmake -D CMAKE_SKIP_BUILD_RPATH=ON"
generate_cmd="${generate_cmd} -D CMAKE_C_COMPILER=\"${C_COMPILER}\""
generate_cmd="${generate_cmd} -D CMAKE_CXX_COMPILER=\"${CXX_COMPILER}\""
generate_cmd="${generate_cmd} -D CMAKE_BUILD_TYPE=\"${BUILD_TYPE}\""
generate_cmd="${generate_cmd} \"${TRAVIS_BUILD_DIR}\""
echo "CMake project generation command: ${generate_cmd}"
eval "${generate_cmd}"

build_cmd="cmake --build \"${BUILD_HOME}\" --config \"${BUILD_TYPE}\""
echo "CMake project build command: ${build_cmd}"
eval "${build_cmd}"
