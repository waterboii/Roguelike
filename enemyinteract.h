//
//  enemyinteract.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __ENEMYINTERACT_H__
#define __ENEMYINTERACT_H__

#include "interact.h"
#include <iostream>
#include "enemy.h"

class EnemyInteract: public Interact {
public:
    EnemyInteract();
    void move(Object *o);
    void attack(Object *o);
    Object *inRange();
};

#endif
