//
// Created by marcin on 30.03.25.
//

#ifndef SDL2TEST_RECTANGLE_H
#define SDL2TEST_RECTANGLE_H
#include "Line.h"
#include "Primitive.h"
class Rectangle : Primitive{

    Point corner;
    double Width;
    double Height;
    Point A;
    Point B;
    Point C;
    Point D;


public:
    Rectangle(int PosX, int PosY, int Width, int Height,RGBA color = COLORS[WHITE]);


    void DrawRectangle(SDL_Renderer * renderer);
    void Translation(int targetX, int targetY);
    void FillColor(SDL_Renderer * renderer, RGBA color);

    Point getCorner();
};


#endif //SDL2TEST_RECTANGLE_H