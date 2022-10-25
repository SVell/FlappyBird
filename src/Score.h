#pragma once

#include "SDL.h"
#include "SDL_ttf.h"
#include <string>

class Score {
public:
    Score();
    Score(int x, int y);

    void Render();
    void SetScore(unsigned int newScore);
    void IncreaseScore();

private:
    unsigned int score;

    SDL_Texture* texture;
    TTF_Font* font;

    SDL_Rect srcRect;
    SDL_Rect destRect;

    void TextToImage(std::string text, SDL_Color color);
};
