#include "Bird.h"
#include <GL/glut.h>
#include <cmath>

Bird::Bird(float xPos, float yPos)
{
    x = xPos;
    y = yPos;
    velocityY = 0.0f;
    scale = 0.7f;
    speedX = 0.0015f;
}

void Bird::update()
{

    velocityY -= 0.0008f;
    y += velocityY;


    x = -0.5f;


    if (y < -0.85f) { y = -0.85f; velocityY = 0; }
    if (y >  0.85f) { y =  0.85f; velocityY = 0; }
}


void Bird::draw()
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1);


    glColor3f(1.0f, 0.9f, 0.0f);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 100; i++)
    {
        float a = 2 * 3.1416f * i / 100;
        glVertex2f(0.18f * cos(a), 0.12f * sin(a));
    }
    glEnd();


    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 50; i++)
    {
        float a = 2 * 3.1416f * i / 50;
        glVertex2f(0.04f * cos(a) + 0.08f,
                   0.04f * sin(a) + 0.04f);
    }
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 50; i++)
    {
        float a = 2 * 3.1416f * i / 50;
        glVertex2f(0.02f * cos(a) + 0.09f,
                   0.02f * sin(a) + 0.04f);
    }
    glEnd();


    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.18f,  0.02f);
        glVertex2f(0.28f,  0.00f);
        glVertex2f(0.18f, -0.02f);
    glEnd();

    glPopMatrix();
}

