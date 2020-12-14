all: run

build: main pixel block collision
	g++ main.o pixel.o block.o collision.o blockdata.o -o tetris -lncurses
	rm -r *.o

main: main.cpp
	g++ main.cpp -c -lncurses

pixel: pixel.cpp pixel.h
	g++ pixel.cpp -c -lncurses

block: blockdata block.cpp blocks.h
	g++ block.cpp -c -lncurses

blockdata: blockdata.cpp blockdata.h
	g++ blockdata.cpp -c -lncurses

collision: collision.h collision.cpp
	g++ collision.cpp -c -lncurses

run: build
	./tetris

clean:
	rm -rf pixel.o main.o tetris
