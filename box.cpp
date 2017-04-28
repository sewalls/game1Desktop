#include "box.h"
#include "graphics.h"
#include <vector>
#include "vec2d.h"

using namespace mssm;

Image getImage(blockType block) {
    static Image im1("block1.png");
    static Image im2("air.png");

    switch (block)
    {
    case blockType::solid:
        return im1;
    case blockType::air:
        return im2;
    }
}

box::box(int x, int y, blockType block) {
    xCoords = (y - 1) * 64;
    yCoords = 600 - x * 64;
    type = block;
}

void box::draw(Graphics& g) {
    g.image(xCoords, yCoords, getImage(type));
}
