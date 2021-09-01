#pragma once

#include <SDL2/SDL_image.h>
#include "window.hpp"
#include "rect.hpp"

Rectangle::Rectangle(float p_x, float p_y, float p_w, float p_h)
:x(p_x), y(p_y), w(p_w), h(p_h)
{
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

bool Rectangle::detect(Rectangle& p_rect)
{
    //SDL_GetMouseState(&Xt, &Yt);

    //int pX = p_rect.x;
    //int pY = p_rect.y;

    if (p_rect.x >= x && p_rect.x <= (x + w) && p_rect.y >= y && p_rect.y <= (y + h))
    {
        return true;
    } 
    else
        return false;

    
}