#include <GL/glut.h>
#include "Tower.h"

#define TOWER_COUNT 3

Tower towers[TOWER_COUNT];

float birdY = 0.0f;
float velocity = 0.0f;
float gravity = -0.0008f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 0);
    glBegin(GL_QUADS);
        glVertex2f(-0.3f, birdY);
        glVertex2f(-0.25f, birdY);
        glVertex2f(-0.25f, birdY + 0.05f);
        glVertex2f(-0.3f, birdY + 0.05f);
    glEnd();

    for (int i = 0; i < TOWER_COUNT; i++)
        towers[i].draw();

    glutSwapBuffers();
}

void update(int)
{
    velocity += gravity;
    birdY += velocity;

    for (int i = 0; i < TOWER_COUNT; i++)
        towers[i].update();

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void keyboard(unsigned char key, int, int)
{
    if (key == ' ')
        velocity = 0.015f;
}

void init()
{
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);

    towers[0] = Tower(0.5f, -1.0f, 0.1f, 0.6f);
    towers[1] = Tower(1.0f, -1.0f, 0.1f, 0.7f);
    towers[2] = Tower(1.5f, -1.0f, 0.1f, 0.5f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("SkyFlyer");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}


