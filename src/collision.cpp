#pragma once

#include <SDL2/SDL_image.h>
#include <vector>
#include "rect.hpp"

bool pointRectCollison(Rectangle& p_rect, int p_x, int p_y)
{
    //int x, y, w, h;
    //x = p_rect.x;
    //y = p_rect.y;
    //w = p_rect.w;
    //h = p_rect.h;

    if (p_x >= p_rect.x && p_x <= (p_rect.x + p_rect.w) && p_y >= p_rect.y && p_y <= (p_rect.y + p_rect.h))
    {
        return true;
    }
    else
        return false;


}

bool rectToRectColl(Rectangle& rectA, Rectangle& rectB)
{
    //int x, y, w, h;
    //x = rectA.x;
    //y = rectA.y;
    //w = rectA.w;
    //h = rectA.h;

    // int xB, yB, wB, hB;
    // xB = rectB.x;
    // yB = rectB.y;
    // wB = rectB.w;
    // hB = rectB.h;

    if (pointRectCollison(rectB, rectA.x, rectA.y) || pointRectCollison(rectB, rectA.x + rectA.w, rectA.y) || pointRectCollison(rectB, rectA.x, rectA.y + rectA.h) || pointRectCollison(rectB, rectA.x + rectA.w, rectA.y + rectA.h))
    {
        return true;
    }
    else
        return false;
    
}

bool rectSideColl(Rectangle& mainRect, Rectangle& checkRect, int side)
{
    
    //int x, y, w, h;
    //x = mainRect.x;
    //y = mainRect.y;
    //w = mainRect.w;
    //h = mainRect.h;

    //int points[8] {/*TL*/ x, y, /*TR*/x + w, y,/*BR*/ x + w, y + h,/*BL*/ x, y + h};
    
    
    switch (side)
    {
    case 0:
        rectToRectColl(mainRect, checkRect);
        break;
    case 1: //UP TL, TR
        if (pointRectCollison(checkRect, mainRect.x + 1, mainRect.y) || pointRectCollison(checkRect, mainRect.x + mainRect.w - 1, mainRect.y))
        {
            return true;
        }
        else 
            return false;

        break;
    case 2: //RIGHT TR, BR
        if (pointRectCollison(checkRect, mainRect.x + mainRect.w + 0, mainRect.y + 1) || pointRectCollison(checkRect, mainRect.x + mainRect.w + 0, mainRect.y + mainRect.h - 1))
        {
            return true;
        }
        else 
            return false;

        break;
    case 3: //DOWN BL, BR
        if (pointRectCollison(checkRect, mainRect.x + 1, mainRect.y + mainRect.h) || pointRectCollison(checkRect, mainRect.x + mainRect.w - 1, mainRect.y + mainRect.h))
        {
            return true;
        }
        else 
            return false;

        break;
    case 4: //LEFT TL, BL
        if (pointRectCollison(checkRect, mainRect.x - 0, mainRect.y + 1) || pointRectCollison(checkRect, mainRect.x - 0, mainRect.y + mainRect.h - 1))
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

bool rectListColl(Rectangle& mainRect, std::vector<Rectangle> &list, int side)
{
    //for (std::size_t i = 0, max = list.size(); i < max; i++)
    for (int i = 0; i < list.size(); i++)
    {
        
        if (rectSideColl(mainRect, list[i], side))
        {
            return true;
        }

    }
    return false;
    
}