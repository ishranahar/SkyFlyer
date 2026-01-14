#include "Polygon.h"
#include <GL/glut.h>

Polygon::Polygon(float x, float y, float w, float h,
                 float r, float g, float b)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    this->r = r;
    this->g = g;
    this->b = b;
}

void Polygon::draw()
{
    glColor3f(r, g, b);

    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x, y + h);
    glEnd();
}

