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
    Background Def;
    Asteroids Ast[45];
    Ship Player;
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
        Player.TrackShip();
        Player.Maneuver();
        STARLOOP
        {
            Ast[i].TrackAst();
            Ast[i].ColAst(Ast, 45, i);
        }
        BP.TrackProj(Player.GetNode(2, 'x'), Player.GetNode(2, 'y'));
        EndDrawing();
    }
}
