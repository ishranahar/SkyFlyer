#include "interaction.h"
#include "bird.h"
#include "sound.h"   
#include <GL/glut.h>
#include <stdlib.h>

extern Bird birds[];
extern bool isPaused;
extern void init();

void handleKeys(unsigned char key, int x, int y) {
    switch (key) {
        case 'p':
        case 'P':
            playSound("select.wav"); 
            isPaused = !isPaused;
            break;
        case 'r':
        case 'R':
            playSound("select.wav"); 
            init();
            isPaused = false;
            break;
        case 27:
            exit(0);
            break;
    }
}

void handleSpecialKeys(int key, int x, int y) {
    if (isPaused) return;

    float speed = 0.05f;

    switch (key) {
        case GLUT_KEY_UP:
            birds[0].move(speed);
            playSound("flap.wav"); 
            break;
        case GLUT_KEY_DOWN:
            birds[0].move(-speed);
            playSound("flap.wav");
            break;
        case GLUT_KEY_RIGHT:
            birds[0].moveHorizontal(speed);
            playSound("flap.wav");
            break;
        case GLUT_KEY_LEFT:
            birds[0].moveHorizontal(-speed);
            playSound("flap.wav");
            break;
    }
}
