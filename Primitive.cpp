//
// Created by marcin on 17.04.25.
//

#include "Primitive.h"

void Primitive::setColor(SDL_Color color) {
    this->color=color;
}

void Primitive::setFill(SDL_Color color) {
    this->fillColor =color;
}



SDL_Color Primitive::ExtractColorFromPixel(Uint32 pixel, SDL_PixelFormat *format){
    Uint32 tmp;
    SDL_Color color;

    tmp = pixel & format->Rmask;
    tmp = tmp >> format->Rshift;
    tmp = tmp << format->Rloss;
    color.r=(Uint8)tmp;
    tmp = pixel & format->Gmask;
    tmp = tmp >> format->Gshift;
    tmp = tmp << format->Gloss;
    color.g=(Uint8)tmp;
    tmp = pixel & format->Bmask;
    tmp = tmp >> format->Bshift;
    tmp = tmp << format->Bloss;
    color.b=(Uint8)tmp;
    if(format->BitsPerPixel==24){
        color.a =1;
    }else if(format->BitsPerPixel==32){
        tmp = pixel & format->Amask;
        tmp = tmp >> format->Ashift;
        tmp = tmp << format->Aloss;
        color.a=(Uint8)tmp;
    }
    return color;
}

