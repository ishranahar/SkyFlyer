#ifndef TOWER_H
#define TOWER_H

class Tower
{
public:
    float x, y, w, h;

    Tower(float x, float y, float w, float h);

    void update();
    void draw();
};

#endif
