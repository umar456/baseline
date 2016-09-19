# Copyright Umar Arshad 2016

# Baseline CMake project that uses google test and google benchmark for testing
#
# Find and modify the TODOs to customize the compilation process

cmake_minimum_required (VERSION 3.6)
project(baseline_cmake_project)

add_subdirectory(external/googletest)
add_subdirectory(external/benchmark)

add_definitions(-Wall -Werror -std=c++11)

include_directories(${gtest_SOURCE_DIR}/include)
include_directories(${benchmark_SOURCE_DIR}/include)

enable_testing()

if(POLICY CMP0037)
  cmake_policy(SET CMP0037 NEW)
endif()

# TODO: Set test source names and executables
SET(TEST_SOURCE_NAMES test.cpp)
SET(TEST_EXECUTABLE_NAME BaselineUnitTest)
add_executable(${TEST_EXECUTABLE_NAME} ${TEST_SOURCE_NAMES})
target_link_libraries(${TEST_EXECUTABLE_NAME} PRIVATE gmock_main)

# TODO: Set benchmark source names and executables
SET(BENCHMARK_SOURCE_NAMES benchmark.cpp)             #Modify file name
SET(BENCHMARK_EXECUTABLE_NAME BaselineBenchmark)  #Modify executable name
add_executable(${BENCHMARK_EXECUTABLE_NAME} ${BENCHMARK_SOURCE_NAMES})
target_link_libraries(${BENCHMARK_EXECUTABLE_NAME} PRIVATE benchmark)
