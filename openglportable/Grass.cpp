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

    glColor3f(0.1f, 0.6f, 0.1f);
    glRectf(-1.2f, y, 1.2f, y + height);



    glEnd();
}


