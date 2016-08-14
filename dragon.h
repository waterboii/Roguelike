//
//  dragon.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "enemy.h"
#include <iostream>

class Dtreasure;
class Floor;

class Dragon : public Enemy{
    Dtreasure *dt;
    bool PCinRange;
public:
    Dragon(Dtreasure* dt);
    void setPCinRange();
    void notify();
    void randmove();
};
#endif
