cmake_minimum_required(VERSION 3.2)
project(task2_test)

add_executable(task2_test "src/task2_test.cpp")

target_compile_features(task2_test PRIVATE cxx_lambdas cxx_auto_type)

target_link_libraries(task2_test
    PRIVATE
    Cpp_learn::coverage
    gtest_main
    Cpp_learn::task2_lib)

add_test(NAME task2_test COMMAND task2_test)
