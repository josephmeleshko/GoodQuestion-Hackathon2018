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
int savedLines = 0;

void terminalDisplay(char input){
        //std::string input_char = std::to_string(input);

        std::cout << input << std::endl;
        std::string char_directory = "./assets/_.bmp";
        if(input == ','){
            char_directory = "./assets/comma.bmp";
        }
        else if(input == ' '){
            char_directory = "./assets/space.bmp";
        }
        else{
            char_directory[9] = input;
        }
        const char *cstar = char_directory.c_str();
        SDL_Texture* tex = loadTexture(cstar, terminalRenderer);
        renderTexture(tex, terminalRenderer, letterSize*terminalJ, letterSize*(terminalI+1), letterSize, letterSize);
        SDL_UpdateWindowSurface(terminalWindow);
        SDL_RenderPresent(terminalRenderer);
        terminalJ++;
        if(input == '\b'){
            terminalJ-=2;
            std::cout << "we are here" << std::endl;
            std::string temp = "./assets/space.bmp";
            const char *cstar = temp.c_str();
            SDL_Texture* tex = loadTexture(cstar, terminalRenderer);
            renderTexture(tex, terminalRenderer, letterSize*terminalJ, letterSize*(terminalI+1), letterSize, letterSize);
            SDL_UpdateWindowSurface(terminalWindow);
            SDL_RenderPresent(terminalRenderer);

        }

        if(terminalJ > 17){
            terminalI++;
            terminalJ = 0;
            if(terminalI > 35){
                terminalI = 0;
            }
        }
    //while(true){}

}
