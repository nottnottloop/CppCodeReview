#pragma once

#include <SDL2/SDL_image.h>
#include "rect.hpp"

bool pointRectCollison(Rectangle& p_rect, int p_x, int p_y);


bool rectToRectColl(Rectangle& rectA, Rectangle& rectB);


bool rectSideColl(Rectangle& mainRect, Rectangle& checkRect, int side);


bool rectListColl(Rectangle& mainRect, std::vector<Rectangle> &list, int side);
