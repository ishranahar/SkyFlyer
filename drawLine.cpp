#include <GL/glut.h>
#include "drawLine.h"

void drawLine() {
    glLineWidth(3.0f);

    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.8f, 0.0f);
        glVertex2f(0.8f, 0.0f);
    glEnd();
}

