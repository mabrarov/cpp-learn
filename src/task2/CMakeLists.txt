cmake_minimum_required(VERSION 3.2)
project(task2)

set(compile_definitions )
if(WIN32)
    list(APPEND compile_definitions _UNICODE UNICODE)
endif()

if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -municode")
endif()

add_executable(task2 "src/main.cpp")

target_compile_definitions(task2 PRIVATE ${compile_definitions})
