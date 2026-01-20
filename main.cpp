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

#include "Airline.h"
Airline plane;
#define CLOUD_COUNT 4
#define DRONE_COUNT 5

const float GRASS_Y = -1.0f;
const float GRASS_HEIGHT = 0.15f;
const float GROUND_Y = GRASS_Y + GRASS_HEIGHT;


Bird bird;
Drone drones[DRONE_COUNT];
Cloud clouds[CLOUD_COUNT];

Grass grass(GRASS_Y);


Tower tower1(-0.85f, GROUND_Y, 0.18f, 0.35f);
Tower tower2(-0.35f, GROUND_Y, 0.20f, 0.50f);
Tower tower3( 0.20f, GROUND_Y, 0.18f, 0.45f);
Tower tower4( 0.70f, GROUND_Y, 0.20f, 0.60f);


Flower flower1(-0.95f, GROUND_Y);
Flower flower2(-0.55f, GROUND_Y);
Flower flower3(-0.05f, GROUND_Y);
Flower flower4( 0.45f, GROUND_Y);
Flower flower5( 0.85f, GROUND_Y);

bool birdOnGround = false;


bool collision(float ax,float ay,float aw,float ah,
               float bx,float by,float bw,float bh)
{
    return !(ax + aw < bx || ax > bx + bw ||
             ay + ah < by || ay > by + bh);
}


void drawText(float x, float y, const char* text)
{
    glColor3f(1,0,0);
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
  plane.draw();
    grass.draw();

    flower1.draw();
    flower2.draw();
    flower3.draw();
    flower4.draw();
    flower5.draw();

    tower1.draw();
    tower2.draw();
    tower3.draw();
    tower4.draw();

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
    plane.update();
    updateSky();
    updateClouds(clouds, CLOUD_COUNT);

    if (!paused && !gameOver)
    {
        bird.update();
        grass.update();

        tower1.update();
        tower2.update();
        tower3.update();
        tower4.update();

        for(int i = 0; i < DRONE_COUNT; i++)
            drones[i].update();


        float birdHalfH = 0.12f * bird.scale;

        if (bird.y - birdHalfH <= GROUND_Y)
        {
            birdOnGround = true;
            bird.velocityY = 0;
            bird.y = GROUND_Y + birdHalfH;
        }
        else
        {
            birdOnGround = false;
        }


        if (!birdOnGround)
            score++;

        level = score / 400 + 1;
        GAME_SPEED = 0.002f + level * 0.0006f;


        /*
        if (
            collision(bird.x,bird.y,0.12f,0.12f, tower1.x,tower1.y,tower1.w,tower1.h) ||
            collision(bird.x,bird.y,0.12f,0.12f, tower2.x,tower2.y,tower2.w,tower2.h) ||
            collision(bird.x,bird.y,0.12f,0.12f, tower3.x,tower3.y,tower3.w,tower3.h) ||
            collision(bird.x,bird.y,0.12f,0.12f, tower4.x,tower4.y,tower4.w,tower4.h)
           )
        {
            gameOver = true;
        }
        */


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
        case 32: bird.velocityY = 0.015f; break;
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
