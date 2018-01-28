#include "mainDraw.h"
#include "levels.h"
#include "textures.h"
#include "globalHeader.h"
#include <SDL2/SDL.h>

//level needs to be int [17][31] kinda
void drawScreen(int level[]) {
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 31; j++) {
            int value = level[31*i + j];
            SDL_Texture* tex = getTexture(value);
            renderTexture(tex, mainRenderer, blockSize*(j+1), blockSize*(i), blockSize, blockSize);
        }
    }
    SDL_UpdateWindowSurface(mainWindow);
    SDL_RenderPresent(mainRenderer);
}

void drawBackground() {
    SDL_Texture* tex = NULL;
    tex = loadTexture("./assets/bg.bmp", mainRenderer);
    renderTexture(tex, mainRenderer, 0, 0, 1280, 720);
}

void mainDraw() {

}
