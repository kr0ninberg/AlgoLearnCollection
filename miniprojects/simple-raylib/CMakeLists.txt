cmake_minimum_required(VERSION 3.14)
project(RaylibSimple)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
find_package(raylib REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} raylib gtest::gtest)