#include "mainLoop.h"
#include "globalHeader.h"
#include <SDL2/SDL.h>

void gameInit() {
    quit = false;
}

void mainRun(SDL_Renderer *mainRenderer, SDL_Renderer *terminalRenderer) {

    gameInit();
    while (!quit) {
        SDL_Delay(5000);
        quit = true;
    }
}
