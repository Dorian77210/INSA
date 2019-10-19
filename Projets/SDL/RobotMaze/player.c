#include <stdlib.h>

#include "player.h"
#include "level.h"
#include "coordinate.h"
#include "action.h"

Player* create_player(BoardCoordinate coords, byte lifes) {
    Sprite* sprite;
    Player* player;

    player = (Player*)malloc(sizeof(Player));
    if(!player) {
        fprintf(stderr, "Error when creating the player \n");
        return NULL;
    }

    sprite = create_sprite(PLAYER_IMAGE_PATH, coords.x, coords.y);
    if(!sprite) {
        fprintf(stderr, "Error when creating the sprite of the player \n");
        free(player);
        return NULL;
    }


    player->coords = coords;
    player->lifes = lifes;
    player->sprite = sprite;

    return player;
}

void move(Player* player, PlayerAction action) {
    if(action == UP) {
        if(player->coords.y > 0 && player->coords.y < SPRITE_BY_COLUMN) {
            player->coords.y--;
        }
    } else if(action == RIGHT) {
        if(player->coords.x > 0 && player->coords.x < SPRITE_BY_LINE) {
            player->coords.x++;
        }
    } else if(action == DOWN) {
        if(player->coords.y > 0 && player->coords.y < SPRITE_BY_COLUMN) {
            player->coords.y++;
        }
    } else if(action == LEFT) {
        if(player->coords.x > 0 && player->coords.x < SPRITE_BY_LINE) {
            player->coords.x--;
        }
    }
}

void free_player(Player* player) {
    free(player->sprite);
    free(player);
}