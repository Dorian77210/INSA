#ifndef APP_STATE_H
#define APP_STATE_H

#include <SDL2/SDL.h>

#include "home-view.h"
#include "home-controller.h"

typedef enum { HOME_STATE, GAME_STATE, QUIT_STATE, UNDEFINED_STATE } AppState;

AppState home_state(SDL_Window* window);
AppState game_state(SDL_Window* window);
void free_home(HomeView* view, HomeController* controller);

#endif