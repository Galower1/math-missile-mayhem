#include "raylib.h"
#include "Macros.h"
#include <string>

#pragma once

class Asteroids
{
private:
    int Size = 7;
    std::string Id;
    const char *Text;
    bool Check;
    bool Alive = true;
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
                Dirx = -1;
            if ((GetRandomValue(0, 9) % 2) == 0)
                Diry = 1;
            else
                Diry = -1;
        }
    }

    bool isAlive()
    {
        return Alive;
    }

    void TagAst(int num)
    {
        Id = std::to_string(num);
        Text = Id.c_str();
    }

    void CheckPos()
    {
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

    void TrackAst()
    {
        if (Alive)
        {
            DrawCircle(Posx, Posy, Size, Tone);
            Posx += Dirx;
            Posy += Diry;
            CheckPos();

            DrawText(Text, Posx, Posy, 20, WHITE);
        }
    }

    void ColAst(Asteroids Ast[], int num, int self)
    {
        Vector2 Pos1 = {Posx, Posy};
        for (int i = 0; i < num; i++)
        {
            Vector2 Pos2 = {Ast[i].Posx, Ast[i].Posy};
            Check = CheckCollisionCircles(Pos1, (Size + 1), Pos2, (Ast[i].Size + 1));
            if (Check && (i != self))
            {
                Ast[i].Dirx *= -1;
                Ast[i].Diry *= -1;
                Dirx *= -1;
                Diry *= -1;
            }
        }
    }

    Vector2 getCenter()
    {
        return Vector2{(float)Posx, (float)Posy};
    }

    int getRadius()
    {
        return Size;
    }

    void kill()
    {
        Alive = false;
    }
};