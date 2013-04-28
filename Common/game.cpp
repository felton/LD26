 //
//  game.cpp
//  LD26-Minimalism
//
//  Created by Felton Vaughn on 4/27/13.
//  Copyright (c) 2013 Felton Vaughn. All rights reserved.
//

#include "game.h"


Game::Game()
{
    this->input = new Input();
    this->player = new Player();
    this->levelExit = new LevelExit();
    srand(time(NULL));
}


Game::~Game()
{
    delete this->input;
    for (int i = 0; i < enemies.size(); i++) {
        delete enemies[i];
    }
    SDL_Quit();
}

void Game::Init()
{
    SDL_Init(SDL_INIT_VIDEO);
    
    this->gameScreen = SDL_SetVideoMode(640, 480, 32, this->videoFlags);
    
    this->player->rect.x = this->player->rect.y = 0;
    this->player->rect.w = this->player->rect.h = 10;
    
    this->player->w->rect.w = this->player->w->rect.h = 5;
    Enemy e1;
    Enemy e2;
    
    e1.rect.x = e1.x= 100; e1.rect.y = e1.y = 100;
    e1.rect.w = 10; e1.rect.h = 10;
    
    
    e2.rect.x = e2.x = 50; e2.rect.y = e2.y = 50;
    e2.rect.w = 10; e2.rect.h = 10;
    
    //enemies.push_back(e1);
    //enemies.push_back(e2);
    
    AdvanceLevel();
    
 }

void Game::Update()
{
    
    int done = 0;
    int start_ticks, end_ticks;
    while (!done) {
        start_ticks = SDL_GetTicks();
        input->Update();
        if (input->keyPressed(SDLK_ESCAPE)) {
            done = 1;
        }
        
        if(input->keyPressed(SDLK_LEFT)){
            this->player->xvel = -1 * accel;
            this->player->direction = 3;
        } else if(input->keyPressed(SDLK_RIGHT)) {
            this->player->xvel = 1 * accel;
            this->player->direction = 1;
        } else {
            this->player->xvel = 0;
        }
        

        
        if(input->keyPressed(SDLK_UP)){
            this->player->yvel = -1 * accel;
            this->player->direction = 2;
        } else if(input->keyPressed(SDLK_DOWN)){
            this->player->yvel = 1 * accel;
            this->player->direction = 4;
        } else {
            this->player->yvel = 0;
        }
        
        
        if (input->keyPressed(SDLK_SPACE)) {
            //this->UpdateObject((Object*)this->player->w);
            this->DrawObject((Object*)this->player->w);
            this->player->Shoot();
        } else {
            this->player->Withdraw();
        }
        
        
        this->UpdateObject((Object*)this->player);
        this->DrawObject((Object*)this->player);
        
        for (int i = 0; i < enemies.size(); i++) {
            
            /*if() {
                
            }*/
            if(!enemies[i]->isDead()){
            this->DrawObject((Object*) enemies[i]);
            
            if(Collided(player, (Object*) enemies[i])){
                
            }
            
            if(Collided(player->w, (Object*) enemies[i]) && player->isShooting()){
                enemies[i]->Die();
                enemyCount--;
                player->LevelUp();
            }
            }
            
        }
        
        if(enemyCount == 0)
        {
            this->UpdateObject((Object*)this->levelExit);
            this->DrawObject((Object*)this->levelExit);
            
            if (Collided(player, levelExit)) {
                AdvanceLevel();
                //done=1;
            }
        }
        
        
        SDL_Flip(this->gameScreen);
        SDL_FillRect(this->gameScreen, NULL, SDL_MapRGB(this->gameScreen->format, 0,0,0));
        if((SDL_GetTicks() - start_ticks) < 1000 / fps)
        {
            SDL_Delay((1000/fps) - (SDL_GetTicks() - start_ticks));
        }
    }
}

void Game::Run()
{
    this->Init();
    
    this->Update();

}

void Game::DrawObject(Object *o)
{
    o->Draw();
    
    SDL_FillRect(this->gameScreen, &o->rect, SDL_MapRGB(this->gameScreen->format, o->r, o->g, o->b));
}



void Game::UpdateObject(Object *o)
{

    
    o->Update(); // There we go, OOP is starting to form.
}

bool Game::Collided(Object *o, Object *o2)
{
    if ((o->x+o->rect.w) < o2->x) return false;
    if (o->x > o2->x+o2->rect.w) return false;
    if (o->y+ o->rect.h < o2->y) return false;
    if (o->y > o2->y+ o2->rect.h) return false;
                    
        return true;
}

void Game::AdvanceLevel()
{
    level++;
    
    enemyCount = level * 3;
    
    
    for (int i = 0; i < enemyCount; i++) {
        Enemy *temp = new Enemy(((rand() % (screenWidth - 50)) + 50 ),((rand() % (screenHeight - 50)) + 50 ) , 10 + level); // This shouldnt hurt, right??
        enemies.push_back(temp);
        
        
    }
    
    player->x = player->y = 0;
}
