set(GLFW_DIR "${EXTERNAL_DIR}/glfw")
add_subdirectory("${GLFW_DIR}")
target_link_libraries(${PROJECT_NAME} glfw)
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
