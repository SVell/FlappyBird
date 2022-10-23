#include <iostream>
#include <random>
#include "Game.h"
#include "Player.h"
#include "MovingObject.h"
#include "Collision.h"

const int Game::SCREEN_WIDTH = 288;
const int Game::SCREEN_HEIGHT = 624;

SDL_Renderer* Game::renderer = nullptr;

bool Game::isRunning = false;

Game::Game() = default;

Game::~Game() = default;

void Game::Init(const char *windowTitle, const int xPos, const int yPos, bool fullscreen) {

    int flags = 0;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVENTS) != 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return;
    }
    else{
        window = SDL_CreateWindow(windowTitle, xPos, yPos, SCREEN_WIDTH, SCREEN_HEIGHT, flags);

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

    player = new Player("../Assets/BirdUp.png", SCREEN_WIDTH / 2 - 16, SCREEN_HEIGHT / 2 - 12, 32, 24);
    CreateEnv();
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
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    isRunning = false;
                    break;
                case SDLK_SPACE:
                    break;
            }
        default:
            break;
    }

    player->HandleEvents(event);
}

void Game::Update() {
    player->Update();

    bg->Update();

    for(auto obj: pipes) {
        obj->Update();

        if(obj->GetPosition().x + obj->GetRect().w < 0) {
            int randomPosX = GenerateRandomNumber(-10, 50);

            Vector2 newPos;
            newPos.x = SCREEN_WIDTH / 1.5f * (pipes.size() / 2);
            newPos.y = obj->GetPosition().y;
            obj->SetPosition(newPos);
        }
    }

    for(auto f : floor){
        f->Update();

        if(f->GetPosition().x + f->GetRect().w < 0){
            Vector2 newPos;
            newPos.x = f->GetRect().w - 4;
            newPos.y = f->GetPosition().y;
            f->SetPosition(newPos);
        }
    }

    return;
    // Handle collision
    for (auto obj : pipes){
        bool res = Collision::AABB(player->GetRect(), obj->GetRect());
        if (res) {
            player->SetVelocity(Vector2(0, 400));
            for (auto obj : pipes){
                obj->SetVelocity(Vector2(0, 0));
            }
        }
    }
}

void Game::Render() {
    SDL_RenderClear(renderer);

    bg->Render();

    for (auto obj : pipes){
        obj->Render();
    }

    for (auto f : floor){
        f->Render();
    }

    player->Render();

    SDL_RenderPresent(renderer);
}

void Game::Clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    delete player;

    for (auto obj : pipes){
        delete obj;
    }

    std::cout << "Game Cleaned" << std::endl;
}

void Game::CreateEnv(int pipesPairsToCreate) {

    bg = new GameObject("../Assets/BG.png", 0 ,0, SCREEN_WIDTH, SCREEN_HEIGHT);

    floor.emplace_back(new MovingObject("../Assets/base.png", 0, SCREEN_HEIGHT - 112, 336, 112, false, -200));
    floor.emplace_back(new MovingObject("../Assets/base.png", 336, SCREEN_HEIGHT - 112, 336, 112, false, -200));

    for(int i = 0; i < pipesPairsToCreate; ++i){
        int randomPosX = GenerateRandomNumber(-10, 50);
        int randomPosY = GenerateRandomNumber(-50, 50);
        SDL_Log("%d", randomPosX);

        pipes.emplace_back(new MovingObject("../Assets/pipe.png",
                                      SCREEN_WIDTH + SCREEN_WIDTH / 1.5f * i + randomPosX,
                                      SCREEN_HEIGHT / 3 - 320 - 56 + randomPosY,
                                            52,
                                            320,
                                            true,
                                            -200));
        pipes.emplace_back(new MovingObject("../Assets/pipe.png",
                                      SCREEN_WIDTH + SCREEN_WIDTH / 1.5f * i + randomPosX,
                                      SCREEN_HEIGHT / 3 * 2 - 56 + randomPosY,
                                            52,
                                            320,
                                            false,
                                            -200));
    }
}

int Game::GenerateRandomNumber(int from, int to) {
    std::random_device r;
    std::default_random_engine generator(r());
    std::uniform_int_distribution<int> distribution(from, to);
    return distribution(generator);
}


