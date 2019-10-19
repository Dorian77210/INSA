#include <stdlib.h>
#include <SDL2/SDL.h>

#include "window-controller.h"

int is_close_window_event(SDL_Window* window, SDL_Event* event) {
    if(event->type == SDL_WINDOWEVENT) {
        if(event->window.event == SDL_WINDOWEVENT_CLOSE) {
            printf("Close game \n");
            return 1;    
        }
    }
    
    return 0;
}