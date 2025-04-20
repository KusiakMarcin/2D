//
// Created by marcin on 30.03.25.
//

#ifndef SDL2TEST_RECTANGLE_H
#define SDL2TEST_RECTANGLE_H
#include "Line.h"
#include "Primitive.h"
class Rectangle : public Primitive {

    Point corner;
    double Width;
    double Height;
    Point A;
    Point B;
    Point C;
    Point D;



public:
    Rectangle(int PosX, int PosY, int Width, int Height,
              SDL_Color color = COLORS[WHITE],SDL_Color fillcolor = COLORS[BLACK]);
    Rectangle(int PosX, int PosY, int Width, int Height,const char* file);

    void DrawRectangle(SDL_Renderer * renderer,bool fill);
    void Translation(int targetX, int targetY);
    void FillColor(SDL_Renderer * renderer);
    void FillTexture(SDL_Renderer* renderer);
    void Scaling(double k);
    void CeterTexture(SDL_Surface* texture);
    SDL_Surface * getTexture();
    Point getCorner();
};


#endif //SDL2TEST_RECTANGLE_H