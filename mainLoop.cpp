#include "mainLoop.h"
#include "globalHeader.h"
#include "levels.h"
#include "mainDraw.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "gametick.h"
#include "terminalDraw.h"
#include "input_parser.h"
#include "textures.h"
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
int currentLevel;
int tickTime;
std::string filename = "editor.txt";

void gameInit() {
    quit = false;
    isPlaying = false;
    walkingRight = true;
    charX = 0;
    charY = 0;
    currentLevel = 0;
    tickTime = 1000;
    SDL_UpdateWindowSurface(mainWindow);
    SDL_UpdateWindowSurface(terminalWindow);
    drawBackground();
    activeLevel = nullData();
    levelPointer = level0data();
    for (int i = 0; i < 527; i++) {activeLevel[i] = levelPointer[i];}
    drawScreen(activeLevel);
    SDL_Texture* tex = NULL;
    tex = loadTexture("./assets/tab0.bmp", terminalRenderer);
    renderTexture(tex, terminalRenderer, 0, 0, 360, 40);
    SDL_UpdateWindowSurface(terminalWindow);
    SDL_RenderPresent(terminalRenderer);
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

                            //If the mouse is over the edit tab
                            if( ( x > 180 ) && ( x < 360 ) && ( y > 0 ) && ( y < 40 ) ) {
                                editTab = true;
                                terminalTab = false;
                                isPlaying = false;
                                terminalWipe();

                                if (InputFile(filename).length() > 0) {
                                    string base_input = InputFile(filename);

                                    for (int i = 0; i < base_input.length()-1; i++) {
                                        terminalDisplay(base_input[i]);
                                    }
                                }

                                SDL_Texture* tex = NULL;
                                tex = loadTexture("./assets/tab1.bmp", terminalRenderer);
                                renderTexture(tex, terminalRenderer, 0, 0, 360, 40);
                                SDL_UpdateWindowSurface(terminalWindow);
                                SDL_RenderPresent(terminalRenderer);
                            }

                            //If the mouse is over the terminal tab
                            else if( ( x > 0 ) && ( x < 180 ) && ( y > 0 ) && ( y < 40 ) ) {
                                //Set the button sprite
                                //clip = &clips[ CLIP_MOUSEDOWN ];
                                editTab = false;
                                terminalTab = true;
                                terminalWipe();
                                SDL_Texture* tex = NULL;
                                tex = loadTexture("./assets/tab0.bmp", terminalRenderer);
                                renderTexture(tex, terminalRenderer, 0, 0, 360, 40);
                                SDL_UpdateWindowSurface(terminalWindow);
                                SDL_RenderPresent(terminalRenderer);
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

                        std::ofstream editorFile(filename);
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
