#include "coordinate.h"

int to_inline(BoardCoordinate coords, int dimension) {
    return (coords.y * dimension) + (coords.x % dimension);
}

BoardCoordinate to_coordinates(int coords, int dimension) {
    BoardCoordinate c;
    c.y = coords / dimension;
    c.x = coords % dimension;

    return c;
}