#include <GL/glut.h>


#include "Triangle.h"
#include "Polygon.h"
#include "drawLine.h"

#include "Drone.h"

#define DRONE_COUNT 40
Drone drones[DRONE_COUNT];


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);


    // drawTriangle();
    // drawLine();
    // drawPolygon();
    // drawDrone();


    for (int i = 0; i < DRONE_COUNT; i++)
    {
        drones[i].draw();
    }

    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);


    glutInitWindowSize(800, 800);
    glutCreateWindow("CG Project ");


    glClearColor(1.0f, 0.8f, 0.2f, 1.0f);


    for (int i = 0; i < DRONE_COUNT; i++)
    {
        float x = -0.9f + (i % 8) * 0.25f;
        float y =  0.7f - (i / 8) * 0.25f;
        drones[i] = Drone(x, y, 0.35f);
    }

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

