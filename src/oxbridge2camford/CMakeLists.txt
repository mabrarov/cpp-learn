cmake_minimum_required(VERSION 3.2)
project(oxbridge2camford)

set(compile_definitions )
if(WIN32)
    list(APPEND compile_definitions _UNICODE UNICODE)
endif()

if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -municode")
endif()

add_executable(oxbridge2camford "src/main.cpp")

target_compile_definitions(oxbridge2camford PRIVATE ${compile_definitions})

target_link_libraries(oxbridge2camford PRIVATE
    Cpp_learn::input
    Cpp_learn::oxbridge2camford_lib)
