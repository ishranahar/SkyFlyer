#include <GL/glut.h>
#include "Triangle.h"

void drawTriangle() {
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.6f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.6f, -0.6f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.6f, -0.6f);
    glEnd();
}


