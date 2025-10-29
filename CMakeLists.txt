cmake_minimum_required(VERSION 3.14)
project(AlgoLearn)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(GTest REQUIRED)

# Include directories
include_directories(${GTEST_INCLUDE_DIRS})

# Create test executable
add_executable(${PROJECT_NAME} main.cpp algorithms/tests/basic_test.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)

# Enable testing
enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})