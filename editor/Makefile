# Editor Makefile

# Compiler
CXX = g++

# Flags
CXXFLAGS = -Wall -std=c++17 -g -DWIN32 -O2

# Output directory
OUTPUT_DIRECTORY = ../dist/editor/

# Include directories
INCLUDE_DIRECTORIES = \
    -ISDL2/include \
    -I../libraries/UI/ \
    -I../libraries/multimedia_layer/include/ \
    -I../libraries/gui_layer/include/ \
    -I../libraries/logging/include/ \
    -I../vendor/

# Source directories
SOURCE_DIRECTORIES = $(wildcard *.cpp) \
    $(wildcard ./UI/views/*.cpp) \
	$(wildcard ../libraries/multimedia_layer/source/context/*.cpp) \
    $(wildcard ../libraries/multimedia_layer/source/data_structures/*.cpp) \
    $(wildcard ../libraries/multimedia_layer/source/registry/*.cpp) \
    $(wildcard ../libraries/gui_layer/source/*.cpp) \
    $(wildcard ../libraries/logging/source/logger/*.cpp) \
    $(wildcard ../libraries/logging/source/enums/*.cpp) \
    $(wildcard ../vendor/imgui/*.cpp)

# Object files
FILE_OBJECTS = $(patsubst %.cpp, %.o, $(SOURCE_DIRECTORIES))

# Libraries to link
LIBRARIES = \
    -lSDL2 \
    -lSDL2main

# Targets
TARGET = ByteForgeEditor.exe

# Build
build: $(FILE_OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRECTORIES) $(FILE_OBJECTS) $(LIBRARIES) -o $(OUTPUT_DIRECTORY)$(TARGET)

%.o: %.cpp	
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRECTORIES) -c $< -o $@