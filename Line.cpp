//
// Created by marcin on 30.03.25.
//

#include "Line.h"
#include "SDL.h"
#include "math.h"


Line::Line(Point a, Point b,SDL_Color color) {
    this->aPoint.x=a.x;
    this->aPoint.y=a.y;
    this->bPoint.x=b.x;
    this->bPoint.y=b.y;
    this->color =color;
    dx = b.x - a.x;
    dy = b.y - a.y;
    if(dx!=0)Ratio = dy/dx;

}

void Line::drawLine(SDL_Renderer * renderer) {
    SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
    double tmpx = aPoint.x;
    double tmpy = aPoint.y;
    bool startConX = tmpx<=bPoint.x;
    bool startConY = tmpy<=bPoint.y;
    if(dx==0){
        while(startConY==(tmpy<=bPoint.y)){
            SDL_RenderDrawPoint(renderer,tmpx+0.5,tmpy+0.5);
            if(dy>0)tmpy+=1.0;
            else tmpy-=1.0;
        }
    }
    if(dy==0){
        while(startConX==(tmpx<=bPoint.x)){
            SDL_RenderDrawPoint(renderer,tmpx+0.5,tmpy+0.5);
            if(dx>0)tmpx+=1.0;
            else tmpx -=1.0;
        }
    }
    if(Ratio>=-1&&Ratio<=1&&dx!=0&&dy!=0){
        double tmpm = Ratio;
    while(startConX==(tmpx<=bPoint.x)&&startConY==(tmpy<=bPoint.y)){
        SDL_RenderDrawPoint(renderer,tmpx+0.5,tmpy+0.5);
        if(dx>0)tmpx+=1.0;
        else tmpx -=1.0;
        tmpy+= tmpm;

        }
    }if(dx!=0&&dy!=0&&(Ratio>1||Ratio<-1)){
        double tmpm = 1/Ratio;

        while(startConX==(tmpx<bPoint.x)&&startConY==(tmpy<bPoint.y)){
            SDL_RenderDrawPoint(renderer, tmpx+0.5,tmpy+0.5);
            tmpx+= tmpm;
            if(dy>0)tmpy+=1.0;
            else tmpy-=1.0;

        }
    }



}

void Line::setA(Point newPoint) {
    aPoint = newPoint;
    dx = bPoint.x - aPoint.x;
    dy = bPoint.y - aPoint.y;
    if(dx!=0)Ratio = dy/dx;
}

void Line::setB(Point newPoint) {
    bPoint = newPoint;
    dx = bPoint.x - aPoint.x;
    dy = bPoint.y - aPoint.y;
    if(dx!=0)Ratio = dy/dx;
}

double Line::Lenght() {
    double xfactor =aPoint.x-bPoint.x;
    xfactor*=xfactor;
    double yfactor = aPoint.y-bPoint.y;
    yfactor*=yfactor;
    return sqrt(xfactor+yfactor);
}