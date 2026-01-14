#include "Drone.h"
#include "background.h"
#include <GL/glut.h>
#include <cmath>


static void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 100; i++)
    {
        float a = 2 * 3.1416f * i / 100;
        glVertex2f(cx + r * cos(a),
                   cy + r * sin(a));
    }
    glEnd();
}

Drone::Drone()
{
    x = 1.3f;
    y = 0.25f;
    scale = 0.5f;
}

Drone::Drone(float x, float y, float scale)
{
    this->x = x;
    this->y = y;
    this->scale = scale;
}

void Drone::update()
{

    x -= GAME_SPEED * 50;

    if(x < -1.5f)
    {
        x = 1.5f;
        y = 0.2f + ((rand() % 40) / 100.0f);
    }
}

void Drone::draw()
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1);

   //Body
    glColor3f(0.3f, 0.6f, 0.85f);
    glBegin(GL_QUADS);
        glVertex2f(-0.18f,  0.06f);
        glVertex2f( 0.18f,  0.06f);
        glVertex2f( 0.15f, -0.08f);
        glVertex2f(-0.15f, -0.08f);
    glEnd();

    // Arms
    glLineWidth(4);
    glColor3f(0.15f, 0.25f, 0.35f);
    glBegin(GL_LINES);
        glVertex2f(-0.15f, 0.02f);
        glVertex2f(-0.35f, 0.12f);

        glVertex2f( 0.15f, 0.02f);
        glVertex2f( 0.35f, 0.12f);
    glEnd();

    // Rotors
    glColor3f(0.2f, 0.4f, 0.6f);
    drawCircle(-0.35f, 0.12f, 0.06f);
    drawCircle( 0.35f, 0.12f, 0.06f);

    glPopMatrix();
}



