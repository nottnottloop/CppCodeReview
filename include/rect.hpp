#pragma once

#include <SDL2/SDL_image.h>

class rectangle
{
public:
    rectangle(float p_x, float p_y, float p_w, float p_h);
    bool detect(rectangle& p_rect);
    
    float x, y, w, h;
    SDL_Rect rect;
};