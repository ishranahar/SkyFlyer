#include "Flower.h"
#include <GL/glut.h>
#include <cmath>

Flower::Flower(float xPos, float yPos)
{
    x = xPos;
    y = yPos;
}

void Flower::draw()
{
    glPushMatrix();
    glTranslatef(x, y, 0);



    glColor3f(0.0f, 0.8f, 0.0f);
    glLineWidth(4.0f);
    glBegin(GL_LINE_STRIP);
    for (float i = 0; i <= 0.12f; i += 0.01f) {

        glVertex2f(0.01f * sin(i * 20.0f), i);
    }
    glEnd();


    glColor3f(0.0f, 0.9f, 0.0f);


    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.04f);
        glVertex2f(-0.06f, 0.08f);
        glVertex2f(-0.08f, 0.04f);
        glVertex2f(-0.04f, 0.02f);
    glEnd();


    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.06f);
        glVertex2f(0.06f, 0.10f);
        glVertex2f(0.08f, 0.06f);
        glVertex2f(0.04f, 0.04f);
    glEnd();


   // glColor3f(1.0f, 0.2f, 0.6f);
    glColor3f(1.0f, 0.0f, 0.0f);
    float petalRadius = 0.03f;

    for(int p = 0; p < 5; p++)
    {
        float a = p * (2 * 3.1416f / 5);
        glBegin(GL_POLYGON);
        for(int i = 0; i <= 360; i += 10)
        {
            float ang = i * 3.1416f / 180.0f;

            glVertex2f(
                0.045f * cos(a) + petalRadius * cos(ang),
                0.12f + 0.045f * sin(a) + (petalRadius + 0.01f) * sin(ang)
            );
        }
        glEnd();
    }

    glColor3f(1.0f, 0.9f, 0.0f);
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 360; i += 10)
    {
        float ang = i * 3.1416f / 180.0f;
        glVertex2f(
            0.025f * cos(ang),
            0.12f + 0.025f * sin(ang)
        );
    }
    glEnd();

    glPopMatrix();
}
