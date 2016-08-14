//
//  dragon.cpp
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#include "dragon.h"
#include <iostream>
#include "enemyinteract.h"
#include "dtreasure.h"
#include "floor.h"
#include <cstdlib>

using namespace std;

Dragon::Dragon(Dtreasure *dt) : Enemy("Dragon"),PCinRange(0),dt(dt){}

void Dragon::setPCinRange(){ PCinRange = !PCinRange;}

void Dragon::notify(){
    dt->setDdead();
}

void Dragon::randmove(){
    if (action->inRange() != NULL){
        PCinRange = 1;
        action->attack(this);
    }
}
