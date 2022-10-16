#pragma once

#include "Sprite.h"

class Bird : public Sprite {
public:
    Bird(const char* texture, int x, int y);
    void Update();
    void Render();

    void SetXVelocity(int x);
    void SetYVelocity(int y);
private:
    static const uint16_t WIDTH = 32;
    static const uint16_t HEIGHT = 24;

    int velocityX, velocityY = 0;
};

