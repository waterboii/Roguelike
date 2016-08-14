//
//  potion.cpp
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#include "potion.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Potion::Potion(){
    int randnum = rand() % 6 + 1;
    if (randnum == 1){
        var = "RH";
        amount = 10;
    }
    if (randnum == 2){
        var = "BA";
        amount = 5;
    }
    if (randnum == 3){
        var = "BD";
        amount = 5;
    }
    if (randnum == 4){
        var = "PH";
        amount = -10;
    }
    if (randnum == 5){
        var = "WA";
        amount = -5;
    }
    if (randnum == 6){
        var = "WD";
        amount = -5;
    }
}

char Potion::getType(){ return 'b';}

string Potion::getVar(){ return var;}

char Potion::getSymbol(){ return 'P';}

int Potion::getAmount(){ return amount;}

