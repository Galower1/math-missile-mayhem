#include "raylib.h"
#include "Ship.h"

#pragma once

class Missile
{
private:
    int Size = 3;
    int Speed = 3;

    bool Flag = 0;
    Color Tone = GREEN;

    float Angle;
    float Mag;

    Vector2 Pos;
    Vector2 Dir;

public:
    Missile(Vector2 Origin)
    {
        Pos = Origin;
        Dir = {(GetMousePosition().x) - Pos.x, (GetMousePosition().y - Pos.y)};
        Mag = sqrt((Dir.x * Dir.x) + (Dir.y * Dir.y));
        Angle = atan(Dir.y / Dir.x);
        Angle = (Angle * RAD2DEG);
    }
    void TrackPos()
    {
        Pos = {(Pos.x + ((Dir.x / Mag) * Speed)), (Pos.y + ((Dir.y / Mag) * Speed))};
        DrawCircle(Pos.x, Pos.y, Size, Tone);
    }
    Vector2 GetPos()
    {
        return (Pos);
    }
};
;