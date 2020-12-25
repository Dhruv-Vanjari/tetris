#include"rotate.h"

void rotateLeft(bool d[BLOCK_HEIGHT][BLOCK_WIDTH], bool *r)
{
    for(int j = 0; j < BLOCK_HEIGHT; j++) {
        for(int i = 0; i < BLOCK_WIDTH; i++) {
            r[((BLOCK_WIDTH - i - 1) * BLOCK_HEIGHT) + j] = d[j][i];
        }
    }
}

void rotateRight(bool d[BLOCK_HEIGHT][BLOCK_WIDTH], bool *r)
{
    for(int j = 0; j < BLOCK_HEIGHT; j++) {
        for(int i = 0; i < BLOCK_WIDTH; i++) {
            r[(i * BLOCK_HEIGHT) + (BLOCK_WIDTH - 1 - j)] = d[j][i];
        }
    }
}
