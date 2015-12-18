OBJECT_NAME = cavestory
OBJECTS = main.o graphics.o game.o input.o sprite.o
CC = g++
LINKER_FLAGS = -lSDL2 -lSDL2_image

# vpath %.cpp src
# vpath %.h headers
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

