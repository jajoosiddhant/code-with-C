cmake_minimum_required (VERSION 3.5)

project (pointers)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}")

file (GLOB source_files "${source_dir}/main.c" "${source_dir}/src/*.c")

add_executable (pointers ${source_files})