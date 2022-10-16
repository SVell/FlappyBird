#include <cmath>
#include "Bird.h"
#include "Game.h"

Bird::Bird(const char *path, int x, int y) : Sprite(path, x, y, WIDTH, HEIGHT) {
    velocityX = 0;
    velocityY = 0;
}

void Bird::Update() {
    velocityY += Game::GRAVITY;

    if(velocityY > Game::GRAVITY){
        velocityY = Game::GRAVITY;
    }

    float delta = 1.f / 60;
    MoveSprite(std::round(velocityX * delta), std::round(velocityY * delta));
}

void Bird::Render() {
    Draw();
}


void Bird::SetXVelocity(int x) {

}

void Bird::SetYVelocity(int y) {
    velocityY = y;
}




