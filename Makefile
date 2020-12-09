all: run

build: main pixel block
	g++ main.o pixel.o blockdata.o -o tetris -lncurses
	rm -r *.o

main: main.cpp
	g++ main.cpp -c -lncurses

pixel: pixel.cpp pixel.h
	g++ pixel.cpp -c -lncurses

block: blockdata

blockdata: blockdata.cpp blockdata.h
	g++ blockdata.cpp -c

run: build
	./tetris

clean:
	rm -rf pixel.o main.o tetris
