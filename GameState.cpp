#include "GameState.h"
#include "Bird.h"
#include "Drone.h"
#include "Tower.h"

// Game variables
int score = 0;
int level = 1;
float GAME_SPEED = 0.002f;
bool paused = false;
bool gameOver = false;

// Reset function
void resetGame()
{
    // Bird reset
    extern Bird bird;
    bird.x = -0.5f;
    bird.y = 0.0f;
    bird.velocityY = 0.0f;
    bird.wingAngle = 0.0f;
    bird.wingUp = true;

    // Towers reset
    extern Tower towers[3];
    towers[0] = Tower(-0.7f, -0.6f, 0.2f, 0.3f);
    towers[1] = Tower(-0.1f, -0.6f, 0.2f, 0.5f);
    towers[2] = Tower(0.5f, -0.6f, 0.2f, 0.7f);

    // Drones reset
    extern Drone drones[3];
    drones[0] = Drone(1.2f, 0.3f, 0.35f);
    drones[1] = Drone(1.8f, -0.1f, 0.35f);
    drones[2] = Drone(2.4f, 0.1f, 0.35f);

    // Score, level, game speed
    score = 0;
    level = 1;
    GAME_SPEED = 0.002f;

    // Game state
    gameOver = false;
    paused = false;
}

