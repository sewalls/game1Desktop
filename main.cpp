#include "graphics.h"
#include "box.h"
#include "world.h"
#include <vector>
#include "player.h"

using namespace std;
using namespace mssm;

void graphicsMain(Graphics& g)
{
    Image img("block1.png");
    Sound pew("ShortLaser.wav");

    box b1(1, 1, blockType::solid);
    box b2(2, 1, blockType::solid);
    box b3(3, 1, blockType::solid);
    box b4(4, 1, blockType::solid);
    box b5(5, 1, blockType::solid);
    box b6(6, 1, blockType::solid);
    box b7(7, 1, blockType::solid);
    box b8(8, 1, blockType::solid);
    box b9(9, 1, blockType::solid);
    box b10(10, 1, blockType::solid);
    box b11(11, 1, blockType::solid);
    box b12(12, 1, blockType::solid);
    box b13(13, 1, blockType::solid);
    box b14(14, 1, blockType::solid);
    box b15(15, 1, blockType::solid);
    box b16(4, 3, blockType::solid);


    player kura{0, 0, 0, 0, false, Image{"player1.png"}};

    world world1{{b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, b16}, kura};

    while (g.draw())
    {
        g.clear();

        world1.update(g);
        world1.draw(g);

        for (const Event& e : g.events()) {
            switch (e.evtType) {
            case EvtType::KeyPress:
                g.out << "KeyPress: " << e.arg << endl;
                world1.keypressed(g, e.arg);
                break;
            case EvtType::KeyRelease:
                g.out << "KeyRelease: " << e.arg << endl;
                break;
            case EvtType::MouseMove:
                g.image(e.x, e.y, img);
                break;
            case EvtType::MousePress:
                g.out << "MousePress: " << e.arg << endl;
                break;
            case EvtType::MouseRelease:
                g.out << "MouseRelease: " << e.arg << endl;
                break;
            default:
                break;
            }
        }
    }
}

int main()
{
    Graphics g("Game", 800, 600, graphicsMain);
}
