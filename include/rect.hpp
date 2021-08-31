#pragma once

#include <SDL2/SDL_image.h>

class Rectangle
{
public:
    Rectangle(float p_x, float p_y, float p_w, float p_h);
    bool detect(Rectangle& p_rect);
    
    float x, y, w, h;
    SDL_Rect rect;
};