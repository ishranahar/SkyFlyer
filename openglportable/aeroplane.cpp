
#include "airline.h"
#include <math.h>

Airline::Airline() {}

void Airline::draw() {
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0.969f, 0.008f, 0.004f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.68, -0.75);
    glVertex2f(-0.78, -0.55);
    glVertex2f(-0.84, -0.55);
    glVertex2f(-0.80, -0.75);
    glEnd();


    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8315, -0.60);
    glVertex2f(-0.8275, -0.62);
    glVertex2f(-0.755, -0.64);
    glVertex2f(-0.765, -0.62);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.8215, -0.64);
    glVertex2f(-0.8175, -0.66);
    glVertex2f(-0.735, -0.68);
    glVertex2f(-0.745, -0.66);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-0.55, -0.89);
    glVertex2f(0.0, -0.89);
    glVertex2f(0.07, -0.875);
    glVertex2f(0.07, -0.835);
    glVertex2f(0.03, -0.82);
    glVertex2f(-0.085, -0.75);
    glVertex2f(-0.20, -0.73);
    glVertex2f(-0.75, -0.73);
    glVertex2f(-0.90, -0.75);
    glVertex2f(-0.90, -0.79);
    glVertex2f(-0.80, -0.83);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.90, -0.75);
    glVertex2f(-0.93, -0.755);
    glVertex2f(-0.93, -0.785);
    glVertex2f(-0.90, -0.79);
    glEnd();


    glColor3f(0.969f, 0.008f, 0.004f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.28, -0.84);
    glVertex2f(-0.33, -0.83);
    glVertex2f(-0.50, -0.84);
    glVertex2f(-0.70, -0.90);
    glVertex2f(-0.60, -0.893);
    glVertex2f(-0.57, -0.90);
    glEnd();


    glColor3f(0.353f, 0.431f, 0.459f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.10, -0.89);
    glVertex2f(-0.12, -0.89);
    glVertex2f(-0.12, -0.92);
    glVertex2f(-0.10, -0.92);
    glEnd();

    glFlush();
}
