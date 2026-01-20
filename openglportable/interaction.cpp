#include "interaction.h"
#include "sound.h"
#include "Bird.h"
#include "GameState.h"
#include <GL/glut.h>
#include <cstdlib>

extern Bird bird;

void handleKeys(unsigned char key, int x, int y)
{
    if (key == 'w') {
        bird.velocityY = 0.015f;
        playSound("jump.wav");
    }
    else if (key == 's') {
        bird.velocityY = -0.015f;
        playSound("swoosh.wav");
    }

    switch(key)
    {
        case 'p':
            paused = !paused;
            playSound("select.wav");
            break;

        case 'r':
            resetGame();
            playSound("select.wav");
            break;

        case 27:
            exit(0);
            break;
    }
}
