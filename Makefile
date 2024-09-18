# Compiler
CXX = g++

# Flags
CXXFLAGS = -Wall -std=c++17 -g

# Include directories
INCLUDE_DIRECTORIES = \
    -Ilibs/SDL2/include \
    -Ilibs/imgui \
    -Ilibs/lua/include \
    -Ilibs/sol \
    -Ilibs/glm \
    -Isource/engine \
    -Isource/games

# Library directories
LIBRARY_DIRECTORIES = \
    -Llibs/SDL2/lib \
    -Llibs/lua/libs

# Libraries to link
LIBRARIES = \
    -lSDL2 \
    -lSDL2main \
    -lSDL2_image \
    -llua54

# Source file directories
SOURCE_DIRECTORIES = \
    source/*.cpp \
    source/engine/core_systems/application/*.cpp \
    source/engine/core_systems/logging/*.cpp \
    source/engine/core_systems/strings/*.cpp \
    source/engine/platform/multimedia/*.cpp \
    source/engine/gameplay_foundations/ecs/components/*.cpp \
    source/engine/gameplay_foundations/ecs/systems/*.cpp \
    source/engine/gameplay_foundations/ecs/registries/*.cpp \
    source/games/pong/*.cpp

# Output executable name
OUTPUT_EXECUTABLE_NAME = byteforgeproject

# Build command
build:
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRECTORIES) $(LIBRARY_DIRECTORIES) $(SOURCE_DIRECTORIES) -o ./dist/$(OUTPUT_EXECUTABLE_NAME).exe $(LIBRARIES)

# Clean command
clean:
	del ./dist/$(OUTPUT_EXECUTABLE_NAME).exe