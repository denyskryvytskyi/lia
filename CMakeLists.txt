cmake_minimum_required(VERSION 3.10)

project(lia
        VERSION 1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

option(LIA_BUILD_TESTS "Build the LIA tests" OFF)

add_library(lia INTERFACE)

target_include_directories(
    lia
    INTERFACE
    "include/"
)

if (LIA_BUILD_TESTS)
    add_subdirectory(tests)
endif()