#include "background.h"
#include "sky.h"

float GAME_SPEED = 0.0025f;

void drawGround()
{
    glBegin(GL_QUADS);
    //soil
       glColor3f(0.263f, 0.169f, 0.071f);
       glVertex2f(-1.0f, -1.0f);
       glVertex2f( 1.0f, -1.0f);
       glVertex2f( 1.0f, -0.7f);
       glVertex2f(-1.0f, -0.7f);

    //grass
       glColor3f(0.0f, 0.659f, 0.0f);
       glVertex2f(-1.0f, -0.7f);
       glVertex2f( 1.0f, -0.7f);
       glVertex2f( 1.0f, -0.6f);
       glVertex2f(-1.0f, -0.6f);

    glEnd();

}



void drawBackground()
{
    drawSky();
    drawGround();
}

void updateBackground()
{
    updateSky();

}

void initScene()
{
    initSky();
}
