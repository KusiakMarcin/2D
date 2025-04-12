#include "Engine.h"
#include <iostream>
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
#include <unistd.h>
Engine::Engine(const char *title,int posx, int posy, int width, int height, int flags) {
    SDL_Init(SDL_INIT_EVERYTHING);
    isRunning = true;
    flags = SDL_WINDOW_MAXIMIZED;


    int err = SDL_CreateWindowAndRenderer(width, height, flags, &window, &renderer);
    if (err) {
        std::cout << "bruh" << SDL_GetError() << std::endl;
    }
    Point A = {40,20};
    Point B = {300,500};
    Line line(A,B);
    line.drawLine(renderer);
    Rectangle rectangle(20,20,150,150);
    rectangle.DrawSquare(renderer);



    SDL_RenderPresent(renderer);

    loop();

}
Engine::~Engine() {
    //w


}

void Engine::loop() {
    //Rectangle square (20, 20, 100, 120);

    //square.DrawSquare(renderer);
    int i=1;
    while(isRunning){
        Uint64 start = SDL_GetPerformanceCounter();
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);

        //Point tmp = square.getCorner();
        //square.Transposition(tmp.x+i,tmp.y+i,renderer);
        //if(tmp.x<20) i=1;
        //if(tmp.x>100) i = -1;
        //std::cout<<tmp.x<<std::endl;
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
                            std::cerr << "q" << std::endl;
                            break;
                    }
                    break;

                case SDL_MOUSEMOTION:
                    std::cerr << "x:" << event.motion.x << " y:" << event.motion.y << std::endl;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    std::cerr << event.button.button<< std::endl;

            }
        }
       // SDL_RenderPresent(renderer);
        //Uint64 end = SDL_GetPerformanceCounter();
       // float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f; //cap frame rate
        //SDL_Delay(floor(16.666f-elapsedMS));
    }


}

void Engine::terminate(){
    isRunning = false;
    SDL_DestroyWindow(window);
    SDL_Quit();

}
//
// Created by marcin on 16.03.25.
//
