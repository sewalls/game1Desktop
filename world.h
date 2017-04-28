#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "box.h"
#include "player.h"

class world
{
public:
    std::vector<box> boxes;
    player player1;

    void draw(Graphics& g);
    void update(Graphics &g);
};

#endif // WORLD_H
