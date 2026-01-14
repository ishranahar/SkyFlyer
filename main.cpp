#include <GL/glut.h>
#include "background.h"
#include "Tower.h"

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawBackground();


    Tower t1(-0.7f, -0.6f, 0.2f, 0.25f);
    Tower t2(-0.1f, -0.6f, 0.2f, 0.4f);
    Tower t3(0.5f, -0.6f, 0.2f, 0.8f);

    t1.draw();
    t2.draw();
    t3.draw();

    glutSwapBuffers();
}

void update()
{
    updateBackground();
}


void timer(int value)
{
    update();
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void init()
{
    initScene();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

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
/*#include <GL/glut.h>
#include "sky.h"
#include "Cloud.h"
#include "Drone.h"
#include "bird.h"

#define CLOUD_COUNT 4
#define DRONE_COUNT 3
#define BIRD_COUNT 1

Cloud clouds[CLOUD_COUNT];
Drone drones[DRONE_COUNT];
Bird birds[BIRD_COUNT];

// DISPLAY
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawSky();
    drawSun();

    drawClouds(clouds, CLOUD_COUNT);

    for (int i = 0; i < DRONE_COUNT; i++)
        drones[i].draw();

    for (int i = 0; i < BIRD_COUNT; i++)
        birds[i].draw();

    glutSwapBuffers();
}

// UPDATE
void update()
{
    updateSky();
    updateClouds(clouds, CLOUD_COUNT);

    for (int i = 0; i < DRONE_COUNT; i++)
        drones[i].update();

    for (int i = 0; i < BIRD_COUNT; i++)
        birds[i].update();
}

// TIMER
void timer(int)
{
    update();
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

// INIT
void init()
{
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);

    initSky();
    initClouds(clouds, CLOUD_COUNT);

    drones[0] = Drone(1.2f,  0.3f, 0.35f);
    drones[1] = Drone(1.8f, -0.1f, 0.35f);
    drones[2] = Drone(2.4f,  0.1f, 0.35f);

    birds[0] = Bird(-0.4f, 0.3f, 0.6f);
    birds[1] = Bird( 0.2f, 0.45f, 0.5f);
}

// MAIN
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
}*/

