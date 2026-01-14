#include <GL/glut.h>
#include "sky.h"
#include "Drone.h"

#define DRONE_COUNT 3
Drone drones[DRONE_COUNT];


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);


    drawSky();
    drawSun();


    for(int i = 0; i < DRONE_COUNT; i++)
        drones[i].draw();

    glutSwapBuffers();
}

//  Update
void update()
{
    updateSky();

    for(int i = 0; i < DRONE_COUNT; i++)
        drones[i].update();

}

// Timer  Function
void timer(int)
{
    update();
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

// Init Game
void init()
{
    glClearColor(0.6f, 0.8f, 1.0f, 1.0f);

    initSky();

    drones[0] = Drone(1.2f,  0.3f, 0.35f);
    drones[1] = Drone(1.8f, -0.1f, 0.35f);
    drones[2] = Drone(2.4f,  0.1f, 0.35f);
}

//  Main Function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("SkyFlyer");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}


