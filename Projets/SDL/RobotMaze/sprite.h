#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL_image.h>

#include "coordinate.h"

#define SPRITE_WIDTH 30
#define SPRITE_HEIGHT 30
#define PLAYER_TYPE_MASK 0x1
#define END_TYPE_MASK 0x2
#define TRAP_TYPE_MASK 0x4
#define MOVABLE_TYPE_MASK 0x8

typedef char sprite_type;

struct Sprite {
    SDL_Surface* surface;
    SDL_Rect* rect;
    GraphicCoordinate coords;
    sprite_type type;
};

typedef struct Sprite Sprite;

Sprite* create_sprite(const char* path, int case_x, int case_y);
void free_sprite(Sprite* sprite);
int is_colliding(Sprite s1, Sprite s2);
int is(const Sprite* sprite, sprite_type mask);
char mask_to_type(sprite_type type);
sprite_type type_to_mask(char type);

#endif