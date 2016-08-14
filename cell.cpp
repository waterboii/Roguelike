//
//  cell.cpp
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#include "cell.h"
#include <cstdlib>
using namespace std;

Cell::Cell(char type, int id):
    type (type),chamberID (id),cellObj (NULL) {}

char Cell::getType() const {
    return type;
}

int Cell::getChamberID () const {
    return chamberID;
}

Object* Cell::getCellObj() {
    if (cellObj != NULL) {
        return cellObj;
    }
    return NULL;
}

void Cell::setCellObj (Object* obj){
    cellObj = obj;
}

Cell::~Cell(){
    if (cellObj != NULL && (cellObj->getType() != 0)){
        delete cellObj;
    }
}
