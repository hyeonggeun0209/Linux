project(linux)
cmake_minimum_required(VERSION 3.10)

include_directories(inc)

add_subdirectory(src)
add_subdirectory(lib)

add_dependencies(my_prog util)