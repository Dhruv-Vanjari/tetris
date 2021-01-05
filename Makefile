all: run

build: main pixel block collision origin rotate collapse
	g++ main.o pixel.o block.o collision.o origin.o rotate.o collapse.o blockdata.o -o tetris -lncurses -lpthread
	rm -r *.o

main: main.cpp
	g++ main.cpp -c -lncurses -lpthread

pixel: pixel.cpp pixel.h
	g++ pixel.cpp -c -lncurses

block: blockdata block.cpp block.h
	g++ block.cpp -c -lncurses

blockdata: blockdata.cpp blockdata.h
	g++ blockdata.cpp -c -lncurses

collision: collision.h collision.cpp
	g++ collision.cpp -c -lncurses

origin: origin.cpp origin.h
	g++ origin.cpp -c -lncurses

rotate: rotate.cpp rotate.h
	g++ rotate.cpp -c -lncurses

collapse: collapse.h collapse.cpp
	g++ collapse.cpp -c -lncurses

run: build
	./tetris

clean:
	rm -rf pixel.o main.o tetris
