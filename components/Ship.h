#include "Macros.h"
#include "raylib.h"
#include "math.h"
#include <string>

#pragma once

class Ship
{
private:
    Texture2D texture;
    Vector2 textureOffset;

public:
    Vector2 position;
    float rotationAngle;
    Ship(Texture2D texture);
    void Draw();
    void RotateTowardsMouse(float rotateSpeed);
};

Ship::Ship(Texture2D texture)
{
    this->texture = texture;
    textureOffset = Vector2{(float)texture.width / 2, (float)texture.height / 2};
    position = Vector2{350, 350};
    rotationAngle = 0;
}

void Ship::Draw()
{
    DrawTexturePro(texture,
                   Rectangle{0, 0, (float)texture.width, (float)texture.height},
                   Rectangle{position.x - textureOffset.x,
                             position.y - textureOffset.y,
                             (float)texture.width,
                             (float)texture.height},
                   textureOffset,
                   rotationAngle,
                   WHITE);
}

void Ship::RotateTowardsMouse(float rotateSpeed)
{
    Vector2 mousePos = GetMousePosition();
    float targetAngle = atan2(mousePos.y - position.y, mousePos.x - position.x) * RAD2DEG;
    if (targetAngle < 0)
        targetAngle += 360;

    float angleDiff = targetAngle - rotationAngle;
    if (angleDiff < -180)
        angleDiff += 360;
    else if (angleDiff > 180)
        angleDiff -= 360;

    rotationAngle += (angleDiff * rotateSpeed);
}