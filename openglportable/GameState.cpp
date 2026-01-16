#include "GameState.h"
#include "Bird.h"
#include "Drone.h"


extern Bird bird;
extern Drone drones[];

bool paused = false;
bool gameOver = false;
int score = 0;
int level = 1;


float GAME_SPEED = 0.0025f;

void resetGame()
{
    paused = false;
    gameOver = false;
    score = 0;
    level = 1;

    GAME_SPEED = 0.0025f;


    bird.x = -0.5f;
    bird.y = 0.0f;
    bird.velocityY = 0.0f;


    for (int i = 0; i < 3; i++)
    {
        drones[i].x = 1.2f + i * 0.6f;
        drones[i].y = (i % 2 == 0) ? 0.3f : -0.1f;
    }
}
