//
//  enemyinteract.cpp
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#include "enemyinteract.h"
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <sstream>
#include "merchant.h"
#include "PC.h"

using namespace std;


//NO, SO, EA, WE, NE, NW, SE, SW
// 0,  1,  2,  3,  4,  5,  6,  7

EnemyInteract::EnemyInteract(): Interact(){}

void EnemyInteract::move(Object *o) {
    int count = 0;
    while (true) {
        if ( count > 50)
        {
            return;
        }
        
        int dir = rand() % 8;
        if (dir == 0)
        {
            SetDir("no");
        }
        
        else if (dir == 1)
        {
            SetDir("so");
        }
        
        else if (dir == 2)
        {
            SetDir("ea");
        }
        
        else if (dir == 3)
        {
            SetDir("we");
        }
        
        else if (dir == 4)
        {
            SetDir("ne");
        }
        
        else if (dir == 5)
        {
            SetDir("nw");
        }
        
        else if (dir == 6)
        {
            SetDir("se");
        }
        
        else if (dir == 7)
        {
            SetDir("sw");
        }
        
        if (floor->getFloorType(tr, tc) == 'g')
        {
            if (floor->getObj(tr, tc) == NULL)
            {
                floor->setObj(tr, tc, o);
                floor->setObj(pr, pc, NULL);
                pr = tr;
                pc = tc;
                break;
            }
        }
        
        else
        {
            count++;
            continue;
        }
    }
}

void EnemyInteract::attack(Object *o) {
    Enemy *enemy = dynamic_cast <Enemy*>(o);
    PC *pc1 = dynamic_cast<PC *>(floor->pcInRange(pr, pc));
    
    if (rand() % 2 == 1) {
        
        float enemyatk = enemy->getAtk();
        float playerdef = pc1->getDef();
        int damage = ceil(((100 / (100 + playerdef))) * enemyatk);
        pc1->newHP(damage);
        string msg = enemy->getName();
        string dmg;
        stringstream tostr;
        tostr << damage;
        dmg = tostr.str();
        msg += string(" deals ") + dmg + string(" to PC. ");
        floor->addmsg(msg);
    }
    else
    {
        floor->addmsg(enemy->getName() + " missed attack on PC. ");
    }
}


Object* EnemyInteract::inRange() {
    return floor->pcInRange(pr, pc);
}
