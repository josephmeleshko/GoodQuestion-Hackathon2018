#include "mainLoop.h"
#include "globalHeader.h"
#include "levels.h"
#include "mainDraw.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "gametick.h"

bool quit;
bool isPlaying;
int charX;
int charY;
int *activeLevel;

void gameInit() {
    quit = false;
    isPlaying = true;
    charX = 0;
    charY = 0;
    SDL_UpdateWindowSurface(mainWindow);
    SDL_UpdateWindowSurface(terminalWindow);
    drawBackground();
    activeLevel = level0data();
    drawScreen(activeLevel);
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
        gametick();
        while( SDL_PollEvent( &e ) != 0 ) {
            gametick();
            //User requests quit
            switch (e.type){
                case SDL_QUIT:
                case SDL_WINDOWEVENT_CLOSE:
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
                                if( ( x > 0 ) && ( x < 180 ) && ( y > 0 ) && ( y < 20 ) ) {
                                    //Set the button sprite
                                    //clip = &clips[ CLIP_MOUSEDOWN ];
                                    std::cout << "editor" << std::endl;
                                }
                                else if( ( x > 180 ) && ( x < 360 ) && ( y > 0 ) && ( y < 20 ) ) {
                                    //Set the button sprite
                                    //clip = &clips[ CLIP_MOUSEDOWN ];
                                    std::cout << "terminal" << std::endl;
                                }
                            }
                        }
                        break;
                    case SDL_KEYDOWN:
                    case SDL_TEXTINPUT:
                        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0){
                            text = text.substr(0, text.length()-1);
                            //TODO
                        }
                        else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN && text.length() > 0) {

                            text = "";
                            //TODO:
                        }
                        else if (e.type == SDL_TEXTINPUT) {
                            text += e.text.text;
                        }
                        break;
            }
            //std::cout << text << std::endl;
        }
    }
    //std::cout << "You made it out of !quit loop";
}
