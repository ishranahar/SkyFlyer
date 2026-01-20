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

    // --- 1. Stem ---
    // The stem in the image is curved and thick
    glColor3f(0.0f, 0.8f, 0.0f); // Bright green
    glLineWidth(4.0f);
    glBegin(GL_LINE_STRIP);
    for (float i = 0; i <= 0.12f; i += 0.01f) {
        // Adding a slight curve using sin
        glVertex2f(0.01f * sin(i * 20.0f), i);
    }
    glEnd();

    // --- 2. Leaves ---
    // Drawing two teardrop-shaped leaves
    glColor3f(0.0f, 0.9f, 0.0f);

    // Left Leaf
    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.04f);
        glVertex2f(-0.06f, 0.08f);
        glVertex2f(-0.08f, 0.04f);
        glVertex2f(-0.04f, 0.02f);
    glEnd();

    // Right Leaf
    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.06f);
        glVertex2f(0.06f, 0.10f);
        glVertex2f(0.08f, 0.06f);
        glVertex2f(0.04f, 0.04f);
    glEnd();

    // --- 3. Petals ---
    // Bright pink petals, larger and more rounded
    glColor3f(1.0f, 0.2f, 0.6f);
    float petalRadius = 0.03f;

    for(int p = 0; p < 5; p++)
    {
        float a = p * (2 * 3.1416f / 5);
        glBegin(GL_POLYGON);
        for(int i = 0; i <= 360; i += 10)
        {
            float ang = i * 3.1416f / 180.0f;
            // Petals are slightly elongated (0.06f vs 0.05f) to look like the image
            glVertex2f(
                0.045f * cos(a) + petalRadius * cos(ang),
                0.12f + 0.045f * sin(a) + (petalRadius + 0.01f) * sin(ang)
            );
        }
        glEnd();
    }

    // --- 4. Center ---
    // Bright yellow center
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
