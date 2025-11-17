#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>

int allInit(SDL_Window** window, SDL_Renderer** renderer);

SDL_Texture* getImg(SDL_Renderer* renderer, SDL_Window* window, const char* name);

void cleanUp(SDL_Window* window, SDL_Renderer* renderer);