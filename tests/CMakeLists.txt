set(SOURCES
  "Main.cpp"
  "Helpers.h"
  "Helpers.cpp"
  "VecTest.cpp"
  "MatTest.cpp"
  "QuaternionTest.cpp"
)

set(APP_NAME LiaTests)

add_executable(${APP_NAME} ${SOURCES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

target_link_libraries(
  ${APP_NAME}
  PRIVATE
  lia
)

set_target_properties(${APP_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>)

target_compile_definitions(${APP_NAME} PRIVATE
  $<$<CONFIG:Debug>:DEBUG_MODE>
  $<$<CONFIG:Release>:RELEASE_MODE>
)