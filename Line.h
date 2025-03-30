//
// Created by marcin on 30.03.25.
//

#ifndef SDL2TEST_LINE_H
#define SDL2TEST_LINE_H
#include "SDL.h"
struct Point{
    int x;
    int y;
};

class Line {
public:
    double Ratio;
    Point aPoint;
    Point bPoint;
    Line(Point a, Point b);
    void drawLine(SDL_Renderer * renderer);
};



#endif //SDL2TEST_LINE_H
