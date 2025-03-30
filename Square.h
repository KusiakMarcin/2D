//
// Created by marcin on 30.03.25.
//

#ifndef SDL2TEST_SQUARE_H
#define SDL2TEST_SQUARE_H
#include "Line.h"

class Square {

    int cornerX;
    int cornerY;
    int Width;
    int Height;
public:
    Square(int PosX,int PosY,int Width, int Height);

    void DrawSquare(SDL_Renderer * renderer);
};


#endif //SDL2TEST_SQUARE_H
