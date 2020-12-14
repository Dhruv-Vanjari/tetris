#include"block.h"
#include"pixel.h"
#include"collision.h"

Block::Block(WINDOW *win, const bool *bd, int y, int x)
{
    d = BlockData(bd);
    pos.x = (x * Pixel::pixel) + 1;
    pos.y = y + 1;
    pos.win = win;
}

void Block::show()
{
    initPixel(pos.win);
    for(int i = 0; i < BLOCK_WIDTH; i++)
        for(int j = 0; j < BLOCK_HEIGHT; j++)
            if(d.d[j][i] == 1)
                drawPixel(j + pos.y, (i * Pixel::pixel) + pos.x, pos.win);

    endPixel(pos.win);
}

bool Block::moveVertical(int dir) {
    Collision collision;
    if(collision.vertical(dir, d, pos))
        return true;

    // clear pixels where the block currently is
    for(int i = 0; i < BLOCK_WIDTH; i++)
        for(int j = 0; j < BLOCK_HEIGHT; j++)
            if(d.d[j][i] == 1)
                drawPixel(j + pos.y, (i * Pixel::pixel) + pos.x, pos.win);


    pos.y += dir;
    return false;
}

bool Block::moveHorizontal(int dir) {
    Collision collision;
    if(collision.horizontal(dir, d, pos))
        return true;

    // clear pixels where the block currently is
    for(int i = 0; i < BLOCK_WIDTH; i++)
        for(int j = 0; j < BLOCK_HEIGHT; j++)
            if(d.d[j][i] == 1)
                drawPixel(j + pos.y, (i * Pixel::pixel) + pos.x, pos.win);


    pos.x += dir * Pixel::pixel;
    return false;
}
