#pragma once

#include <SDL2/SDL_image.h>
#include "window.hpp"

class rectangle
{
public:
    rectangle(float p_x, float p_y, float p_w, float p_h);
    bool detect(rectangle& p_rect);
    
    float x, y, w, h;
    SDL_Rect rect;
};

rectangle::rectangle(float p_x, float p_y, float p_w, float p_h)
:x(p_x), y(p_y), w(p_w), h(p_h)
{
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

bool rectangle::detect(rectangle& p_rect)
{
    //SDL_GetMouseState(&Xt, &Yt);

    int pX = p_rect.x;
    int pY = p_rect.y;

    if (pX >= x && pX <= (x + w) && pY >= y && pY <= (y + h))
    {
        return true;

    } 
    else
        return false;

    
}