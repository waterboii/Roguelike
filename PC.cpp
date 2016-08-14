//
//  PC.cpp
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#include "PC.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "shade.h"
#include "drow.h"
#include "troll.h"
#include "vampire.h"
#include "goblin.h"
#include "pcinteract.h"

using namespace std;

PC::PC(string type): gold(0), loPotion(new int[6]) {
    te = new TempEffect;
    action = new PCInteract();
    if (type == "Shade") {
        hp = 125;
        atk = 25;
        def = 25;
        maxHP = 125;
        race1 = "Shade";
        race = new Shade;
    }
    
    if (type == "Drow"){
        hp = 150;
        atk = 25;
        def = 15;
        maxHP = 150;
        race1 = "Drow";
        race = new Drow;
    }
    
    if (type == "Vampire"){
        hp = 50;
        atk = 25;
        def = 25;
        maxHP = 99999;
        race1 = "Vampire";
        race = new Vampire;
    }
    
    if (type == "Troll"){
        hp = 120;
        atk = 25;
        def = 15;
        maxHP = 120;
        race1 = "Troll";
        race = new Troll;
    }
    if (type == "Goblin"){
        hp = 110;
        atk = 15;
        def = 20;
        maxHP = 110;
        race1 = "Goblin";
        race = new Goblin;
    }
    for (int i = 0; i < 6; i++)
    {
        loPotion[i] = 0;
    }
}

PC::~PC(){
    delete race;
    delete te;
    delete loPotion;
    delete action;
}

PC *PC::pc = 0;

void PC::cleanup(){
    delete pc;
    pc = NULL;
}

PC *PC::getPC(string type){
    if (!pc){
        pc = new PC(type);
        atexit(cleanup);
    }
    return pc;
}

void PC::resetPC(){
    if (pc != NULL) {
        cleanup();
        pc = NULL;
    }
}

void PC::newHP(int val){
    hp = hp - val;
}
int PC::getMaxHP() {
    return maxHP;
}
void PC::newTe(string type,int val){
    if (type == "RH" || type == "PH"){
        
        if (race1 == "Drow"){
            
            hp = hp + val *1.5;
        }
        else{
            hp = hp + val;
        }
    }
    if (type == "BD" || type == "WD"){
        race -> addtedef(te,val);
    }
    if (type == "BA" || type == "WA"){
        race -> addteatk(te,val);
    }
}

void PC::newGold(int val){
    gold = gold + race->addgold(val);
}

void PC::resetTe(){
    if (te != NULL){
        delete te;
    }
    te = new TempEffect;
}

char PC::getType(){ return 'p';}

char PC::getSymbol(){ return '@';}

int PC::getAtk(){
    return atk + te->getatk();
}

int PC::getDef(){
    return def + te->getdef();
}

int PC::getHP(){return hp;}

int PC::getGold(){ return gold;}

int PC::getPr(){ return action->getRow();}

int PC::getPc(){ return action -> getCol();}

std::string PC::getRace(){return race1;}

void PC::trackPotion(std::string type){
    if (type == "RH"){
        loPotion[0] = 1;
    }
    if (type == "BA"){
        loPotion[1] = 1;
    }
    if (type == "BD"){
        loPotion[2] = 1;
    }
    if (type == "PH"){
        loPotion[3] = 1;
    }
    if (type == "WA"){
        loPotion[4] = 1;
    }
    if (type == "WD"){
        loPotion[5] = 1;
    }
}

int PC::checkPotion(std::string type){
    
    if (type == "RH"){
        return loPotion[0];
    }
    if (type == "BA"){
        return loPotion[1];
    }
    if (type == "BD"){
        return loPotion[2];
    }
    if (type == "PH"){
        return loPotion[3];
    }
    if (type == "WA"){
        return loPotion[4];
    }
    return loPotion[5];
}

void PC::PCmove(std::string dir){
    action->SetDir(dir);
    action->move(this);
}

void PC::PCattack(std::string dir){
    action->SetDir(dir);
    action->attack(this);
}


void PC::drinkP(std::string dir){
    action->SetDir(dir);
    action->drinkP(this);
}

void PC::setFloor(Floor *floor){
    action->SetFloor(floor);
}

void PC::setPosn(int r,int c){
    action->SetCurrent(r,c);
}


