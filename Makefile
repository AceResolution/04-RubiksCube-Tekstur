all: bin bin/rbs

bin:
	mkdir -p bin	

bin/rbs: _cube.o algorithmes.o cube.o display.o interpretor.o main.o tests.o rotate_animation_threads.o
	gcc -o bin/rbs _cube.o algorithmes.o cube.o display.o interpretor.o main.o tests.o rotate_animation_threads.o -lGL -lXi -lGLU -lXt -lpthread -lglut -lX11

_cube.o: src/_cube.c
	gcc -ggdb -c src/_cube.c

algorithmes.o: src/algorithmes.c
	gcc -ggdb -c src/algorithmes.c

cube.o: src/cube.c
	gcc -ggdb -c src/cube.c

display.o: src/display.c
	gcc -ggdb -c src/display.c

interpretor.o: src/interpretor.c
	gcc -ggdb -c src/interpretor.c

main.o: src/main.c
	gcc -ggdb -c src/main.c

tests.o: src/tests.c
	gcc -ggdb -c src/tests.c

rotate_animation_threads.o: src/rotate_animation_threads.c
	gcc -ggdb -c src/rotate_animation_threads.c

clean:
	rm -f *.o


