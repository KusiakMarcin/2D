//
// Created by marcin on 30.03.25.
//

#include "Circle.h"


Circle::Circle(int posX, int posY, double radius) {
    this->MiddleX = posX;
    this->MiddleY = posY;
    this->radius = radius;
}

void Circle::DrawCircle(SDL_Renderer* renderer) {
    double tmpRadian = PI/(2*radius);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    for(int i = 0;i<4*radius;i++){
        SDL_RenderDrawPoint(renderer,this->MiddleX+radius*cos(tmpRadian*i),this->MiddleY+radius*sin(tmpRadian*i));
    }
}
