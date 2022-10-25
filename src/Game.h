#pragma once

#include <vector>
#include "SDL.h"
#include "GameObject.h"
#include "Player.h"
#include "Score.h"

class Game {
public:
    Game();
    ~Game();

    void Init(const char* windowTitle, int xPos, int yPos, bool fullscreen);

    void HandleEvents();
    void Update();
    void Render();
    void Clean();

    bool IsRunning() const {return isRunning;}

    static const int SCREEN_WIDTH;
    static const int SCREEN_HEIGHT;

    static SDL_Renderer* renderer;
    static bool isRunning;

    static const double GRAVITY;
private:
    SDL_Window* window;
    Player* player;
    Score* score;
    GameObject* bg;
    std::vector<GameObject*> floor;
    std::vector<GameObject*> pipes;

    void CreateEnv(int pipesPairsToCreate = 5);
    int GenerateRandomNumber(int from, int to);

    void LoadMedia();
};