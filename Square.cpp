//
// Created by marcin on 30.03.25.
//

#include "Square.h"


Square::Square(int PosX, int PosY, int Width, int Height) {
    this->cornerX = PosX;
    this->cornerY = PosY;
    this->Width = Width;
    this->Height = Height;
}

void Square::DrawSquare(SDL_Renderer * renderer) {
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    for(int i=cornerX;i<Width;i++){
        SDL_RenderDrawPoint(renderer,i,cornerY);
        SDL_RenderDrawPoint(renderer,i,cornerY+Height);
    }
    for(int i=cornerY;i<Height;i++){
        SDL_RenderDrawPoint(renderer,cornerX,i);
        SDL_RenderDrawPoint(renderer,cornerX+Width,i);
    }
}