#include "Grass.h"
#include <GL/glut.h>
#include <cmath>

static float gt = 0.0f;

Grass::Grass()
{
    x = y = 0;
    h = 0.1f;
    sway = 0;
}

Grass::Grass(float x,float y,float h)
{
    this->x = x;
    this->y = y;
    this->h = h;
    sway = 0;
}

void Grass::update()
{
    gt += 0.02f;
    sway = sin(gt + x * 15) * 0.01f;
}

void Grass::draw()
{
    glColor3f(0.0f, 0.7f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(x, y);
        glVertex2f(x + sway, y + h);
        glVertex2f(x + 0.01f, y);
    glEnd();
}

