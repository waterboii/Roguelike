//
//  merchant.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __MERCHANT_H__
#define __MERCHANT_H__

#include "enemy.h"
#include <iostream>

class Merchant : public Enemy{
    static bool hostile;
public:
    Merchant();
    static bool getHostile();
    static void setHostile();
    void randmove();
};
#endif
