//
//  enemy.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "object.h"
#include <iostream>
#include <string>

class EnemyInteract;
class Floor;

class Enemy : public Object{
    std::string type;
    int hp,atk,def,gold;
    char symbol;
protected:
    bool moved;
    EnemyInteract *action;
public:
    Enemy(std::string type);
    virtual~Enemy();
    char getType();
    char getSymbol();
    std::string getName();
    int getAtk();
    int getDef();
    int getHP();
    void setHP(int);
    int dropGold();
    virtual void randmove();
    void Eattack();
    void setPosn(int r, int c);
    void setFloor(Floor *f);
    void resetMoved();
};

#endif
