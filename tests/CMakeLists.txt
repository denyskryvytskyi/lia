set(SOURCES
  "Main.cpp"
  "Helpers.h"
  "Helpers.cpp"
  "VecTest.cpp"
  "MatTest.cpp"
  "QuaternionTest.cpp"
)

set(PROJECT_INCLUDE_DIRECTORIES
    ${PROJECT_SOURCE_DIR}/include
)

set(APP_NAME LiaTests)

add_executable(${APP_NAME} ${SOURCES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

target_include_directories(${APP_NAME} PRIVATE ${PROJECT_INCLUDE_DIRECTORIES} ${CMAKE_CURRENT_SOURCE_DIR}/"doctest.h")

set_target_properties(${APP_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>)

target_compile_definitions(${APP_NAME} PRIVATE
  $<$<CONFIG:Debug>:DEBUG_MODE>
  $<$<CONFIG:Release>:RELEASE_MODE>
)