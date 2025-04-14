//
// Created by marcin on 16.03.25.
//

#ifndef SDL2TEST_ENGINE_H
#include <SDL.h>
#include <iostream>
#include <string>

class Engine{
    protected:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event event;
        bool isRunning;
    public:
        Engine(const char *title,int posx, int posy, int width, int height, int flags = SDL_WINDOW_SHOWN);
        ~Engine();
        void loop();
        void terminate();

};



#define SDL2TEST_ENGINE_H

#endif //SDL2TEST_ENGINE_H
