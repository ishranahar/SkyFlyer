/*#include <GL/glut.h>
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
#include <GL/glut.h>
#include "sky.h"
#include "Cloud.h"
enum GameState {
    RUNNING,
    PAUSED
};

GameState gameState = RUNNING;

// Global variables
float coord_x = 0.0f;
float coord_y = 0.0f;

Cloud clouds[3];

// ---------- DISPLAY (ONLY HERE) ----------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawSky();
    drawSun();

    glTranslatef(coord_x, coord_y, 0.0f);
    drawClouds(clouds, 3);

    glutSwapBuffers();
}

// ---------- Keyboard ----------
/*void KeyboardInput(unsigned char key, int, int)
{
    if (key == 'l') coord_x += 0.05f;
    if (key == 'r') coord_x -= 0.05f;

    glutPostRedisplay();
}
*/
void KeyboardInput(unsigned char key, int, int)
{
    // MOVE CLOUD (already have)
    if (key == 'l') coord_x += 0.05f;
    if (key == 'r') coord_x -= 0.05f;

    // -------- PAUSE --------
    if (key == 'p' || key == 'P')
    {
        gameState = PAUSED;
    }

    // -------- RESUME --------
    if (key == 'c' || key == 'C')
    {
        gameState = RUNNING;
    }

    // -------- RESTART --------
    if (key == 'R' || key == 'r')
    {
        gameState = RUNNING;

        // reset sky
        timeOfDay = 0.0f;
        sunX = -1.2f;

        // reset clouds
        clouds[0] = {-0.6f, 0.6f, 0.0005f};
        clouds[1] = {-0.05f, 0.8f, 0.0007f};
        clouds[2] = { 0.6f, 0.5f, 0.0006f};
    }

    glutPostRedisplay();
}

// ---------- Update ----------
/*void update()
{
    updateSky();

    for (int i = 0; i < 3; i++) {
        clouds[i].x += clouds[i].speed;
        if (clouds[i].x > 1.4f)
            clouds[i].x = -1.4f;
    }

    glutPostRedisplay();
}
*/
void update()
{
    if (gameState == RUNNING)
    {
        updateSky();

        for (int i = 0; i < 3; i++) {
            clouds[i].x += clouds[i].speed;
            if (clouds[i].x > 1.4f)
                clouds[i].x = -1.4f;
        }
    }

    glutPostRedisplay();
}

// ---------- Init ----------
void initScene()
{
    initSky();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);

    clouds[0] = {-0.6f, 0.6f, 0.0005f};
    clouds[1] = {-0.05f, 0.8f, 0.0007f};
    clouds[2] = { 0.6f, 0.5f, 0.0006f};
}

// ---------- MAIN ----------
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("SkyFlyer - Final Merged Version");

    initScene();

    glutDisplayFunc(display);
    glutIdleFunc(update);
    glutKeyboardFunc(KeyboardInput);

    glutMainLoop();
    return 0;
}
