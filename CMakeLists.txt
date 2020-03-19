cmake_minimum_required(VERSION 3.2)
project(cpp_learn)

option(CPP_LEARN_COVERAGE "Add coverage flags for compiler and linker" OFF)

# Turn on grouping of projects
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
# Groups of projects reflect location of projects in file system
set(project_group_extern "extern")
set(project_group_src "src")
set(project_group_tests "tests")

# Interface-only target for turning on code coverage
add_subdirectory(cmake/coverage)

add_subdirectory(extern/googletest)
set_target_properties(gtest PROPERTIES FOLDER "${project_group_extern}/gtest")
set_target_properties(gmock PROPERTIES FOLDER "${project_group_extern}/gtest")
set_target_properties(gtest_main PROPERTIES FOLDER "${project_group_extern}/gtest")
set_target_properties(gmock_main PROPERTIES FOLDER "${project_group_extern}/gtest")
target_compile_features(gtest PUBLIC cxx_std_11)
target_compile_features(gmock PUBLIC cxx_std_11)

add_subdirectory(src/task1_lib)
add_subdirectory(src/task2_lib)
add_subdirectory(src/task1)
add_subdirectory(src/task2)
set_target_properties(task1_lib PROPERTIES FOLDER "${project_group_src}")
set_target_properties(task2_lib PROPERTIES FOLDER "${project_group_src}")
set_target_properties(task1 PROPERTIES FOLDER "${project_group_src}")
set_target_properties(task2 PROPERTIES FOLDER "${project_group_src}")

enable_testing()
add_subdirectory(tests/task1_test)
add_subdirectory(tests/task2_test)
set_target_properties(task1_test PROPERTIES FOLDER "${project_group_tests}")
set_target_properties(task2_test PROPERTIES FOLDER "${project_group_tests}")
