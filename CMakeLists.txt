cmake_minimum_required(VERSION 3.10)

project(lia
        VERSION 1.0
        LANGUAGES CXX)

option(LIA_BUILD_TESTS "Build the LIA tests" OFF)

if (LIA_BUILD_TESTS)
    add_subdirectory(tests)
endif()