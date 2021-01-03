#ifndef __COLLISION_H
#define __COLLISION_H

#include"blockdata.h"
#include"position.h"

#define DIR_UP    -1
#define DIR_DOWN   1
#define DIR_LEFT  -1
#define DIR_RIGHT  1

class Collision
{
public:
    bool vertical(int dir, BlockData d, Position p);
    bool horizontal(int dir, BlockData d, Position p);
    bool canBePlaced(bool d[], Position p);
};

#endif
