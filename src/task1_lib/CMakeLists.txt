cmake_minimum_required(VERSION 3.2)
project(task1_lib)

set(compile_definitions )
if(WIN32)
    list(APPEND compile_definitions _UNICODE UNICODE)
endif()

add_library(task1_lib STATIC "include/task1_lib.hpp" "src/task1_lib.cpp")

add_library(Cpp_learn::task1_lib ALIAS task1_lib)

target_compile_definitions(task1_lib PUBLIC ${compile_definitions})

target_include_directories(task1_lib PUBLIC "include")

target_link_libraries(task1_lib PRIVATE Cpp_learn::coverage)
