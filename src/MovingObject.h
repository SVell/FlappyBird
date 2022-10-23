#pragma once

#include "GameObject.h"

class MovingObject : public GameObject {
public:
    MovingObject(const char* path, int xPos, int yPos, int sWidth, int sHeight, bool flip, int speed);

    void Update() override;
    void Render() override;

private:
    bool flipY;
};
