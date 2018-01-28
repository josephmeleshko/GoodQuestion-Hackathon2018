#include "gametick.h"
#include "globalHeader.h"
#include "textures.h"
#include "mainDraw.h"
#include "levels.h"
#include <SDL2/SDL.h>
#include "mainDraw.h"
#include <iostream>

int lastTickTime = 0;

int getSpace(int x, int y) {
    return activeLevel[(((17-y)*31) + (x-1))];
}

void changeSpace(int x, int y, int value) {
    activeLevel[(((17-y)*31) + (x-1))] = value;
}

void gametick() {
    if (isPlaying && (SDL_GetTicks() - lastTickTime > 200)) {
        lastTickTime = SDL_GetTicks();
        if (getSpace(charX, charY-1) == 0) {
            changeSpace(charX, charY-1, 2);
            changeSpace(charX, charY, 0);
            charY--;
        }
        else if (getSpace(charX+1, charY) == 0) {
            changeSpace(charX+1, charY, 2);
            changeSpace(charX, charY, 0);
            charX++;
        }
        else if (getSpace(charX+1, charY) == 3) {
            changeSpace(charX+1, charY, 2);
            changeSpace(charX, charY, 0);
            charX++;
            activeLevel = nullData();
            levelPointer = level0data();
            for (int i = 0; i < 527; i++) {activeLevel[i] = levelPointer[i];}
            drawScreen(activeLevel);
        }
        drawScreen(activeLevel);
    }
}
