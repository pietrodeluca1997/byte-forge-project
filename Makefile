# Compiler
CXX = g++

# Flags
CXXFLAGS = -Wall -std=c++17 -g

# Include directories
INCLUDES = \
    -Ilibs/SDL2/include \
    -Ilibs/imgui \
    -Ilibs/lua/include \
    -Ilibs/sol \
    -Ilibs/glm \
    -Isource/engine \
    -Isource/games

# Library directories
LIBDIRS = \
    -Llibs/SDL2/lib \
    -Llibs/lua/libs

# Libraries to link
LIBS = \
    -lSDL2 \
    -lSDL2main \
    -lSDL2_image \
    -llua54

# Source file directories
SRC = \
    source/*.cpp \
    source/engine/core_systems/application/*.cpp \
    source/engine/core_systems/logger/*.cpp \
    source/engine/core_systems/strings/*.cpp \
    source/engine/platform/multimedia/*.cpp \
    source/engine/gameplay_foundations/ecs/components/*.cpp \
    source/engine/gameplay_foundations/ecs/systems/*.cpp \
    source/engine/gameplay_foundations/ecs/registries/*.cpp \
    source/games/pong/*.cpp

# Output executable name
OBJNAME = byteforgeproject

# Build command
build:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBDIRS) $(SRC) -o ./dist/$(OBJNAME).exe $(LIBS)

# Clean command
clean:
	del ./dist/$(OBJNAME).exe