set(GLFW_DIR "${EXTERNAL_DIR}/glfw")
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_INSTALL OFF)
add_subdirectory("${GLFW_DIR}")
