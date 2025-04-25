#include "Engine.h"
#include <iostream>
#include "time.h"

Engine::Engine(const char *title,int posx, int posy, int width, int height, int flags) {
    SDL_Init(SDL_INIT_EVERYTHING);
    isRunning = true;
    gameOver = false;
    flags = SDL_WINDOW_MAXIMIZED;
    srand(time(NULL));


    int err = SDL_CreateWindowAndRenderer(width, height, flags, &window, &renderer);
    if (err) {
        std::cout << "bruh" << SDL_GetError() << std::endl;
    }


    SDL_RenderPresent(renderer);

    mainLoop();

}
Engine::~Engine() {
    //w


}



void Engine::mainLoop() {
    SDL_WarpMouseInWindow(window, 400, 400);



    for(int i =0 ;i<3;i++){
        Obstacles.push_back(new Rectangle(rand()%100+50+(650*(rand()%2)),
                                      rand()%100+50+(650*(rand()%2)),
                                      50,50,COLORS[RED],COLORS[RED]));
        Obstacles[i]->setVelocityX(3);
        Obstacles[i]->setVelocityY(3);
    }
    while(isRunning){

        refreshFrame();

        eventLoop();

        player.DrawCircle(renderer, true);
        for(int i =0; i<Obstacles.size();i++){
            if(Obstacles[i]->getCorner().x>=750) {Obstacles[i]->setVelocityX(-1*rand()%6+1);}
            if(Obstacles[i]->getCorner().y>=750){ Obstacles[i]->setVelocityY(-1*rand()%6+1);}
            if(Obstacles[i]->getCorner().x<=0) {Obstacles[i]->setVelocityX(rand()%6+1);}
            if(Obstacles[i]->getCorner().y<=0){ Obstacles[i]->setVelocityY(rand()%6+1);}
        }
        for(int i =0; i<Obstacles.size();i++){
            double velocityx = Obstacles[i]->getVelocityX();
            double velocityy = Obstacles[i]->getVelocityY();
            Obstacles[i]->Translation(Obstacles[i]->getCorner().x+velocityx,
                                      Obstacles[i]->getCorner().y+velocityy);
            Obstacles[i]->DrawRectangle(renderer,true);
        }
        for(int i =0; i<Obstacles.size();i++)
        {
                if(player.GetMidX()>Obstacles[i]->getCorner().x&&player.GetMidX()<Obstacles[i]->getCorner().x+50){
                    if (player.Colision(Line(Obstacles[i]->getA(), Obstacles[i]->getD()))) gameOver = true;
                    if(player.Colision(Line(Obstacles[i]->getB(),Obstacles[i]->getC()))) gameOver = true;
                }
                if(player.GetMidY()>Obstacles[i]->getCorner().y)
                if (player.Colision(Line(Obstacles[i]->getA(), Obstacles[i]->getB()))) gameOver = true;


                if(player.Colision(Line(Obstacles[i]->getD(),Obstacles[i]->getC()))) gameOver = true;




        }

        while(gameOver){
            eventLoop();
        }

        SDL_Delay(20);

    }


}

void Engine::terminate(){
    isRunning = false;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    for(int i = 0;i<Obstacles.size();i++){
        delete Obstacles[i];
    }
    SDL_Quit();

}

void Engine::refreshFrame() {
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderClear(renderer);
}

void Engine::eventLoop() {
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
                if(!gameOver)player.Translation(event.motion.x, event.motion.y);
                break;


        }
    }
}

