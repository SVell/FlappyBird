#include "Player.h"

void Player::HandleEvents(SDL_Event event) {
    GameObject::HandleEvents(event);

    switch(event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    SetVelocity(Vector2(velocity.x, jumpStrength));
                    break;
            }
        default:
            break;
    }

    if(abs(velocity.y) >= maxVelocity){
        velocity.y = velocity.y > 0 ? maxVelocity : -maxVelocity;
    }
}

void Player::Update() {
    GameObject::Update();

    AddVelocity(Vector2(0, gravityStrength));
}

