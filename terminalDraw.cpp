#include "terminalDraw.h"
#include "mainLoop.h"
#include "globalHeader.h"
#include "mainDraw.h"
#include "textures.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

int terminalI = 0;
int terminalJ = 0;

void terminalDisplay(){

    std::string input = "";
    std::string char_directory = "";
    std::cin >> input;
    if(input == ","){
        char_directory = "./assets/comma.bmp";
    }
    else{
        char_directory = "./assets/" + input + ".bmp";
    }
    const char *cstar = char_directory.c_str();
    SDL_Texture* tex = loadTexture(cstar, terminalRenderer);
    renderTexture(tex, terminalRenderer, letterSize*terminalJ, letterSize*(terminalI+1), letterSize, letterSize);
    SDL_UpdateWindowSurface(terminalWindow);
    SDL_RenderPresent(terminalRenderer);
    terminalJ++;
    if(terminalJ > 17){
        terminalI++;
        terminalJ = 0;
        if(terminalI > 35){
            terminalI = 0;
        }
    }
}
