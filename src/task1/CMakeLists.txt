cmake_minimum_required(VERSION 3.2)
project(task1)

set(compile_definitions )
if(WIN32)
    list(APPEND compile_definitions _UNICODE UNICODE)
endif()

if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -municode")
endif()

add_executable(task1 "src/main.cpp")

target_compile_features(task1 PRIVATE cxx_lambdas cxx_auto_type)

target_compile_definitions(task1 PRIVATE ${compile_definitions})

target_link_libraries(task1 PRIVATE Cpp_learn::input Cpp_learn::task1_lib)
