#include <GL/glut.h>
#include <cmath>
#include "drawdrone.h"


void drawCircle(float cx, float cy, float r)
{
    int segments = 100;

    glBegin(GL_POLYGON);
    for (int i = 0; i <= segments; i++)
    {
        float a = 2 * M_PI * i / segments;
        float x = r * cos(a);
        float y = r * sin(a);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}


void drawDrone()
{
   //Body

    // Top Body


     glColor3f(0.35, 0.7, 0.8);
    glBegin(GL_POLYGON);
      glVertex2f(-0.12,  0.15);
       glVertex2f( 0.12,  0.15);
       glVertex2f( 0.18,  0.05);
      glVertex2f(-0.18,  0.05);
     glEnd();




//Front Body

glColor3f(0.15, 0.35, 0.5);
glBegin(GL_POLYGON);
    glVertex2f(-0.18,  0.05);
    glVertex2f( 0.18,  0.05);
    glVertex2f( 0.15, -0.10);
    glVertex2f(-0.15, -0.10);
glEnd();




    // Arms

    glLineWidth(6);
    glColor3f(0.1, 0.2, 0.3);

    glBegin(GL_LINES);
        glVertex2f(-0.15, 0.0);
        glVertex2f(-0.35, 0.15);
        glVertex2f( 0.15, 0.0);
        glVertex2f( 0.35, 0.15);
        glVertex2f(-0.15, 0.0);
        glVertex2f(-0.35,-0.05);
        glVertex2f( 0.15, 0.0);
        glVertex2f( 0.35,-0.05);
    glEnd();


    // Circles Of Arms

    glColor3f(0.2, 0.4, 0.5);
    drawCircle(-0.35,  0.15, 0.06);
    drawCircle( 0.35,  0.15, 0.06);
    drawCircle(-0.35, -0.05, 0.06);
    drawCircle( 0.35, -0.05, 0.06);





    // Landing Legs

    glLineWidth(4);
    glBegin(GL_LINES);
        glVertex2f(-0.15, -0.10);
        glVertex2f(-0.20, -0.15);
        glVertex2f( 0.15, -0.10);
        glVertex2f( 0.20, -0.15);
    glEnd();
}
