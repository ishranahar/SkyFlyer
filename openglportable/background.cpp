#include "background.h"
#include "sky.h"

float GAME_SPEED = 0.0025f;

void drawBackground()
{
    drawSky();
}

void updateBackground()
{
    updateSky();

}

void initScene()
{
    initSky();
}
