#ifndef BIRD_H
#define BIRD_H

class Bird
{
public:
    float x, y;
    float velocityY;
    float scale;
    float speedX;
    float wingAngle;

    Bird(float xPos = -0.5f, float yPos = 0.0f);

    void update();
    void draw();
};

#endif


