#pragma once

#include <SDL2/SDL_image.h>
#include <vector>

#include "rect.hpp"

class windowApp
{
private:
    
public:
    windowApp();
    ~windowApp();
    void render(rectangle& p_rect);
    void renderEverything(std::vector<rectangle> &rects);
    void display();
    void clear();

    SDL_Window *window;
    SDL_Renderer *renderer;
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);
};