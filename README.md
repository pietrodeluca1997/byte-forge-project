# ByteForge Project

ByteForge is a simple 2D (for now) game engine developed in C++ using popular libraries such as SDL2, ImGui, Lua, Sol, and GLM. Currently, the engine generates only an executable based on the selected game's class. However, in the future, the engine will evolve into a library, benefiting both the editor and the game.

## Roadmap

- **Core Features**: First, I plan to complete the basic 2D engine components like input handling, physics, animation, and others. After that, the focus will shift to 3D capabilities.
- **OpenGL**: Initial graphics API implementation due to its simplicity, allowing for faster feature releases in the engine.
- **WebGPU**: Support for WebGPU, alongside WebAssembly, using Google Dawn to run both native applications and web-based versions with WebGPU.
- **Vulkan**: After OpenGL, the focus will be on Vulkan to enable more complex games with better performance and flexibility.
- **DirectX 12 and 11**: DirectX 12 will be added as an additional option for developers.

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

- `docs`: Documentation files (discovery and architecture).
- `source/engine`: Source code of the engine.
- `source/games`: Source code of the games samples.
- `libs/`: External dependencies.
  - `SDL2/`: SDL2 library.
  - `SDL2_image/`: Extension for SDL2 for image handling.
  - `imgui/`: ImGui library.
  - `lua/`: Lua library.
  - `sol/`: Sol library.
  - `glm/`: GLM library.

## Lifecycle (Activity Diagram)
![Lifecycle Activity Diagram](https://github.com/pietrodeluca1997/byte-forge-project/blob/main/docs/application-lifecycle.png)
## Makefile

The `Makefile` includes the following rules:

- **build**: Compiles the project and generates the `byteforgeproject.exe` executable.
- **clean**: Removes the generated executable.

### Variables

- `CXX`: C++ compiler (g++).
- `CXXFLAGS`: Compilation flags (`-Wall -std=c++17`).
- `INCLUDE_DIRECTORIES`: Header directories.
- `LIBRARY_DIRECTORIES`: Library directories.
- `LIBRARIES`: Libraries to link.
- `SOURCE_DIRECTORIES`: Source files directories.

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

## Contributing

We welcome contributions to ByteForge! To contribute, please follow these steps:

1. Fork the repository and clone your fork locally.
2. Create a new branch for your feature or bugfix.
3. Submit a pull request with a clear description of your changes.

Please ensure that your code is well-documented and explain any complex logic where necessary.

## More Information

For more information on using Makefile, refer to the [GNU Make documentation](https://www.gnu.org/software/make/manual/make.html).
