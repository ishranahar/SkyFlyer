#include <GL/glut.h>
#include <math.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1.0f, 1.0f, 1.0f);
    float pi = 3.1415f;
    int segments = 100;

    float r = 0.25f;
    float cx = -0.3f, cy = 0.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i <= segments; i++)
    {
        float a = 2 * pi * i / segments;
        float x = r * cos(a);
        float y = r * sin(a);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();

    r = 0.30f;
    cx = -0.05f; cy = 0.1f;
    glBegin(GL_POLYGON);
    for (int i = 0; i <= segments; i++)
    {
        float a = 2 * pi * i / segments;
        float x = r * cos(a);
        float y = r * sin(a);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();

    r = 0.25f;
    cx = 0.25f; cy = 0.0f;
    glBegin(GL_POLYGON);
    for (int i = 0; i <= segments; i++)
    {
        float a = 2 * pi * i / segments;
        float x = r * cos(a);
        float y = r * sin(a);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();

    r = 0.35f;
    cx = 0.05f; cy = -0.05f;
    glBegin(GL_POLYGON);
    for (int i = 0; i <= segments; i++)
    {
        float a = 2 * pi * i / segments;
        float x = r * cos(a);
        float y = r * sin(a);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cloud Without Extra Function");

    glClearColor(0.4f, 0.7f, 1.0f, 1.0f);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
