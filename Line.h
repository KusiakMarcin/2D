//
// Created by marcin on 30.03.25.
//

#ifndef SDL2TEST_LINE_H
#define SDL2TEST_LINE_H
#include "SDL.h"
#include "Primitive.h"
struct Point{
    double x;
    double y;
};

class Line : Primitive{
public:
    double Ratio;
    double dx;
    double dy;
    Point aPoint;
    Point bPoint;
    Line(Point a, Point b,RGBA color=COLORS[WHITE]);
    void drawLine(SDL_Renderer * renderer);
    void setA(Point newPoint);
    void setB(Point newPoint);
};



#endif //SDL2TEST_LINE_H
