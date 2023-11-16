cmake_minimum_required(VERSION 3.7)

project(HelloOpenGL LANGUAGES C CXX VERSION 0.0.1)

add_definitions(-DUNICODE)
set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY CMAKE_CXX_EXTENSIONS OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT "${PROJECT_NAME}")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++17")
    if(NOT WIN32)
        set(DL_LIBRARIES dl)
    endif()
endif()

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/CMake")
set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
set(EXTERNAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external")


include_directories(include/)

file(GLOB_RECURSE PROJECT_INCLUDE include/*.hpp)
file(GLOB_RECURSE PROJECT_SRC src/*.cpp)
file(GLOB_RECURSE PROJECT_SHADERS data/shaders/*.comp
                          data/shaders/*.frag
                          data/shaders/*.geom
                          data/shaders/*.vert)
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

add_executable(${PROJECT_NAME} ${PROJECT_SRC} ${PROJECT_INCLUDE}
${PROJECT_SHADERS} ${PROJECT_CONFIGS})

target_link_libraries(${PROJECT_NAME} ${DL_LIBRARIES})

# Remove warning flags on CMAKE_CXX_FLAGS to avoid compilation errors of external submodules
if(MSVC)
    string(REPLACE " /W4" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else()
    string(REPLACE " -Wall -Wextra -Wpedantic" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

include(glad)
include(glfw)
include(glm)
include(assimp)
include(bullet)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/data/shaders $<TARGET_FILE_DIR:${PROJECT_NAME}>
    DEPENDS ${PROJECT_SHADERS})