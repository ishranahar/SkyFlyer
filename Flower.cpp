#include "Flower.h"
#include <GL/glut.h>
#include <cmath>

static float t = 0.0f;

void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= 40; i++)
        {
            float a = 2 * 3.1416f * i / 40;
            glVertex2f(cx + cos(a) * r, cy + sin(a) * r);
        }
    glEnd();
}

Flower::Flower()
{
    x = y = 0;
    r = g = b = 1;
    sway = 0;
}

Flower::Flower(float x,float y,float r,float g,float b)
{
    this->x = x;
    this->y = y;
    this->r = r;
    this->g = g;
    this->b = b;
    sway = 0;
}

void Flower::update()
{
    t += 0.01f;
    sway = sin(t + x * 10) * 0.01f;
}

void Flower::draw()
{
    glColor3f(0, 0.6f, 0);
    glBegin(GL_QUADS);
        glVertex2f(x - 0.005f, y);
        glVertex2f(x + 0.005f, y);
        glVertex2f(x + sway, y + 0.07f);
        glVertex2f(x - sway, y + 0.07f);
    glEnd();

    float cy = y + 0.09f + sway;

    glColor3f(r, g, b);
    for (int i = 0; i < 7; i++)
    {
        float a = 2 * 3.1416f * i / 7;
        drawCircle(x + cos(a) * 0.025f, cy + sin(a) * 0.025f, 0.015f);
    }

    glColor3f(1, 0.85f, 0);
    drawCircle(x, cy, 0.012f);
}

