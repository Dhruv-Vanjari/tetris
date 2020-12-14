#ifndef _BLOCKDATA_H
#define _BLOCKDATA_H

#define BLOCK_HEIGHT 3
#define BLOCK_WIDTH  3

#define BLOCK_VERTICAL   2   // edges to look for while moving vertically
#define BLOCK_HORIZONTAL 2   // edges to look for while moving horizontally

// Directions
#define BLOCK_UP    0
#define BLOCK_DOWN  1
#define BLOCK_LEFT  0
#define BLOCK_RIGHT 1

class BlockData
{
private:
    bool d[BLOCK_HEIGHT][BLOCK_WIDTH];                 // block data
    int ev[BLOCK_VERTICAL][BLOCK_WIDTH];    // Edges that can collide vertically
    int eh[BLOCK_HORIZONTAL][BLOCK_HEIGHT]; // Edges that can collide horizontally
    //            NO of Edges     No of Layer

    BlockData();

    void scanVertical();
    void scanHorizontal();

public:
    BlockData(const bool *);

    friend class Block;
    friend class Collision;
};

#endif
