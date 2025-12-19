#ifndef DRONE_H
#define DRONE_H

class Drone
{
public:
    float x, y, scale;

    Drone();
    Drone(float x, float y, float s);

    void draw();
};

#endif

