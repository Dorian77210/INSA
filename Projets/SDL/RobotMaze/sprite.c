#include "sprite.h"

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>

Sprite* create_sprite(const char* path, int case_x, int case_y) {
    Sprite* sprite;
    SDL_Surface* surface;
    SDL_Rect* rect;

    surface = IMG_Load(path);
    if(!surface) {
        fprintf(stderr, "Error during the loading of the image %s : %s\n", path, IMG_GetError());
        return NULL;
    }

    sprite = (Sprite*)malloc(sizeof(Sprite));
    if(!sprite) {
        fprintf(stderr, "Error during the creation of sprite \n");
        return NULL;
    }

    rect = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    if(!rect) {
        fprintf(stderr, "Error during mallocing for the surface \n");
        return NULL;
    }

    rect->h = SPRITE_HEIGHT;
    rect->w = SPRITE_WIDTH;
    rect->x = case_x * SPRITE_WIDTH;
    rect->y = case_y * SPRITE_HEIGHT;

    sprite->coords.x = case_x;
    sprite->coords.y = case_y;
    sprite->rect = rect;
    sprite->surface = surface;

    return sprite;
}

void free_sprite(Sprite* sprite) {
    SDL_FreeSurface(sprite->surface);
    free(sprite->rect);
    free(sprite);
}

int is_colliding(Sprite s1, Sprite s2) {
    return (s1.coords.x == s2.coords.x) && (s1.coords.y == s2.coords.y);
}

int is(const Sprite* sprite, sprite_type mask) {
    return (sprite->type & mask);
}

char mask_to_type(sprite_type type) {
    if(type == MOVABLE_TYPE_MASK) {
        return 'c';
    }

    if(type == PLAYER_TYPE_MASK) {
        return 'p';
    }

    if(type == END_TYPE_MASK) {
        return 'e';
    }

    if(type == TRAP_TYPE_MASK) {
        return 't';
    }
}

sprite_type type_to_mask(char type) {
    if(type == 'c') {
        return MOVABLE_TYPE_MASK;
    }

    if(type == 'p') {
        return PLAYER_TYPE_MASK;
    }

    if(type == 'e') {
        return END_TYPE_MASK;
    }

    if(type == 't') {
        return TRAP_TYPE_MASK;
    }
}