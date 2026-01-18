#ifndef GRASS_H
#define GRASS_H

class Grass
{
public:
    float x, y, h;
    float sway;

    Grass();
    Grass(float x, float y, float h);

    void update();
    void draw();
};

#endif

