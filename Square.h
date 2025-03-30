//
// Created by marcin on 30.03.25.
//

#ifndef SDL2TEST_SQUARE_H
#define SDL2TEST_SQUARE_H
#include "Line.h"

class Square {

    int cornerX;
    int cornerY;
    double Width;
    double Height;
public:
    Square(int PosX,int PosY,double Width, double Height){
        this->cornerX = PosX;
        this->cornerY = PosY;
        this->Width = Width;
        this->Height = Height;
    }

    void DrawSquare(){
        for()
    }
};


#endif //SDL2TEST_SQUARE_H
