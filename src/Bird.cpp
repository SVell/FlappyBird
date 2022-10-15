#include "Bird.h"
#include "TextureManager.h"

Bird::Bird(const char *path) {
    texture = TextureManager::LoadTexture(path);

    srcRect.x = srcRect.y = 0;
    srcRect.w = 34;
    srcRect.h = 24;
}

void Bird::Update() {
    // Logic
    destRect.x = 100;
    destRect.y = 100;
    destRect.w = 32;
    destRect.h = 24;
}

void Bird::Render() {
    TextureManager::Draw(texture, srcRect, destRect);
}
