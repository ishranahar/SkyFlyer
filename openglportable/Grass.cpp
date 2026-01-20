#include "Grass.h"
#include "GameState.h"
#include <GL/glut.h>

Grass::Grass(float yPos)
{
    y = yPos;
    height = 0.15f;
    offset = 0.0f;
}

void Grass::update()
{
    offset += GAME_SPEED * 50;
    if(offset > 0.05f)
        offset = 0.0f;
}

void Grass::draw()
{
    // Ground base
    glColor3f(0.1f, 0.6f, 0.1f);
    glRectf(-1.2f, y, 1.2f, y + height);

    // Grass blades
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_LINES);
    for(float x = -1.2f + offset; x <= 1.2f; x += 0.05f)
    {
        glVertex2f(x, y + height);
        glVertex2f(x, y + height + 0.03f);
    }
    glEnd();
}


