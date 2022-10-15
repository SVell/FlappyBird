#pragma once

#include "SDL.h"
#include "Bird.h"

class Game {
public:
    Game();
    ~Game();

    void Init(const char* windowTitle, const int xPos, const int yPos, const int width, const int height, bool fullscreen);

    void HandleEvents();
    void Update();
    void Render();
    void Clean();

    bool IsRunning(){return isRunning;}

    static SDL_Renderer* renderer;
    static bool isRunning;
private:
    SDL_Window* window;

    Bird* player = nullptr;
};