//
// Created by marcin on 30.03.25.
//

#ifndef SDL2TEST_RECTANGLE_H
#define SDL2TEST_RECTANGLE_H
#include "Line.h"
#include "Primitive.h"

/**
 * Klasa reprezentująca prostokąt.
 *
 * Dziedziczy z klasy Primitive.
 */
class Rectangle : public Primitive {
private:
    Point corner;
    double Width;
    double Height;
    /**
     * Wierzchołki prostokąta (punkty A, B, C, D oznaczają kolejne rogi).
     */
    Point A,B,C,D;
    /**
     * Wypełnia prostokąt teksturą (jeśli ustawiona).
     *
     * @param renderer Wskaźnik do renderer'a SDL.
     */
    void FillTexture(SDL_Renderer* renderer);
    /**
    * Zwraca wskaźnik do aktualnej tekstury prostokąta.
    *
    * @return Wskaźnik do SDL_Surface tekstury.
    */
    SDL_Surface * getTexture();
    /**
    * Wypełnia prostokąt kolorem za pomocą renderer'a SDL.
    *
    * @param renderer Wskaźnik do renderer'a SDL.
    */
    void FillColor(SDL_Renderer * renderer);


public:
    /**
     * Konstruktor prostokąta z kolorem obramowania i kolorem wypełnienia.
     *
     * @param PosX Pozycja X lewego górnego rogu.
     * @param PosY Pozycja Y lewego górnego rogu.
     * @param Width Szerokość prostokąta.
     * @param Height Wysokość prostokąta.
     * @param color Kolor obramowania (domyślnie biały).
     * @param fillcolor Kolor wypełnienia (domyślnie czarny).
     */
    Rectangle(int PosX, int PosY, int Width, int Height,
              SDL_Color color = COLORS[WHITE],SDL_Color fillcolor = COLORS[BLACK]);
    /**
    * Konstruktor prostokąta z teksturą i kolorem obramowania.
    *
    * @param PosX Pozycja X lewego górnego rogu.
    * @param PosY Pozycja Y lewego górnego rogu.
    * @param Width Szerokość prostokąta.
    * @param Height Wysokość prostokąta.
    * @param file Ścieżka do pliku tekstury (.bmp).
    * @param color Kolor obramowania (domyślnie biały).
    */
    Rectangle(int PosX, int PosY, int Width, int Height,const char* file,SDL_Color color = COLORS[WHITE]);
    /**
     * Rysuje prostokąt na podanym rendererze SDL.
     *
     * @param renderer Wskaźnik do renderer'a SDL.
     * @param fill Flaga określająca, czy prostokąt ma być wypełniony.
     */
    void DrawRectangle(SDL_Renderer * renderer,bool fill);
    /**
     * Przesuwa Lewy górny róg prostokąta do nowej pozycji (translacja).
     *
     * @param targetX Nowa pozycja X.
     * @param targetY Nowa pozycja Y.
     */
    void Translation(int targetX, int targetY);

    /**
     * Skaluje prostokąt względem lewego górnego rogu.
     *
     * @param k Współczynnik skalowania.
     */
    void Scaling(double k);
    /**
     * Ustawia wspólrzędne środkowego piksela tekstury na siatce pikseli.
     *
     * @param texture Wskaźnik do tekstury SDL_Surface.
     */
    void CeterTexture(SDL_Surface* texture);
    /**
     * Zwraca pozycję lewego górnego rogu prostokąta.
     *
     * @return Struktura Point reprezentująca róg prostokąta.
     */
    Point getCorner();
};


#endif //SDL2TEST_RECTANGLE_H