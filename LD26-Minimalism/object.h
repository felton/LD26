//
//  object.h
//  LD26-Minimalism
//
//  Created by Felton Vaughn on 4/27/13.
//  Copyright (c) 2013 Felton Vaughn. All rights reserved.
//

#ifndef __LD26_Minimalism__object__
#define __LD26_Minimalism__object__
#include "SDL.h"

class Object{

public:
    virtual void Update() {};
    virtual void Draw(){};
    virtual void Collision(){};
    SDL_Rect rect;
    int xvel = 0;
    int yvel = 0;
    int x = 0;
    int y = 0;
    
    int r = 255;
    int g = 0;
    int b = 0;
};

class Weapon : public Object {
public:
    void Update();
    void Draw();
    int size = 5;
};

class Player : public Object {
private:
    int w_dist = 7;
    int size = 10;
    bool shooting = false;

public:
    Player();
    ~Player();
    void Update();
    void Draw();
    bool isShooting(){return shooting;}
    void Shoot(){shooting=true;};
    void Withdraw(){shooting=false;};
    void LevelUp(){size +=2; w->size +=1;}
    Weapon *w;
    int direction;
};

class Enemy : public Object {
    bool dead = false;
    int size = 0;
public:
    Enemy();
    Enemy(int x, int y, int size);
    void Update();
    void Draw();
    void Die(){ dead = true;};
    bool isDead() {return dead;};
    Weapon *w;
};

class LevelExit: public Object {
public:
    LevelExit();
    void Update();
    void Draw();
    
};

#endif /* defined(__LD26_Minimalism__object__) */
