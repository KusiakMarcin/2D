//
// Created by marcin on 30.03.25.
//

//
// Created by marcin on 30.03.25.
//

#include "Rectangle.h"
#include "Line.h"
#include <iostream>

Rectangle::Rectangle(int PosX, int PosY, int Width, int Height,
                     SDL_Color color,SDL_Color fillcolor) {
    this->corner.x = PosX;
    this->corner.y= PosY;
    this->Width = Width;
    this->Height = Height;
    A = corner;
    B.x = corner.x;
    B.y = corner.y+Height;
    C.x = corner.x + Width;
    C.y = corner.y +Height;
    D.x = corner.x + Width;
    D.y = corner.y;
    this->color = color;
    this->fillColor = fillcolor;
    texture = false;


}
Rectangle::Rectangle(int PosX, int PosY, int Width, int Height,const char* file) {
    this->corner.x = PosX;
    this->corner.y= PosY;
    this->Width = Width;
    this->Height = Height;
    A = corner;
    B.x = corner.x;
    B.y = corner.y+Height;
    C.x = corner.x + Width;
    C.y = corner.y +Height;
    D.x = corner.x + Width;
    D.y = corner.y;
    texture = true;
    SDL_RWops * buffer = SDL_RWFromFile(file,"r");
    if(!buffer) {
        std::cerr<<"buffer error"<<std::endl;
    }
    Texture = SDL_LoadBMP_RW(buffer,0);
    CeterTexture(Texture);




}

void Rectangle::DrawRectangle(SDL_Renderer * renderer,bool fill){
    SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
    Line tmp1(A,B,color);
    Line tmp2(A,D,color);
    Line tmp3(C,B,color);
    Line tmp4(C,D,color);
    tmp1.drawLine(renderer);
    tmp2.drawLine(renderer);
    tmp3.drawLine(renderer);
    tmp4.drawLine(renderer);
    if(fill&&!texture)FillColor(renderer);
    if(fill&&texture)FillTexture(renderer);
}


void Rectangle::Translation(int targetX, int targetY) {

    corner.x = targetX;
    corner.y = targetY;
    A = corner;
    B.x = corner.x;
    B.y = corner.y+Height;
    C.x = corner.x + Width;
    C.y = corner.y +Height;
    D.x = corner.x + Width;
    D.y = corner.y;

}

Point Rectangle::getCorner() {
    return corner;
}
void Rectangle::FillColor(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer,fillColor.r,fillColor.g,
                           fillColor.b,fillColor.a);
    for(int x=1;x<Width;x++){
        for(int y=1; y<Height;y++){
            SDL_RenderDrawPoint(renderer,x+corner.x,y+corner.y);
        }
    }

}
void Rectangle::FillTexture(SDL_Renderer* renderer){
    Uint32* pixels = (Uint32*)Texture->pixels;
    SDL_Color color;
    int ShapeVerticalBorder = (Height+1)/2;
    int ShapeHorizontalBorder = (Width+1)/2;

    for(int x=1;x<Width;x++){
        for(int y=1; y<Height;y++){
            color =ExtractColorFromPixel(pixels[(TextureCenterY-ShapeVerticalBorder+y)
                                                *(Texture->pitch/4)+x]
                    ,Texture->format);
            SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
            SDL_RenderDrawPoint(renderer,x+corner.x,y+corner.y);
        }
    }
}

void Rectangle::CeterTexture(SDL_Surface* texture) {
    TextureCenterX = texture->w/2;
    TextureCenterY = texture->h/2;

}



