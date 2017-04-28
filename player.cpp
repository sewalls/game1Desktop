#include "player.h"

void player::draw(Graphics& g) {
    g.image(px, py, playerImage);
}

void player::input(Graphics& g) {
    if(g.isKeyPressed('A') && pvx > -10) {
        pvx += -2;
    }

    if(g.isKeyPressed('D') && pvx < 10) {
        pvx += 2;
    }

    if(g.isKeyPressed('W')) {
        pvy = -10;
    }
}

void player::update() {
    px = px + pvx;
    py = py + pvy;

    if(pvx > 0) {
        pvx -= 1;
    }
    if(pvx < 0) {
        pvx += 1;
    }

    if(pvy < 10) {
        pvy += 1;
    }
}
