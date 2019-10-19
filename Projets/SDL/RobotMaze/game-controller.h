#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <SDL2/SDL_image.h>

#include "player.h"
#include "action.h"

typedef struct {
    Player* player;
} GameController;

void proceed(GameController* game_controller, SDL_Event* event);
PlayerAction touch_to_action(GameController* game_controller, SDL_Event* event);
void free_game_controller(GameController* game_controller);

#endif