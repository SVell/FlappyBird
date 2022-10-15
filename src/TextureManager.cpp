#include "TextureManager.h"
#include "Game.h"

SDL_Texture* TextureManager::LoadTexture(const char *path) {

    SDL_Surface* surface = IMG_Load(path);
    SDL_Log("Image could not be loaded due to errors: %s\n", SDL_GetError());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}

void TextureManager::Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}
