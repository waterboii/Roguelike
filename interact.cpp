//
//  interact.cpp
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#include "interact.h"
#include <iostream>
#include <string>

using namespace std;

Interact::Interact():pr(0),pc(0),tr(0),tc(0),dir(""),floor(0),ob(0){}

void Interact::SetFloor(Floor *f){
    floor = f;
}

void Interact::SetDir(string dir){
    if (dir == "no"){
        tr = pr - 1;
        tc = pc;
        dir = "North";
    }
    else if (dir == "ne"){
        tr = pr - 1;
        tc = pc + 1;
        dir = "Northeast";
    }
    else if (dir == "we"){
        tr = pr;
        tc = pc - 1;
        dir = "West";
    }
    else if (dir == "sw"){
        tr = pr + 1;
        tc = pc - 1;
        dir = "Southwest";
    }
    else if (dir == "so"){
        tr = pr + 1;
        tc = pc;
        dir = "South";
    }
    else if (dir == "se"){
        tr = pr + 1;
        tc = pc + 1;
        dir = "Southeast";
    }
    else if (dir == "ea"){
        tr = pr;
        tc = pc + 1;
        dir = "East";
    }
    else if (dir == "ne"){
        tr = pr - 1;
        tc = pc + 1;
        dir = "Northeast";
    }
    ob = floor->getObj(tr,tc);
}

void Interact::SetCurrent(int r, int c){
    pr = r;
    pc = c;
}
