#include "Drone.h"
#include <GL/glut.h>
#include "GameState.h"
#include <cstdlib>

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

    // Body
    glColor3f(0.3f,0.6f,0.9f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.2f, 0.05f);
        glVertex2f(0.2f, 0.05f);
        glVertex2f(0.2f, -0.05f);
        glVertex2f(-0.2f, -0.05f);
    glEnd();

    // Cockpit
    glColor3f(0.8f,0.9f,1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.05f, 0.05f);
        glVertex2f(0.05f, 0.05f);
        glVertex2f(0.05f, -0.05f);
        glVertex2f(-0.05f, -0.05f);
    glEnd();

    // Propellers
    glColor3f(0.2f,0.2f,0.2f);
    float bladeLength = 0.12f;
    for(int i = -1; i<=1; i+=2){
        // Left propeller
        glBegin(GL_LINES);
            glVertex2f(-0.25f, i*0.05f);
            glVertex2f(-0.25f - bladeLength, i*0.05f);
        glEnd();

        // Right propeller
        glBegin(GL_LINES);
            glVertex2f(0.25f, i*0.05f);
            glVertex2f(0.25f + bladeLength, i*0.05f);
        glEnd();
    }

    glPopMatrix();
}
