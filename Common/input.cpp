//
//  input.cpp
//  LD26-Minimalism
//
//  Created by Felton Vaughn on 4/27/13.
//  Copyright (c) 2013 Felton Vaughn. All rights reserved.
//

#include "input.h"


Input::Input()
{
    //nop
}

/*void Input::keyPressed(SDLKey key)
{
    keys[key] = true;
}

void Input::keyReleased(SDLKey key)
{
    keys[key] = false;
}*/

bool Input::keyPressed(SDLKey key)
{
    return this->keystate[key];
}


void Input::Update()
{
    SDL_PumpEvents();
    this->keystate = SDL_GetKeyState(NULL);
    
    
}