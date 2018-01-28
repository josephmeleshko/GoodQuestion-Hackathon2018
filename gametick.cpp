#include "gametick.h"
#include "globalHeader.h"
#include "textures.h"
#include "mainDraw.h"
#include "levels.h"
#include <SDL2/SDL.h>
#include "mainDraw.h"
#include "input_parser.h"
#include <iostream>

int lastTickTime = 0;

int getSpace(int x, int y) {
    if (x > 31 || x < 1 || y > 17 || y < 1) {
        std::cout << "out of bounds" << std::endl;
        return -1;
    }
    else {
        return activeLevel[(((17-y)*31) + (x-1))];
    }
}

void changeSpace(int x, int y, int value) {
    if (x > 31 || x < 1 || y > 17 || y < 1) {
        std::cout << "out of bounds" << std::endl;
    }
    activeLevel[(((17-y)*31) + (x-1))] = value;
}

void gametick() {
    if (isPlaying && (SDL_GetTicks() - lastTickTime > tickTime)) {
        lastTickTime = SDL_GetTicks();
        if (getSpace(charX, charY-1) == 0) {
            changeSpace(charX, charY-1, 2);
            changeSpace(charX, charY, 0);
            charY--;
        }
        else if (getSpace(charX, charY-1) == 5 || getSpace(charX, charY-1) == 8) {
            InGameResetFunc();
        }
        else if (walkingRight) {
            if (charX == 31) {
                walkingRight = false;
            }
            else if (getSpace(charX, charY-1) == 7 && getSpace(charX+1, charY-1) == 0) {
                changeSpace(charX+1, charY-1, 2);
                changeSpace(charX, charY, 0);
                charX++;
                charY--;
            }
            else if (getSpace(charX, charY-1) == 7 && getSpace(charX+1, charY-1) == 3) {
                InGameResetFunc();
            }
            else if (getSpace(charX+1, charY) == 0) {
                changeSpace(charX+1, charY, 2);
                changeSpace(charX, charY, 0);
                charX++;
            }
            else if (getSpace(charX+1, charY) == 3) {
                InGameResetFunc();
            }
            else if (getSpace(charX+1, charY) == 4 && getSpace(charX+1, charY+1) == 0) {
                changeSpace(charX+1, charY+1, 2);
                changeSpace(charX, charY, 0);
                charX++;
                charY++;
            }
            else if (getSpace(charX+1, charY) == 4 && getSpace(charX+1, charY+1) == 3) {
                InGameResetFunc();
            }
            else {
                walkingRight = false;
            }
        }
        else {
            if (charX == 1) {
                walkingRight = true;
            }
            else if (getSpace(charX, charY-1) == 4 && getSpace(charX-1, charY-1) == 0) {
                changeSpace(charX-1, charY-1, 2);
                changeSpace(charX, charY, 0);
                charX--;
                charY--;
            }
            else if (getSpace(charX, charY-1) == 4 && getSpace(charX-1, charY-1) == 3) {
                InGameResetFunc();
            }
            else if (getSpace(charX-1, charY) == 0) {
                changeSpace(charX-1, charY, 2);
                changeSpace(charX, charY, 0);
                charX--;
            }
            else if (getSpace(charX-1, charY) == 3) {
                walkingRight = true;
                InGameResetFunc();
            }
            else if (getSpace(charX-1, charY) == 7 && getSpace(charX-1, charY+1) == 0) {
                changeSpace(charX-1, charY+1, 2);
                changeSpace(charX, charY, 0);
                charX--;
                charY++;
            }
            else if (getSpace(charX-1, charY) == 7 && getSpace(charX-1, charY+1) == 3)  {
                InGameResetFunc();
            }
            else {
                walkingRight = true;
            }
        }
        drawScreen(activeLevel);
    }
}
