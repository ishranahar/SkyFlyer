#include <GL/glut.h>
#include <cstdio>
#include <cstdlib>

#include "Bird.h"
#include "Drone.h"
#include "Tower.h"
#include "Flower.h"
#include "Grass.h"
#include "GameState.h"
#include "sky.h"
#include "Cloud.h"

#define CLOUD_COUNT 4
#define DRONE_COUNT 3
#define TOWER_COUNT 3
#define FLOWER_COUNT 6
#define GRASS_COUNT 40

Bird bird;
Drone drones[DRONE_COUNT];
Cloud clouds[CLOUD_COUNT];

Tower towers[TOWER_COUNT] =
{
    Tower(-0.7f, -0.6f, 0.2f, 0.3f),
    Tower(-0.1f, -0.6f, 0.2f, 0.5f),
    Tower( 0.5f, -0.6f, 0.2f, 0.7f)
};

Flower flowers[FLOWER_COUNT] =
{
    Flower(-0.8f, -0.6f, 1,0,0),
    Flower(-0.5f, -0.6f, 1,0.5f,0),
    Flower(-0.2f, -0.6f, 1,1,0),
    Flower( 0.1f, -0.6f, 0,0.8f,1),
    Flower( 0.4f, -0.6f, 0.6f,0.2f,1),
    Flower( 0.7f, -0.6f, 1,0.2f,0.6f)
};

Grass grasses[GRASS_COUNT];

bool collision(float ax,float ay,float aw,float ah,
               float bx,float by,float bw,float bh)
{
    return !(ax + aw < bx || ax > bx + bw ||
             ay + ah < by || ay > by + bh);
}

void drawText(float x, float y, const char* text)
{
    glColor3f(1,1,1);
    glRasterPos2f(x, y);
    while (*text)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text++);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawSky();
    drawSun();
    drawClouds(clouds, CLOUD_COUNT);

    for (int i = 0; i < GRASS_COUNT; i++)
        grasses[i].draw();

    for (int i = 0; i < FLOWER_COUNT; i++)
        flowers[i].draw();

    for (int i = 0; i < TOWER_COUNT; i++)
        towers[i].draw();

    bird.draw();

    for(int i = 0; i < DRONE_COUNT; i++)
        drones[i].draw();

    char buf[80];
    sprintf(buf, "Score: %d   Level: %d", score, level);
    drawText(-0.95f, 0.9f, buf);

    if (paused)
        drawText(-0.1f, 0.0f, "PAUSED");

    if (gameOver)
        drawText(-0.35f, 0.0f, "GAME OVER - Press R");

    glutSwapBuffers();
}

void update()
{
    updateSky();
    updateClouds(clouds, CLOUD_COUNT);

    if (!paused && !gameOver)
    {
        bird.update();

        for(int i = 0; i < TOWER_COUNT; i++)
            towers[i].update();

        for(int i = 0; i < DRONE_COUNT; i++)
            drones[i].update();

        for (int i = 0; i < FLOWER_COUNT; i++)
            flowers[i].update();

        for (int i = 0; i < GRASS_COUNT; i++)
            grasses[i].update();

        score++;
        level = score / 400 + 1;
        GAME_SPEED = 0.002f + level * 0.0006f;

        for (int i = 0; i < TOWER_COUNT; i++)
        {
            if (collision(
                bird.x, bird.y, 0.12f, 0.12f,
                towers[i].x, towers[i].y,
                towers[i].w, towers[i].h))
            {
                gameOver = true;
            }
        }

        for(int i = 0; i < DRONE_COUNT; i++)
        {
            if (collision(
                bird.x, bird.y, 0.12f, 0.12f,
                drones[i].x, drones[i].y,
                0.25f, 0.12f))
            {
                gameOver = true;
            }
        }
    }
}

void timer(int)
{
    update();
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void keyboard(unsigned char key, int, int)
{
    switch(key)
    {
        case 'p': paused = !paused; break;
        case 'r': resetGame(); break;
        case 'u': bird.velocityY = 0.015f; break;
        case 'd': bird.velocityY = -0.015f; break;
        case 27: exit(0);
    }
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.05f, 1.0f);

    initSky();
    initClouds(clouds, CLOUD_COUNT);

    drones[0] = Drone(1.2f,  0.3f, 0.35f);
    drones[1] = Drone(1.8f, -0.1f, 0.35f);
    drones[2] = Drone(2.4f,  0.1f, 0.35f);

    float gx = -1.0f;
    for (int i = 0; i < GRASS_COUNT; i++)
    {
        grasses[i] = Grass(gx, -0.7f, 0.04f + (i % 5) * 0.01f);
        gx += 0.05f;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("SkyFlyer");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
