#include "terminalDraw.h"
#include "mainLoop.h"
#include "globalHeader.h"
#include "mainDraw.h"
#include "textures.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

void terminalDisplay(){
    for(int i = 0; i < 36; i++){
        for(int j = 0;j < 18; j++){
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
            renderTexture(tex, terminalRenderer, letterSize*j, letterSize*(i+1), letterSize, letterSize);
            SDL_UpdateWindowSurface(terminalWindow);
            SDL_RenderPresent(terminalRenderer);
        }
    }
}
