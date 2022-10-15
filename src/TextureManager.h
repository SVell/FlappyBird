#pragma once

#include "SDL_image.h"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* path);
    static void Draw(SDL_Texture* texture, SDL_Rect src,SDL_Rect dest);
};

