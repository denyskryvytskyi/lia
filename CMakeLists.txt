cmake_minimum_required(VERSION 3.10)

project(lia
        VERSION 1.0
        LANGUAGES CXX)

set(LIA_SOURCES
    "lia/lia.cpp"
)

option(LIA_BUILD_TESTS "Build the LIA tests" OFF)

add_library(lia ${LIA_SOURCES})

target_include_directories(lia 
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

if (LIA_BUILD_TESTS)
    add_subdirectory(tests)
endif()