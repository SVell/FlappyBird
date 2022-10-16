#pragma once

#include "SDL.h"
#include "Bird.h"

class Game {
public:
    Game();
    ~Game();

    void Init(const char* windowTitle, const int xPos, const int yPos, bool fullscreen);

    void HandleEvents();
    void Update();
    void Render();
    void Clean();

    bool IsRunning(){return isRunning;}

    static const int SCREEN_WIDTH;
    static const int SCREEN_HEIGHT;

    static SDL_Renderer* renderer;
    static bool isRunning;

    static const double GRAVITY;
private:


    SDL_Window* window;

    Bird* player = nullptr;
};