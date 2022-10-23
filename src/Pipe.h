#pragma once

#include "GameObject.h"

class Pipe : public GameObject {
public:
    Pipe(const char* path, int xPos, int yPos, int sWidth, int sHeight, bool flip, int speed);

    void Update() override;
    void Render() override;

private:
    bool flipY;
};
