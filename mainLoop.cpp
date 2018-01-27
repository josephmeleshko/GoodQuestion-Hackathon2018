#include "mainLoop.h"
#include "globalHeader.h"
#include <SDL2/SDL.h>

void gameInit() {
    quit = false;
}

void mainRun(SDL_Renderer *mainRenderer, SDL_Renderer *terminalRenderer) {
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
        //std::cout << "You made it out of PollEvent loop";
        // SDL_Delay(5000);
        // quit = true;
    }
    std::cout << "You made it out of !quit loop";
}
