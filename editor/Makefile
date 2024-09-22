# Compiler
CXX = g++

# Flags
CXXFLAGS = -Wall -std=c++17 -g -DWIN32

# Output directory
OUTPUT_DIRECTORY = ../dist/editor/

# Include directories
INCLUDE_DIRECTORIES = \
    -ISDL2/include \
    -I../libraries/multimedia_layer/include/ \
    -I../libraries/gui_layer/include/ \
    -I../vendor/

# Source directories
SOURCE_DIRECTORIES = $(wildcard *.cpp) \
	$(wildcard ../libraries/multimedia_layer/source/*.cpp) \
    $(wildcard ../libraries/gui_layer/source/*.cpp) \
    $(wildcard ../vendor/imgui/*.cpp)

FILE_OBJECTS = $(patsubst %.cpp, %.o, $(SOURCE_DIRECTORIES))

# Libraries to link
LIBRARIES = \
    -lSDL2 \
    -lSDL2main

# Targets
TARGET = ByteForgeEditor.exe

# Build
build:
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRECTORIES) $(SOURCE_DIRECTORIES) $(LIBRARIES) -o $(OUTPUT_DIRECTORY)$(TARGET)

%.o: %.cpp	
	$(CXX) $(CXXFLAGS) -c $< -o $@