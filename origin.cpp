#include"origin.h"

static int findVerticalStart(const bool data[BLOCK_HEIGHT][BLOCK_WIDTH])
{
    for(int j = 0; j < BLOCK_HEIGHT; j++)
        for(int i = 0; i < BLOCK_WIDTH; i++)
            if(data[j][i])
                return j;

    return false;
}

static int findHorizontalStart(const bool data[BLOCK_HEIGHT][BLOCK_WIDTH])
{
    for(int i = 0; i < BLOCK_WIDTH; i++)
        for(int j = 0; j < BLOCK_HEIGHT; j++)
            if(data[j][i])
                return i;

    return 0;
}

void moveToOrigin(const bool d[BLOCK_HEIGHT][BLOCK_WIDTH], bool *r)
{
    int startX = findHorizontalStart(d);
    int startY = findVerticalStart(d);

    if(startX == 0 && startY == 0)
        return;

    for(int j = 0; j < BLOCK_HEIGHT; j++)
        for(int i = 0; i < BLOCK_WIDTH; i++)
            if(((i + startX) < BLOCK_WIDTH) && ((j + startY) < BLOCK_HEIGHT))
                r[(j * BLOCK_HEIGHT) + i] = d[startY + j][startX + i];
            else
                r[(j * BLOCK_HEIGHT) + i] = 0;
}
