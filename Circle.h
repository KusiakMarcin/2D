//
// Created by marcin on 30.03.25.
//

#ifndef SDL2TEST_CIRCLE_H
#define SDL2TEST_CIRCLE_H
#include "math.h"
#include "SDL.h"
#define PI 3.14159
#include "Primitive.h"
class Circle : public Primitive {
private:
    int MiddleX;
    int MiddleY;
    double radius;



public:
    Circle(int posX, int posY,double radius,SDL_Color color = COLORS[WHITE],SDL_Color fillcolor=COLORS[BLACK]);
    Circle(int posX,int posY,double radius,const char* file,SDL_Color = COLORS[WHITE]);
    void DrawCircle(SDL_Renderer* renderer,bool fillColor);

    void FillColor(SDL_Renderer * renderer);
    void Translation(int targetX, int targetY);
    int GetMidX();
    int GetMidY();
    void Scaling(double k);
    void CenterTexture(SDL_Surface* texture);
    void FillTexture(SDL_Renderer* renderer);
};



#endif //SDL2TEST_CIRCLE_H
