#ifndef CLOUD_H
#define CLOUD_H

struct Cloud
{
    float x;
    float y;
    float speed;
};

void drawCloud(float x, float y);
void drawClouds(Cloud clouds[], int count);

#endif

