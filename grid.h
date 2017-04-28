#ifndef GRID_H
#define GRID_H

#include "graphics.h"
#include <vector>
#include "box.h"

class grid
{
public:
    int numCols;
    int numRows;
    std::vector<box> boxes;

    void draw(mssm::Graphics& g);
};

#endif // GRID_H
