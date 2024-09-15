# ByteForge Project

ByteForge is a simple 2D (for now) game engine developed in C++ using popular libraries such as SDL2, ImGui, Lua, Sol, and GLM.

## Requirements

- **g++**: C++ compiler.
- **SDL2**: Library for graphics and input.
- **SDL2_image**: SDL2 extension for image handling.
- **ImGui**: Graphical user interface library.
- **Lua**: Scripting language.
- **Sol**: Lua binding for C++.
- **GLM**: Mathematics library.

## Platform

This project is developed using **MSYS2** with **MinGW-w64**. It is the only platform currently being tested and worked on.

## Project Structure

- `source/engine`: Source code of the engine.
- `libs/`: External dependencies.
  - `SDL2/`: SDL2 library.
  - `SDL2_image/`: Extension for SDL2 for image handling.
  - `imgui/`: ImGui library.
  - `lua/`: Lua library.
  - `sol/`: Sol library.
  - `glm/`: GLM library.

## Makefile

The `Makefile` includes the following rules:

- **build**: Compiles the project and generates the `byteforgeproject.exe` executable.
- **clean**: Removes the generated executable.

### Variables

- `CXX`: C++ compiler (g++).
- `CXXFLAGS`: Compilation flags (`-Wall -std=c++17`).
- `INCLUDES`: Header directories.
- `LIBDIRS`: Library directories.
- `LIBS`: Libraries to link.
- `SRC`: Source files.

### Commands

To compile the project, use:
````sh
make
````

This will create the `byteforgeproject.exe` executable in the build directory.

To remove the generated files, use:

````sh
make clean
````

This will delete the `byteforgeproject.exe` executable.

## More Information

For more information on using Makefile, refer to the [GNU Make documentation](https://www.gnu.org/software/make/manual/make.html).
