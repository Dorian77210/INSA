#include <stdio.h>
#include <stdlib.h>

#include "progress.h"
#include "coordinate.h"

int save_exists() {
    FILE* file;

    file = fopen(SAVE_FILE, "r");
    if(!file) {
        return 0;
    }

    fclose(file);

    return 1;
}

int save(int current_level, Player player) {
    FILE* outfile;
    size_t bytes_read;

    outfile = fopen(SAVE_FILE, "w");
    if(!outfile) {
        fprintf(stderr, "Error when opening the file %s for the save \n", SAVE_FILE);
        return 0;
    }

    bytes_read = fwrite(&current_level, sizeof(int), 1, outfile);
    if(bytes_read != sizeof(int)) {
        fprintf(stderr, "Error when writing the current level for the save \n");
        fclose(outfile);
        return 0;
    }

    if(fwrite(&player.coords.x, 1, 1, outfile) != 1
    || fwrite(&player.coords.y, 1, 1, outfile) != 1
    ) {
        fprintf(stderr, "Error when writing the coords in the file %s \n", SAVE_FILE);
        fclose(outfile);
        return 0;
    }

    if(fwrite(&player.lifes, sizeof(player.lifes), 1, outfile) != 1) {
        fprintf(stderr, "Error when writing the number of life in the file %s \n", SAVE_FILE);
        fclose(outfile);
        return 0;
    }

    return 1;
}

Progress* load() {
    FILE* file;
    Player* player;
    BoardCoordinate coords;
    Progress* progress;
    int current_level;

    file = fopen(SAVE_FILE, "r");
    if(!file) {
        fprintf(stderr, "Error when opengin the file %s \n", SAVE_FILE);
        return NULL;
    }

    player = (Player*)malloc(sizeof(Player));
    if(!player) {
        fprintf(stderr, "Error during malloc for the player \n");
        return NULL;
    }

    progress = (Progress*)malloc(sizeof(Progress));
    if(!progress) {
        fprintf(stderr, "Error during malloc for the progress \n");
    }

    // load the x coordinate
    if(fread(&coords.x, 1, 1, file) != 1) {
        fprintf(stderr, "Error during the reading of the x coordinate \n");
        free(player);
        fclose(file);
        return NULL;
    } 

    // load the y coordinate
    if(fread(&coords.y, 1, 1, file) != 1) {
        fprintf(stderr, "Error during the readinf of the y coordinate \n");
        free(player);
        fclose(file);
        return NULL;
    }

    // read the current level
    if(fread(&current_level, sizeof(int), 1, file) != sizeof(int)) {
        fprintf(stderr, "Error during the reading of the current level index \n");
        free(player);
        fclose(file);
        return NULL;
    }

    // read the number of life for the player
    if(fread(&player->lifes, sizeof(byte), 1, file) != sizeof(byte)) {
        
    }


    player->coords = coords;
    progress->current_level = current_level;
    progress->player = player;

    return progress;
}