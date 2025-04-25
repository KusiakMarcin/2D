

#ifndef SDL2TEST_ENGINE_H
#include <SDL.h>
#include <iostream>
#include <string>
#include <vector>
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
class Engine{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event event;
        bool isRunning;
        bool gameOver;
        std::vector<Rectangle*> Obstacles;
        Circle player= Circle(400, 400, 50, "zaba.bmp");

    public:
        Engine(const char *title,int posx, int posy, int width, int height, int flags = SDL_WINDOW_SHOWN);
        ~Engine();
        void mainLoop();
        void phisicsLoop();
        void terminate();
        void refreshFrame();
        void eventLoop();
};



#define SDL2TEST_ENGINE_H

#endif //SDL2TEST_ENGINE_H
