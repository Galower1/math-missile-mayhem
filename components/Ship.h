#include "Macros.h"
#include "raylib.h"

#pragma once

class Ship
{
private:
    int Posx = CENTROX;
    int Posy = CENTROY;

    int Basehalved = 20;
    int Heighthalved = 25;

    int N1x;
    int N1y;

    int N2x;
    int N2y;

    int N3x;
    int N3y;

    Vector2 Node1;
    Vector2 Node2;
    Vector2 Node3;

public:
    void Maneuver()
    {
        if (IsKeyDown(87))
        {
            Posy -= 2;
        }
        if (IsKeyDown(83))
        {
            Posy += 2;
        }
        if (IsKeyDown(65))
        {
            Posx -= 2;
        }
        if (IsKeyDown(68))
        {
            Posx += 2;
        }
    }

    void CalculateNode()
    {
        N1x = Posx + Basehalved;
        N1y = Posy + Heighthalved;

        N2x = Posx;
        N2y = Posy - Heighthalved;

        N3x = Posx - Basehalved;
        N3y = Posy + Heighthalved;
    }

    void TrackShip()
    {
        CalculateNode();
        Vector2 Node1 = {N1x, N1y};
        Vector2 Node2 = {N2x, N2y};
        Vector2 Node3 = {N3x, N3y};
        DrawTriangle(Node1, Node2, Node3, GREEN);
    }

    int GetNode(int x, char y)
    {
        int xNodes[]{N1x, N2x, N3x};
        int yNodes[]{N1y, N2y, N3y};
        return y == 'x' ? xNodes[x - 1] : yNodes[x - 1];
    }
};