#include "world.h"

void world::draw(Graphics& g) {
    for (box b : boxes) {
        b.draw(g);
    }
    player1.draw(g);
}

void world::update(Graphics& g) {
    player1.input(g);
    player1.update();
}
