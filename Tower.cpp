
#include "Tower.h"
#include "GameState.h"
#include <GL/glut.h>
#include <cstdlib>
#include <cmath>

// ---------------- HELPER FUNCTIONS ----------------
void FilledCircle(float cx, float cy, float r, int n) {
    glBegin(GL_TRIANGLE_FAN);
    for(int i=0;i<=n;i++){
        float a = 2*3.1416f*i/n;
        glVertex2f(cx + r*cos(a), cy + r*sin(a));
    }
    glEnd();
}

void windowBack(){
    glBegin(GL_QUADS);
    glVertex2f(-1.72,-0.38);
    glVertex2f(-1.72,-0.43);
    glVertex2f(-1.60,-0.43);
    glVertex2f(-1.60,-0.38);
    glEnd();
}

void window(){
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-1.72,-0.38);
    glVertex2f(-1.72,-0.43);
    glVertex2f(-1.60,-0.43);
    glVertex2f(-1.60,-0.38);
    glEnd();
}

void Origin(){ glLoadIdentity(); }

// ---------------- DEMO BUILDING ----------------
void demoBuilding(){
    glBegin(GL_POLYGON);
        glVertex2f(-1.79,0.3);
        glVertex2f(-1.79,-0.62);
        glVertex2f(-1.4,-0.62);
        glVertex2f(-1.4,0.3);
        glVertex2f(-1.595,0.35);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-1.595,0.35);
        glVertex2f(-1.39,0.29);
        glVertex2f(-1.39,0.3);
        glVertex2f(-1.595,0.36);
        glVertex2f(-1.80,0.3);
        glVertex2f(-1.80,0.29);
    glEnd();

    FilledCircle(-1.595,0.3,0.03,100);

    for(int i=0;i<5;i++){
        for(int j=0;j<2;j++){
            glBegin(GL_QUADS);
            glVertex2f(-1.72,-.43);
            glVertex2f(-1.72,-.44);
            glVertex2f(-1.60,-.44);
            glVertex2f(-1.60,-.43);
            glEnd();
            windowBack();
            window();
            glTranslatef(.17,0,0);
        }
        glTranslatef(-.34,.15,0);
    }
    Origin();
}

// ---------------- TOWER CLASS ----------------
Tower::Tower(float x,float y,float w,float h){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void Tower::update(){
    x -= GAME_SPEED;

    if (x + w < -1.2f){
        x = 1.2f;  // smooth reposition to right
    }
}

void Tower::draw(){
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(w, h, 1.0f);  // scale width/height
    glColor3f(1.0f, 0.5f, 0.0f); // tower color
    demoBuilding();
    glPopMatrix();
}
