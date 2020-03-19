cmake_minimum_required(VERSION 3.2)
project(task2_lib)

set(compile_definitions )
if(WIN32)
    list(APPEND compile_definitions _UNICODE UNICODE)
endif()

add_library(task2_lib STATIC "include/task2_lib.hpp" "src/task2_lib.cpp")

add_library(Cpp_learn::task2_lib ALIAS task2_lib)

target_compile_definitions(task2_lib PUBLIC ${compile_definitions})

target_include_directories(task2_lib PUBLIC "include")

target_link_libraries(task2_lib PRIVATE Cpp_learn::coverage)
