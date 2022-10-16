#pragma once

#include "SDL.h"
#include "TextureManager.h"


class Sprite {
public:
    Sprite() = default;

    ~Sprite();

    Sprite(const char* path, int xPos = 0, int yPos = 0, int width = 32, int height = 32);

    void Draw();

    void SetPosition(int newX, int newY);

    void MoveSprite(int xPos, int yPos);

protected:
    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;

    int x, y, w, h = 0;
};
