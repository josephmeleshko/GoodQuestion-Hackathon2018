#include "mainLoop.h"
#include "globalHeader.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

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
    bool terminalFocus = true;
    SDL_StartTextInput();
    std::string text = "";

    while (!quit) {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ) {
            //User requests quit
            switch (e.type){
                case SDL_QUIT:
                    quit = true;
                    //std::cout<< "You made it to quit";
                    break;
                case SDL_WINDOWEVENT:
                    if (e.window.windowID == SDL_GetWindowID(terminalWindow)){
                        switch(e.window.event){
                            case SDL_WINDOWEVENT_FOCUS_GAINED:
                                terminalFocus = true;
                                break;
                            case SDL_WINDOWEVENT_FOCUS_LOST:
                                terminalFocus = false;
                                break;
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (terminalFocus) {
                        switch (e.button.button) {
                            case SDL_BUTTON_LEFT:
                                int x = e.button.x;
                                int y = e.button.y;

                                //If the mouse is over the button
                                if( ( x > 0 ) && ( x < 180 ) && ( y > 0 ) && ( y < 40 ) ) {
                                    //Set the button sprite
                                    //clip = &clips[ CLIP_MOUSEDOWN ];
                                    std::cout << "editor" << std::endl;
                                }
                                else if( ( x > 180 ) && ( x < 360 ) && ( y > 0 ) && ( y < 40 ) ) {
                                    //Set the button sprite
                                    //clip = &clips[ CLIP_MOUSEDOWN ];
                                    std::cout << "terminal" << std::endl;
                                }
                            }
                        }
                        break;
                case SDL_TEXTINPUT:
                    case SDL_KEYDOWN:
                        //Handle backspace
                        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0) {
                            text.pop_back();
                        }
                        //Handle Return
                        else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN && text.length() > 0) {
                            text += '\n';
                        }
                        //Handle text
                        if (e.type == SDL_TEXTINPUT) {
                        text += e.text.text;
                        
                        }
                    break;
            }
        std::ofstream file("input.txt");
        if (!file) {
            std::cerr << "can't open output file" << std::endl;
        }
        file << text;
        std::cout << text << std::flush;
        file.flush();
        file.close();
        }
    }
    SDL_StopTextInput();
    //std::cout << "You made it out of !quit loop";
}
