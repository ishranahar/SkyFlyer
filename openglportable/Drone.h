#ifndef DRONE_H
#define DRONE_H

class Drone
{
public:
    float x, y;
    float scale;

    Drone();
    Drone(float x, float y, float scale);

    void update();
    void draw();
};

#endif
