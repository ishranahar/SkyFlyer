#include <GL/glut.h>
#include "sky.h"
#include "Cloud.h"
#include "Drone.h"


#define CLOUD_COUNT 4
#define DRONE_COUNT 3


Cloud clouds[CLOUD_COUNT];
Drone drones[DRONE_COUNT];

// DISPLAY
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);


    drawSky();
    drawSun();


    drawClouds(clouds, CLOUD_COUNT);


    for(int i = 0; i < DRONE_COUNT; i++)
        drones[i].draw();

    glutSwapBuffers();
}

//  UPDATE
void update()
{
    updateSky();
    updateClouds(clouds, CLOUD_COUNT);

    for(int i = 0; i < DRONE_COUNT; i++)
        drones[i].update();
}

//  TIMER
void timer(int)
{
    update();
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

//  INIT
void init()
{
    glClearColor(0.0f, 0.0f, 0.1f, 1.0f);

    // Sky
    initSky();

    // Clouds
    initClouds(clouds, CLOUD_COUNT);

    // Drones
    drones[0] = Drone(1.2f,  0.3f, 0.35f);
    drones[1] = Drone(1.8f, -0.1f, 0.35f);
    drones[2] = Drone(2.4f,  0.1f, 0.35f);
}

//  MAIN
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





