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
    -lSDL2_image \
    -llua54
SRC = \
    source/*.cpp \
    source/engine/core_systems/application/*.cpp \
    source/engine/core_systems/logger/*.cpp \
    source/engine/platform/multimedia/*.cpp \
    source/engine/gameplay_foundations/ecs/systems/*.cpp 
    
OBJNAME = byteforgeproject

build: 
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBDIRS) $(SRC) -o $(OBJNAME).exe $(LIBS)
	
clean:
	del $(OBJNAME).exe
