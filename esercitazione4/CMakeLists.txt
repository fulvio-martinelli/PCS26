cmake_minimum_required(VERSION 3.20)
project(esercitazione4) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

# Target for wall-clock time measurements
add_executable(measure_sorts timecounter.cpp measure_sorts.cpp)

# Targets for unit test executables
add_executable(test_bubblesort_numeric test_bubblesort_numeric.cpp)
add_executable(test_bubblesort_string test_bubblesort_string.cpp)
add_test(NAME bubblesort_numeric COMMAND test_bubblesort_numeric)
add_test(NAME bubblesort_string COMMAND test_bubblesort_string)

add_executable(test_insertionsort_numeric test_insertionsort_numeric.cpp)
add_executable(test_insertionsort_string test_insertionsort_string.cpp)
add_test(NAME insertionsort_numeric COMMAND test_insertionsort_numeric)
add_test(NAME insertionsort_string COMMAND test_insertionsort_string)

add_executable(test_selectionsort_numeric test_selectionsort_numeric.cpp)
add_executable(test_selectionsort_string test_selectionsort_string.cpp)
add_test(NAME selectionsort_numeric COMMAND test_selectionsort_numeric)
add_test(NAME selectionsort_string COMMAND test_selectionsort_string)

#add_executable(test_sorters test_sorters.cpp)
#add_test(NAME test_sorters COMMAND test_sorters)
enable_testing()
