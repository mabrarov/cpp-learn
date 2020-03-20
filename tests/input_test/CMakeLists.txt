cmake_minimum_required(VERSION 3.2)
project(input_test)

add_executable(input_test "src/istream_reader_test.cpp")

target_compile_features(input_test PRIVATE cxx_auto_type)

target_link_libraries(input_test
    PRIVATE
    Cpp_learn::coverage
    gtest_main
    gmock
    Cpp_learn::input)

add_test(NAME input_test COMMAND input_test)
