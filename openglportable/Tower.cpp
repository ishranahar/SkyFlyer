#include "Tower.h"
#include "GameState.h"
#include <GL/glut.h>
#include <cstdlib>

Tower::Tower(float x,float y,float w,float h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void Tower::update()
{
    x -= GAME_SPEED;

    if (x + w < -1.2f)
    {
        x = 1.3f + (rand() % 50) / 100.0f;
    }
}

void Tower::draw()
{
    glColor3f(0.6f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(x,     y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x,     y + h);
    glEnd();
}

