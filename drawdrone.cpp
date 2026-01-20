#include <GL/glut.h>
#include <cmath>
#include "Drone.h"


Drone::Drone()
{
    x = 0;
    y = 0;
    scale = 1;
}


Drone::Drone(float x, float y, float s)
{
    this->x = x;
    this->y = y;
    this->scale = s;
}

// Circle
static void drawCircle(float cx, float cy, float r)
{
    int segments = 100;
    glBegin(GL_POLYGON);
    for (int i = segments; i >= 0; i--)
    {
        float a = 2 * M_PI * i / segments;
        glVertex2f(cx + r * cos(a), cy + r * sin(a));
    }
    glEnd();
}

// Draw drone
void Drone::draw()
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1);

    // Body top
    glColor3f(0.35f, 0.7f, 0.8f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.12f, 0.15f);
        glVertex2f( 0.12f, 0.15f);
        glVertex2f( 0.18f, 0.05f);
        glVertex2f(-0.18f, 0.05f);
    glEnd();

    // Body bottom
    glColor3f(0.15f, 0.35f, 0.5f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.18f, 0.05f);
        glVertex2f( 0.18f, 0.05f);
        glVertex2f( 0.15f,-0.10f);
        glVertex2f(-0.15f,-0.10f);
    glEnd();

    // Arms
    glLineWidth(6);
    glColor3f(0.1f, 0.2f, 0.3f);
    glBegin(GL_LINES);
        glVertex2f(-0.15f, 0); glVertex2f(-0.35f, 0.15f);
        glVertex2f( 0.15f, 0); glVertex2f( 0.35f, 0.15f);
        glVertex2f(-0.15f, 0); glVertex2f(-0.35f,-0.05f);
        glVertex2f( 0.15f, 0); glVertex2f( 0.35f,-0.05f);
    glEnd();

    // Propellers
    glColor3f(0.2f, 0.4f, 0.5f);
    drawCircle(-0.35f,  0.15f, 0.06f);
    drawCircle( 0.35f,  0.15f, 0.06f);
    drawCircle(-0.35f, -0.05f, 0.06f);
    drawCircle( 0.35f, -0.05f, 0.06f);

    glPopMatrix();
}
