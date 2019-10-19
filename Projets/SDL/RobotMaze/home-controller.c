#include <stdio.h>
#include <stdlib.h>

#include "coordinate.h"
#include "home-controller.h"

ClickTarget proceed_event(const HomeController* home_controller, const SDL_Event* event) {
    ClickTarget click_target = INVALID_CLICK_TARGET;

    // verify if it is a mouse event
    if(event->type == SDL_MOUSEBUTTONDOWN) {
        // verify if it is a left click
        SDL_MouseButtonEvent mouse_event = event->button;
        if(mouse_event.button == SDL_BUTTON_LEFT) {
            GraphicCoordinate coords;
            coords.x = mouse_event.x;
            coords.y = mouse_event.y;
            click_target = who_is_clicking(home_controller, coords);
        }
    }

    return click_target;
}

ClickTarget who_is_clicking(const HomeController* home_controller, const GraphicCoordinate coords) {
    if(is_clicking(home_controller->new_game, coords)) {
        return NEW_GAME_CLICKING;
    }

    if(is_clicking(home_controller->quit_button, coords)) {
        return QUIT_BUTTON_CLICKING;
    }

    if(home_controller->has_take_back && is_clicking(home_controller->take_back_button, coords)) {
        return TAKE_BACK_BUTTON_CLICKING;
    }

    return NO_ELEMENT_CLICKING;

}

void free_home_controller(HomeController* home_controller) {
    free(home_controller);
}

HomeController* create_home_controller(GraphicElement* quit_button, GraphicElement* new_game, GraphicElement* take_back_button) {
    HomeController* home_controller;

    home_controller = (HomeController*)malloc(sizeof(HomeController));
    if(!home_controller) {
        fprintf(stderr, "Error when creating the home controller \n");
        return NULL;
    }

    home_controller->quit_button = quit_button;
    home_controller->new_game = new_game;
    home_controller->take_back_button = take_back_button;

    return home_controller;
}