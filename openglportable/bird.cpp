#include "bird.h"
#include <GL/glut.h>
#include <cmath>

Bird::Bird(float xPos, float yPos, float s)
{
    x = xPos;
    y = yPos;
    scale = s;
    wingAngle = 0.0f;
}

void Bird::update()
{
    wingAngle += 0.12f;
    if (wingAngle > 2 * M_PI)
        wingAngle = 0.0f;
}

void Bird::draw()
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    int segments = 60;

    // BODY
    float bodyR = 0.18f;
    glColor3f(1.0f, 0.9f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float a = 2 * M_PI * i / segments;
        glVertex2f(bodyR * cos(a), bodyR * sin(a));
    }
    glEnd();

    // EYE
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float a = 2 * M_PI * i / segments;
        glVertex2f(0.04f * cos(a) + 0.06f,
                   0.04f * sin(a) + 0.05f);
    }
    glEnd();

    // BEAK
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.15f,  0.02f);
        glVertex2f(0.28f,  0.00f);
        glVertex2f(0.15f, -0.02f);
    glEnd();

    // WING
    float flap = sin(wingAngle) * 0.06f;
    glColor3f(1.0f, 0.85f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.02f,  0.02f + flap);
        glVertex2f(-0.22f, -0.04f);
        glVertex2f(-0.02f, -0.12f - flap);
    glEnd();

    glPopMatrix();
}

