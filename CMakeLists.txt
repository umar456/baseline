# Copyright Umar Arshad 2016

# Baseline CMake project that uses google test and google benchmark for testing
#
# Find and modify the TODOs to customize the compilation process
cmake_minimum_required (VERSION 3.3)
# TODO: Change project name
project(baseline_cmake_project)

if(POLICY CMP0037)
  cmake_policy(SET CMP0037 NEW)
endif()

add_definitions(-Wall -Werror)

# TODO: Set test source names and executables
if(EXISTS ${CMAKE_SOURCE_DIR}/external/googletest)
  add_subdirectory(external/googletest)

  set(TEST_SOURCE_NAMES source/test.cpp)
  set(TEST_EXECUTABLE_NAME BaselineUnitTest)

  add_executable(${TEST_EXECUTABLE_NAME} ${TEST_SOURCE_NAMES})
  target_link_libraries(${TEST_EXECUTABLE_NAME} PRIVATE gmock_main rt)

  set_property(TARGET ${TEST_EXECUTABLE_NAME} PROPERTY CXX_STANDARD 11)
  set_property(TARGET ${TEST_EXECUTABLE_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

  include_directories(${gtest_SOURCE_DIR}/include)
  enable_testing()
else()
  MESSAGE(WARNING "Tests Disabled: Google test framework not found. To enable clone googletest into external/googletest")
endif(EXISTS ${CMAKE_SOURCE_DIR}/external/googletest)

# TODO: Set benchmark source names and executables
if(EXISTS ${CMAKE_SOURCE_DIR}/external/benchmark)
  add_subdirectory(external/benchmark)

  set(BENCHMARK_SOURCE_NAMES source/benchmark.cpp)             #Modify file name
  set(BENCHMARK_EXECUTABLE_NAME BaselineBenchmark)  #Modify executable name
  add_executable(${BENCHMARK_EXECUTABLE_NAME} ${BENCHMARK_SOURCE_NAMES})
  target_link_libraries(${BENCHMARK_EXECUTABLE_NAME} PRIVATE benchmark rt)
  include_directories(${benchmark_SOURCE_DIR}/include)

  set_property(TARGET ${BENCHMARK_EXECUTABLE_NAME} PROPERTY CXX_STANDARD 11)
  set_property(TARGET ${BENCHMARK_EXECUTABLE_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
else()
  MESSAGE(WARNING "Benchmarks Disabled: Google benchmarks framework not found. To enable clone google benchmarks into external/benchmark")
endif(EXISTS ${CMAKE_SOURCE_DIR}/external/benchmark)

#TODO: Set the name and sources for your application
add_executable(myapp source/main.cpp)
set_property(TARGET myapp PROPERTY CXX_STANDARD 11)
set_property(TARGET myapp PROPERTY CXX_STANDARD_REQUIRED ON)

