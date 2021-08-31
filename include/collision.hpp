#pragma once

#include <SDL2/SDL_image.h>
#include "rect.hpp"

bool pointRectCollison(rectangle& p_rect, int p_x, int p_y)
{
    int x, y, w, h;
    x = p_rect.x;
    y = p_rect.y;
    w = p_rect.w;
    h = p_rect.h;

    if (p_x >= x && p_x <= (x + w) && p_y >= y && p_y <= (y + h))
    {
        return true;
    }
    else
        return false;


}

bool rectToRectColl(rectangle& rectA, rectangle& rectB)
{
    int x, y, w, h;
    x = rectA.x;
    y = rectA.y;
    w = rectA.w;
    h = rectA.h;

    // int xB, yB, wB, hB;
    // xB = rectB.x;
    // yB = rectB.y;
    // wB = rectB.w;
    // hB = rectB.h;

    if (pointRectCollison(rectB, x, y) || pointRectCollison(rectB, x + w, y) || pointRectCollison(rectB, x, y + h) || pointRectCollison(rectB, x + w, y + h))
    {
        return true;
    }
    else
        return false;
    
}

bool rectSideColl(rectangle& mainRect, rectangle& checkRect, int side)
{
    
    int x, y, w, h;
    x = mainRect.x;
    y = mainRect.y;
    w = mainRect.w;
    h = mainRect.h;

    //int points[8] {/*TL*/ x, y, /*TR*/x + w, y,/*BR*/ x + w, y + h,/*BL*/ x, y + h};
    
    
    switch (side)
    {
    case 0:
        rectToRectColl(mainRect, checkRect);
        break;
    case 1: //UP TL, TR
        if (pointRectCollison(checkRect, x + 1, y) || pointRectCollison(checkRect, x + w - 1, y))
        {
            return true;
        }
        else 
            return false;

        break;
    case 2: //RIGHT TR, BR
        if (pointRectCollison(checkRect, x + w + 0, y + 1) || pointRectCollison(checkRect, x + w + 0, y + h - 1))
        {
            return true;
        }
        else 
            return false;

        break;
    case 3: //DOWN BL, BR
        if (pointRectCollison(checkRect, x + 1, y + h) || pointRectCollison(checkRect, x + w - 1, y + h))
        {
            return true;
        }
        else 
            return false;

        break;
    case 4: //LEFT TL, BL
        if (pointRectCollison(checkRect, x - 0, y + 1) || pointRectCollison(checkRect, x - 0, y + h - 1))
        {
            return true;
        }
        else 
            return false;

        break;
    
    default:
        return false;
        break;
    }
    return false;
}

bool rectListColl(rectangle& mainRect, std::vector<rectangle> &list, int side)
{
    for (std::size_t i = 0, max = list.size(); i < max; i++)
    {
        
        if (rectSideColl(mainRect, list[i], side))
        {
            return true;
        }

    }
    return false;
    
}