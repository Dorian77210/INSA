#ifndef LEVEL_H
#define LEVEL_H

#include "sprite.h"
#include "window.h"
#include "coordinate.h"

#define BASE_PATH_IMAGE "./rsc/img/"
#define BUSH_PATH "./rsc/img/bush.bmp"
#define END_GAME_PATH "./rsc/img/key.bmp"

#define BASE_PATH_MAPS "./rsc/maps/"

#define SPRITE_BY_LINE WINDOW_WIDTH / SPRITE_WIDTH
#define SPRITE_BY_COLUMN WINDOW_HEIGHT / SPRITE_HEIGHT
#define SPRITES_BY_LEVELS SPRITE_BY_LINE * SPRITE_BY_COLUMN

#define NUMBER_OF_MAPS 1
#define MAX_PATH_SIZE 64

struct Level {
    Sprite** sprites;
    int sprites_size;
    BoardCoordinate initial_player_coords;
    int level_index;
};

typedef struct Level Level;

Level* load_level(int current_level);
void delete_level(Level* level);
char* char_to_sprite_path(char c);

#endif