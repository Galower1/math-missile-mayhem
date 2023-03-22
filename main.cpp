#include <iostream>
#include "raylib.h"
#include "Macros.h"
#include "Background.h"
#include "Asteroids.h"

using namespace std;

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