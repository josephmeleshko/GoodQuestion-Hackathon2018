#include "mainLoop.h"
#include "globalHeader.h"
#include <SDL2/SDL.h>
#include <iostream>

void gameInit() {
    SDL_UpdateWindowSurface(mainWindow);
    SDL_UpdateWindowSurface(terminalWindow);
    SDL_FillRect(mainSurface, NULL, SDL_MapRGB(mainSurface->format, 255, 255, 255));
    SDL_FillRect(terminalSurface, NULL, SDL_MapRGB(terminalSurface->format, 0, 0, 0));
    SDL_UpdateWindowSurface(mainWindow);
    SDL_UpdateWindowSurface(terminalWindow);
    quit = false;
}

void mainRun() {
    gameInit();
    //Event handler
    SDL_Event e;
    while (!quit) {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ) {
            //User requests quit
            std::cout << e.type;
            if( e.type == SDL_QUIT ) {
                quit = true;
                std::cout << "You made it to quit. ";
                break;
            }
        }
    }
    std::cout << "You made it out of !quit loop";
}
