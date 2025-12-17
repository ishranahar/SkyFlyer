#include <GL/glut.h>
#include "Triangle.h"
#include "Polygon.h"
#include"drawLine.h"

void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    drawTriangle();
  drawLine();

    glColor3f(1.0f, 1.0f, 0.0f);
    drawPolygon();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Triangle + Polygon");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

