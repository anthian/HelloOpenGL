cmake_minimum_required(VERSION 3.12)

project(HelloOpenGL LANGUAGES C CXX VERSION 0.0.1)

add_definitions(-DUNICODE)
set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY CMAKE_CXX_EXTENSIONS OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/CMake")
set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
set(EXTERNAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external")

include(glad)
include(glfw)
include(glm)
include(assimp)
include(bullet)
include(stb)
include(freetype)
include(openal)

set(DL_LIBRARIES )
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT "${PROJECT_NAME}")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++17")
    if(NOT WIN32)
        set(DL_LIBRARIES dl)
    endif()
endif(MSVC)

include_directories(include/)

file(GLOB_RECURSE PROJECT_INCLUDE include/*.hpp
                                  include/*.h)
file(GLOB_RECURSE PROJECT_SRC src/*.cpp)
file(GLOB_RECURSE PROJECT_SHADERS data/shaders/*.comp # Compute shaders
                                  data/shaders/*.frag # Fragment shaders
                                  data/shaders/*.geom # Geometry shaders
                                  data/shaders/*.vert # Vertex shaders
                                  data/shaders/*.tesc # Tessellation control shaders
                                  data/shaders/*.tese # Tessellation evaluation shaders
                                  data/shaders/*.mesh # Mesh shaders
                                  data/shaders/*.task # Task shaders
                                  data/shaders/*.rgen # Ray generation shaders
                                  data/shaders/*.rint # Ray intersection shaders
                                  data/shaders/*.rahit # Ray any hit shaders
                                  data/shaders/*.rchit # Ray clasest hit shaders
                                  data/shaders/*.rmiss # Ray miss shaders
                                  data/shaders/*.rcall) # Ray callable shaders

file(GLOB PROJECT_CONFIGS CMakeLists.txt
                          Readme.md
                          LICENSE
                         .gitattributes
                         .gitignore
                         .gitmodules)

source_group("include" FILES ${PROJECT_INCLUDE})
source_group("shaders" FILES ${PROJECT_SHADERS})
source_group("src" FILES ${PROJECT_SRC})
source_group("externals" FILES ${EXTERNAL_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SRC} ${PROJECT_INCLUDE} ${PROJECT_SHADERS} ${PROJECT_CONFIGS})

target_include_directories(${PROJECT_NAME} PRIVATE "${ASSIMP_DIR}/include/"
                                                   "${BULLET_DIR}/src/"
                                                   "${GLAD_DIR}/"
                                                   "${GLFW_DIR}/include/"
                                                   "${GLM_DIR}/"
                                                   "${STB_DIR}/"
                                                   "${FREETYPE_DIR}/include/"
                                                   "${OPENAL_DIR}/include/")

target_link_libraries(${PROJECT_NAME} assimp BulletDynamics BulletCollision LinearMath freetype OpenAL glad glfw ${DL_LIBRARIES})

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/data/shaders $<TARGET_FILE_DIR:${PROJECT_NAME}>
    DEPENDS ${PROJECT_SHADERS})