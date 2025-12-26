#include "Cloud.h"
#include <GL/glut.h>
#include <math.h>

void drawCloud(float x, float y)
{
    glColor3f(1.0f, 1.0f, 1.0f);

    float r1 = 0.11f;
    float r2 = 0.14f;
    float r3 = 0.10f;

    // Left circle
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180.0f;
        glVertex2f(x + r1 * cos(angle), y + r1 * sin(angle));
    }
    glEnd();

    // Middle circle
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180.0f;
        glVertex2f(x + 0.13f + r2 * cos(angle), y  + r2 * sin(angle));
    }
    glEnd();

    // Right circle
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180.0f;
        glVertex2f(x + 0.26f + r3 * cos(angle), y + r3 * sin(angle));
    }
    glEnd();
}

void drawClouds(Cloud clouds[], int count)
{
    for (int i = 0; i < count; i++)
    {
        drawCloud(clouds[i].x, clouds[i].y);
    }
}

