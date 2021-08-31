#pragma once

#include <SDL2/SDL_image.h>
#include "rect.hpp"

bool pointRectCollison(rectangle& p_rect, int p_x, int p_y);


bool rectToRectColl(rectangle& rectA, rectangle& rectB);


bool rectSideColl(rectangle& mainRect, rectangle& checkRect, int side);


bool rectListColl(rectangle& mainRect, std::vector<rectangle> &list, int side);
