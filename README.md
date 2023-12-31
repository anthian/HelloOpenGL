[![CMake on multiple platforms](https://github.com/anthian/HelloOpenGL/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/anthian/HelloOpenGL/actions/workflows/cmake-multi-platform.yml)

[![GitHub license](https://img.shields.io/github/license/anthian/HelloOpenGL.svg)](https://github.com/anthian/HelloOpenGL/blob/master/LICENSE)
[![GitHub contributors](https://img.shields.io/github/contributors/anthian/HelloOpenGL.svg)](https://GitHub.com/anthian/HelloOpenGL/graphs/contributors/)
[![GitHub issues](https://img.shields.io/github/issues/anthian/HelloOpenGL.svg)](https://GitHub.com/anthian/HelloOpenGL/issues/)
[![GitHub pull-requests](https://img.shields.io/github/issues-pr/anthian/HelloOpenGL.svg)](https://GitHub.com/anthian/HelloOpenGL/pulls/)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)

[![GitHub watchers](https://img.shields.io/github/watchers/anthian/HelloOpenGL.svg?style=social&label=Watch)](https://GitHub.com/anthian/HelloOpenGL/watchers/)
[![GitHub forks](https://img.shields.io/github/forks/anthian/HelloOpenGL.svg?style=social&label=Fork)](https://GitHub.com/anthian/HelloOpenGL/network/)
[![GitHub stars](https://img.shields.io/github/stars/anthian/HelloOpenGL.svg?style=social&label=Star)](https://GitHub.com/anthian/HelloOpenGL/stargazers/)

# HelloOpenGL

## Summary
HelloOpenGL is a template project with the same pourpose of [Glitter](http://polytonic.github.io/Glitter/) project on which it is based, to be a starting point for the tutorials on [learnopengl.com](http://www.learnopengl.com) and [open.gl](https://open.gl). HelloOpenGL also compiles and statically links every required library, so you can jump right into doing what you probably want: how to get started with OpenGL, but has some minor differences with Glitter project. 
- Uses glad2 generator despite of the older generated files of the C branch
- The folder structure follow the [Pitchfork layout conventions](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs)
- Has github actions to test de Cmake files against different platforms

## Getting Started
HelloOpenGL has a single dependency, [cmake](http://www.cmake.org/download/), which is used to generate platform-specific makefiles or project files. Nevertheless, you will also need to install the peer dependencies to compile the GLAD and GLFW submodules. 

### GLAD submodule peer dependencies
- [python3](https://www.python.org/downloads/)
- [Jinja2 module](https://pypi.org/project/Jinja2/)

For exmple, Ubuntu has python3 installed so you only need to add the Jinja2 module using pip package manager:
```bash
# If Python3 isn't preinstalled, uncomment the following line
# sudo apt install python3
pip install -U Jinja2
```

### GLFW submodule peer dependencies
They are defined in [GLFW compile instructions](https://www.glfw.org/docs/3.3/compile.html). For example, on Ubuntu you will need the following debian package to create a X11 window:
```bash
sudo apt install xorg-dev
```

Start by cloning this repository, making sure to pass the `--recursive` flag to grab all the dependencies. If you forgot, then you can `git submodule update --init` instead.

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
HelloOpenGL provides the most basic windowing example. It is a starting point. HelloOpenGL bundles most of the dependencies needed to implement a basic rendering engine. This includes:

Functionality           | Library
----------------------- | ------------------------------------------
Mesh Loading            | [assimp](https://github.com/assimp/assimp)
Physics                 | [bullet](https://github.com/bulletphysics/bullet3)
OpenGL Function Loader  | [glad](https://github.com/Dav1dde/glad)
Windowing and Input     | [glfw](https://github.com/glfw/glfw)
OpenGL Mathematics      | [glm](https://github.com/g-truc/glm)
Texture Loading         | [stb](https://github.com/nothings/stb)

If you started the tutorials by installing [SDL](https://www.libsdl.org/), [GLEW](https://github.com/nigels-com/glew), or [SOIL](http://www.lonesock.net/soil.html), *stop*. The libraries bundled with HelloOpenGL supersede or are functional replacements for these libraries.
