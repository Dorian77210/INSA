#ifndef PROGRESS_H
#define PROGRESS_H

#define SAVE_FILE "rsc/save.dat"

#include "game.h"
#include "level.h"
#include "player.h"

typedef struct {
    Player* player;
    int current_level;
} Progress;

int save_exists();
int save(int current_level, Player player);
Progress* load();

#endif