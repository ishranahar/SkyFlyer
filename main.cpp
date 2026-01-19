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
#define GRASS_COUNT 200

Grass grasses[GRASS_COUNT];


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
    if (!paused && !gameOver)
    {
        bird.update();

        // Update towers, drones, flowers, grass
        for(int i = 0; i < TOWER_COUNT; i++) towers[i].update();
        for(int i = 0; i < DRONE_COUNT; i++) drones[i].update();
        for(int i = 0; i < FLOWER_COUNT; i++) flowers[i].update();
        for(int i = 0; i < GRASS_COUNT; i++) grasses[i].update();

        // score, level, game speed
        score++;
        level = score / 400 + 1;
        GAME_SPEED = 0.002f + level * 0.0006f;

        // ---------------- Collision with Towers ----------------
        float birdWidth  = 0.12f * bird.scale;
        float birdHeight = 0.12f * bird.scale;
        float birdLeft   = bird.x - birdWidth / 2;
        float birdBottom = bird.y - birdHeight / 2;

        for (int i = 0; i < TOWER_COUNT; i++)
        {
            float towerWidth  = towers[i].w;
            float towerHeight = towers[i].h * 1.5f; // scaled in draw()
            float towerLeft   = towers[i].x;
            float towerBottom = towers[i].y;

            if (collision(birdLeft, birdBottom, birdWidth, birdHeight,
                          towerLeft, towerBottom, towerWidth, towerHeight))
            {
                gameOver = true;
            }
        }

        // ---------------- Collision with Drones ----------------
        for (int i = 0; i < DRONE_COUNT; i++)
        {
            float droneWidth  = 0.25f * drones[i].scale;
            float droneHeight = 0.12f * drones[i].scale;
            float droneLeft   = drones[i].x;
            float droneBottom = drones[i].y;

            if (collision(birdLeft, birdBottom, birdWidth, birdHeight,
                          droneLeft, droneBottom, droneWidth, droneHeight))
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
        float randomHeight = 0.06f + (rand() % 3) * 0.01f;
        grasses[i] = Grass(gx, -0.7f, randomHeight);
        gx += 0.01f; // narrow spacing → no gap
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
