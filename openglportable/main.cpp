#include <GL/glut.h>
#include "Cloud.h"

float coord_x = 0.0f;
float coord_y = 0.0f;

Cloud clouds[3];

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(coord_x, coord_y, 0.0f);
    drawClouds(clouds, 3);

    glutSwapBuffers();
}

void KeyboardInput(unsigned char key, int x, int y)
{
    if (key == 'l')
        coord_x += 0.05f;
    if (key == 'r')
        coord_x -= 0.05f;

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(2050, 1200);
    glutCreateWindow("SkyFlyer - OpenGL OOP Project");

    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glutDisplayFunc(display);
    glutKeyboardFunc(KeyboardInput);

    clouds[0].x = -0.6f; clouds[0].y = 0.6f; clouds[0].speed = 0.0f;
    clouds[1].x = -0.05f; clouds[1].y = 0.8f; clouds[1].speed = 0.0f;
    clouds[2].x =  0.6f; clouds[2].y = 0.5f; clouds[2].speed = 0.0f;

    glutMainLoop();
    return 0;
}




/*#include <GL/glut.h>
#include "Triangle.h"
#include "Polygon.h"
#include "drawLine.h"
#include "drawdrone.h"
#include "airline.h"
#include "bird.h"

Airline airplane;
Bird bird1(0.0f, 0.0f, 1.0f);


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    airplane.draw();
    bird1.draw();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(2050, 1200);
    glutCreateWindow("SkyFlyer - OpenGL OOP Project ");

    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}





/*#include <GL/glut.h>
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
    glutInitWindowSize(2050, 1200);
    glutCreateWindow("OpenGL Project (Merged)");

    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}*/

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
