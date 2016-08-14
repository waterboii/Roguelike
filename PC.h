//
//  PC.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __PC_H__
#define __PC_H__

#include "object.h"
#include <iostream>
#include <string>
#include "race.h"
#include "tempeffect.h"

class PCInteract;
class Floor;

class PC : public Object {
    int hp, maxHP, atk,def,gold;
    std::string race1;
    Race *race;
    TempEffect *te;
    PCInteract *action;
    int *loPotion;
    static PC *pc;
    static void cleanup();
    ~PC();
    PC(std::string type = "Shade");
    
public:
    static PC *getPC(std::string type = "Shade");
    static void resetPC();
    int getMaxHP();
    void newHP(int);
    void newTe(std::string,int);
    void newGold(int);
    void resetTe();
    char getType();
    char getSymbol();
    int getAtk();
    int getDef();
    int getHP();
    int getGold();
    int getPr();
    int getPc();
    std::string getRace();
    void trackPotion(std::string type);
    int checkPotion(std::string type);
    void PCmove(std::string dir);
    void PCattack(std::string dir);
    void drinkP(std::string dir);
    void setFloor(Floor *floor);
    void setPosn(int r,int c);
};
#endif

