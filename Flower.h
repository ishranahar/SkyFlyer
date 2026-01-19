#ifndef FLOWER_H
#define FLOWER_H

class Flower
{
public:
    float x, y;
    float r, g, b;
    float sway;

    Flower();
    Flower(float x, float y, float r, float g, float b);

    void update();
    void draw();
};

#endif

