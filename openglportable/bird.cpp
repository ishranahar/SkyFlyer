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
    wingAngle = 0.0f;
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
    // Calculate wing flap angle based on time
    // 0.01f controls the speed, 25.0f controls the range of the flap
    float time = glutGet(GLUT_ELAPSED_TIME) * 0.01f;
    wingAngle = sin(time) * 25.0f;

    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale * 0.6f, scale * 0.6f, 1);

    // --- Tail ---
    glColor3f(0.65f, 0.65f, 0.55f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.12f, 0.0f);
        glVertex2f(-0.22f, 0.05f);
        glVertex2f(-0.20f, -0.05f);
    glEnd();

    // --- Body ---
    glColor3f(0.75f, 0.75f, 0.65f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++)
    {
        float a = 2 * 3.1416f * i / 100;
        float rx = (cos(a) > 0) ? 0.15f : 0.12f;
        glVertex2f(rx * cos(a), 0.10f * sin(a));
    }
    glEnd();

    // --- Animated Wing ---
    glPushMatrix();
        // Move rotation point to where the wing attaches to the body
        glTranslatef(-0.05f, 0.0f, 0.0f);
        glRotatef(wingAngle, 1, 0, 0); // Rotate around X-axis for a flapping effect
        glTranslatef(0.05f, 0.0f, 0.0f); // Move back

        glColor3f(0.55f, 0.55f, 0.45f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.05f, 0.0f);   // Wing Base
            glVertex2f(0.02f, 0.18f);   // Wing Tip
            glVertex2f(-0.08f, 0.22f);
            glVertex2f(-0.12f, 0.10f);
        glEnd();
    glPopMatrix();

    // --- Eye ---
    glColor3f(0.2f, 0.1f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 30; i++)
    {
        float a = 2 * 3.1416f * i / 30;
        glVertex2f(0.012f * cos(a) + 0.08f, 0.04f + 0.012f * sin(a));
    }
    glEnd();

    // --- Beak ---
    glColor3f(1.0f, 0.9f, 0.2f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.14f, 0.03f);
        glVertex2f(0.20f, 0.00f);
        glVertex2f(0.14f, -0.02f);
    glEnd();

    glPopMatrix();
}
