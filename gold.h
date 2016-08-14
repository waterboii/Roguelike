//
//  gold.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __GOLD_H__
#define __GOLD_H__

#include "treasure.h"
#include <iostream>
#include <string>

class Gold: public Treasure{
    std::string gType;
    int value;
public:
    Gold(std::string type);
    int goldValue();
    std::string getGoldType();
    char getSymbol();
};
#endif

