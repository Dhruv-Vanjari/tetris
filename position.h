#ifndef __POSITION_H
#define __POSITION_H

#include<ncurses.h>

struct Position
{
    int x = 0;
    int y = 0;
    WINDOW *win;
};

#endif
