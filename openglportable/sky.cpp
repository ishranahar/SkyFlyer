#include "sky.h"
#include <cmath>

float timeOfDay = 0.0f;
float sunX = -1.2f;

void drawSky()
{
    float r, g, b;

    r = 0.2f + 0.5f * sin(timeOfDay * 3.1416f);
    g = 0.4f + 0.5f * sin(timeOfDay * 3.1416f);
    b = 0.6f + 0.5f * sin(timeOfDay * 3.1416f);

    glBegin(GL_QUADS);
        glColor3f(r, g, b);
        glVertex2f(-1,  1);
        glVertex2f( 1,  1);

        glColor3f(0.0f, 0.0f, 0.2f);
        glVertex2f( 1, -1);
        glVertex2f(-1, -1);
    glEnd();
}

void drawSun()
{
    glColor3f(1, 1, 0);

    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float a = 2 * 3.1416f * i / 100;
        glVertex2f(sunX + 0.1f * cos(a),
                   0.6f + 0.1f * sin(a));
    }
    glEnd();
}

void updateSky()
{
    timeOfDay += 0.001f;
    if (timeOfDay > 1.0f) timeOfDay = 0.0f;

    sunX += 0.001f;
    if (sunX > 1.2f) sunX = -1.2f;
}

void initSky()
{
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
}
