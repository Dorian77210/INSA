#ifndef PLAYER_H
#define PLAYER_H

#include "coordinate.h"
#include "sprite.h"
#include "player.h"
#include "action.h"

#define PLAYER_IMAGE_PATH "./rsc/img/droid.bmp"
#define INITIAL_LIFES 5

struct Player {
    BoardCoordinate coords;
    Sprite* sprite;
    byte lifes;
};

typedef struct Player Player;

Player* create_player(BoardCoordinate coords, byte lifes);
void move(Player* player, PlayerAction player_action);
void free_player(Player* player);

#endif