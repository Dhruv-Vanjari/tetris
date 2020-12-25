#ifndef __BLOCKS_H
#define __BLOCKS_H

#include"blockdata.h"
#include"position.h"
#include"collision.h"

const bool block[][16] =
{
    {1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0}
};

class Block
{
    BlockData d;
    Position pos;
    Block();

    void clear();
    void setOrigin();

    public:
    Block(WINDOW *win, const bool *, int y, int x);
    bool moveVertical(int dir);
    bool moveHorizontal(int dir);
    void rotate(bool dir);
    void show();

    friend class Collision;
};

#endif
