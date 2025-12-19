#include <GL/glut.h>
#include <cmath>


class Drone
{
public:
    float x, y;
    float scale;

    Drone() {}

    Drone(float x, float y, float scale)
    {
        this->x = x;
        this->y = y;
        this->scale = scale;
    }

//Draw Circle
static void drawCircle(float cx, float cy, float r)
{
    int segments = 100;
    glBegin(GL_POLYGON);
    for (int i = segments; i >= 0; i--)
    {
        float a = 2 * M_PI * i / segments;
        glVertex2f(cx + r * cos(a), cy + r * sin(a));
    }
    glEnd();
}


    // Draw Drone
   void draw()
{
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glScalef(scale, scale, 1.0);

    // Body Top
    glColor3f(0.35, 0.7, 0.8);
    glBegin(GL_POLYGON);
        glVertex2f(-0.12,  0.15);
        glVertex2f( 0.12,  0.15);
        glVertex2f( 0.18,  0.05);
        glVertex2f(-0.18,  0.05);
    glEnd();

    // Body Bottom
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

    glPopMatrix();
}

};

