#include "graphics.h"
#include "grid.h"
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
    box b2(1, 2, blockType::air);
    box b3(1, 3, blockType::solid);
    box b4(1, 5, blockType::solid);
    box b5(2, 1, blockType::air);
    box b6(5, 3, blockType::solid);

    player kura{70, 500, 0, 0, Image{"toby.png"}};

    world world1{{b1, b2, b3, b4, b5, b6}, kura};

    while (g.draw())
    {
        g.clear();

        world1.draw(g);
        world1.update(g);

        for (const Event& e : g.events()) {
            switch (e.evtType) {
            case EvtType::KeyPress:
                g.out << "KeyPress: " << e.arg << endl;
                break;
            case EvtType::KeyRelease:
                g.out << "KeyRelease: " << e.arg << endl;
                break;
            case EvtType::MouseMove:
                g.image(e.x, e.y, img);
                break;
            case EvtType::MousePress:
                g.out << "MousePress: " << e.arg << endl;
                g.play(pew);
                break;
            case EvtType::MouseRelease:
                g.out << "MouseRelease: " << e.arg << endl;
                g.play(pew);
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
