#include "Drone.h"
#include <GL/glut.h>
#include "GameState.h"
#include <cmath>

Drone::Drone(float x, float y, float s)
{
    this->x = x;
    this->y = y;
    scale = s;
}

void Drone::update()
{
    x -= GAME_SPEED;

    if (x < -1.6f)
    {
        x = 1.6f + (rand() % 100) / 100.0f;
        y = -0.4f + (rand() % 80) / 100.0f;
    }
}

void Drone::draw()
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1);


    float darkGrey[3] = {0.2f, 0.22f, 0.25f};
    float midGrey[3] = {0.35f, 0.38f, 0.42f};
    float yellow[3] = {1.0f, 0.8f, 0.0f};


    glColor3fv(midGrey);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.25f, 0.15f);  glVertex2f(0.25f, -0.15f);
        glVertex2f(0.25f, 0.15f);   glVertex2f(-0.25f, -0.15f);
    glEnd();


    glColor3fv(darkGrey);
    glBegin(GL_POLYGON);
        glVertex2f(-0.15f, 0.08f);
        glVertex2f(0.12f, 0.08f);
        glVertex2f(0.18f, 0.02f);
        glVertex2f(0.15f, -0.06f);
        glVertex2f(-0.12f, -0.06f);
        glVertex2f(-0.18f, 0.02f);
    glEnd();


    glColor3f(0.45f, 0.48f, 0.52f);
    glBegin(GL_QUADS);
        glVertex2f(-0.10f, 0.05f);
        glVertex2f(0.08f, 0.05f);
        glVertex2f(0.06f, 0.02f);
        glVertex2f(-0.08f, 0.02f);
    glEnd();


    glColor3f(0.1f, 0.1f, 0.1f);

    glBegin(GL_POLYGON);
    for(int i=0; i<20; i++){
        float a = i * 2.0f * 3.14159f / 20;
        glVertex2f(0.04f * cos(a) - 0.05f, 0.04f * sin(a) - 0.08f);
    }
    glEnd();


    float rotorSpeed = glutGet(GLUT_ELAPSED_TIME) * 0.8f;
    float rotorOffsets[4][2] = {
        {-0.25f, 0.15f}, {0.25f, 0.15f},
        {-0.25f, -0.15f}, {0.25f, -0.15f}
    };

    for (int i = 0; i < 4; ++i)
    {
        glPushMatrix();
        glTranslatef(rotorOffsets[i][0], rotorOffsets[i][1], 0);


        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_POLYGON);
        for(int j=0; j<10; j++){
            float a = j * 2.0f * 3.14159f / 10;
            glVertex2f(0.025f * cos(a), 0.025f * sin(a));
        }
        glEnd();


        glRotatef(rotorSpeed + (i * 90), 0, 0, 1);
        glColor3f(0.1f, 0.1f, 0.1f);


        glBegin(GL_QUADS);

            glVertex2f(-0.12f, 0.015f); glVertex2f(0.12f, 0.015f);
            glVertex2f(0.12f, -0.015f); glVertex2f(-0.12f, -0.015f);
        glEnd();


        glColor3fv(yellow);
        glBegin(GL_POINTS);
            glVertex2f(0.11f, 0.0f);
            glVertex2f(-0.11f, 0.0f);
        glEnd();

        glPopMatrix();
    }

    glPopMatrix();
}
