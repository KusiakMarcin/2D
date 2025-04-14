//
// Created by marcin on 30.03.25.
//

#ifndef SDL2TEST_RECTANGLE_H
#define SDL2TEST_RECTANGLE_H
#include "Line.h"

class Rectangle : Primitive{

    Point corner;
    double Width;
    double Height;
    Point A;
    Point B;
    Point C;
    Point D;
public:
    Rectangle(int PosX, int PosY, int Width, int Height);

    void DrawSquare(SDL_Renderer * renderer);
    void DrawRectangle(SDL_Renderer * renderer);
    void Transposition(int targetX,int targetY,SDL_Renderer * renderer);
    void DrawColor(SDL_Renderer * renderer,RGBA color);
    void DrawColor(SDL_Renderer * renderer,int color);
    Point getCorner();
};


#endif //SDL2TEST_RECTANGLE_H
