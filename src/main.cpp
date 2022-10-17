#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"

const int FPS = 60;
constexpr int frameDelay = 1000 / FPS;

Game* game = nullptr;

int main(int argc, char* args[]) {

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->Init("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, false);

    while (game->IsRunning()){
        frameStart = SDL_GetTicks();

        game->HandleEvents();
        game->Update();
        game->Render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay >= frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->Clean();
    delete game;

    return 0;
}
