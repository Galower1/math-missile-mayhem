#include <iostream>
#include "raylib.h"
#include "Macros.h"
#include "Background.h"

using namespace std;

class Asteroids
{
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

private:
    int Size = 5;
    Color Tone = BROWN;

    int Posx;
    int Posy;

    int Dirx;
    int Diry;
};

int main()
{
    InitWindow(SCREENX, SCREENY, "Math Missile Mayhem");
    Background Def;
    Asteroids Ast[45];
    while (!WindowShouldClose())
    {
        BeginDrawing();
        SetTargetFPS(60);
        DrawFPS(0, 0);
        Def.Clear();
        Def.TrackStar();
        STARLOOP
        {
            Ast[i].TrackAst();
        }
        EndDrawing();
    }
}