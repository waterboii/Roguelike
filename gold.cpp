//
//  gold.cpp
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#include "gold.h"
#include <iostream>

using namespace std;

Gold::Gold(string type):gType(type){
    if (type == "small"){
        value = 1;
    }
    if (type == "normal"){
        value = 2;
    }
    if (type == "merchant hoard"){
        value = 4;
    }
    if (type == "dragon hoard"){
        value = 6;
    }
}

int Gold::goldValue(){
    return value;
}

string Gold::getGoldType(){
    return gType;
}

char Gold::getSymbol(){
    return 'G';
}

