#include "world.h"

void world::keypressed(Graphics& g, int arg) {
    player1.jump(g, arg);
}

void world::draw(Graphics& g) {
    for (box b : boxes) {
        b.draw(g);
    }
    player1.draw(g);
}

void world::update(Graphics& g) {
    player1.input(g);
    player1.update(g, boxes);

    if(player1.px > 600 && player1.pvx > 0) {
        for (box& b : boxes) {
            b.xCoords -= player1.pvx;
        }
        player1.px -= player1.pvx + 1;
    }

    if(player1.px < 100 && player1.pvx < 0) {
        for (box& b : boxes) {
            b.xCoords -= player1.pvx;
        }
        player1.px -= player1.pvx - 1;
    }
}
