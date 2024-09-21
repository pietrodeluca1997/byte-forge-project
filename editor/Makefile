# Editor Makefile

# Directories
OUTPUT_DIRECTORY = ../dist/editor/
SOURCE_DIRECTORIES = $(wildcard ./source/*.cpp)
INCLUDE_DIRECTORIES = -Iinclude -I../layers/multimedia_layer/

FILE_OBJECTS = $(patsubst %.cpp, %.o, $(SOURCE_DIRECTORIES))

# Compiler
CXX = g++
CXXFLAGS = -Wall -O2 $(INCLUDE_DIRECTORIES) -DWIN32 -g
LIBRARYFLAGS = -L/../dist/editor/ ../dist/editor/multimedia_layer.dll -lSDL2

# Targets
TARGET = ByteForgeEditor.exe

# Build
build:
	$(CXX) $(CXXFLAGS) $(SOURCE_DIRECTORIES) $(LIBRARYFLAGS) -o $(OUTPUT_DIRECTORY)$(TARGET)
	
%.o: %.cpp	
	$(CXX) $(CXXFLAGS) -c $< -o $@	