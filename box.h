#ifndef BOX_H
#define BOX_H

#include "graphics.h"

enum class blockType
{
    air,
    solid
};

class box
{
public:
    int xCoords;
    int yCoords;
    blockType type;

    void draw(mssm::Graphics& g);
    box(int x, int y, blockType block);
};

#endif // BOX_H
