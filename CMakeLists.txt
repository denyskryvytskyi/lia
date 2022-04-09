cmake_minimum_required(VERSION 3.10)

project(lia
        VERSION 1.0
        LANGUAGES CXX)

set(LIA_SOURCES
    "src/lia.h"
    "src/lia.cpp"
    "src/mathbase.h"
    "src/quaternion.h"
    "src/mat4.h"
    "src/vec2.h"
    "src/vec3.h"
    "src/vec4.h"
    "src/tests.h"
    "src/tests.cpp"
)

add_library(lia ${LIA_SOURCES})

target_include_directories(lia 
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)