#ifndef MAINLOOP_H
#define MAINLOOP_H

#include <SDL2/SDL.h>

void gameInit();
void mainRun(SDL_Renderer *mainRenderer, SDL_Renderer *terminalRenderer);

#endif
