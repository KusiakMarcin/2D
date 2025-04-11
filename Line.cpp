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
    this->Ratio = (float)tmpxd/(float)tmpyd;
}

void Line::drawLine(SDL_Renderer * renderer) {
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
        double tmpx = aPoint.x;
        double tmpy = aPoint.y;
        bool startConX = tmpx<bPoint.x;
        bool startConY = tmpy<bPoint.y;
        while(startConX==(tmpx<bPoint.x)&&startConY==(tmpy<bPoint.y)){
            SDL_RenderDrawPoint(renderer,(int)tmpx,(int)tmpy);
            tmpx+= Ratio;
            tmpy+= 1/Ratio;

        }



}