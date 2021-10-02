CC=g++
CFLAGS=-w -Wall -std=c++14
LDFLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
BIN=bin/cat_tree
OBJ=obj/main.o obj/Game.o obj/RenderUtils.o

$(BIN): $(OBJ)
	mkdir -p bin
	$(CC) -o $@ $^ $(LDFLAGS)

obj/main.o: src/main.cpp src/main.hpp
	mkdir -p obj
	$(CC) -c $(CFLAGS) -o $@ $<

obj/Game.o: src/Game.cpp src/Game.hpp
	mkdir -p obj
	$(CC) -c $(CFLAGS) -o $@ $<

obj/RenderUtils.o: src/RenderUtils.cpp src/RenderUtils.hpp
	mkdir -p obj
	$(CC) -c $(CFLAGS) -o $@ $<


.PHONY: clean
clean:
	rm -rf $(BIN) $(OBJ)

.PHONY: run
run:
	./$(BIN)

