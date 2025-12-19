#include <GL/glut.h>

// Old headers
#include "Triangle.h"
#include "Polygon.h"
#include "drawLine.h"
#include "drawdrone.h"

// New OOP header
#include "airline.h"

// OOP Object
Airline airplane;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // ===== Old drawings (keep commented if not used) =====
    // drawTriangle();
    // drawLine();
    // drawPolygon();
    // drawDrone();

    // ===== New OOP Airplane =====
    airplane.draw();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Project (Merged)");

    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
