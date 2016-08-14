//
//  merchant.cpp
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#include "merchant.h"
#include <iostream>
#include "enemyinteract.h"

using namespace std;

Merchant::Merchant():Enemy("Merchant"){}

bool Merchant::hostile = 0;

bool Merchant::getHostile(){ return hostile;}

void Merchant::setHostile(){hostile = 1;}

void Merchant::randmove(){
    if (moved == 0) {
        if (action->inRange() != NULL && hostile == 1){
            
            action->attack(this);
        }
        else {
            action->move(this);
        }
        moved = 1;
    }
    else {
        return;
    }
}
