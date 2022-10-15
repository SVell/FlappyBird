#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;

Game* game = nullptr;

int main(int argc, char* args[]) {
    game = new Game();

    game->Init("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

    while (game->IsRunning()){
        game->HandleEvents();
        game->Update();
        game->Render();
    }

    game->Clean();
    delete game;

    return 0;
}
