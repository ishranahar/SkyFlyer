#include "background.h"
#include "sky.h"

void drawGround()
{
    glBegin(GL_QUADS);

       glColor3f(0.263f, 0.169f, 0.071f);
       glVertex2f(-1.0f, -1.0f);
       glVertex2f( 1.0f, -1.0f);
       glVertex2f( 1.0f, -0.7f);
       glVertex2f(-1.0f, -0.7f);


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

