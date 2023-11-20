set(GLAD_DIR "${EXTERNAL_DIR}/glad")
add_subdirectory("${GLAD_DIR}/cmake")
glad_add_library(glad STATIC REPRODUCIBLE API gl:core=4.6)
