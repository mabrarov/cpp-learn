cmake_minimum_required(VERSION 3.2)
project(task1_test)

add_executable(task1_test "src/task1_test.cpp")

target_compile_features(task1_test PRIVATE
    cxx_lambdas
    cxx_auto_type
    cxx_lambda_init_captures)

target_link_libraries(task1_test
    PRIVATE
    Cpp_learn::coverage
    gtest_main
    Cpp_learn::task1_lib)

add_test(NAME task1_test COMMAND task1_test)
