#include <iostream>
#include "Game.h"

SDL_Renderer* Game::renderer = nullptr;

bool Game::isRunning = false;

Game::Game() {

}

Game::~Game() {

}

void Game::Init(const char *windowTitle, const int xPos, const int yPos, const int width, const int height, bool fullscreen) {

    int flags = 0;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVENTS) != 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return;
    }
    else{
        window = SDL_CreateWindow(windowTitle, xPos, yPos, width, height, flags);

        if(window == nullptr){
            SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            return;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer == nullptr){
            SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
            return;
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        isRunning = true;
    }

    SDL_Log("Game Initialized!");

    player = new Bird("../Assets/BirdUp.png", 100, 100);
}

void Game::HandleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE){
                isRunning = false;
            }
        default:
            break;
    }
}

void Game::Update() {
    player->Update();
}

void Game::Render() {
    SDL_RenderClear(renderer);

    player->Render();

    SDL_RenderPresent(renderer);
}

void Game::Clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game Cleaned" << std::endl;
}
