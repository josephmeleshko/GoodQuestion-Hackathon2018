CC = g++
COMPILER_FLAGS = -std=c++11
LINKER_FLAGS = -lSDL2
OBJS = $(shell cat objects.txt)
INCLUDE = -I/usr/local/include
OBJ_NAME = main
SDL_CONFIG = `sdl2-config --cflags --libs`

all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(OBJS) $(INCLUDE) -o $(OBJ_NAME) $(SDL_CONFIG)

clean:
	-rm -f editor.txt
	-rm -f $(OBJ_NAME)

run:
	make all
	./$(OBJ_NAME)
	make clean
