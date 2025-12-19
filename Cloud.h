#ifndef CLOUD_H
#define CLOUD_H

class Circle
{
public:
    float radius;
    float x, y;

    Circle();
    Circle(float r, float x, float y);

    void draw();
};

class Cloud
{
public:
    Circle parts[10];
    int count;

    Cloud();
    void addPart(Circle c);
    void draw();
};

#endif

