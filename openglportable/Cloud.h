#ifndef CLOUD_H
#define CLOUD_H

struct Cloud
{
    float x;
    float y;
    float speed;
};

void initClouds(Cloud clouds[], int count);
void updateClouds(Cloud clouds[], int count);
void drawCloud(float x, float y);
void drawClouds(Cloud clouds[], int count);

#endif


