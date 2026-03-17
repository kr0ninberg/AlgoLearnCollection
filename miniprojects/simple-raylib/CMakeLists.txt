cmake_minimum_required(VERSION 3.14)
project(RaylibSimple)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
find_package(raylib REQUIRED)

file(GLOB_RECURSE SOURCES
        "sources/*.cpp"
)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

target_link_libraries(${PROJECT_NAME} raylib gtest::gtest)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_SOURCE_DIR}
)