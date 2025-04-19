#include "Engine.h"
#include "Circle.h"

int main(int argc, char *argv[])
{
//    Uint8 index;
//    SDL_PixelFormat *fmt;
//    SDL_Color *color;
    const char *title = "bruh";
    Engine *engine = new Engine(title,200,200,400,400);
//    SDL_RWops * buffer = SDL_RWFromFile("mapa.bmp","r");
//    if(buffer==NULL) return -1;
//    SDL_Surface *surface = SDL_LoadBMP_RW(buffer,0);
//    if(!surface) return -2;
//    fmt=surface->format;
//    index = fmt->BitsPerPixel;
//    std::cout<<(int)index<<std::endl;
//
//
//    SDL_LockSurface(surface);
//    Uint32*pixels;
//    Uint32 tmp;
//    pixels = (Uint32*)surface->pixels;
//    SDL_Color pixelsEnd[3];
//    for(int i=0;i<3;i++){
//         tmp = pixels[i] & fmt->Rmask;
//         tmp = tmp >> fmt->Rshift;
//         tmp = tmp << fmt->Rloss;
//         pixelsEnd[i].r=(Uint8)tmp;
//         tmp = pixels[i] & fmt->Gmask;
//         tmp = tmp >> fmt->Gshift;
//         tmp = tmp << fmt->Gloss;
//        pixelsEnd[i].g=(Uint8)tmp;
//         tmp = pixels[i] & fmt->Bmask;
//         tmp = tmp >> fmt->Bshift;
//         tmp = tmp << fmt->Bloss;
//        pixelsEnd[i].b=(Uint8)tmp;
//
//        pixelsEnd[i].a=1;
//        std::cout<<(int)pixelsEnd[i].r<<"  "<<(int)pixelsEnd[i].g
//        <<"  "<<(int)pixelsEnd[i].b<<"  "<<(int)pixelsEnd[i].a<<std::endl;
//    }
//
///* ... */
//
//    SDL_UnlockSurface(surface);
//    SDL_FreeSurface(surface);
//    SDL_FreeRW(buffer);

    return 0;
}