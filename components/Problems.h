#include "raylib.h"
#include "Asteroids.h"
#include <vector>
#include "Macros.h"

class Problems
{
private:
    bool solved;
    int target;
    int totalAsteroids;
    int idAsteroid;
    Asteroids *asteroids;

    void setTotalAsteroid()
    {
        int count = 0;
        for (int i = 0; i < ASTEROID_NUMBER; i++)
        {
            if (asteroids[i].isAlive())
            {
                count++;
            }
        }
        totalAsteroids = count;
    }

    void renderProblemBox()
    {
        DrawRectangle(0, 0, 250, 80, WHITE);
        DrawText("EXERCISE", 10, 10, 20, BLACK);
    }

    void renderProblem()
    {
        if (solved)
        {
            setTotalAsteroid();
            target = GetRandomValue(1, 500);
            idAsteroid = GetRandomValue(1, totalAsteroids);
            solved = false;
        }

        int output = idAsteroid + target;
        DrawText(TextFormat("%d + x = %d", target, output), 10, 40, 30, BLUE);
    }

public:
    Problems(Asteroids ast[]) : solved(false), target(GetRandomValue(1, 500)), asteroids(ast)
    {
        setTotalAsteroid();
        idAsteroid = GetRandomValue(1, totalAsteroids);
    }

    ~Problems()
    {
        delete asteroids;
    }

    int getProblemAsteroidId()
    {
        return idAsteroid;
    }

    void setSolved()
    {
        solved = true;
    }

    void render()
    {
        renderProblemBox();
        renderProblem();
    }
};