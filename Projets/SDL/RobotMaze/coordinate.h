#ifndef COORDINATE_H
#define COORDINATE_H

#include "common.h"

struct BoardCoordinate {
    byte x;
    byte y;
};

struct GraphicCoordinate {
    int x;
    int y;
};

typedef struct BoardCoordinate BoardCoordinate;
typedef struct GraphicCoordinate GraphicCoordinate;

int to_inline(BoardCoordinate coords, int dimension);
BoardCoordinate to_coordinates(int coords, int dimension);

#endif