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


windowApp::windowApp()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);



    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);


}

windowApp::~windowApp()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

void windowApp::render(rectangle& p_rect)
{
    SDL_RenderFillRect(renderer, &p_rect.rect);
}

void windowApp::display()
{
    SDL_RenderPresent(renderer);
}

void windowApp::clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
}

void windowApp::renderEverything(std::vector<rectangle> &rects)
{
    for (std::size_t i = 0, max = rects.size(); i < max; i++)
    {
        SDL_RenderFillRect(renderer, &rects[i].rect);
    }

}
    
    
    
