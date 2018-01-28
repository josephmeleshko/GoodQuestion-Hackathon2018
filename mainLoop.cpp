#include "mainLoop.h"
#include "globalHeader.h"
#include "levels.h"
#include "mainDraw.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "gametick.h"
#include "terminalDraw.h"
#include "input_parser.h"
#include <stdio.h>
#include <string>
#include <fstream>

bool quit;
bool isPlaying;
bool walkingRight;
int charX;
int charY;
int *activeLevel;
int *levelPointer;

void gameInit() {
    quit = false;
    isPlaying = true;
    walkingRight = true;
    charX = 0;
    charY = 0;
    SDL_UpdateWindowSurface(mainWindow);
    SDL_UpdateWindowSurface(terminalWindow);
    drawBackground();
    activeLevel = nullData();
    levelPointer = level0data();
    for (int i = 0; i < 527; i++) {activeLevel[i] = levelPointer[i];}
    drawScreen(activeLevel);
}

void mainRun() {
    gameInit();
    //Event handler
    SDL_Event e;
    bool terminalFocus = true;
    bool editTab = false;
    bool terminalTab = true;
    SDL_StartTextInput();
    std::string text = "";

    while (!quit) {
        //terminalDisplay();
        //Handle events on queue
        gametick();
        while( SDL_PollEvent( &e ) != 0 ) {
            gametick();
            //User requests quit
            switch (e.type){
                case SDL_QUIT:
                case SDL_WINDOWEVENT_CLOSE:
                quit = true;
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
                                editTab = true;
                                terminalTab = false;
                                terminalWipe();
                            }
                            else if( ( x > 180 ) && ( x < 360 ) && ( y > 0 ) && ( y < 40 ) ) {
                                //Set the button sprite
                                //clip = &clips[ CLIP_MOUSEDOWN ];
                                editTab = false;
                                terminalTab = true;
                                terminalWipe();
                            }
                        }
                    }
                break;

                case SDL_TEXTINPUT:
                case SDL_KEYDOWN:
                if (terminalFocus){
                    if(terminalTab) {
                        //Handle backspace
                        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0) {
                            text.pop_back();
                            terminalDisplay('\b');
                        }
                        //Handle Return
                        else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN && text.length() > 0) {
                            text += '\n';
                            terminalDisplay('\n');
                            if (terminalTab) {
                                parse_terminal_input();
                                text = "";
                            }
                        }
                        //Handle text
                        if (e.type == SDL_TEXTINPUT) {
                            text += e.text.text;
                            terminalDisplay(text[text.length()-1]);
                        }
                        std::ofstream file("input.txt");
                        if (!file) {
                            std::cerr << "can't open output file" << std::endl;
                        }
                        file << text;
                        file.flush();
                        file.close();
                    }
                    if(editTab) {
                        //Handle backspace
                        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0) {
                            text.pop_back();
                            terminalDisplay('\b');
                        }
                        //Handle Return
                        else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN && text.length() > 0) {
                            text += '\n';
                            terminalDisplay('\n');
                        }
                        //Handle text
                        if (e.type == SDL_TEXTINPUT) {
                            text += e.text.text;
                            terminalDisplay(text[text.length()-1]);
                        }
                        std::ofstream editorFile("editor.txt");
                        if (!editorFile) {
                            std::cerr << "can't open output file" << std::endl;
                        }
                        editorFile << text;
                        editorFile.flush();
                        editorFile.close();
                    }
                }
                break;
            }
        }
    }
    SDL_StopTextInput();
}
