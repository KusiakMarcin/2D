//
// Created by marcin on 30.03.25.
//

#ifndef SDL2TEST_LINE_H
#define SDL2TEST_LINE_H
#include "SDL.h"
#include "Primitive.h"

/**
 * Struktura reprezentująca punkt w przestrzeni dwuwymiarowej.
 *
 * Używana do określania położeń końcowych linii oraz innych prymitywów graficznych.
 */
struct Point{
    double x;
    double y;
};

/**
 * Klasa reprezentująca linię.
 *
 * Dziedziczy z klasy Primitive,
 */
class Line : Primitive{
public:
    /**
     * Stosunek długości do szerokości linii.
     */
    double Ratio;
    /**
     * Składowa X wektora kierunkowego linii.
     */
    double dx;
    /**
     * Składowa Y wektora kierunkowego linii.
     */
    double dy;
    /**
     * Punkt początkowy linii.
     */
    Point aPoint;
    /**
     * Punkt końcowy linii.
     */
    Point bPoint;
    /**
    * Konstruktor linii.
    *
    * @param a Punkt początkowy linii.
    * @param b Punkt końcowy linii.
    * @param color Kolor linii (domyślnie biały).
    */
    Line(Point a, Point b,SDL_Color color=COLORS[WHITE]);
    /**
     * Rysuje linię na zadanym rendererze SDL.
     *
     * @param renderer Wskaźnik do renderer'a SDL, na którym linia zostanie narysowana.
     */
    void drawLine(SDL_Renderer * renderer);
    /**
    * Ustawia nowy punkt początkowy linii.
    *
    * @param newPoint Nowy punkt początkowy.
    */
    void setA(Point newPoint);
    /**
     * Ustawia nowy punkt końcowy linii.
     *
     * @param newPoint Nowy punkt końcowy.
     */
    void setB(Point newPoint);
};



#endif //SDL2TEST_LINE_H
