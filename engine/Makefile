# Engine Makefile

# Directories
OUTPUT_DIRECTORY = ../dist/engine/
SOURCE_DIRECTORIES = $(wildcard ./source/*.cpp)
FILE_OBJECTS = $(patsubst %.cpp, %.o, $(SOURCE_DIRECTORIES))

# Compiler
CXX = g++
CXXFLAGS = -Wall -O2 -Iinclude -DWIN32
AR = ar

# Targets
TARGET = ByteForgeEngine.dll

# Dynamic library build
ByteForgeEngine.dll: $(FILE_OBJECTS)
	$(AR) -r -o $(OUTPUT_DIRECTORY)$(TARGET) $(FILE_OBJECTS)

%.o: %.cpp	
	$(CXX) $(CXXFLAGS) -c $< -o $@