//
//  object.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//


#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <iostream>

class Object {
public:
    virtual ~Object()=0;
    virtual char getSymbol()=0;
    virtual char getType()= 0;
};

#endif
