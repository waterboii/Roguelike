//
//  floor.h
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#ifndef __FLOOR_H__
#define __FLOOR_H__
#include "cell.h"
#include <string>

const int maxRow = 25;
const int maxCol = 79;
class Object;

class Floor {
    std::string action;
    static Floor* thisFloor;
    Cell **map[maxRow];
    Floor();
    
    ~Floor();
    bool chamSpawn (int chamID, Object* obj);
    int reCalcRan (int random);
    
public:
    static Floor *getInst();
    static void cleanup();
    void addmsg (std::string);
    void clearmsg();
    void display();
    void spawn (int=0);
    void resetFloor();
    Object *getObj (int row, int col);
    void setObj (int row, int col, Object*);
    void clearCell (int row, int col);
    Object *pcInRange (int row, int col);
    Object **PotionInRange (int row, int col);
    int getFloorType (int row, int col);
    void spawnGold (int, int);
    void changemsg (std::string);
    void showMsg();
};


#endif
