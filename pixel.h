#ifndef __PIXEL_H
#define __PIXEL_H

#include<ncurses.h>

struct Pixel
{
    static int pixel;
};

void initPixel(WINDOW* win = stdscr);
void endPixel(WINDOW* win = stdscr);
void drawPixel(int y, int x, WINDOW * win = stdscr);

#endif
