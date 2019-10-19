#ifndef GRAPHIC_ELEMENT_H
#define GRAPHIC_ELEMENT_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

#include "coordinate.h"

struct GraphicElement {
    SDL_Surface* background;
    SDL_Rect* rect;
};

typedef struct GraphicElement GraphicElement;

GraphicElement* create_graphic_element(const char* path, int x, int y, int w, int h);
void delete_graphic_element(GraphicElement* element);
int is_clicking(const GraphicElement* element,  const GraphicCoordinate coords);
int blit_graphic_element(SDL_Surface* window, const GraphicElement* element);

#endif