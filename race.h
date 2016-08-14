//
//  race.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __RACE_H__
#define __RACE_H__

#include <iostream>
#include "tempeffect.h"

class Race{
public:
    virtual int addgold(int)=0;
    virtual void addteatk(TempEffect *&t,int val)=0;
    virtual void addtedef(TempEffect *&t,int val)=0;
    virtual ~Race();
};
#endif
