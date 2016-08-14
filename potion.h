//
//  potion.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __POTION_H__
#define __POTION_H__

#include "object.h"
#include <iostream>
#include <string>

class Potion :public Object {
    int amount;
    std::string var;
public:
    Potion();
    char getType();
    char getSymbol();
    int getAmount();
    std::string getVar();
};
#endif
