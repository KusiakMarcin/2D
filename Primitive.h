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




/**
 * Klasa bazowa reprezentująca prymityw graficzny.
 *
 * Klasa zawiera podstawowe właściwości i metody wspólne dla różnych typów prymitywów graficznych,
 * takie jak kolor obramowania, kolor wypełnienia, możliwość ustawienia tekstury, a także obsługę koloru piksela.
 * Przeznaczona do dziedziczenia przez bardziej szczegółowe klasy prymitywów (np. linie, prostokąty, koła).
 */

class Primitive {
protected:
    SDL_Color color;
    SDL_Color fillColor;
    /**
     * Flaga informująca, czy prymityw posiada teksturę.
     */
    bool texture = false;
    /**
     * Wskaźnik do powierzchni tekstury (jeśli dotyczy).
     */
    SDL_Surface * Texture;
    /**
     * Pozycja X,Y środka tekstury. Używane w przypadku gdy tekstura ma większą
     * rozdzielczość niż prymityw, na który nakłada się teksturę.
     */
    int TextureCenterX,TextureCenterY;
public:
    /**
     * Ustawia kolor obramowania prymitywu.
     *
     * @param color Kolor typu SDL_Color do ustawienia jako kolor obramowania.
     */
    void setColor(SDL_Color color);
    /**
    * Ustawia kolor wypełnienia prymitywu.
    *
    * @param color Kolor typu SDL_Color do ustawienia jako kolor wypełnienia.
    */
    void setFill(SDL_Color color);
    /**
     * Statyczna metoda wyodrębniająca kolor z pojedynczego piksela.
     *
     * @param pixel Wartość piksela typu Uint32. Wskaśnik do piksela uzyskujemy ze struktury SDL_Surface w której zapisany jest wskażnik do za pomocą którego można uzyskac dostep do pikseli
     * @param format Wskaźnik do struktury SDL_PixelFormat używanej do interpretacji koloru piksela.
     * @return Wyodrębniony kolor typu SDL_Color.
     */
    static SDL_Color ExtractColorFromPixel(Uint32 pixel,SDL_PixelFormat*format);

    /**
     * Metoda ustawia flage texture
     *
     * @param value true wypełnia teksturą;
     */
    void setTextureFill(bool value);


};


#endif //SDL2TEST_PRIMITIVE_H
