#include <SDL2/SDL.h>
#include <iostream>
#include "mainLoop.h"
#include "globalHeader.h"
#include <string>
#include <fstream>

using namespace std;

const int MAIN_SCREEN_WIDTH = 1280;
const int MAIN_SCREEN_HEIGHT = 720;

const int TERMINAL_WIDTH = 360;
const int TERMINAL_HEIGHT = 720;

const int FRAME_LOCATION_X = 10;
const int FRAME_LOCATION_Y = 100;

//stops windows from overlapping
const int FRAME_BUFFER = 40;

int blockSize = 40;
int letterSize = 20;
SDL_Window* mainWindow = NULL;
SDL_Window* terminalWindow = NULL;
SDL_Surface* mainSurface = NULL;
SDL_Surface* terminalSurface = NULL;
SDL_Renderer* mainRenderer = NULL;
SDL_Renderer* terminalRenderer = NULL;

int main(int argc, const char* argv[]) {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { //Attempt INIT and catch errors
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    //Build our game window
    mainWindow = SDL_CreateWindow("Main Game",
                                            FRAME_LOCATION_X,
                                            FRAME_LOCATION_Y,
                                            MAIN_SCREEN_WIDTH,
                                            MAIN_SCREEN_HEIGHT,
                                            SDL_WINDOW_SHOWN);

    //Build our terminal window
    terminalWindow = SDL_CreateWindow("Terminal",
                                            FRAME_LOCATION_X + MAIN_SCREEN_WIDTH + FRAME_BUFFER,
                                            FRAME_LOCATION_Y,
                                            TERMINAL_WIDTH,
                                            TERMINAL_HEIGHT,
                                            SDL_WINDOW_SHOWN);

    //Build surfaces and renderer
    mainSurface = SDL_GetWindowSurface(mainWindow);
    terminalSurface = SDL_GetWindowSurface(terminalWindow);
    mainRenderer = SDL_CreateSoftwareRenderer(mainSurface);
    terminalRenderer = SDL_CreateSoftwareRenderer(terminalSurface);

    mainRun();

    //Once we're out of the main loop close everything
    SDL_DestroyWindow(mainWindow);
    SDL_DestroyWindow(terminalWindow);
    SDL_Quit();

    return 0;
}
