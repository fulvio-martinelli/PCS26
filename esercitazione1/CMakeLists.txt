cmake_minimum_required(VERSION 3.20)

project(esercitazione1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add compiler warning flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

# Add executable
add_executable(file_processing file_processing.cpp)
add_executable(main_arguments main_arguments.cpp)
