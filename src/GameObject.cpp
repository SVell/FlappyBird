#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"


GameObject::GameObject(const char* path, int xPos, int yPos, int sWidth, int sHeight) : width(sWidth), height(sHeight) {
    texture = TextureManager::LoadTexture(path);

    position.x = xPos;
    position.y = yPos;

    srcRect.x = srcRect.y = 0;
    srcRect.w = width;
    srcRect.h = height;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = width;
    destRect.h = height;
}

void GameObject::Update() {
    int vX = velocity.x / 60;
    int vY = velocity.y / 60;

    if(position.x + width + vX <= Game::SCREEN_WIDTH && position.x + vY > 0){
        position.x += vX;
        destRect.x += vX;
    }

    if(position.y + height + vY <= Game::SCREEN_HEIGHT && position.y + vY > 0){
        position.y += vY;
        destRect.y += vY;
    }
}

void GameObject::Render() {
    TextureManager::Draw(texture, srcRect, destRect);
}

GameObject::~GameObject() {
    SDL_DestroyTexture(texture);
}

void GameObject::SetPosition(const Vector2& newPos) {
    position = newPos;

    destRect.x = position.x;
    destRect.y = position.y;
}

void GameObject::SetVelocity(const Vector2& newVelocity) {
    velocity = newVelocity;
}

void GameObject::AddVelocity(const Vector2& velocityToAdd) {
    velocity += velocityToAdd;
}

void GameObject::HandleEvents(SDL_Event event) {

}

void GameObject::Move() {

}






