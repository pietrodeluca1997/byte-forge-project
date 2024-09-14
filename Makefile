CXX = g++
CXXFLAGS = -Wall -std=c++17
INCLUDES = \
    -Ilibs/SDL2/include \
    -Ilibs/imgui \
    -Ilibs/lua/include \
    -Ilibs/sol \
    -Ilibs/glm \
    -Isource/engine
LIBDIRS = \
    -Llibs/SDL2/lib \
    -Llibs/lua/libs
LIBS = \
    -lSDL2 \
    -lSDL2main \
    -llua54

SRC = \
    source/*.cpp \
    source/engine/coresystems/application/*.cpp \
    source/engine/platform/multimedia/*.cpp

build: 
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBDIRS) $(SRC) -o byteforgeproject.exe $(LIBS)
	
clean:
	del byteforgeproject.exe
