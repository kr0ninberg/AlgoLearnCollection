cmake_minimum_required(VERSION 3.14)
project(AlgoLearn)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define to switch main functionality
add_definitions(-DTESTS)

# Find required packages
find_package(GTest REQUIRED)

# Collect all test files
file(GLOB_RECURSE TEST_SOURCES
    "algorithms/tests/*.cpp"
    "datastructures/tests/*.cpp"
    "excercises/tests/*.cpp"
)

# Create test executable
add_executable(${PROJECT_NAME} main.cpp ${TEST_SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_SOURCE_DIR}
)

# Link libraries
target_link_libraries(${PROJECT_NAME} GTest::gtest GTest::gtest_main pthread)

# Enable testing
enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})