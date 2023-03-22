#include "raylib.h"
#include "Macros.h"

class Asteroids
{
private:
    int Size = 5;
    Color Tone = BROWN;

    int Posx;
    int Posy;

    int Dirx;
    int Diry;

public:
    Asteroids()
    {
        STARLOOP
        {
            Posx = RANDOMX;
            Posy = RANDOMY;

            if ((GetRandomValue(0, 9) % 2) == 0)
                Dirx = 1;
            else
                Dirx - 1;
            if ((GetRandomValue(0, 9) % 2) == 0)
                Diry = 1;
            else
                Diry = -1;
        }
    }

    void TrackAst()
    {
        DrawCircle(Posx, Posy, Size, Tone);
        Posx += Dirx;
        Posy += Diry;
        if (Posy > SCREENY)
        {
            Posy = 0;
        }
        else if (Posy < 0)
        {
            Posy = SCREENY;
        }

        if (Posx > SCREENX)
        {
            Posx = 0;
        }
        else if (Posx < 0)
        {
            Posx = SCREENX;
        }
    }
};