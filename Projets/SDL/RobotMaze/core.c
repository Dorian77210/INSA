#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "core.h"
#include "window.h"

void init_app() {
    SDL_Init(SDL_INIT_VIDEO);
    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int initted=IMG_Init(flags);
}

SDL_Window* create_window() {
    SDL_Window* window;
    window = SDL_CreateWindow(APP_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_CONFIGURATION);

    if(!window) {
        fprintf(stderr, "Error when creating the window : %S \n", SDL_GetError());
        return NULL;
    }

    return window;
}