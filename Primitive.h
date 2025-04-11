//
// Created by marcin on 06.04.25.
//

#ifndef SDL2TEST_PRIMITIVE_H
#define SDL2TEST_PRIMITIVE_H

struct Point{
    double x;
    double y;
};

struct RGBA{
    int R;
    int G;
    int B;
    int A;
};
class Primitive {
private:
    RGBA Color;
public:
    void setColor(int R,int G, int B, int A);

};


#endif //SDL2TEST_PRIMITIVE_H
