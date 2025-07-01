cmake_minimum_required(VERSION 3.14)

project(DSProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# Enable testing for the whole project
enable_testing()


add_executable(
  runStackTests
  test_stack.cpp
)

add_library(graph SHARED
graph.cpp)

target_include_directories(graph PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(graphexec 
graphexec.cpp)

target_link_libraries(graphexec graph)
target_include_directories(graphexec PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(
  graphTests
  test_graph.cpp
)

target_link_libraries(
  runStackTests
  GTest::gtest_main # this will not require explicitly defining a main function for the test exec
)

target_link_libraries(
  graphTests
  graph
  GTest::gtest_main # this will not require explicitly defining a main function for the test exec
)

include(GoogleTest)
include_directories(CMAKE_CURRENT_SOURCE_DIR)
gtest_discover_tests(runStackTests)
gtest_discover_tests(graphTests)