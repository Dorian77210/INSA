#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphic-element.h"
#include "coordinate.h"

GraphicElement* create_graphic_element(const char* path, int x, int y, int w, int h) {
    GraphicElement* element;
    SDL_Surface* background;
    SDL_Rect* rect;

    // load the background image
    background = IMG_Load(path);
    if(!background) {
        fprintf(stderr, "Error when loading the image %s : %s \n", path, IMG_GetError());
        return NULL;
    }

    // create and init the rect
    rect = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    if(!rect) {
        fprintf(stderr, "Error during the creation of the rectangle \n");
        return NULL;
    }

    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;

    element = (GraphicElement*)malloc(sizeof(GraphicElement));
    if(!element) {
        fprintf(stderr, "Error during mallocing for the creation of graphic element \n");
        return NULL;
    }

    element->background = background;
    element->rect = rect;

    return element;
}

void delete_graphic_element(GraphicElement* element) {
    SDL_FreeSurface(element->background);
    free(element->rect);
    free(element);
}

int is_clicking(const GraphicElement* element, const GraphicCoordinate coords) {
    if((coords.x < element->rect->x) || (coords.x > element->rect->x + element->rect->w)) return 0;
    if((coords.y < element->rect->y) || (coords.y > element->rect->y + element->rect->h)) return 0;

    return 1;
}

int blit_graphic_element(SDL_Surface* window, const GraphicElement* element) {
    int result = SDL_BlitSurface(element->background, NULL, window, element->rect);

    if(result != 0) {
        fprintf(stderr, "Error during blitting the surface : %s \n", SDL_GetError());
        return 0;
    }

    return 1;
}