#include "grid.h"
#include "box.h"

void grid::draw(mssm::Graphics& g) {
    for(double i = 0; i < numRows; i++) {
        g.line({0, 600 - (i * 64)}, {800, 600 - (i * 64)});
    }
    for(double i = 0; i < numCols; i++) {
        g.line({i * 64, 0}, {i * 64, 800});
    }
}
