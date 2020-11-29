#include"pixel.h"

const char * __pixel = "  ";

int Pixel::pixel = 2;

void initPixel(WINDOW* win) {
    wattron(win, A_REVERSE);
}

void drawPixel(int y, int x, WINDOW* win) {
    mvwprintw(win, y, x, __pixel);
}

void endPixel(WINDOW* win) {
    wattroff(win, A_REVERSE);
    refresh();
}
