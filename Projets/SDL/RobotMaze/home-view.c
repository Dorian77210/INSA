#include <SDL2/SDL_image.h>

#include "home-view.h"
#include "progress.h"
#include "graphic-element.h"

HomeView* init_home_view() {
    HomeView* home_view;
    GraphicElement* quit_button, *take_back_button, *new_game, *background;
    
    home_view = (HomeView*)malloc(sizeof(HomeView));
    if(!home_view) {
        fprintf(stderr, "Error when creating the home view \n");
        return NULL;
    }

    // verify if the save exists to initialize the take back button
    if(!refresh_home_view(home_view)) {
        fprintf(stderr, "Error during refresh the home view \n");
        return NULL;
    }

    // TODOD
    quit_button = create_graphic_element(QUIT_APP_IMAGE_PATH, QUIT_APP_X, QUIT_APP_Y,
    QUIT_APP_WIDTH, QUIT_APP_HEIGHT);
    new_game = create_graphic_element(NEW_GAME_IMAGE_PATH, NEW_GAME_IMAGE_X, NEW_GAME_IMAGE_Y, 
    NEW_GAME_IMAGE_WIDTH, NEW_GAME_IMAGE_HEIGHT);
    background = create_graphic_element(HOME_BACKGROUND_IMAGE_PATH, 0, 0, 
    HOME_BACKGROUND_WIDTH, HOME_BACKGROUND_HEIGHT);

    if(!quit_button || !new_game || !background) {
        fprintf(stderr, "Error when loading one of the graphic elements \n");
        return NULL;
    }

    home_view->quit_button = quit_button;
    home_view->new_game = new_game;
    home_view->background = background;

    return home_view;
}

void free_home_view(HomeView* home_view) {
    // delete all of the graphics element of the home_view
    delete_graphic_element(home_view->quit_button);
    delete_graphic_element(home_view->new_game);
    if(home_view->take_back_button) {
        delete_graphic_element(home_view->take_back_button);
    }

    free(home_view);
}

int refresh_home_view(HomeView* home_view) {
    GraphicElement* take_back_button = NULL;
    // verify if the save exists to initialize the take back button
    if(save_exists()) {
        home_view->has_save = 0x1;
        take_back_button = create_graphic_element(TAKE_BACK_IMAGE_PATH, 0, 0, 0, 0);
        if(!take_back_button) {
            fprintf(stderr, "Error when creating the take back button \n");
            return 0;
        }
    } else {
        home_view->take_back_button = take_back_button;
        home_view->has_save = 0x0;
        home_view->take_back_button = NULL;
    }   

    return 1;
}

int blit_home_view(SDL_Surface* window, const HomeView* home_view) {
    if(!blit_graphic_element(window, home_view->background) 
    || !blit_graphic_element(window, home_view->quit_button)
    || !blit_graphic_element(window, home_view->new_game)
    ) { 
        fprintf(stderr, "Error when blitting element on the home view \n");
        return 0;
    }

    if(home_view->has_save && !blit_graphic_element(window, home_view->take_back_button)) {
        fprintf(stderr, "Error when blitting the take back button element on the home view \n");
        return 0;
    }

    return 1;
}