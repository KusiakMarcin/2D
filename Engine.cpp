#include "Engine.h"
#include <iostream>
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
Engine::Engine(const char *title,int posx, int posy, int width, int height, int flags) {
    SDL_Init(SDL_INIT_EVERYTHING);
    isRunning = true;
    flags = SDL_WINDOW_MAXIMIZED;



    int err = SDL_CreateWindowAndRenderer(width, height, flags, &window, &renderer);
    if (err) {
        std::cout << "bruh" << SDL_GetError() << std::endl;
    }
    Point A = {20,20};
    Point B = {20,100};
    Rectangle rect(20,20,200,200,"mapa.bmp");
    rect.DrawRectangle(renderer,true);


    SDL_RenderPresent(renderer);

    loop();

}
Engine::~Engine() {
    //w


}

void Engine::loop() {

    while(isRunning){

        if(SDL_PollEvent(&event)== 0){ continue;}
        else{
            switch (event.type) {

            case SDL_QUIT:
                terminate();
                break;

                case SDL_KEYDOWN:

                    //keyboardHandle(event);
                    switch (event.key.keysym.sym) {
                        case SDLK_q:
                            std::cout << "q" << std::endl;
                            break;
                    }
                    break;

                case SDL_MOUSEMOTION:
                    std::cout << "x:" << event.motion.x << " y:" << event.motion.y << std::endl;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    std::cout << event.button.button<< std::endl;

            }
        }

    }

}

void Engine::terminate(){
    isRunning = false;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}

void Engine::refreshFrame() {
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderClear(renderer);
}
//
// Created by marcin on 16.03.25.
//
