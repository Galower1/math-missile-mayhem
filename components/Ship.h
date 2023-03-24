#include "Macros.h"
#include "raylib.h"
#include "math.h"
#include <string>
#include <iostream>

#pragma once

class Ship
{
private:
    Texture2D texture;
    Vector2 position{SCREENX / 2, SCREENY / 2};
    float rotationAngle;
    Vector2 shipCenter;
    Rectangle shipBox;

public:
    Ship(Texture2D texture) : texture(texture)
    {
        shipCenter.x = texture.width / 2;
        shipCenter.y = texture.height / 2;
        shipBox = {
            0, 0, (float)texture.width, (float)texture.height};
    }

    ~Ship()
    {
        UnloadTexture(texture);
    }

    void maneuver()
    {
        if (IsKeyDown(87))
        {
            position.y -= 3;
        }
        if (IsKeyDown(83))
        {
            position.y += 3;
        }
        if (IsKeyDown(65))
        {
            position.x -= 3;
        }
        if (IsKeyDown(68))
        {
            position.x += 3;
        }

        if(position.x>SCREENX)
        {
            position.x=0;
        }
        else if (position.x<0)
        {
            position.x=SCREENX;
        }
        if(position.y>SCREENY)
        {
            position.y=0;
        }
        else if (position.y<0)
        {
            position.y=SCREENY;
        }
    }

    void draw()
    {
        Vector2 mousePosition = GetMousePosition();
        float angle = atan2(mousePosition.y - (position.y + shipCenter.y), mousePosition.x - (position.x + shipCenter.x));
        angle = angle * RAD2DEG;

        DrawTexturePro(
            texture,
            shipBox,
            Rectangle{
                position.x + texture.width / 2,
                position.y + texture.height / 2,
                (float)texture.width,
                (float)texture.height},
            shipCenter,
            angle + 90,
            WHITE);
    }

    Vector2 getCannonPosition()
    {
        return Vector2{
            x : position.x + shipCenter.x,
            y : position.y + shipCenter.y
        };
    }
};
