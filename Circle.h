//
// Created by marcin on 30.03.25.
//

#ifndef SDL2TEST_CIRCLE_H
#define SDL2TEST_CIRCLE_H
#include "math.h"
#include "SDL.h"
#define PI 3.14159
#include "Primitive.h"

/**
 * Klasa reprezentująca okrąg jako prymityw graficzny.
 *
 * Dziedziczy z klasy Primitive. Umożliwia rysowanie okręgu z kolorem lub teksturą wypełnienia,
 * a także wykonywanie operacji takich jak translacja, skalowanie oraz ustawianie środka tekstury.
 */
class Circle : public Primitive {
private:
    /**
     * Współrzędne środka okręgu.
     */
    int MiddleX,MiddleY;
    /**
     * Promień okręgu.
     */
    double radius;

    /**
     * Wypełnia okrąg teksturą (jeśli ustawiona).
     *
     * @param renderer Wskaźnik do renderer'a SDL.
     */
    void FillTexture(SDL_Renderer* renderer);

public:
    /**
     * Konstruktor okręgu z kolorem obramowania i kolorem wypełnienia.
     *
     * @param posX Pozycja X środka okręgu.
     * @param posY Pozycja Y środka okręgu.
     * @param radius Promień okręgu.
     * @param color Kolor obramowania (domyślnie biały).
     * @param fillcolor Kolor wypełnienia (domyślnie czarny).
     */
    Circle(int posX, int posY,double radius,SDL_Color color = COLORS[WHITE],SDL_Color fillcolor=COLORS[BLACK]);
    /**
     * Konstruktor okręgu z teksturą i kolorem obramowania.
     *
     * @param posX Pozycja X środka okręgu.
     * @param posY Pozycja Y środka okręgu.
     * @param radius Promień okręgu.
     * @param file Ścieżka do pliku tekstury.
     * @param color Kolor obramowania (domyślnie biały).
     */
    Circle(int posX,int posY,double radius,const char* file,SDL_Color = COLORS[WHITE]);
    /**
     * Rysuje okrąg na podanym rendererze SDL.
     *
     * @param renderer Wskaźnik do renderer'a SDL.
     * @param fillColor Flaga określająca, czy okrąg ma być wypełniony.
     */
    void DrawCircle(SDL_Renderer* renderer,bool fillColor);
    /**
     * Wypełnia okrąg kolorem za pomocą renderer'a SDL.
     *
     * @param renderer Wskaźnik do renderer'a SDL.
     */
    void FillColor(SDL_Renderer * renderer);
    /**
     * Przesuwa okrąg do nowej pozycji (translacja).
     *
     * @param targetX Nowa pozycja X środka okręgu.
     * @param targetY Nowa pozycja Y środka okręgu.
     */
    void Translation(int targetX, int targetY);
    /**
     * Zwraca współrzędną X środka okręgu.
     *
     * @return Wartość X środka.
     */
    int GetMidX();
    /**
     * Zwraca współrzędną Y środka okręgu.
     *
     * @return Wartość Y środka.
     */
    int GetMidY();
    /**
     * Skaluje promień okręgu względem jego środka.
     *
     * @param k Współczynnik skalowania.
     */
    void Scaling(double k);
    /**
     * Ustawia wspólrzędne środkowego piksela tekstury na siatce pikseli.
     *
     * @param texture Wskaźnik do tekstury SDL_Surface.
     */
    void CenterTexture(SDL_Surface* texture);

};



#endif //SDL2TEST_CIRCLE_H
