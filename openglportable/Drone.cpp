#include "Drone.h"
#include <GL/glut.h>
#include "GameState.h"

Drone::Drone(float x, float y, float s)
{
    this->x = x;
    this->y = y;
    scale = s;
}



void Drone::update()
{
    x -= GAME_SPEED;

    if (x < -1.6f)
    {
        x = 1.6f + (rand() % 100) / 100.0f;
        y = -0.4f + (rand() % 80) / 100.0f;
    }
}


void Drone::draw()
{
    glPushMatrix();
    glTranslatef(x,y,0);
    glScalef(scale,scale,1);

    glColor3f(0.3f,0.6f,0.9f);
    glBegin(GL_QUADS);
        glVertex2f(-0.2f,0.05f);
        glVertex2f(0.2f,0.05f);
        glVertex2f(0.15f,-0.05f);
        glVertex2f(-0.15f,-0.05f);
    glEnd();

    glPopMatrix();
}
