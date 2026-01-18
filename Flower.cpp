#include "Flower.h"
#include <GL/gl.h>
#include <cmath>


void drawCircle(float cx, float cy, float r, int segments = 40)
{
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= segments; i++)
        {
            float a = 2.0f * 3.1416f * i / segments;
            glVertex2f(cx + cos(a) * r,
                       cy + sin(a) * r);
        }
    glEnd();
}

Flower::Flower()
{
    x = y = 0.0f;
    r = g = b = 1.0f;
}

Flower::Flower(float x, float y, float r, float g, float b)
{
    this->x = x;
    this->y = y;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Flower::draw()
{

    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(x - 0.005f, y);
        glVertex2f(x + 0.005f, y);
        glVertex2f(x + 0.005f, y + 0.06f);
        glVertex2f(x - 0.005f, y + 0.06f);
    glEnd();

    float cy = y + 0.08f;
    float petalR = 0.015f;


    glColor3f(r, g, b);
    int petalCount = 7;

    for (int i = 0; i < petalCount; i++)
    {
        float a = 2.0f * 3.1416f * i / petalCount;
        float px = x + cos(a) * 0.025f;
        float py = cy + sin(a) * 0.025f;
        drawCircle(px, py, petalR);
    }


    glColor3f(1.0f, 0.85f, 0.0f);
    drawCircle(x, cy, 0.012f);
}
