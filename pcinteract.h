//
//  pcinteract.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __PCINTERACT_H__
#define __PCINTERACT_H__

#include "interact.h"
#include <iostream>
#include <string>

class PC;

class PCInteract: public Interact{
public:
    PCInteract();
    void move(Object *o);
    void attack(Object *o);
    void drinkP(PC *pc);
    int getRow();
    int getCol();
};

#endif
