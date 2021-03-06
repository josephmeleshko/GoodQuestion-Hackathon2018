#include "terminalDraw.h"
#include "mainLoop.h"
#include "globalHeader.h"
#include "mainDraw.h"
#include "textures.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "input_parser.h"

int terminalI = 0;
int terminalJ = 0;
int savedLines = 0;

void terminalWipe() {
    std::string temp = "./assets/space.bmp";
    const char *cstar = temp.c_str();
    SDL_Texture* tex = loadTexture(cstar, terminalRenderer);

    for(int i = 0; i < 34; i++){
        for(int j = 0; j < 26; j++){
            renderTexture(tex, terminalRenderer, 14*j, letterSize*(i+2), 14, letterSize);
        }
    }
    SDL_DestroyTexture(tex);
    SDL_UpdateWindowSurface(terminalWindow);
    SDL_RenderPresent(terminalRenderer);
    terminalJ = 0;
    terminalI = 0;
}

void terminalDisplay(char input){


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
        renderTexture(tex, terminalRenderer, 14*terminalJ, letterSize*(terminalI+2), 14, letterSize);
        SDL_DestroyTexture(tex);
        SDL_UpdateWindowSurface(terminalWindow);
        SDL_RenderPresent(terminalRenderer);
        terminalJ++;
        if(input == '\b'){

            terminalJ--;

            std::string temp = "./assets/space.bmp";
            const char *cstar = temp.c_str();
            SDL_Texture* tex = loadTexture(cstar, terminalRenderer);
            renderTexture(tex, terminalRenderer, 14*terminalJ, letterSize*(terminalI+2), 14, letterSize);
            SDL_UpdateWindowSurface(terminalWindow);
            SDL_RenderPresent(terminalRenderer);

            terminalJ--;

            renderTexture(tex, terminalRenderer, 14*terminalJ, letterSize*(terminalI+2), 14, letterSize);
            SDL_UpdateWindowSurface(terminalWindow);
            SDL_RenderPresent(terminalRenderer);
            if(terminalJ < 0){
                if(terminalI > 0){
                    string in = InputFile("editor.txt");
                    int count = 0;
                    for (int i = 0; i < in.length() - 2; i++) {
                        count++;
                        if (in[i] == '\n') {
                            count = 0;
                        }
                    }
                    terminalJ = count;
                    terminalI--;
                    renderTexture(tex, terminalRenderer, 14*terminalJ, letterSize*(terminalI+2), 14, letterSize);
                    SDL_UpdateWindowSurface(terminalWindow);
                    SDL_RenderPresent(terminalRenderer);
                }
                else{
                    terminalJ = 0;
                }
            }
            SDL_DestroyTexture(tex);
        }
        else if(input == '\n'){
            if(terminalI != 34){
                terminalI++;
                terminalJ = 0;
            }
            else{
                terminalWipe();
            }
        }

        if(terminalJ > 25){
            terminalI++;
            terminalJ = 0;
            if(terminalI > 33){
                terminalWipe();
            }
        }
        std::string cursor = "./assets/cursor.bmp";
        const char *cursorstar = cursor.c_str();
        SDL_Texture* tex1 = loadTexture(cursorstar, terminalRenderer);
        renderTexture(tex1, terminalRenderer, 14*terminalJ, letterSize*(terminalI+2), 14, letterSize);
        SDL_DestroyTexture(tex1);
        SDL_UpdateWindowSurface(terminalWindow);
        SDL_RenderPresent(terminalRenderer);

}
