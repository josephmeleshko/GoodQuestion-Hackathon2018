#include "mainLoop.h"
#include "globalHeader.h"
#include <SDL2/SDL.h>
#include <iostream>

void gameInit() {
    SDL_UpdateWindowSurface(mainWindow);
    SDL_UpdateWindowSurface(terminalWindow);
    SDL_FillRect(mainSurface, NULL, SDL_MapRGB(mainSurface->format, 255, 255, 255));
    SDL_FillRect(terminalSurface, NULL, SDL_MapRGB(terminalSurface->format, 0, 0, 0));
    SDL_UpdateWindowSurface(mainWindow);
    SDL_UpdateWindowSurface(terminalWindow);
    quit = false;
}

void mainRun() {
    gameInit();
    //Event handler
    SDL_Event e;

    SDL_StartTextInput();
    std::string text = "";

    while (!quit) {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ) {
            //User requests quit
            std::cout << e.type;
            switch (e.type){
              case SDL_QUIT:
                quit = true;
                std::cout<< "You made it to quit";
                break;
              case SDL_KEYDOWN:
              case SDL_TEXTINPUT:
                if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0)
                  text = text.substr(0, text.length()-1);
                else if (e.type == SDL_TEXTINPUT)
                  text += e.text.text;
                break;
            }
            std::cout << text << std::endl;
        }
    }
    std::cout << "You made it out of !quit loop";
}
