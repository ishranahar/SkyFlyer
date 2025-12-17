#include <GL/glut.h>
#include "Polygon.h"

void drawPolygon() {
    glBegin(GL_POLYGON);
        glVertex2f(-0.3f, 0.3f);
        glVertex2f(-0.6f, -0.3f);
        glVertex2f(0.0f, -0.6f);
        glVertex2f(0.3f, -0.3f);
    glEnd();
}

