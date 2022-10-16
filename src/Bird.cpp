#include "Bird.h"
#include "TextureManager.h"

Bird::Bird(const char *path, int x, int y) : Sprite(path, x, y, WIDTH, HEIGHT) {
}

void Bird::Update() {
    // MoveSprite(x++, y);
}

void Bird::Render() {
    Draw();
}
