#include <GL/glut.h>
#include <cmath>

class Circle {
public:
    float radius;
    float centerX, centerY;
    float red, green, blue;

    Circle(float r = 0.1f, float x = 0.0f, float y = 0.0f,
           float red = 1.0f, float green = 1.0f, float blue = 1.0f) {
        radius = r;
        centerX = x;
        centerY = y;
        this->red = red;
        this->green = green;
        this->blue = blue;
    }

    void draw(int segments = 100) {
        glColor3f(red, green, blue);
        glBegin(GL_POLYGON);
        float pi = 3.1415;
        for (int i = 0; i <= segments; ++i) {
            float angle = 2 * pi * i / segments;
            float x = radius * cos(angle);
            float y = radius * sin(angle);
            glVertex2f(x + centerX, y + centerY);
        }
        glEnd();
    }
};

class Cloud {
public:
    Circle cloudParts[10];
    int count = 0;

    void addPart(const Circle& c) {
        if (count < 10) {
            cloudParts[count++] = c;
        }
    }

    void draw() {
        for (int i = 0; i < count; ++i) {
            cloudParts[i].draw();
        }
    }
};

Cloud cloud;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    cloud.draw();

    glFlush();
}


int main(int argc, char** argv) {
    cloud.addPart(Circle(0.25f, -0.3f, 0.0f));
    cloud.addPart(Circle(0.30f, -0.05f, 0.1f));
    cloud.addPart(Circle(0.25f, 0.25f, 0.0f));
    cloud.addPart(Circle(0.35f, 0.05f, -0.05f));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Cloud ");

    glClearColor(0.4f, 0.7f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
