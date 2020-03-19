cmake_minimum_required(VERSION 3.2)
project(cpp_learn)

add_subdirectory(src/task1)
set_target_properties(task1 PROPERTIES FOLDER "${project_group_src}")
