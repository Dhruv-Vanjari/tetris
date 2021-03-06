#include"block.h"
#include"pixel.h"
#include"collision.h"
#include"origin.h"
#include"rotate.h"

Block::Block(WINDOW *win, const bool *bd, int y, int x)
{
    d = BlockData(bd);
    pos.x = (x * Pixel::pixel) + 1;
    pos.y = y + 1;
    pos.win = win;
}

Position Block::getPos()
{
    return pos;
}

void Block::clear()
{
    // clear pixels where the block currently is
    for(int i = 0; i < BLOCK_WIDTH; i++)
        for(int j = 0; j < BLOCK_HEIGHT; j++)
            if(d.d[j][i] == 1)
                drawPixel(j + pos.y, (i * Pixel::pixel) + pos.x, pos.win);

    endPixel(pos.win);
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

void Block::setOrigin(bool matrix[])
{
    Collision collision;
    bool newMatrix[BLOCK_HEIGHT * BLOCK_WIDTH];
    bool supplied[BLOCK_HEIGHT][BLOCK_WIDTH];

    for(int j = 0; j < BLOCK_HEIGHT; j++)
        for(int i = 0; i < BLOCK_WIDTH; i++)
            supplied[j][i] = matrix[(j * BLOCK_HEIGHT) + i];

    moveToOrigin(supplied, newMatrix);
    if(collision.canBePlaced(newMatrix, pos))
        d = BlockData(newMatrix);
}

void Block::rotate(bool dir)
{
    Collision collision;
    bool newMatrix[BLOCK_HEIGHT * BLOCK_WIDTH];

    if(dir == BLOCK_RIGHT)
        rotateRight(d.d, newMatrix);
    else
        rotateLeft(d.d, newMatrix);

    clear();
    setOrigin(newMatrix);
}

bool Block::moveVertical(int dir) {
    Collision collision;
    if(collision.vertical(dir, d, pos))
        return true;

    clear();
    pos.y += dir;
    return false;
}

bool Block::moveHorizontal(int dir) {
    Collision collision;
    if(collision.horizontal(dir, d, pos))
        return true;

    clear();
    pos.x += dir * Pixel::pixel;
    return false;
}
