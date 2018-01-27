#include <SDL2/SDL.h>
#include <iostream>
#include "main2.h"

using namespace std;

const int MAIN_SCREEN_WIDTH = 1280;
const int MAIN_SCREEN_HEIGHT = 720;

const int TERMINAL_WIDTH = 360;
const int TERMINAL_HEIGHT = 720;

const int FRAME_LOCATION_X = 10;
const int FRAME_LOCATION_Y = 100;

const int BLOCK_SIZE = 40;

int main(int argc, const char* argv[]) {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { //Attempt INIT and catch errors
        cout << "SDL_Init Error: " << SDL_GetError() << endl;
        return 1;
    }

    //Build our game window
    SDL_Window* mainWindow = SDL_CreateWindow("Main Game",
                                            FRAME_LOCATION_X,
                                            FRAME_LOCATION_Y,
                                            MAIN_SCREEN_WIDTH,
                                            MAIN_SCREEN_HEIGHT,
                                            SDL_WINDOW_SHOWN);

    //Build our terminal window
    SDL_Window* terminalWindow = SDL_CreateWindow("Terminal",
                                            FRAME_LOCATION_X + MAIN_SCREEN_WIDTH,
                                            FRAME_LOCATION_Y,
                                            TERMINAL_WIDTH,
                                            TERMINAL_HEIGHT,
                                            SDL_WINDOW_SHOWN);

    //Build surfaces and renderer
    SDL_Surface* mainSurface = SDL_GetWindowSurface(mainWindow);
    SDL_Surface* terminalSurface = SDL_GetWindowSurface(terminalWindow);
    SDL_Renderer* mainRenderer = SDL_CreateSoftwareRenderer(mainSurface);
    SDL_Renderer* terminalRenderer = SDL_CreateSoftwareRenderer(terminalSurface);


    SDL_UpdateWindowSurface(mainWindow);
    SDL_UpdateWindowSurface(terminalWindow);
    SDL_FillRect(mainSurface, NULL, SDL_MapRGB(mainSurface->format, 255, 255, 255));
    SDL_FillRect(terminalSurface, NULL, SDL_MapRGB(terminalSurface->format, 0, 0, 0));
    SDL_UpdateWindowSurface(mainWindow);
    SDL_UpdateWindowSurface(terminalWindow);

    SDL_Delay(20000);

    SDL_DestroyWindow(mainWindow);
    SDL_DestroyWindow(terminalWindow);
    SDL_Quit();

    return 0;
}
