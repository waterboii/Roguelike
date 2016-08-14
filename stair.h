//
//  stair.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __STAIR_H__
#define __STAIR_H__

#include "object.h"

class Stair: public Object {
public:
    char getType();
    char getSymbol();
};
#endif