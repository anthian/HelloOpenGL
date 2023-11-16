# HelloOpenGL

## Summary
HelloOpenGL is a template project with all the boilerplate code, with the same pourpose of [Glitter](http://polytonic.github.io/Glitter/) project on which it is based, to be a starting point for the tutorials on [learnopengl.com](http://www.learnopengl.com) and [open.gl](https://open.gl). HelloOpenGL also compiles and statically links every required library, so you can jump right into doing what you probably want: how to get started with OpenGL, but has some minor differences with Glitter project. 
- Uses glad2 generator despite of the older generated files of the C branch
- The folder structure follow the [Pitchfork layout conventions](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs)
- Has github actions to test de Cmake files against different platforms

## Getting Started
HelloOpenGL has also a single dependency: [cmake](http://www.cmake.org/download/), which is used to generate platform-specific makefiles or project files. Start by cloning this repository, making sure to pass the `--recursive` flag to grab all the dependencies. If you forgot, then you can `git submodule update --init` instead.

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
