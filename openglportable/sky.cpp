#include "sky.h"
#include <GL/glut.h>
#include <cmath>

float sunX = -1.2f;
float dayFactor = 0.0f;

void drawSky()
{

    float r = 0.08f + 0.35f * dayFactor;
    float g = 0.15f + 0.45f * dayFactor;
    float b = 0.25f + 0.55f * dayFactor;

    glBegin(GL_QUADS);
        glColor3f(r, g, b);
        glVertex2f(-1,  1);
        glVertex2f( 1,  1);

        glColor3f(0.02f, 0.02f, 0.12f);
        glVertex2f( 1, -1);
        glVertex2f(-1, -1);
    glEnd();
}

void drawSun()
{
    if(dayFactor < 0.05f) return;

    glColor3f(1.0f, 1.0f, 0.0f);

    glBegin(GL_POLYGON);
    for(int i = 0; i < 100; i++)
    {
        float a = 2 * 3.1416f * i / 100;
        glVertex2f(sunX + 0.1f * cos(a),0.6f + 0.1f * sin(a));
    }
    glEnd();
}

void updateSky()
{
    sunX += 0.0012f;

    if(sunX > 1.3f)
        sunX = -1.3f;


    float normalized = (sunX + 1.3f) / 2.6f;


    dayFactor = sin(normalized * 3.1416f);

    if(dayFactor < 0.0f)
        dayFactor = 0.0f;
}

void initSky()
{
    glClearColor(0.0f, 0.0f, 0.05f, 1.0f);
}

