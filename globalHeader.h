#ifndef GLOBALHEADER_H
#define GLOBALHEADER_H

#include <SDL2/SDL.h>

extern bool quit;
extern int blockSize;
extern SDL_Window* mainWindow;
extern SDL_Window* terminalWindow;
extern SDL_Surface* mainSurface;
extern SDL_Surface* terminalSurface;
extern SDL_Renderer* mainRenderer;
extern SDL_Renderer* terminalRenderer;
extern int *activeLevel;

#endif
