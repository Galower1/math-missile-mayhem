#include <iostream>
#include <vector>
#include "raylib.h"
#include "components/Macros.h"
#include "components/Background.h"
#include "components/Asteroids.h"
#include "components/Ship.h"
#include "components/BounceProjectile.h"
#include "components/Missile.h"
#include "components/Problems.h"

int main()
{

    InitWindow(SCREENX, SCREENY, "Math Missile Mayhem");
    Texture2D shipTexture = LoadTexture("assets/ship-medium.png");
    Background Def;
    Asteroids Ast[ASTEROID_NUMBER];
    Ship Player{shipTexture};
    BounceProjectile BP;
    Problems problems = Problems{Ast};
    std::vector<Missile> Proj{};
    bool gameOver = false;
    STARLOOP
    {
        Ast[i].TagAst(i + 1);
    }
    while (!WindowShouldClose())
    {
        BeginDrawing();
        SetTargetFPS(60);
        if (!gameOver)
        {
            Def.Clear();
            Def.TrackStar();
            Player.maneuver();
            Player.draw();
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                Proj.push_back(Player.getCannonPosition());
            }
            STARLOOP
            {
                Ast[i].TrackAst();
                Ast[i].ColAst(Ast, ASTEROID_NUMBER, i);

                if (CheckCollisionCircles(Player.getCenter(), Player.getRadius(), Ast[i].getCenter(), Ast[i].getRadius()))
                {
                    gameOver = true;
                }
            }
            for (int i = 0; i < Proj.size(); i++)
            {
                Proj[i].TrackPos();
                if ((Proj[i].GetPos().x > SCREENX) || (Proj[i].GetPos().y > SCREENY))
                {
                    Proj.erase(Proj.begin() + i);
                }
            }

            problems.render();
        }
        else
        {
            char *gameOverMessage = "GAME OVER";
            char *gameOverDescription = "PRESS (ENTER) TO CONTINUE";
            int messageSize = MeasureText(gameOverMessage, 60);
            int descriptionSize = MeasureText(gameOverDescription, 30);
            DrawText(gameOverMessage, (SCREENX - messageSize) / 2, SCREENY / 2 - 60, 60, RED);
            DrawText(gameOverDescription, (SCREENX - descriptionSize) / 2, SCREENY / 2 + 100 - 30, 30, WHITE);

            if (IsKeyDown(KEY_ENTER))
            {
                gameOver = false;
                STARLOOP
                {
                    Ast[i] = Asteroids{};
                    Ast[i].TagAst(i + 1);
                }
                Player.resetPosition();
                problems.setSolved();
            }
        }
        EndDrawing();
    }
}
