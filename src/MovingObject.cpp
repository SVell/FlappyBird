#include "MovingObject.h"
#include "TextureManager.h"

MovingObject::MovingObject(const char* path, int xPos, int yPos, int sWidth, int sHeight, bool flip, int speed)
        : GameObject(path, xPos, yPos, sWidth, sHeight), flipY(flip){
    velocity.x = speed;
}

void MovingObject::Update() {
    int vX = velocity.x / 60;
    int vY = velocity.y / 60;

    position.x += vX;
    destRect.x += vX;
}

void MovingObject::Render() {
    if(flipY)
    {
        TextureManager::DrawFlipped(texture, srcRect, destRect, SDL_FLIP_VERTICAL);
    }
    else{
        GameObject::Render();
    }
}


