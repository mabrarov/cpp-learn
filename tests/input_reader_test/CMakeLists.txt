cmake_minimum_required(VERSION 3.2)
project(input_reader_test)

add_executable(input_reader_test "src/input_reader_test.cpp")

target_compile_features(input_reader_test PRIVATE cxx_auto_type)

target_link_libraries(input_reader_test
    PRIVATE
    Cpp_learn::coverage
    gtest_main
    gmock
    Cpp_learn::input_reader)

add_test(NAME input_reader_test COMMAND input_reader_test)
