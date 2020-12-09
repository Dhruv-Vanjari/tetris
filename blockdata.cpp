#include"./blockdata.h"
#include<cstring>

BlockData::BlockData(bool *pattern)
{
    memset(d, 0, BLOCK_HEIGHT * BLOCK_WIDTH);
    memset(eh, -1, sizeof(int) *  BLOCK_HORIZONTAL * BLOCK_HEIGHT);
    memset(ev, -1, sizeof(int) * BLOCK_VERTICAL * BLOCK_WIDTH);

    for(int j = 0; j < BLOCK_HEIGHT; j++)
        for(int i = 0; i < BLOCK_WIDTH; i++)
            d[j][i] = *(pattern + (BLOCK_HEIGHT * j) + i);

    scanHorizontal();
    scanVertical();
}

void BlockData::scanHorizontal()
{
    int end_h = 0;
    int end_v = 0;
    bool startScan = true;

    // horizontal start
    for(int j = 0; j < 3; j++) {
        startScan = true;
        for(int i = 0; i < 3; i++) {
            if(startScan & d[j][i]) {
                startScan = false;
                eh[BLOCK_LEFT][j] = i;
            }

            if(d[j][i]) {
                end_h = i;
                end_v = j;
            }
        }

        if(startScan == false)
           eh[BLOCK_RIGHT][end_v] = end_h;
    }
}

void BlockData::scanVertical()
{
    int end_h = 0;
    int end_v = 0;
    bool startScan = true;

    // vertical start
    for(int i = 0; i < 3; i++) {
        startScan = true;
        for(int j = 0; j < 3; j++) {
            if(startScan & d[j][i]) {
                ev[BLOCK_UP][i] = j;
                startScan = false;
            }

            if(d[j][i]) {
                end_v = j;
                end_h = i;
            }
        }

        if(startScan == false)
            ev[BLOCK_DOWN][end_h] = end_v;
    }
}
