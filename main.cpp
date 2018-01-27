#include <SDL2/SDL.h>
#include <iostream>
#include "main2.h"

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, const char* argv[]) {
    cout << "Main" << endl;
    cout << one() << endl;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    screenSurface = SDL_GetWindowSurface(window);

    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 255, 255));
    SDL_UpdateWindowSurface(window);

    SDL_Delay(2000);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
