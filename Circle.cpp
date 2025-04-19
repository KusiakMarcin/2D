//
// Created by marcin on 30.03.25.
//

#include "Circle.h"


Circle::Circle(int posX, int posY,double radius,SDL_Color color,SDL_Color fillcolor) {
    this->MiddleX = posX;
    this->MiddleY = posY;
    this->radius = radius;
    this-> color = color;
    this->fillColor =fillcolor;
}

void Circle::DrawCircle(SDL_Renderer* renderer,bool fillColor) {
    double tmpRadian = 1.0/radius;
    SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
    for(double i = 0;i<2*PI;i+=tmpRadian){
        SDL_RenderDrawPoint(renderer,this->MiddleX+radius*cos(i),
                            this->MiddleY+radius*sin(i));
    }
    if(fillColor) FillColor(renderer);
}

void Circle::FillColor(SDL_Renderer * renderer){
    SDL_SetRenderDrawColor(renderer,fillColor.r,fillColor.g,
                           fillColor.b,fillColor.a);
    for(int y=0; MiddleX + y < MiddleX + radius; y++){
        SDL_RenderDrawPoint(renderer,MiddleX, MiddleY + y);
        SDL_RenderDrawPoint(renderer,MiddleX, MiddleY - y);
    }
    for(int x=1; MiddleX + x < MiddleX + radius; x++){
        SDL_RenderDrawPoint(renderer, MiddleX + x, MiddleY);
        SDL_RenderDrawPoint(renderer, MiddleX - x, MiddleY);


        for(int y=0; MiddleY + y < MiddleY + radius * sin(acos(x / radius));y++){
            SDL_RenderDrawPoint(renderer, MiddleX + x, MiddleY + y);
            SDL_RenderDrawPoint(renderer, MiddleX - x, MiddleY - y);
            SDL_RenderDrawPoint(renderer, MiddleX + x, MiddleY - y);
            SDL_RenderDrawPoint(renderer, MiddleX - x, MiddleY + y);
        }
    }

}

void Circle::Translation(int targetX, int targetY) {
    MiddleX = targetX;
    MiddleY = targetY;
}

int Circle::GetMidX() {
    return MiddleX;
}

void Circle::Scaling(double k) {
    radius = radius*k;
}

int Circle::GetMidY() {
    return MiddleY;
}
