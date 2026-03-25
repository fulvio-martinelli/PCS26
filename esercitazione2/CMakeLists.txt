cmake_minimum_required(VERSION 3.20)

project(esercitazione2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add compiler warning flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

# Add executable
add_executable(memoryLayout memoryLayout.cpp)
add_executable(doubleArrayStats doubleArrayStats.cpp)
