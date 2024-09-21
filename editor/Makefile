# Editor Makefile

# Directories
OUTPUT_DIRECTORY = ../dist/editor/
SOURCE_DIRECTORIES = $(wildcard ./source/*.cpp)

FILE_OBJECTS = $(patsubst %.cpp, %.o, $(SOURCE_DIRECTORIES))

# Compiler
CXX = g++
CXXFLAGS = -Wall -O2 -Iinclude -DWIN32 -g

# Targets
TARGET = ByteForgeEditor.exe

# Build
build:
	$(CXX) $(CXXFLAGS) $(SOURCE_DIRECTORIES) -o $(OUTPUT_DIRECTORY)$(TARGET)
	
%.o: %.cpp	
	$(CXX) $(CXXFLAGS) -c $< -o $@	