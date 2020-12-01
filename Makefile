all: run

build: main pixel
	g++ main.o pixel.o -o tetris -lncurses
	rm -r *.o

main: main.cpp
	g++ main.cpp -c -lncurses

pixel: pixel.cpp pixel.h
	g++ pixel.cpp -c -lncurses

run: build
	./tetris

clean:
	rm -rf pixel.o main.o tetris
