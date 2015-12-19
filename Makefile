OBJECT_NAME = cavestory

CC = g++

LINKER_FLAGS = 

# Different options for Linux and OSX
uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')
ifeq ($(uname_S),Darwin)
	LINKER_FLAGS = -F/Library/Frameworks -framework SDL2_image -framework SDL2
endif
ifeq ($(uname_S),Linux)
    LINKER_FLAGS = -lSDL2 -lSDL2_image
endif

VPATH = src:headers

# Guard against environment variables
OBJECTS = 

OBJECTS += main.o
OBJECTS += graphics.o
OBJECTS += game.o
OBJECTS += input.o
OBJECTS += sprite.o
OBJECTS += animatedsprite.o

all: $(OBJECTS)
	$(CC) $(OBJECTS) $(LINKER_FLAGS) -o $(OBJECT_NAME)


main.o: graphics.h
graphics.o: graphics.h globals.h
game.o: graphics.h game.h
input.o: input.h
sprite.o: sprite.h graphics.h globals.h
animatedsprite.o: animatedsprite.h sprite.h graphics.h

.PHONY: clean
clean:
	rm -f cavestory $(OBJECTS)

