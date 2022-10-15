#pragma once

#include "SDL.h"

class Bird {
public:
    Bird(const char* texture);
    void Update();
    void Render();
private:
    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
};

