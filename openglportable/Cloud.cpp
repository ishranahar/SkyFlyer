#include "Cloud.h"
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

void drawCloud(float x, float y)
{
    glColor3f(1.0f, 1.0f, 1.0f);

    float r1 = 0.11f;
    float r2 = 0.14f;
    float r3 = 0.10f;


    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        float a = i * 3.1416f / 180.0f;
        glVertex2f(x + r1 * cos(a), y + r1 * sin(a));
    }
    glEnd();


    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        float a = i * 3.1416f / 180.0f;
        glVertex2f(x + 0.13f + r2 * cos(a), y + r2 * sin(a));
    }
    glEnd();


    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        float a = i * 3.1416f / 180.0f;
        glVertex2f(x + 0.26f + r3 * cos(a), y + r3 * sin(a));
    }
    glEnd();
}

void drawClouds(Cloud clouds[], int count)
{
    for(int i = 0; i < count; i++)
        drawCloud(clouds[i].x, clouds[i].y);
}


void updateClouds(Cloud clouds[], int count)
{
    for(int i = 0; i < count; i++)
    {
        clouds[i].x -= clouds[i].speed;

        if(clouds[i].x < -1.6f)
        {
            clouds[i].x = 1.6f;
            clouds[i].y = 0.6f + (rand() % 30) / 100.0f;
        }
    }
}

void initClouds(Cloud clouds[], int count)
{
    for(int i = 0; i < count; i++)
    {
        clouds[i].x = -1.0f + i * 0.8f;
        clouds[i].y = 0.6f + (rand() % 20) / 100.0f;
        clouds[i].speed = 0.0005f + (rand() % 3) * 0.0003f;
    }
}



