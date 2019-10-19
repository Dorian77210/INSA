#ifndef HOME_VIEW_H
#define HOME_VIEW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphic-element.h"

// quit path and dimension
#define QUIT_APP_IMAGE_PATH "./rsc/img/quit.bmp"
#define QUIT_APP_WIDTH 400
#define QUIT_APP_HEIGHT 150
#define QUIT_APP_X 100
#define QUIT_APP_Y 25

// new game path and dimension
#define NEW_GAME_IMAGE_PATH "./rsc/img/new-game.bmp"
#define NEW_GAME_IMAGE_WIDTH 400
#define NEW_GAME_IMAGE_HEIGHT 150
#define NEW_GAME_IMAGE_X 100
#define NEW_GAME_IMAGE_Y 200

// take back path and dimension
#define TAKE_BACK_IMAGE_PATH "./rsc/img/take-back.bmp"
#define TAKE_BACK_IMAGE_WIDTH 400
#define TAKE_BACK_IMAGE_HEIGHT 150
#define TAKE_BACK_IMAGE_X 100
#define TAKE_BACK_IMAGE_Y 375

// home bacground path and dimension
#define HOME_BACKGROUND_IMAGE_PATH "./rsc/img/forest.bmp"
#define HOME_BACKGROUND_WIDTH 600
#define HOME_BACKGROUND_HEIGHT 600


typedef struct {
    GraphicElement* background;
    GraphicElement* quit_button;
    GraphicElement* take_back_button;
    GraphicElement* new_game;
    int has_save;
} HomeView;

HomeView* init_home_view();
void free_home_view(HomeView* home_view);
int blit_home_view(SDL_Surface* window, const HomeView* home_view);
int refresh_home_view(HomeView* home_view);

#endif