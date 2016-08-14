//
//  interact.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __INTERACT_H__
#define __INTERACT_H__

#include <iostream>
#include "object.h"
#include "floor.h"
#include <string>

class Interact{
protected:
    int pr,pc,tr,tc; //tr,tc are target row and column
    std::string dir;
    Floor *floor;
    Object *ob;
public:
    Interact();
    void SetFloor(Floor *f);
    void SetDir(std::string dir);
    void SetCurrent(int r,int c);
    virtual void move(Object *o) = 0;
    virtual void attack(Object *o) = 0;
};
#endif
