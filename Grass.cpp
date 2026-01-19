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
/*
void Grass::draw()
{
    glColor3f(0.0f, 0.7f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(x, y);
        glVertex2f(x + sway, y + h);
        glVertex2f(x + 0.01f, y);
    glEnd();
}*/
   void Grass::draw()
{
    glColor3f(0.0f, 0.6f, 0.0f);  // সবুজ ঘাসের রঙ (নিচের দিকে)
    glBegin(GL_TRIANGLES);
        glVertex2f(x, y);        // নিচের বাম
        glVertex2f(x + sway, y + h); // ঘাসের টিপ
        glVertex2f(x + 0.01f, y);    // নিচের ডান
    glEnd();

    // Optional: নিচের base আরও ভরাট করতে full rectangle
    glColor3f(0.0f, 0.5f, 0.0f); // dark green base
    glBegin(GL_QUADS);
        glVertex2f(x - 0.01f, -1.0f); // bottom left (screen bottom)
        glVertex2f(x + 0.02f, -1.0f); // bottom right
        glVertex2f(x + 0.02f, y);     // top right (grass base)
        glVertex2f(x - 0.01f, y);     // top left
    glEnd();
}


