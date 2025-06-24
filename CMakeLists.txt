cmake_minimum_required(VERSION 3.14)

project(StackProject)

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

target_link_libraries(
  runStackTests
  GTest::gtest_main # this will not require explicitly defining a main function for the test exec
)

include(GoogleTest)
include_directories(CMAKE_CURRENT_SOURCE_DIR)
gtest_discover_tests(runStackTests)