//
// Created by marcin on 17.04.25.
//

#ifndef SDL2TEST_PRIMITIVE_H
#define SDL2TEST_PRIMITIVE_H
#include "SDL.h"
#include <iostream>

enum Palette{WHITE,BLACK,RED,GREEN,BLUE};
const SDL_Color COLORS[5]{SDL_Color{255,255,255,255},SDL_Color{0,0,0,0},SDL_Color{255,0,0,1},
                          SDL_Color{0,255,0,1},SDL_Color{0,0,255,1}};
class Primitive {
protected:
    SDL_Color color;
    SDL_Color fillColor;
    bool texture;
    SDL_Surface * Texture;
    int TextureCenterX;
    int TextureCenterY;
public:
    void setColor(SDL_Color color);
    void setFill(SDL_Color color);

    static SDL_Color ExtractColorFromPixel(Uint32 pixel,SDL_PixelFormat*format);



};


#endif //SDL2TEST_PRIMITIVE_H
