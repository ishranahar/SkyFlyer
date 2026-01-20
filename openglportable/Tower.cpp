#include "Tower.h"
#include "GameState.h"
#include <GL/glut.h>
#include <cstdlib>
#include <cmath>

Tower::Tower(float xPos, float groundY, float width, float height)
{
    x = xPos;
    y = groundY;   // Bottom of the tower
    w = width;
    h = height;
}

void Tower::update()
{
    x -= GAME_SPEED;

    if(x + w < -1.3f)
    {
        x = 1.3f + (rand() % 50) / 100.0f;
    }
}

void Tower::draw()
{
    // Color Palette: Deep Red/Brown for the structure
    float r = 0.6f, g = 0.1f, b = 0.1f;
    // Lighter shade for highlights/accents
    float r2 = 0.8f, g2 = 0.4f, b2 = 0.3f;

    float centerX = x + w / 2.0f;

    // --- 1. Base Section (Wide Trapezoid) ---
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(x, y);                   // Bottom Left
        glVertex2f(x + w, y);               // Bottom Right
        glVertex2f(x + w * 0.75f, y + h * 0.3f); // Top Right
        glVertex2f(x + w * 0.25f, y + h * 0.3f); // Top Left
    glEnd();

    // --- 2. Base Arch (Cutting into the Base) ---
    // We draw this in a background-like color or a lighter accent to simulate the arch
    glColor3f(r2, g2, b2);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 180; i++) {
        float angle = i * 3.14159f / 180.0f;
        float archW = w * 0.35f;
        float archH = h * 0.15f;
        glVertex2f(centerX + cos(angle) * archW, y + sin(angle) * archH);
    }
    glEnd();

    // --- 3. Middle Section ---
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(x + w * 0.28f, y + h * 0.3f);
        glVertex2f(x + w * 0.72f, y + h * 0.3f);
        glVertex2f(x + w * 0.62f, y + h * 0.6f);
        glVertex2f(x + w * 0.38f, y + h * 0.6f);
    glEnd();

    // --- 4. Top Section (Narrowing to Top) ---
    glBegin(GL_QUADS);
        glVertex2f(x + w * 0.42f, y + h * 0.6f);
        glVertex2f(x + w * 0.58f, y + h * 0.6f);
        glVertex2f(centerX + w * 0.05f, y + h * 0.9f);
        glVertex2f(centerX - w * 0.05f, y + h * 0.9f);
    glEnd();

    // --- 5. Tip & Antenna ---
    // The "Dome" top
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 30) {
        float rad = i * 3.14159f / 180.0f;
        glVertex2f(centerX + cos(rad) * (w * 0.08f), (y + h * 0.92f) + sin(rad) * (h * 0.03f));
    }
    glEnd();

    // The Antenna needle
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(centerX, y + h * 0.95f);
        glVertex2f(centerX, y + h * 1.0f);
    glEnd();

    // --- 6. Horizontal Balconies (Detail Lines) ---
    glColor3f(0.3f, 0.05f, 0.05f); // Darker color for lines
    glBegin(GL_LINES);
        // First Balcony
        glVertex2f(x + w * 0.25f, y + h * 0.3f);
        glVertex2f(x + w * 0.75f, y + h * 0.3f);
        // Second Balcony
        glVertex2f(x + w * 0.38f, y + h * 0.6f);
        glVertex2f(x + w * 0.62f, y + h * 0.6f);
    glEnd();
}

