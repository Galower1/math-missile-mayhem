#include "raylib.h"
#include "Macros.h"

#pragma once

class Background
{
private:
    int EstrellasX[45];
    int EstrellasY[45];

public:
    Background()
    {
        STARLOOP
        {
            EstrellasX[i] = RANDOMX;
            EstrellasY[i] = RANDOMY;
        }
    }

    void TrackStar()
    {
        STARLOOP
        {
            DrawPixel(EstrellasX[i], EstrellasY[i], WHITE);
            EstrellasY[i]++;
            if (EstrellasY[i] > SCREENY)
            {
                EstrellasY[i] = 0;
            }
        }
    }

    void Clear()
    {
        ClearBackground(BLACK);
    }
};