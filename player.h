#ifndef PLAYER_H
#define PLAYER_H

#include "graphics.h"
#include "box.h"

using namespace std;
using namespace mssm;

class player
{
public:
    int px;
    int py;
    int pvx;
    int pvy;
    bool isOnPlatform;

    Image playerImage;

    void draw(Graphics& g);
    void input(Graphics& g);
    void update(Graphics &g, vector<box> boxes);
    void jump(Graphics &g, int arg);
    bool checkOnPlatform(vector<box> boxes);
    void checkCollisions(vector<box> boxes);
};

#endif // PLAYER_H
