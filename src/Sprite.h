#pragma once

#include "SDL.h"
#include "TextureManager.h"

class Sprite {
public:
    Sprite() = default;

    ~Sprite(){
        SDL_DestroyTexture(texture);
    }

    Sprite(const char* path, int xPos = 0, int yPos = 0, int width = 32, int height = 32) : x(xPos), y(yPos), w(width), h(height){
        texture = TextureManager::LoadTexture(path);

        srcRect.x = srcRect.y = 0;
        srcRect.w = width;
        srcRect.h = height;

        destRect.x = xPos;
        destRect.y = yPos;
        destRect.w = width;
        destRect.h = height;
    }

    void Draw(){
        TextureManager::Draw(texture, srcRect, destRect);
    }

    void MoveSprite(int newX, int newY){
        x = newX;
        y = newY;

        destRect.x = x;
        destRect.y = y;
    }

protected:
    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;

    int x, y, w, h = 0;
};
