#include "Drone.h"
#include <GL/glut.h>
#include "GameState.h"
#include <cstdlib>
#include <cmath>
using namespace std;


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
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1);

    // Body (slightly rounded rectangle)
    glColor3f(0.3f, 0.6f, 0.9f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.2f, 0.05f);
        glVertex2f(0.2f, 0.05f);
        glVertex2f(0.25f, 0.0f);
        glVertex2f(0.2f, -0.05f);
        glVertex2f(-0.2f, -0.05f);
        glVertex2f(-0.25f, 0.0f);
    glEnd();

    // Cockpit (ellipse-like)
    glColor3f(0.8f, 0.9f, 1.0f);
    glBegin(GL_POLYGON);
        for(int i = 0; i <= 50; i++)
        {
            float a = 2 * 3.1416f * i / 50;
            float cx = 0.0f + 0.05f * cos(a);
            float cy = 0.0f + 0.03f * sin(a);
            glVertex2f(cx, cy);
        }
    glEnd();

    // Wings
    glColor3f(0.2f, 0.5f, 0.8f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.25f, 0.0f);
        glVertex2f(-0.35f, 0.08f);
        glVertex2f(-0.35f, -0.08f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(0.25f, 0.0f);
        glVertex2f(0.35f, 0.08f);
        glVertex2f(0.35f, -0.08f);
    glEnd();

    // Propellers (rotating)
    glColor3f(0.1f, 0.1f, 0.1f);
    float bladeLength = 0.12f;
    for(int i = -1; i <= 1; i += 2)
    {
        // Left propeller
        glBegin(GL_LINES);
            glVertex2f(-0.35f, i*0.05f);
            glVertex2f(-0.35f - bladeLength, i*0.05f);
        glEnd();

        // Right propeller
        glBegin(GL_LINES);
            glVertex2f(0.35f, i*0.05f);
            glVertex2f(0.35f + bladeLength, i*0.05f);
        glEnd();
    }

    glPopMatrix();
}

