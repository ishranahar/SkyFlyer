
#include "bird.h"
#include <GL/glut.h>
#include <cmath>

Bird::Bird(float xPos, float yPos, float s) {
    x = xPos;
    y = yPos;
    scale = s;
}

void Bird::draw() {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    int segments = 100;

    //body
    float bodyR = 0.25f;
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= segments; i++) {
        float a = 2 * M_PI * i / segments;
        glVertex2f(bodyR * cos(a), bodyR * sin(a));
    }
    glEnd();

    // outer eye
    float eyeR = 0.09f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= segments; i++) {
        float a = 2 * M_PI * i / segments;
        glVertex2f(eyeR * cos(a) + 0.08f, eyeR * sin(a) + 0.08f);
    }
    glEnd();

    // inner ye
    float pupilR = 0.07f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= segments; i++) {
        float a = 2 * M_PI * i / segments;
        glVertex2f(pupilR * cos(a) + 0.095f, pupilR * sin(a) + 0.08f);
    }
    glEnd();

    //Beak
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.20f,  0.02f);
        glVertex2f(0.35f,  0.00f);
        glVertex2f(0.20f, -0.03f);
    glEnd();

    //w2ings
    glColor3f(1.0f, 0.8f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.05f,  0.00f);
        glVertex2f(-0.25f, -0.05f);
        glVertex2f(-0.05f, -0.15f);
    glEnd();

    glPopMatrix();
}
