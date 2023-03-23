#include "raylib.h"
#include "Macros.h"

#pragma once

class BounceProjectile
{
public:
    void TrackProj(int x, int y)
    {
        DrawCircle(x, y, Size, Tone);
    }

private:
    int Size = 5;
    Color Tone = RED;

    int Posx = CENTROX;
    int Posy = CENTROY;
};
