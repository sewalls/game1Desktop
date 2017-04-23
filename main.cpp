#include "graphics.h"

using namespace std;
using namespace mssm;

void graphicsMain(Graphics& g)
{
    Image img("comp.png");
    Sound pew("ShortLaser.wav");

    while (g.draw())
    {
        g.clear();

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
    Graphics g("Game", 1200, 800, graphicsMain);
}
