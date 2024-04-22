set(SOURCES
    "tests.h"
    "tests.cpp"
)

set(PROJECT_INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set(APP_NAME LiaTests)

add_executable(${APP_NAME} ${SOURCES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

target_link_libraries(${APP_NAME} PUBLIC lia)

target_include_directories(${APP_NAME}
        PRIVATE ${PROJECT_INCLUDE_DIRECTORIES}
        )

set_target_properties(${APP_NAME} PROPERTIES 
                      VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>)

target_compile_definitions(${APP_NAME} PRIVATE
  $<$<CONFIG:Debug>:DEBUG_MODE>
  $<$<CONFIG:Release>:RELEASE_MODE>
)