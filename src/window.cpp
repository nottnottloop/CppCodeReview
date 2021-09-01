#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "rect.hpp"
#include "window.hpp"
#include "constants.hpp"

windowApp::windowApp()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED /*| SDL_RENDERER_PRESENTVSYNC <-- would be nice to have this? :thinking:*/);
}

windowApp::~windowApp()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

void windowApp::render(Rectangle& p_rect)
{
    SDL_RenderFillRect(renderer, &p_rect.rect);
}

void windowApp::display()
{
    SDL_RenderPresent(renderer);
}

void windowApp::clear()
{
    colorChange(BLACK);
    SDL_RenderClear(renderer);
}

void windowApp::colorChange(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void windowApp::renderEverything(std::vector<Rectangle> &rects)
{
    for (std::size_t i = 0, max = rects.size(); i < max; i++)
    {
        SDL_RenderFillRect(renderer, &rects[i].rect);
    }

}