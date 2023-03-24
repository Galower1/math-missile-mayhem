#include <iostream>
#include <vector>
#include "raylib.h"
#include "components/Macros.h"
#include "components/Background.h"
#include "components/Asteroids.h"
#include "components/Ship.h"
#include "components/BounceProjectile.h"
#include "components/Missile.h"

int main()
{

    InitWindow(SCREENX, SCREENY, "Math Missile Mayhem");
    Texture2D shipTexture = LoadTexture("assets/ship-medium.png");
    Background Def;
    Asteroids Ast[45];
    Ship Player{shipTexture};
    BounceProjectile BP;
    std::vector<Missile> Proj{};
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
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Proj.push_back(Player.getCannonPosition());
        }
        STARLOOP
        {
            Ast[i].TrackAst();
            Ast[i].ColAst(Ast, 45, i);
        }
        for (int i=0; i<Proj.size();i++)
        {
            Proj[i].TrackPos();
            if((Proj[i].GetPos().x>SCREENX)||(Proj[i].GetPos().y>SCREENY))
            {
                Proj.erase(Proj.begin()+i);
            }
        }
        EndDrawing();
    }
}

