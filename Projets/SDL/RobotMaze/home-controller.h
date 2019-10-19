#ifndef HOME_CONTROLLER_H
#define HOME_CONTROLLER_H

#include <SDL2/SDL.h>

#include "graphic-element.h"

typedef struct {
    GraphicElement* quit_button;
    GraphicElement* new_game;
    GraphicElement* take_back_button;
    int has_take_back;
} HomeController;

typedef enum { QUIT_BUTTON_CLICKING, NEW_GAME_CLICKING, TAKE_BACK_BUTTON_CLICKING, NO_ELEMENT_CLICKING, INVALID_CLICK_TARGET } ClickTarget;

ClickTarget proceed_event(const HomeController* home_controller, const SDL_Event* event);
ClickTarget who_is_clicking(const HomeController* home_controller, const GraphicCoordinate coords);
void free_home_controller(HomeController* home_controller);
HomeController* create_home_controller(GraphicElement* quit_button, GraphicElement* new_game, GraphicElement* take_back_button);

#endif