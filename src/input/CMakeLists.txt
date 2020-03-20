cmake_minimum_required(VERSION 3.2)
project(input)

set(compile_definitions )
if(WIN32)
    list(APPEND compile_definitions _UNICODE UNICODE)
endif()

add_library(input STATIC "include/istream_reader.hpp" "src/istream_reader.cpp")

add_library(Cpp_learn::input ALIAS input)

target_compile_features(input PRIVATE cxx_auto_type cxx_range_for)

target_compile_definitions(input PUBLIC ${compile_definitions})

target_include_directories(input PUBLIC "include")

target_link_libraries(input PRIVATE Cpp_learn::coverage)
