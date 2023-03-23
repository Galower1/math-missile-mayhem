#include <iostream>
#include "raylib.h"
#include "Macros.h"
#include "Background.h"
#include "Asteroids.h"
#include "Ship.h"

using namespace std;

class BounceProjectile
{
public:
    void TrackProj(int x, int y)
    {
        DrawCircle(x, y, Size, Tone);
    }

private:
    int Size = 5;
    Color Tone = RED;

    int Posx = CENTROX;
    int Posy = CENTROY;
};

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
