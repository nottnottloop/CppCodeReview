#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "window.hpp"
#include "rect.hpp"
#include "collision.hpp"

//TODO: 
//// Make list of objects, and render them all at once
//* Make it so collison code does !NOT! consider edge collison, but only inside collisions
//> Add gravity
//? Restruct rects to be entitys

int main(int argc, char ** argv){

    windowApp testWindow;

    std::vector<Rectangle> rects = {Rectangle(0, 0, 50, 50),
                                    Rectangle(0, 50, 50, 50),
                                    Rectangle(0, 100, 50, 50),};
    
    
    //> BUILD LEVEL
    
    int tiles[8][8] =
    {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    };
    
    for (size_t y = 0; y < 8; y++)
    {
        size_t x = 0;
        for (x = 0; x < 8; x++)
        {
            //std:: cout << x << ", "<< "\n";
            if (tiles[y][x])
            {
                rects.push_back(Rectangle(x * 50, y * 50, 50, 50));
            }
            
        }
    }
    

    //*Makes main entity
    Rectangle mainEntity(75, 300, 25, 25);

    SDL_SetRenderDrawColor(testWindow.renderer, 0, 0, 255, 255);
    

    


    //>LOOP PREP
    
    bool quit = false;
    SDL_Event event;
    //> MOVEMENT PREP
    float x = mainEntity.x;
    float y = mainEntity.y;

    float yVel = 0.0;
    float grav = 0.01;
    float timeInAir = 0.0;
    float speed = 0.05;


    //> LOOP
    while (!quit)
    {
        SDL_PollEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
        }
        

        //> MOVEMENT

        bool groundTouch = rectListColl(mainEntity, rects, 3);

        if (!groundTouch)
        {
            yVel = yVel + (grav * timeInAir) / 2;
            timeInAir += 0.0001;
        }
        else if (groundTouch){
            yVel = 0.0;
            timeInAir = 0.0;
        }




        if (testWindow.state[SDL_SCANCODE_LEFT])
        {
            if (!rectListColl(mainEntity, rects, 4)){
            x += -speed;
            }
        }
        if (testWindow.state[SDL_SCANCODE_RIGHT])
        {
            if (!rectListColl(mainEntity, rects, 2)){
            x += speed;
            }
        }
        if (testWindow.state[SDL_SCANCODE_UP])
        {
            if (rectListColl(mainEntity, rects, 3)){
            yVel += -1;
            groundTouch = false;
            }
        }
        
        //Going down code, saved just in case
        // if (testWindow.state[SDL_SCANCODE_DOWN])
        // {
        //     if (!rectListColl(mainEntity, rects, 3)){
        //     y += speed;

        //     }
            
            
        // }       

        //>UPDATE POS OF RECT
        if (rectListColl(mainEntity, rects, 1) && yVel < 0)
        {
            yVel = 0;
        }

        y += yVel / 10;
        
        mainEntity.x = x;
        mainEntity.y = y;
        mainEntity.rect.x = x;
        mainEntity.rect.y = y;

    //>DRAW
    testWindow.clear();
    testWindow.renderEverything(rects);
    testWindow.render(mainEntity);
    testWindow.display();

    }
    

    

    return 0;
}