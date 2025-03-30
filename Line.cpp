//
// Created by marcin on 30.03.25.
//

#include "Line.h"
#include "SDL.h"



Line::Line(Point a, Point b) {
    this->aPoint.x=a.x;
    this->aPoint.y=a.y;
    this->bPoint.x=b.x;
    this->bPoint.y=b.y;
    int tmpxd = b.x - a.x;
    int tmpyd = b.y - a.y;
    this->Ratio = tmpxd / tmpyd;
}

void Line::drawLine(SDL_Renderer * renderer) {
    int tmpy = aPoint.y;
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    for(int i =aPoint.x; i < bPoint.x; i++){
        SDL_RenderDrawPoint(renderer,i,tmpy);
        tmpy+= Ratio;
    }
}