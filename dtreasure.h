//
//  dtreature.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __DTREASURE_H__
#define __DTREASURE_H__

#include "gold.h"
#include <iostream>

class Dragon;
class Floor;

class Dtreasure : public Gold{
    int r, c;
    Floor *floor;
    bool Ddead;
    Dragon *guard;
public:
    Dtreasure(Floor *floor);
    char getType();
    bool getDdead();
    void setPosn(int r, int c);
    void setDdead();
    void createDrag();
    void check();
    int getDragHP();
};
#endif