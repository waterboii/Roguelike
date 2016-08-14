//
//  tempeffect.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __TEMPEFFECT_H__
#define __TEMPEFFECT_H__

#include <iostream>

class TempEffect {
    int atk,def;
public:
    TempEffect();
    ~TempEffect();
    void setatk(int);
    void setdef(int);
    int getatk();
    int getdef();
};

#endif
