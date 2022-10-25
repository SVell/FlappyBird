#include "Game.h"
#include "Score.h"

Score::Score() : Score(0,0){

}

Score::Score(int x, int y) {

    font = TTF_OpenFont("../Assets/font.ttf", 48);

    SDL_Color textColor = {255, 255, 255};
    TextToImage("0", textColor);

    destRect.x = x - destRect.w / 2;
    destRect.y = y - destRect.h / 2;
}

void Score::TextToImage(std::string text, SDL_Color color) {
    SDL_DestroyTexture(texture);

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);

    if(textSurface == nullptr){
        SDL_Log("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    else{
        texture = SDL_CreateTextureFromSurface(Game::renderer, textSurface);

        if(texture == nullptr)
        {
            SDL_Log( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }
        else
        {
            destRect.w = textSurface->w;
            destRect.h = textSurface->h;
        }

        SDL_FreeSurface(textSurface);
    }
}

void Score::Render() {
    SDL_RenderCopyEx(Game::renderer, texture, NULL, &destRect, 0, NULL, SDL_FLIP_NONE);
}
