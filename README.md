# HelloOpenGL

## Summary
HelloOpenGL is a boilerplate project for OpenGL, intended as a starting point for the tutorials on [learnopengl.com](http://www.learnopengl.com) and [open.gl](https://open.gl). HelloOpenGL compiles and statically links every required library, so you can jump right into doing what you probably want: how to get started with OpenGL.

## Getting Started
HelloOpenGL has a single dependency: [cmake](http://www.cmake.org/download/), which is used to generate platform-specific makefiles or project files. Start by cloning this repository, making sure to pass the `--recursive` flag to grab all the dependencies. If you forgot, then you can `git submodule update --init` instead.

```bash
git clone --recursive https://github.com/anthian/HelloOpenGL
cd HelloOpenGL
cd build
```

And then, generate a project file or makefile for your platform. If you want to use a particular IDE, make sure it is installed; don't forget to set the Start-Up Project in Visual Studio or the Target in Xcode.

```bash
# UNIX Makefile
cmake ..

# Mac OSX
cmake -G "Xcode" ..

# Microsoft Windows
cmake -G "Visual Studio 14" ..
cmake -G "Visual Studio 14 Win64" ..
...
```

If you compile and run, you should now be at the same point as the [Hello Window](http://www.learnopengl.com/#!Getting-started/Hello-Window) or [Context Creation](https://open.gl/context) sections of the tutorials. Open [main.cpp](https://github.com/anthian/HelloOpenGL/blob/master/src/main.cpp) on your computer and start writing code!

## Documentation
Many people overlook how frustrating it is to install dependencies, especially in environments lacking package managers or administrative privileges. For beginners, just getting set up properly set up can be a huge challenge. HelloOpenGL is meant to help you overcome that roadblock.

HelloOpenGL provides the most basic windowing example. It is a starting point, and tries very hard not to enforce any sort of directory structure. Feel free to edit the include paths in `CMakeLists.txt`. HelloOpenGL bundles most of the dependencies needed to implement a basic rendering engine. This includes:

Functionality           | Library
----------------------- | ------------------------------------------
Mesh Loading            | [assimp](https://github.com/assimp/assimp)
Physics                 | [bullet](https://github.com/bulletphysics/bullet3)
OpenGL Function Loader  | [glad](https://github.com/anthian/glad)
Windowing and Input     | [glfw](https://github.com/glfw/glfw)
OpenGL Mathematics      | [glm](https://github.com/g-truc/glm)
Texture Loading         | [stb](https://github.com/nothings/stb)

If you started the tutorials by installing [SDL](https://www.libsdl.org/), [GLEW](https://github.com/nigels-com/glew), or [SOIL](http://www.lonesock.net/soil.html), *stop*. The libraries bundled with HelloOpenGL supersede or are functional replacements for these libraries.

