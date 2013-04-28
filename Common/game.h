//
//  game.h
//  LD26-Minimalism
//
//  Created by Felton Vaughn on 4/27/13.
//  Copyright (c) 2013 Felton Vaughn. All rights reserved.
//

#ifndef __LD26_Minimalism__game__
#define __LD26_Minimalism__game__

#include <iostream>
#include <vector>
#include <cstdlib>

#include "object.h"
#include "input.h"

class Game {
    
private:
    SDL_Surface *gameScreen = NULL;
    Uint32 videoFlags = SDL_HWSURFACE | SDL_DOUBLEBUF;
    Input *input;
    void Init();
    Player *player;
    
    int accel = 5;
    int level = 0;
    
    int screenWidth = 640;
    int screenHeight = 480;
    int enemyCount;
    int fps = 60;
    LevelExit *levelExit;
    
    std::vector<Enemy*> enemies;
    
public:
    Game();
    ~Game();
    void Run();
    void Update();
    void DrawObject(Object *o); //Should be done better, but, you know LD48
    void UpdateObject(Object *o);
    bool Collided(Object *o, Object *o2);
    void AdvanceLevel();
    
    
};

#endif /* defined(__LD26_Minimalism__game__) */
