#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "game.h"
#include "player.h"
#include "level.h"
#include "coordinate.h"

Game* load_game() {
    Level** levels, *level;
    Player* player;
    Game* game;
    BoardCoordinate coords;
    int i;
    char sprite_type, *buffer;

    game = (Game*)malloc(sizeof(Game));
    levels = (Level**)malloc(NUMBER_OF_MAPS * sizeof(Level*));
    
    if(!levels) {
        fprintf(stderr, "Error when mallocing the levels \n");
        return NULL;
    }

    if(!game) {
        fprintf(stderr, "Error when mallocing for the game \n");
        return NULL;
    }

    for(i = 0; i < NUMBER_OF_MAPS; i++) {
        level = load_level(i + 1);
        if(!level) {
            fprintf(stderr, "Error during loading of the game because the level number %d \n", i);
            free(levels);
            return NULL;
        }
    }

    game->current_level = 0;
    game->player = create_player(levels[0]->initial_player_coords, INITIAL_LIFES);
    if(!game->player) {
        fprintf(stderr, "Error when creating the player \n");
        delete_game(game);
        return NULL;
    }

    game->levels = levels;

    return game;
}

Game* load_game_from(int current_level) {

    return NULL;
}

void delete_game(Game* game) {
    int i;

    for(i = 0; i < NUMBER_OF_MAPS; i++) {
        delete_level(game->levels[i]);
    }

    free(game->levels);
    free_player(game->player);
    free(game);
}

void blit_game(Game* game, SDL_Surface* window) {
    int i;
    Sprite* sprite;
    Level* current_level;

    current_level = game->levels[game->current_level];
    int result;

    for(i = 0; i < SPRITES_BY_LEVELS; i++) {
        sprite = current_level->sprites[i];
        // result = SDL_BlitSurface(sprite->surface, NULL, window, sprite->rect);
        // if(result != 0) {
            // fprintf(stderr, "Error when displaying sprites \n");
        // }
    }
}