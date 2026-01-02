#ifndef SKY_H
#define SKY_H

#include <GL/glut.h>

extern float timeOfDay;
extern float sunX;

void drawSky();
void drawSun();
void updateSky();   // sky animation only
void initSky();

#endif
