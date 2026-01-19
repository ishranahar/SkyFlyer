#ifndef POLYGON_H
#define POLYGON_H

class Polygon
{
public:
    float x, y, w, h;
    float r, g, b;

    Polygon(float x, float y, float w, float h,
            float r, float g, float b);

    void draw();
};

#endif


