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
Circle::Circle(int posX, int posY,double radius,const char* file,SDL_Color color) {
    this->MiddleX = posX;
    this->MiddleY = posY;
    this->radius = radius;
    this-> color = color;
    SDL_RWops * buffer = SDL_RWFromFile(file,"r");
    if(!buffer) {
        std::cerr<<"buffer error"<<std::endl;
    }
    Texture = SDL_LoadBMP_RW(buffer,0);
    CenterTexture(Texture);
    texture= true;
}

void Circle::DrawCircle(SDL_Renderer* renderer,bool fillColor) {
    double tmpRadian = 1.0/radius;
    SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
    for(double i = 0;i<2*PI;i+=tmpRadian){
        SDL_RenderDrawPoint(renderer,this->MiddleX+radius*cos(i),
                            this->MiddleY+radius*sin(i));
    }
    if(fillColor&&!texture) FillColor(renderer);
    if(fillColor&&texture)FillTexture(renderer);
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

void Circle::CenterTexture(SDL_Surface* texture){
    TextureCenterY = texture->h/2;
    TextureCenterX = texture->w/2;
}

void Circle::FillTexture(SDL_Renderer *renderer) {
    Uint32* pixels = (Uint32*)Texture->pixels;
    SDL_Color color;

    for(int x=0; MiddleX + x < MiddleX + radius; x++){
        color = ExtractColorFromPixel(pixels[(TextureCenterY)*(Texture->pitch/4)+x]
                ,Texture->format);
        SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
        SDL_RenderDrawPoint(renderer, MiddleX + x, MiddleY);
        color = ExtractColorFromPixel(pixels[(TextureCenterY)*(Texture->pitch/4)-x]
                ,Texture->format);
        SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
        SDL_RenderDrawPoint(renderer, MiddleX - x, MiddleY);


        for(int y=0; MiddleY + y < MiddleY + radius * sin(acos(x / radius));y++){
            color = ExtractColorFromPixel(pixels[(TextureCenterY+y)*(Texture->pitch/4)+TextureCenterX+x]
                    ,Texture->format);
            SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
            SDL_RenderDrawPoint(renderer, MiddleX + x, MiddleY + y);
            color = ExtractColorFromPixel(pixels[(TextureCenterY-y)*(Texture->pitch/4)+TextureCenterX-x]
                    ,Texture->format);
            SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
            SDL_RenderDrawPoint(renderer, MiddleX - x, MiddleY - y);
            color = ExtractColorFromPixel(pixels[(TextureCenterY-y)*(Texture->pitch/4)+TextureCenterX+x]
                    ,Texture->format);
            SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
            SDL_RenderDrawPoint(renderer, MiddleX + x, MiddleY - y);
            color = ExtractColorFromPixel(pixels[(TextureCenterY+y)*(Texture->pitch/4)+TextureCenterX-x]
                    ,Texture->format);
            SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
            SDL_RenderDrawPoint(renderer, MiddleX - x, MiddleY + y);
        }
    }
}