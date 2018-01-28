#include "mainDraw.h"
#include "levels.h"
#include "textures.h"
#include "globalHeader.h"
#include <SDL2/SDL.h>
#include <string>

void drawScreen(int level[]) {
    drawBackground();
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
    std::string bgnum = "./assets/bg" + std::to_string(currentLevel) + ".bmp";
    tex = loadTexture(bgnum.c_str(), mainRenderer);
    renderTexture(tex, mainRenderer, 0, 0, 1280, 720);

    for (int i = 0; i < 32; i++) {
        SDL_Texture* tex2 = NULL;
        std::string s = std::to_string(i);
        s = "./assets/large" + s + ".bmp";
        const char *cstar = s.c_str();
        tex2 = loadTexture(cstar, mainRenderer);
        renderTexture(tex2, mainRenderer, blockSize*(i), 680, blockSize, blockSize);
    }

    for (int i = 1; i < 18; i++) {
        SDL_Texture* tex3 = NULL;
        std::string s = std::to_string(i);
        s = "./assets/large" + s + ".bmp";
        const char *cstar = s.c_str();
        tex3 = loadTexture(cstar, mainRenderer);
        renderTexture(tex3, mainRenderer, 0, 720-(blockSize*(i+1)), blockSize, blockSize);
    }
}

void mainDraw() {

}
