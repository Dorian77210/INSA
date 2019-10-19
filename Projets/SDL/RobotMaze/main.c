#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "app-state.h"
#include "core.h"

int main(int argc, const char** argv) {
    SDL_Window* window;
    AppState app_state = HOME_STATE; // default state of the application

    init_app();
    window = create_window();

    if(!window) {
        return EXIT_FAILURE;
    }

    while(1) {
        if(app_state == HOME_STATE) {
            app_state = home_state(window);
        } else if(app_state == GAME_STATE) {
            app_state = game_state(window);
        } else if(app_state == QUIT_STATE || app_state == UNDEFINED_STATE) {
            SDL_DestroyWindow(window);
            // other free ?
            break;
        }
    }

    SDL_Quit();
    return EXIT_SUCCESS;
}