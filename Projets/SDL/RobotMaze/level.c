#include <stdio.h>
#include <stdlib.h>

#include "level.h"
#include "sprite.h"

Level* load_level(int current_level) {
    Level* level;
    char path[MAX_PATH_SIZE], *image_path;
    FILE* infile;
    int x, y, i = 0;
    char sprite_type;
    Sprite* sprite;

    snprintf(path, MAX_PATH_SIZE, "%smap%d.dat", BASE_PATH_MAPS, current_level);    
    infile = fopen(path, "r");
    if(!infile) {
        fprintf(stderr, "Error when opening the file %s \n", path);
        return NULL;
    }

    level = (Level*)malloc(sizeof(Level));
    if(!level) {
        fprintf(stderr, "Error when mallocing for the level with name %s\n", path);
        return NULL;
    }

    level->sprites = (Sprite**)malloc(SPRITES_BY_LEVELS * sizeof(Sprite*));
    if(!level->sprites) {
        fprintf(stderr, "Error when mallocing for the sprites \n");
        free(level);
        return NULL;
    }

    level->level_index = current_level;

    for(y = 0; y < SPRITE_BY_COLUMN; y++) {
        for(x = 0; x < SPRITE_BY_LINE; x++) {
            sprite_type = fgetc(infile);
            if(sprite_type == EOF) {
                fprintf(stderr, "Error during reading in the file %s\n", path);
                delete_level(level);
                free(level);
                fclose(infile);
                return NULL;
            }

            if(sprite_type != '\n') {
                if(sprite_type == 'd') {
                    // player sprite
                    level->initial_player_coords.x = x;
                    level->initial_player_coords.y = y;
                } else if(sprite_type != '\n') {
                    image_path = char_to_sprite_path(sprite_type);
                    sprite = create_sprite(image_path, x, y);
                    if(!sprite) {
                        fprintf(stderr, "Error when loading sprites \n");
                        delete_level(level);
                        free(level);
                        fclose(infile);
                        return NULL;
                    }

                    level->sprites[i] = sprite;
                    i++;
                }
            }
        }
    }

    fclose(infile);
    return level;
}

char* char_to_sprite_path(char c) {
    if(c == 'e') return END_GAME_PATH;
    if(c == 'b') return BUSH_PATH;

    return NULL;
}

void delete_level(Level* level) {
    int i;
    for(i = 0; i < SPRITES_BY_LEVELS; i++) {
        free_sprite(level->sprites[i]);
    }

    free(level->sprites);
    free(level);
}