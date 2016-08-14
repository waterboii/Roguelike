//
//  treasure.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __TREASURE_H__
#define __TREASURE_H__

#include "object.h"
#include <iostream>

class Treasure: public Object {
public:
    char getType();
    virtual ~Treasure() = 0;
};

#endif