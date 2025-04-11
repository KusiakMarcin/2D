//
// Created by marcin on 30.03.25.
//

#ifndef SDL2TEST_CIRCLE_H
#define SDL2TEST_CIRCLE_H
#include "math.h"
#include "SDL.h"
#include "Primitive.h"
#define PI 3.14159

class Circle : Primitive{
    int MiddleX;
    int MiddleY;
    double radius;


public:
    Circle(int posX, int posY,double radius);

    void DrawCircle(SDL_Renderer* renderer);

};



#endif //SDL2TEST_CIRCLE_H
