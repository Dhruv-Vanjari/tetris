#include"./collision.h"
#include"./pixel.h"
#include"./blockdata.h"

// return true if cant move vertically
bool Collision::vertical(int dir, BlockData d, Position p)
{
    for(int i = 0; i < BLOCK_WIDTH; i++) {

        if(d.ev[(dir == 1) ? 1 : 0][i] == -1)
            continue;

        int y = d.ev[(dir == 1)? 1 : 0][i] + p.y;
        int x = (i * Pixel::pixel) + p.x;

        for(int pw = 0; pw < Pixel::pixel; pw++)
            if(mvwinch(p.win, y + dir, x + pw) != 32)
                return true;
    }

    return false;
}

// return true if cant move horizontal
bool Collision::horizontal(int dir, BlockData d, Position p)
{
    int offset = Pixel::pixel;
    if(dir == DIR_LEFT)
        offset = -1;

    for(int j = 0; j < BLOCK_HEIGHT; j++) {

        if(d.eh[(dir == 1) ? 1 : 0][j] == -1)
            continue;

        int y = j + p.y;
        int x = (Pixel::pixel * d.eh[(dir == 1)? 1 : 0][j]) + p.x;

        if(mvwinch(p.win, y, x + offset) != 32)
            return true;
    }

    return false;
}
