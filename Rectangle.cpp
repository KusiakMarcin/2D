//
// Created by marcin on 30.03.25.
//

#include "Rectangle.h"
#include "Line.h"

Rectangle::Rectangle(int PosX, int PosY, int Width, int Height) {
    this->corner.x = PosX;
    this->corner.y= PosY;
    this->Width = Width;
    this->Height = Height;

}



void Rectangle::DrawSquare(SDL_Renderer * renderer) {

    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    double tmpx = corner.x;
    double tmpy = corner.y;
    double endX = corner.x+Width;
    double endY = corner.y+Height;
    while(tmpx<endX){
        SDL_RenderDrawPoint(renderer,(int)tmpx,(int)corner.y);
        SDL_RenderDrawPoint(renderer,(int)tmpx,(int)endY);
        tmpx+=1.0;
    }
    while (tmpy<endY){
        SDL_RenderDrawPoint(renderer,(int)corner.x,(int)tmpy);
        SDL_RenderDrawPoint(renderer,(int)endX,(int)tmpy);
        tmpy+=1.0;
    }
}
void Rectangle::Transposition(int targetX, int targetY, SDL_Renderer * renderer) {
    this->corner.x=targetX;
    this->corner.y=targetY;
    DrawSquare(renderer);

}

Point Rectangle::getCorner() {
    return corner;
}
void Rectangle::DrawColor(SDL_Renderer* renderer, RGBA Color){
    ;
}

void Rectangle::DrawColor(SDL_Renderer *renderer, int color) {
    ;
}