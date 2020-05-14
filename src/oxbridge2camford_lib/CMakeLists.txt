cmake_minimum_required(VERSION 3.2)
project(oxbridge2camford_lib)

set(compile_definitions )
if(WIN32)
    list(APPEND compile_definitions _UNICODE UNICODE)
endif()

add_library(oxbridge2camford_lib STATIC
    "include/oxbridge2camford_lib.hpp"
    "src/oxbridge2camford_lib.cpp")

add_library(Cpp_learn::oxbridge2camford_lib ALIAS oxbridge2camford_lib)

target_compile_definitions(oxbridge2camford_lib PUBLIC ${compile_definitions})

target_include_directories(oxbridge2camford_lib PUBLIC "include")

target_link_libraries(oxbridge2camford_lib PRIVATE Cpp_learn::coverage)
