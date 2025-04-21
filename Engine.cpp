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


    SDL_RenderPresent(renderer);

    loop();

}
Engine::~Engine() {
    //w


}

void Engine::loop() {
    Rectangle rect(20,20,100,100,"zaba.bmp");
    while(isRunning){

        rect.DrawRectangle(renderer,true);
        rect.Translation(rect.getCorner().x+1,rect.getCorner().y+1);
        refreshFrame();

        while(SDL_PollEvent(&event)){

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
        SDL_Delay(50);

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
