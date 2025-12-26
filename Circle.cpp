#include "Circle.h"
#include <GL/glut.h>
#include <math.h>

Circle::Circle()
{
    x = 0.0f;
    y = 0.0f;
    radius = 0.1f;
}

Circle::Circle(float r, float x, float y)
{
    this->radius = r;
    this->x = x;
    this->y = y;
}

void Circle::draw()
{
    int segments = 100;
    glBegin(GL_POLYGON);
    for (int i = 0; i <= segments; i++)
    {
        float a = 2 * M_PI * i / segments;
        glVertex2f(x + radius * cos(a), y + radius * sin(a));
    }
    glEnd();
}

