#include "player.h"
#include <cmath>

void player::draw(Graphics& g) {
    g.image(px, py, playerImage);
}

void player::jump(Graphics& g, int arg) {
    if(arg == 'W') {
        if(isOnPlatform) {
            pvy = -18;
            py -= 1;
            isOnPlatform = false;
            g.out << "jumped" << endl;
        }
    }
}

void player::input(Graphics& g) {
    if(g.isKeyPressed('A') && pvx > -10) {
        pvx += -2;
    }

    if(g.isKeyPressed('D') && pvx < 10) {
        pvx += 2;
    }
}

void player::checkCollisions(vector<box> boxes) {
    int xOverlap = 0;
    int yOverlap = 0;
    bool above = false;
    bool left = false;

    for (box b : boxes) {
        if(b.type == blockType::solid) {
            if(abs(px - b.xCoords) < 64 && abs(py - b.yCoords) < 64) {
                xOverlap = 64 - abs(px - b.xCoords);
                yOverlap = 64 - abs(py - b.yCoords);

                if(px - b.xCoords > 0) {
                    left = true;
                }
                else {
                    left = false;
                }

                if(py - b.yCoords > 0) {
                    above = true;
                }
                else {
                    above = false;
                }

                if(xOverlap < yOverlap) {
                    if(left) {
                        px = b.xCoords + 64;
                    }
                    else {
                        px = b.xCoords - 64;
                    }
                    pvx = 0;
                }

                if(xOverlap > yOverlap) {
                    if(above) {
                        py = b.yCoords + 64;
                    }
                    else {
                        py = b.yCoords - 64;
                    }
                    pvy = 0;
                }
            }
        }
    }
}

bool player::checkOnPlatform(vector<box> boxes) {
    for (box b : boxes) {
        if(b.type == blockType::solid) {
            if(py + 65 > b.yCoords && py < b.yCoords && px + 64 > b.xCoords && px - 64 < b.xCoords) {
                py = b.yCoords - 64;
                return true;
            }
        }
    }
    return false;
}

void player::update(Graphics& g, vector<box> boxes) {
    //    if(!isOnPlatform) {
    if(checkOnPlatform(boxes)) {
        isOnPlatform = true;
        pvy = 0;
    }
    else {
        isOnPlatform = false;
    }
    //    }

    px = px + pvx;
    py = py + pvy;

    if(pvx > 0) { //deceleration when going right
        pvx -= 1;
    }

    if(pvx < 0) { //deceleration when going left
        pvx += 1;
    }

    if(pvy < 20 && !isOnPlatform) { //gravity
        pvy += 1;
    }

    checkCollisions(boxes);
}
