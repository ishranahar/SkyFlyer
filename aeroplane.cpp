
#include "airline.h"
#include <GL/glut.h>
#include <cstdlib>
#include <cmath>

Airline::Airline() {
    x = 1.6f;
    y = 0.6f + (rand() % 6) * 0.09f;

    speedX = 0.0028f + (rand() % 5) * 0.0004f;
}

void Airline::update() {
    x -= speedX;


    if (x < -1.8f) {
        x = 1.6f;
        y = 0.45f + (rand() % 6) * 0.09f;
        speedX = 0.0028f + (rand() % 5) * 0.0004f;
    }
}

void Airline::draw() {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    glScalef(-0.28f, 0.28f, 1.0f);

    /*auto FilledCircle = [&](float cx, float cy, float r, int segments) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= segments; ++i) {
            float angle = 2.0f * 3.14159f * static_cast<float>(i) / segments;
            glVertex2f(cx + r * cosf(angle), cy + r * sinf(angle));
        }
        glEnd();
    };*/


    glColor3f(247.0f/255.0f, 2.0f/255.0f, 1.0f/255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.68f, -0.75f);
    glVertex2f(-0.78f, -0.55f);
    glVertex2f(-0.84f, -0.55f);
    glVertex2f(-0.80f, -0.75f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8315f, -0.60f);
    glVertex2f(-0.8275f, -0.62f);
    glVertex2f(-0.755f, -0.64f);
    glVertex2f(-0.765f, -0.62f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.8215f, -0.64f);
    glVertex2f(-0.8175f, -0.66f);
    glVertex2f(-0.735f, -0.68f);
    glVertex2f(-0.745f, -0.66f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.55f, -0.89f);
    glVertex2f(0.0f, -0.89f);
    glVertex2f(0.07f, -0.875f);
    glVertex2f(0.07f, -0.835f);
    glVertex2f(0.03f, -0.82f);
    glVertex2f(-0.085f, -0.75f);
    glVertex2f(-0.20f, -0.73f);
    glVertex2f(-0.75f, -0.73f);
    glVertex2f(-0.90f, -0.75f);
    glVertex2f(-0.90f, -0.79f);
    glVertex2f(-0.80f, -0.83f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.90f, -0.75f);
    glVertex2f(-0.93f, -0.755f);
    glVertex2f(-0.93f, -0.785f);
    glVertex2f(-0.90f, -0.79f);
    glEnd();

    glColor3f(247.0f/255.0f, 2.0f/255.0f, 1.0f/255.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.07f, -0.835f);
    glVertex2f(0.07f, -0.875f);
    glVertex2f(0.10f, -0.86f);
    glVertex2f(0.10f, -0.85f);
    glEnd();

    glColor3f(247.0f/255.0f, 2.0f/255.0f, 1.0f/255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.73f, -0.79f);
    glVertex2f(-0.75f, -0.785f);
    glVertex2f(-0.84f, -0.785f);
    glVertex2f(-0.93f, -0.81f);
    glVertex2f(-0.87f, -0.815f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.15f, -0.77f);
    glVertex2f(-0.15f, -0.81f);
    glVertex2f(0.015f, -0.81f);
    glVertex2f(-0.05f, -0.77f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.085f, -0.77f);
    glVertex2f(-0.06f, -0.81f);
    glVertex2f(-0.05f, -0.81f);
    glVertex2f(-0.075f, -0.77f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
   // FilledCircle(-0.46f, -0.923f, 0.025f, 360);

    glColor3f(1.0f, 1.0f, 1.0f);
   // FilledCircle(-0.46f, -0.923f, 0.01f, 360);

    glColor3f(223.0f/255.0f, 227.0f/255.0f, 239.0f/255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.54f, -0.85f);
    glVertex2f(-0.54f, -0.90f);
    glVertex2f(-0.49f, -0.91f);
    glVertex2f(-0.44f, -0.91f);
    glVertex2f(-0.44f, -0.85f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.44f, -0.91f);
    glVertex2f(-0.44f, -0.85f);
    glVertex2f(-0.43f, -0.85f);
    glVertex2f(-0.43f, -0.91f);
    glEnd();

    glColor3f(247.0f/255.0f, 2.0f/255.0f, 1.0f/255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.28f, -0.84f);
    glVertex2f(-0.33f, -0.83f);
    glVertex2f(-0.50f, -0.84f);
    glVertex2f(-0.70f, -0.90f);
    glVertex2f(-0.60f, -0.893f);
    glVertex2f(-0.57f, -0.90f);
    glEnd();

    glColor3f(130.0f/255.0f, 44.0f/255.0f, 39.0f/255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.70f, -0.90f);
    glVertex2f(-0.60f, -0.893f);
    glVertex2f(-0.57f, -0.90f);
    glVertex2f(-0.63f, -0.907f);
    glEnd();

    glColor3f(80.0f/255.0f, 196.0f/255.0f, 245.0f/255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.18f, -0.775f);
    glVertex2f(-0.23f, -0.775f);
    glVertex2f(-0.23f, -0.835f);
    glVertex2f(-0.18f, -0.835f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.185f, -0.78f);
    glVertex2f(-0.225f, -0.78f);
    glVertex2f(-0.225f, -0.83f);
    glVertex2f(-0.185f, -0.83f);
    glEnd();

    float diff = 0.45f;
    glColor3f(80.0f/255.0f, 196.0f/255.0f, 245.0f/255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.18f - diff, -0.775f);
    glVertex2f(-0.23f - diff, -0.775f);
    glVertex2f(-0.23f - diff, -0.835f);
    glVertex2f(-0.18f - diff, -0.835f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.185f - diff, -0.78f);
    glVertex2f(-0.225f - diff, -0.78f);
    glVertex2f(-0.225f - diff, -0.83f);
    glVertex2f(-0.185f - diff, -0.83f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    float x1 = -0.265f, y1 = -0.783f;
    float dist = 0.025f;
    while (x1 - 2 * dist > -0.63f) {
        glBegin(GL_POLYGON);
        glVertex2f(x1, y1);
        glVertex2f(x1 - dist, y1);
        glVertex2f(x1 - dist, y1 - dist);
        glVertex2f(x1, y1 - dist);
        glEnd();
        x1 -= 2 * dist;
    }

    glColor3f(90.0f/255.0f, 110.0f/255.0f, 117.0f/255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.10f, -0.89f);
    glVertex2f(-0.12f, -0.89f);
    glVertex2f(-0.12f, -0.92f);
    glVertex2f(-0.10f, -0.92f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
  //  FilledCircle(-0.11f, -0.925f, 0.02f, 360);

    glColor3f(1.0f, 1.0f, 1.0f);
   // FilledCircle(-0.11f, -0.925f, 0.008f, 360);

    glPopMatrix();
}
