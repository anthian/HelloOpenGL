#ifndef HELLO_OPEN_GL
#define HELLO_OPEN_GL
#pragma once

#define EXIT_SUCCESS 1
#define EXIT_FAILURE 0
#define OPENGL_MAJOR_VERSION 4
#define OPENGL_MINOR_VERSION 6

// System Headers
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
//#include <btBulletDynamicsCommon.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

// Standard Headers
#include <cstdio>
#include <cstdlib>

// Reference: https://github.com/nothings/stb/blob/master/stb_image.h#L4
// To use stb_image, add this in *one* C++ source file.
//     #define STB_IMAGE_IMPLEMENTATION
//#include <stb_image.h>

// Define Some Constants
const unsigned int mWidth = 1280;
const unsigned int mHeight = 800;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

#endif //~ Glitter Header
