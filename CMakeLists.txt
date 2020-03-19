cmake_minimum_required(VERSION 3.2)
project(cpp_learn)

# Turn on grouping of projects
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
# Groups of projects reflect location of projects in file system
set(project_group_src "src")

add_subdirectory(src/task1)
set_target_properties(task1 PROPERTIES FOLDER "${project_group_src}")
