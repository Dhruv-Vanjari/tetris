#ifndef __BLOCKS_H
#define __BLOCKS_H

#include"blockdata.h"
#include"position.h"
#include"collision.h"

const bool block[][9] =
{
    {1, 1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 1, 1}

};

class Block
{
    BlockData d;
    Position pos;
    Block();

    bool _canMove(int dir, WINDOW* win);

    public:
    Block(WINDOW *win, const bool *, int y, int x);
    bool moveVertical(int dir);
    bool moveHorizontal(int dir);
    void show();

    friend class Collision;
};

#endif
