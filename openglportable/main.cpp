#include <GL/glut.h>
#include <math.h>



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();




    glBegin(GL_POLYGON);
        glVertex2f(-0.05, 0.05);
        glVertex2f(0.05, 0.05);
        glVertex2f(0.05, -0.05);
        glVertex2f(-0.05, -0.05);
    glEnd();

    glFlush();
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL ");
    glutDisplayFunc(display);


    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutMainLoop();
    return 0;
}
