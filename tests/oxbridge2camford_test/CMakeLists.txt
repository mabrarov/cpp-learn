cmake_minimum_required(VERSION 3.2)
project(oxbridge2camford_test)

add_executable(oxbridge2camford_test "src/oxbridge2camford_test.cpp")

target_link_libraries(oxbridge2camford_test
    PRIVATE
    Cpp_learn::coverage
    gtest_main
    Cpp_learn::oxbridge2camford_lib)

add_test(NAME oxbridge2camford_test COMMAND oxbridge2camford_test)
