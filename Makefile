OBJECT_NAME = cavestory
OBJECTS = main.o graphics.o game.o input.o sprite.o
CC = g++

LINKER_FLAGS = 

uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')
ifeq ($(uname_S),Darwin)
	LINKER_FLAGS = -F/Library/Frameworks -framework SDL2_image -framework SDL2
endif
ifeq ($(uname_S),Linux)
    LINKER_FLAGS = -lSDL2 -lSDL2_image
endif

VPATH = src:headers

all: $(OBJECTS)
	$(CC) $(OBJECTS) $(LINKER_FLAGS) -o $(OBJECT_NAME)


main.o: graphics.h
graphics.o: graphics.h globals.h
game.o: graphics.h game.h
input.o: input.h
sprite.o: sprite.h graphics.h globals.h

.PHONY: clean
clean:
	rm -f cavestory $(OBJECTS)

