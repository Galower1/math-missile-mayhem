#include <iostream>
#include "raylib.h"
#include "components/Macros.h"
#include "components/Background.h"
#include "components/Asteroids.h"
#include "components/Ship.h"
#include "components/BounceProjectile.h"

int main()
{

    InitWindow(SCREENX, SCREENY, "Math Missile Mayhem");
    Texture2D shipTexture = LoadTexture("assets/ship-medium.png");
    Background Def;
    Asteroids Ast[45];
    Ship Player{shipTexture};
    BounceProjectile BP;
    STARLOOP
    {
        Ast[i].TagAst(i);
    }
    while (!WindowShouldClose())
    {
        BeginDrawing();
        SetTargetFPS(60);
        DrawFPS(0, 0);
        Def.Clear();
        Def.TrackStar();
        Player.maneuver();
        Player.draw();
        STARLOOP
        {
            Ast[i].TrackAst();
            Ast[i].ColAst(Ast, 45, i);
        }
        EndDrawing();
    }
}
