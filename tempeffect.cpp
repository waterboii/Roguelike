//
//  tempeffect.cpp
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#include "tempeffect.h"
#include <iostream>

using namespace std;

TempEffect::TempEffect():atk(0),def(0){}

TempEffect::~TempEffect(){}

void TempEffect::setatk(int val){
    atk = atk + val;
}

void TempEffect::setdef(int val){
    def = def + val;
}

int TempEffect::getatk(){
    return atk;
}

int TempEffect::getdef(){
    return def;
}
