#include "raylib.h"

#define SCREENX 1200
#define SCREENY 900

#define CENTROX SCREENX / 2
#define CENTROY SCREENY / 2

#define RANDOMX GetRandomValue(0, SCREENX)
#define RANDOMY GetRandomValue(0, SCREENY)

#define ASTEROID_NUMBER 45

#define STARLOOP for (int i = 0; i < ASTEROID_NUMBER; i++)
