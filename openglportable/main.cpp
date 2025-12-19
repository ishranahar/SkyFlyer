#include <GL/glut.h>
#include "Triangle.h"
#include "Polygon.h"
#include "drawLine.h"
#include "drawdrone.h"
#include "airline.h"

Airline airplane;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

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

//copy from github
/*
#include <GL/glut.h>
#include "Triangle.h"
#include "Polygon.h"
#include"drawLine.h"
#include"drawdrone.h"

void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    //drawTriangle();
  //drawLine();

    glColor3f(1.0f, 1.0f, 0.0f);
    //drawPolygon();
    drawDrone();

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
*/
