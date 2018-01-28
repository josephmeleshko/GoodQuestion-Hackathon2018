#ifndef GLOBALHEADER_H
#define GLOBALHEADER_H

#include <SDL2/SDL.h>

extern bool quit;
extern bool isPlaying;
extern bool walkingRight;
extern int blockSize;
extern int letterSize;
extern SDL_Window* mainWindow;
extern SDL_Window* terminalWindow;
extern SDL_Surface* mainSurface;
extern SDL_Surface* terminalSurface;
extern SDL_Renderer* mainRenderer;
extern SDL_Renderer* terminalRenderer;
extern int *activeLevel;
extern int *levelPointer;
extern int charX;
extern int charY;
extern int terminalI;
extern int terminalJ;

#endif
