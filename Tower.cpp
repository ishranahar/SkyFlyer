#include "Tower.h"
#include "Polygon.h"

Tower::Tower(float x, float y, float width, float height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Tower::draw() {

    Polygon mainBody(x, y, width, height, 0.65f, 0.1f, 0.1f);
    mainBody.draw();

    int numTopBlocks = 5;
    float blockWidth = width / 9.0f;
    float blockHeight = 0.06f;

    for (int i = 0; i < numTopBlocks; i++) {
        float blockX = x + i * 2 * blockWidth;
        Polygon topBlock(blockX, y + height, blockWidth, blockHeight, 0.75f, 0.1f, 0.1f);
        topBlock.draw();
    }

    int numWindows = 1;

    if (height > 0.35f && height <= 0.55f) {
        numWindows = 2;
    } else if (height > 0.55f) {
        numWindows = 3;
    }

    float windowWidth = width * 0.25f;
    float windowHeight = width * 0.4f;
    float windowX = x + width * 0.1f;

    float verticalGap = height / (numWindows + 1);

    for (int i = 1; i <= numWindows; i++) {
        float windowY = y + i * verticalGap - (windowHeight / 2.0f);
        Polygon window(windowX, windowY, windowWidth, windowHeight, 0.2f, 0.05f, 0.05f);
        window.draw();
    }
}

