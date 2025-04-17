//
// Created by marcin on 30.03.25.
//

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
    A = corner;
    B.x = corner.x;
    B.y = corner.y+Height;
    C.x = corner.x + Width;
    C.y = corner.y +Height;
    D.x = corner.x + Width;
    D.y = corner.y;


}

void Rectangle::DrawRectangle(SDL_Renderer * renderer){

    Line tmp1(A,B);
    Line tmp2(A,D);
    Line tmp3(C,B);
    Line tmp4(C,D);
    tmp1.drawLine(renderer);
    tmp2.drawLine(renderer);
    tmp3.drawLine(renderer);
    tmp4.drawLine(renderer);
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
//
//Point Rectangle::getCorner() {
//    return corner;
//}
void Rectangle::FillColor(SDL_Renderer* renderer, RGBA color){

}
//
//void Rectangle::FillColor(SDL_Renderer *renderer, int color) {
//    ;
//}