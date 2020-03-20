cmake_minimum_required(VERSION 3.2)
project(input_reader)

set(compile_definitions )
if(WIN32)
    list(APPEND compile_definitions _UNICODE UNICODE)
endif()

add_library(input_reader STATIC "include/input_reader.hpp" "src/input_reader.cpp")

add_library(Cpp_learn::input_reader ALIAS input_reader)

target_compile_definitions(input_reader PUBLIC ${compile_definitions})

target_include_directories(input_reader PUBLIC "include")

target_link_libraries(input_reader PRIVATE Cpp_learn::coverage)
