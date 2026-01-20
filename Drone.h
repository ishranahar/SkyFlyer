#ifndef DRONE_H
#define DRONE_H

class Drone
{
public:
    float x, y, scale;

    Drone(float x=1.2f, float y=0.3f, float s=0.4f);
    void update();
    void draw();
};

#endif
