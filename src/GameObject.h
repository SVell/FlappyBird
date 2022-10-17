#pragma once

#include <memory>

#include "SDL.h"
#include "Vector2.h"

class GameObject {
protected:
    Vector2 position;
    Vector2 velocity;

    int width, height;

    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
public:
    GameObject() = default;
    GameObject(const char* path, int xPos, int yPos, int width = 32, int height = 32);
    ~GameObject();

    virtual void Update();
    virtual void Render();
    virtual void HandleEvents(SDL_Event event);
    virtual void Move();

    void SetPosition(const Vector2& newPos);
    void SetVelocity(const Vector2& newVelocity);
    void AddVelocity(const Vector2& velocityToAdd);
};
