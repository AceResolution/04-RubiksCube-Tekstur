# INCLUDE = -I/usr/include/
# LIBDIR  = -L/usr/X11R6/LIBDIR

COMPILERFLAGS = -Wall
CC = g++
CFLAGS = $(COMPILERFLAGS) $(INCLUDE)
LIBRARIES = -lX11 -lXi -lXmu -lglut -lGL -lGLU -lm

all: bin 03-01-RubiksCube clean

# Initialise bin folder
bin:
	mkdir -p bin

03-01-RubiksCube.o:
	$(CC) $(CFLAGS) -c src/03-01-RubiksCube.cpp $(LIBRARIES)

03-01-RubiksCube: 03-01-RubiksCube.o
	$(CC) $(CFLAGS) -o bin/03-01-RubiksCube.lexec 03-01-RubiksCube.o $(LIBRARIES)

clean:
	find . -type f -name '*.o' -delete