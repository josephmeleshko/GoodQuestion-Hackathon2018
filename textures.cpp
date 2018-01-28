#include <SDL2/SDL.h>
#include "textures.h"
#include "globalHeader.h"
#include <iostream>

SDL_Texture* getTexture(int value) {
    SDL_Texture* tex = NULL;
    if (value == 0) {
        tex = loadTexture("./assets/emptyBlock.bmp", mainRenderer);
    }
    else if (value == 1) {
        tex = loadTexture("./assets/block.bmp", mainRenderer);
    }
    else if (value == 2) {
        tex = loadTexture("./assets/character.bmp", mainRenderer);
    }
    else if (value == 3) {
        tex = loadTexture("./assets/flag.bmp", mainRenderer);
    }
    else if (value == 4) {
        tex = loadTexture("./assets/slope.bmp", mainRenderer);
    }
    else if (value == 5) {
        tex = loadTexture("./assets/lava.bmp", mainRenderer);
    }
    else if (value == 6) {
        tex = loadTexture("./assets/metalBlock.bmp", mainRenderer);
    }
    return tex;
}

SDL_Texture* loadTexture(const char* file, SDL_Renderer *ren) {
    SDL_Surface* surface = SDL_LoadBMP(file);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, surface);
	return texture;
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h) {
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}
