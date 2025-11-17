#include "renderer.h"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include "../data/types.h"

const u32 screenHeight = 720;
const u32 screenWidth = 1280;

int allInit(SDL_Window** window, SDL_Renderer** renderer) {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        printf("failed SDL_Init\n");
        return 1;
    }
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("failed IMG_init\n");
        SDL_Quit();
        return 1;
    }
    *window = SDL_CreateWindow(
        "game",
        0,0,
        screenWidth, screenHeight,
        0//SDL_WINDOW_FULLSCREEN_DESKTOP
    );
    if (!*window) {
        printf("failed window init\n");
        printf("%s",SDL_GetError());
        SDL_Quit();
        return 1;
    }
    *renderer = SDL_CreateRenderer(
        *window, -1, SDL_RENDERER_ACCELERATED
    );
    if (!renderer) {
        printf("failed renderer init\n");
        SDL_DestroyWindow(*window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    return 0;
}

SDL_Texture* getImg(SDL_Renderer* renderer, SDL_Window* window, const char* name) {
    SDL_Surface* surface = IMG_Load(name);
    if (!surface) {
        return NULL;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        return NULL;
    }
    return texture;
}

void cleanUp(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}