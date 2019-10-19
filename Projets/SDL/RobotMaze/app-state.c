#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "app-state.h"
#include "window-controller.h"
#include "game.h"

AppState home_state(SDL_Window* window) {
    // variables for the rest of the home logic
    SDL_Event event;
    ClickTarget click_target;

    HomeView* view = init_home_view();
    if(!view) {
        return UNDEFINED_STATE;
    }

    HomeController* controller = create_home_controller(view->quit_button, view->new_game, view->take_back_button);

    if(!controller) {
        return UNDEFINED_STATE;
    }

    while(1) {
        // poll any events
        if(SDL_PollEvent(&event)) {
            if(is_close_window_event(window, &event)) {
                free_home(view, controller);
                return QUIT_STATE;
            } else {
                // click event
                click_target = proceed_event(controller, &event);
                if(click_target == QUIT_BUTTON_CLICKING) {
                    free_home(view, controller);
                    return QUIT_STATE;
                } else if(click_target == NEW_GAME_CLICKING) {
                    free_home(view, controller);
                    return GAME_STATE;
                }
            }
        }

        blit_home_view(SDL_GetWindowSurface(window), view);
        SDL_UpdateWindowSurface(window);
    }

    return QUIT_STATE;
}

void free_home(HomeView* view, HomeController* controller) {
    free_home_view(view);
    free_home_controller(controller);
}

AppState game_state(SDL_Window* window) {
    Game* game;
    SDL_Event event;

    game = load_game();

    if(!game) return QUIT_STATE;

    blit_game(game, SDL_GetWindowSurface(window));

    while(1) {
        // poll any events
        if(SDL_PollEvent(&event)) {
            if(is_close_window_event(window, &event)) {
                delete_game(game);
                return QUIT_STATE;
            }
        }

        // SDL_UpdateWindowSurface(window);
    }

    return QUIT_STATE; 
}