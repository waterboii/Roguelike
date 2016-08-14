//
//  enemy.cpp
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#include "enemy.h"
#include <iostream>
#include "enemyinteract.h"

using namespace std;

Enemy::Enemy(string type): type(type),gold(2),moved(0),action(new EnemyInteract()){
    if (type == "Human"){
        hp = 140;
        atk = 20;
        def = 20;
        symbol = 'H';
    }
    if (type == "Dwarf"){
        hp = 100;
        atk = 20;
        def = 30;
        symbol = 'W';
    }
    if (type == "Elf"){
        hp = 140;
        atk = 30;
        def = 10;
        symbol = 'E';
    }
    if (type == "Orcs"){
        hp = 180;
        atk = 30;
        def = 25;
        symbol = 'O';
    }
    if (type == "Merchant"){
        hp = 30;
        atk = 70;
        def = 5;
        symbol = 'M';
    }
    if (type == "Dragon"){
        hp = 150;
        atk = 20;
        def = 20;
        symbol = 'D';
    }
    
    if (type == "Halfling") {
        hp = 100;
        atk = 15;
        def = 20;
        symbol = 'L';
    }
}

Enemy::~Enemy(){
    delete action;
}

char Enemy::getType(){
    return 'e';
}

string Enemy::getName(){
    return type;
}

char Enemy:: getSymbol() {
    return symbol;
}

int Enemy::getAtk(){
    return atk;
}

int Enemy::getDef(){
    return def;
}

int Enemy::getHP(){
    return hp;
}

void Enemy::setHP(int dmg){
    hp = hp - dmg;
}

int Enemy::dropGold(){
    if (type == "Human"){
        gold = 4;
    }
    return gold;
}

void Enemy::randmove (){
    if (moved == 1){
        return;
    }
    if (action->inRange() != NULL){
        action->attack(this);
    }
    else{
        action->move(this);
    }
    moved = 1;
}

/*void Enemy::Eattack(){
    action->attack(this);
}*/

void Enemy::setPosn(int r, int c){
    action->SetCurrent(r,c);
}

void Enemy::setFloor(Floor *floor){
    action->SetFloor(floor);
}

void Enemy::resetMoved(){
    moved = 0;
}
