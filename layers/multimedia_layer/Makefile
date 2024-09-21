# Multimedia Layer Makefile

# Directories
OUTPUT_DIRECTORY = ../../dist/editor/
SOURCE_DIRECTORIES = $(wildcard *.cpp)
FILE_OBJECTS = $(patsubst %.cpp, %.o, $(SOURCE_DIRECTORIES))

# Compiler
CXX = g++
CXXFLAGS = -Wall -O2 -Iinclude -DWIN32 -DBFE_MULTIMEDIA_DLL_EXPORT
LIBRARYFLAGS = -shared -Llib -lSDL2

# Targets
TARGET = multimedia_layer.dll

# Dynamic library build
$(OUTPUT_DIRECTORY)$(TARGET): $(FILE_OBJECTS)
	$(CXX) $(FILE_OBJECTS) $(LIBRARYFLAGS) -o $(OUTPUT_DIRECTORY)$(TARGET)

%.o: %.cpp	
	$(CXX) $(CXXFLAGS) -c $< -o $@