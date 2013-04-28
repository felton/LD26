//
//  main.cpp
//  LD26
//
//  Created by Felton Vaughn on 4/27/13.
//  Copyright (c) 2013 Felton Vaughn. All rights reserved.
//

#include "main.h"


int main(int argc, char *argv[])
{
    /*SDL_Surface *screen;
    
    SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(640,480,0, SDL_HWSURFACE | SDL_DOUBLEBUF);
    
    SDL_Delay(5000);
    
    SDL_Quit();*/
    
    Game *g = new Game();
    
    g->Run();
    
    delete g;
    
    return 0;
    
}