//
//  dtreasure.cpp
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#include "dtreasure.h"
#include <iostream>
#include "dragon.h"
#include "floor.h"
#include <cstdlib>
#include <time.h>

using namespace std;

Dtreasure::Dtreasure(Floor *floor):Gold("dragon hoard"),r(0),c(0),floor(floor),Ddead(0),guard(0){}

char Dtreasure::getType() {
    return 'g';
}

bool Dtreasure::getDdead(){
    return Ddead;
}

void Dtreasure::setPosn(int r,int c){
    this->r = r;
    this->c = c;
}

void Dtreasure::setDdead(){
    Ddead = 1;
}

void Dtreasure::createDrag(){
    Dragon *d = new Dragon(this);
    guard = d;
    int pr,pc;
    srand(time(NULL));
    while (true){
        int dir = rand() % 8;
        if (dir == 0){ // north
            pr = r-1;
            pc = c;
        }
        if (dir == 1){// northeast
            pr = r - 1;
            pc = c + 1;
        }
        if (dir == 2){//east
            pr = r;
            pc = c + 1;
        }
        if (dir == 3){//southeast
            pr = r + 1;
            pc = c + 1;
        }
        if (dir == 4){//south
            pr = r + 1;
            pc = c;
        }
        if (dir == 5){//southwest
            pr = r + 1;
            pc = c - 1;
        }
        if (dir == 6){//west
            pr = r;
            pc = c - 1;
        }
        else {//northwest
            pr = r - 1;
            pc = c - 1;
        }
        if (floor->getFloorType(pr,pc) == 'g' && floor->getObj(pr,pc) == NULL){
            d->setPosn(pr,pc);//????????????
            d->setFloor(floor);
            floor->setObj(pr,pc,d);
            break;
        }
        else{
            continue;
        }
    }//while
}

void Dtreasure::check(){
    if (floor->pcInRange(r,c) !=NULL){
        guard->setPCinRange();
        guard->randmove();
    }
}

int Dtreasure::getDragHP(){
    return guard->getHP();
}
