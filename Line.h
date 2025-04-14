//
// Created by marcin on 30.03.25.
//

#ifndef SDL2TEST_LINE_H
#define SDL2TEST_LINE_H
#include "SDL.h"
#include "Primitive.h"


class Line : Primitive{
public:
    double Ratio;
    Point aPoint;
    Point bPoint;
    Line(Point a, Point b);
    void drawLine(SDL_Renderer * renderer);
    void setA(Point newPoint);
    void setB(Point newPoint);

};



#endif //SDL2TEST_LINE_H
