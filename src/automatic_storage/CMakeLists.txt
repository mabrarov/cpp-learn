cmake_minimum_required(VERSION 3.2)
project(automatic_storage)

set(compile_definitions )
if(WIN32)
    list(APPEND compile_definitions _UNICODE UNICODE)
endif()

if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -municode")
endif()

add_executable(automatic_storage "src/main.cpp")

target_compile_features(automatic_storage PRIVATE cxx_lambdas cxx_auto_type cxx_range_for)

target_compile_definitions(automatic_storage PUBLIC ${compile_definitions})
