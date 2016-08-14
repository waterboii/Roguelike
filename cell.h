//
//  cell.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __CELL_H__
#define __CELL_H__
#include "object.h"

class Cell{
    
    char type; // Cell type, return char in floor.cc
    int chamberID; //chamber ID of the current cell, refer to diagram for ID
    Object *cellObj; //the current object that is on this cell
    
public:
    Cell(char type, int id);
    char getType() const;
    int getChamberID() const;
    Object *getCellObj();
    void setCellObj (Object *);
    ~Cell();
    
};

#endif
