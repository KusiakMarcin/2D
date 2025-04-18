//
// Created by marcin on 17.04.25.
//

#ifndef SDL2TEST_PRIMITIVE_H
#define SDL2TEST_PRIMITIVE_H

struct RGBA{
    int R;
    int G;
    int B;
    int A;
};
enum Palette{WHITE,BLACK,RED,GREEN,BLUE};
const RGBA COLORS[5]{RGBA{255,255,255,255},RGBA{0,0,0,0},RGBA{255,0,0,1},
                     RGBA{0,255,0,1},RGBA{0,0,255,1}};
class Primitive {
protected:
    RGBA color;

public:
    void setColor(RGBA color);

};


#endif //SDL2TEST_PRIMITIVE_H
