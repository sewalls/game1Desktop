#ifndef PLAYER_H
#define PLAYER_H

#include "graphics.h"

using namespace std;
using namespace mssm;

class player
{
public:
    int px;
    int py;
    int pvx;
    int pvy;

    Image playerImage;

    void draw(Graphics& g);
    void input(Graphics& g);
    void update();
};

#endif // PLAYER_H
