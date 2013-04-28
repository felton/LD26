//
//  object.cpp
//  LD26-Minimalism
//
//  Created by Felton Vaughn on 4/27/13.
//  Copyright (c) 2013 Felton Vaughn. All rights reserved.
//

#include "object.h"

void Player::Update()
{
    if(direction == 1){
        w->xvel = w_dist;
        w->yvel = -1 * w_dist;
        
     } else if (direction == 2) {
        w->xvel = -1 * w_dist;
        w->yvel = (-1) * w_dist *3;

    } else if (direction == 3) {
        w->xvel = -1 * w_dist * 3;
        w->yvel = -1 * w_dist;
        
        //printf("Xvel: %d  Yvel: %d", w->xvel, w->yvel);
        //printf("X: %d  Y: %d", w->x, w->y);

    } else {
        w->xvel = -1 * w_dist;
        w->yvel = w_dist;

    }
    x += xvel;
    y += yvel;
    
    w->rect.x = x + (size + (w->size/2)) + w->xvel;
    w->rect.y = y + (size + (w->size/2)) + w->yvel;
    
    w->x = w->rect.x;
    w->y = w->rect.y;
    
    w_dist = size;
}

void Player::Draw()
{
    rect.x = x;
    rect.y = y;
    
    rect.w = size;
    rect.h = size;
}


Player::Player() {
    w = new Weapon();
}

Player::~Player() {
    delete w;
    //Would this be fine on the stack?? Blah
}

void Weapon::Update()
{
    //rect.x =
}

void Weapon::Draw()
{
    rect.x = x;
    rect.y = y;
    
    rect.w = size;
    rect.h = size;
}

Enemy::Enemy() {
    
}

Enemy::Enemy(int x, int y, int size){
    this->x = x;
    this->y = y;
    this->size= size;
    
}
void Enemy::Update()
{
    
}

void Enemy::Draw()
{
    rect.x = x;
    rect.y = y;
    
    rect.w = size;
    rect.h = size;
}
LevelExit::LevelExit()
{
    rect.x = 540;
    rect.y = 380;
    
    rect.w = 100;
    rect.h = 100;
}

void LevelExit::Draw(){
    x = rect.x;
    y = rect.y;

}

void LevelExit::Update(){
    r = rand() % 255;
    g = rand() % 255;
    b = rand() % 255;
}