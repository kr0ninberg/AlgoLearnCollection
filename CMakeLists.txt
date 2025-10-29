cmake_minimum_required(VERSION 3.14)
project(AlgoLearn)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define to switch main functionality
add_definitions(-DTESTS)

# Find required packages
find_package(GTest REQUIRED)

# Include directories
include_directories(${GTEST_INCLUDE_DIRS})

# Collect all test files
file(GLOB_RECURSE TEST_SOURCES
    "algorithms/tests/*.cpp"
    "datastructures/tests/*.cpp"
    "excercises/tests/*.cpp"
)

# Create test executable
add_executable(${PROJECT_NAME} main.cpp ${TEST_SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)

# Enable testing
enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})