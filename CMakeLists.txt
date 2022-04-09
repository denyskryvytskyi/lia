cmake_minimum_required(VERSION 3.10)

project(lia
        VERSION 1.0
        LANGUAGES CXX)

set(LIA_SOURCES
    "lia/lia.h"
    "lia/lia.cpp"
    "lia/mathbase.h"
    "lia/quaternion.h"
    "lia/mat4.h"
    "lia/vec2.h"
    "lia/vec3.h"
    "lia/vec4.h"
    "lia/tests.h"
    "lia/tests.cpp"
)

add_library(lia ${LIA_SOURCES})

target_include_directories(lia 
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})