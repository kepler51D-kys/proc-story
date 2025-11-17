#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>

#include <stdbool.h>
#include <stdio.h>

#include "../rendering/renderer.hpp"

int main() {

    SDL_Window* window;
    SDL_Renderer* renderer;
    if (allInit(&window, &renderer)) {
        printf("failed init\n");
        return 1;
    }

    SDL_Event e;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
                goto quit;
            }
        }
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }
    quit:
    cleanUp(window,renderer);
    return 0;
}