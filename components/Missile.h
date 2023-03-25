#include "raylib.h"
#include "Ship.h"
#include <vector>
#include "Problems.h"

#pragma once

class Missile
{
private:
    int Size = 3;
    int Speed = 6;

    bool Flag = 0;
    Color Tone = GREEN;

    float Angle;
    float Mag;

    Vector2 Pos;
    Vector2 Dir;
    int projectileId;

public:
    Missile(Vector2 Origin, int id) : projectileId(id)
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

    void checkCollisions(Asteroids ast[], std::vector<Missile> &projectiles, Problems &problems)
    {
        for (int i = 0; i < ASTEROID_NUMBER; i++)
        {
            if (CheckCollisionCircles(ast[i].getCenter(), ast[i].getRadius(), Pos, Size))
            {
                if (problems.getProblemAsteroidId() == i + 1)
                {
                    ast[i].kill();
                    problems.setSolved();
                }
                for (int j = 0; j < projectiles.size(); j++)
                {

                    if (projectiles[j].projectileId == projectileId)
                    {
                        projectiles.erase(projectiles.begin() + j);
                    }
                }
            }
        }
    }
};