#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#include "player.h"
#include "level.h"

struct Game {
    Player* player;
    Level** levels;
    int current_level;
};

typedef struct Game Game;

Game* load_game();
Game* load_game_from(int current_level);
void delete_game(Game* game);
void blit_game(Game* game, SDL_Surface* window);

#endif