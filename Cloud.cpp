#include <GL/glut.h>
#include <cmath>

class Circle
{
public:
    float radius;
    float x, y;

    Circle() : radius(0.1f), x(0.0f), y(0.0f) {}

    Circle(float r, float x, float y)
    {
        this->radius = r;
        this->x = x;
        this->y = y;
    }

    // Draw this circle
    void draw()
    {
        int segments = 100;
        glBegin(GL_POLYGON);
        for (int i = 0; i <= segments; i++)
        {
            float angle = 2 * M_PI * i / segments;
            glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
        }
        glEnd();
    }
};

class Cloud
{
public:
    Circle parts[10];
    int count;

    Cloud() : count(0) {}

    void addPart(Circle c)
    {
        if (count < 10)
            parts[count++] = c;
    }

    void draw()
    {
        for (int i = 0; i < count; i++)
        {
            parts[i].draw();
        }
    }
};
