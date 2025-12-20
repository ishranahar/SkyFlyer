
#ifndef BIRD_H
#define BIRD_H

class Bird {
private:
    float x, y;
    float scale;

public:
    Bird(float xPos = 0.0f, float yPos = 0.0f, float s = 1.0f);
    void draw();
};

#endif
