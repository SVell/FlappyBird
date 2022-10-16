#include "Sprite.h"
#include "Game.h"

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}

Sprite::Sprite(const char* path, int xPos, int yPos, int width, int height) : x(xPos), y(yPos), w(width), h(height){
    texture = TextureManager::LoadTexture(path);

    srcRect.x = srcRect.y = 0;
    srcRect.w = width;
    srcRect.h = height;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = width;
    destRect.h = height;
}

void Sprite::Draw(){
    TextureManager::Draw(texture, srcRect, destRect);
}

void Sprite::SetPosition(int newX, int newY){
    x = newX;
    y = newY;

    destRect.x = x;
    destRect.y = y;
}

void Sprite::MoveSprite(int xPos, int yPos){
    if(x + w <= Game::SCREEN_WIDTH && x > 0){
        x += xPos;
    }

    if(y + h + yPos <= Game::SCREEN_HEIGHT && y + yPos > 0){
        y += yPos;
    }

    destRect.x = x;
    destRect.y = y;
}