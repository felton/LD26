//
//  input.h
//  LD26-Minimalism
//
//  Created by Felton Vaughn on 4/27/13.
//  Copyright (c) 2013 Felton Vaughn. All rights reserved.
//

#ifndef __LD26_Minimalism__input__
#define __LD26_Minimalism__input__

#include <iostream>
#include "SDL.h"

class Input{
private:
    Uint8 *keystate;
    
public:
    Input();
    //~Input();
    void Update();
    bool keyPressed(SDLKey key);
    void keyReleased(SDLKey key);
    
    
    
    
};









#endif /* defined(__LD26_Minimalism__input__) */
