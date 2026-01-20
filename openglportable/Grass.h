#ifndef GRASS_H
#define GRASS_H

class Grass
{
public:
    float y;
    float height;
    float offset;

    Grass(float yPos = -0.9f);
    void update();
    void draw();
};

#endif
