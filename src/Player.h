#pragma once

#include "GameObject.h"

class Player : public GameObject{
public:
    const int gravityStrength = 10;
    const int maxVelocity = gravityStrength * 100;

    const int jumpStrength = -300;

    bool isDead = false;

    Player(const char* path, int xPos, int yPos, int sWidth, int sHeight) : GameObject(path, xPos, yPos, sWidth, sHeight){};

    void Update() override;
    void HandleEvents(SDL_Event event) override;
};
