//
//  floor.cpp
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#include "floor.h"
#include "cell.h"
#include "floor.h"
#include "PC.h"
#include "enemy.h"
#include "gold.h"
#include "stair.h"
#include "dtreasure.h"
#include "potion.h"
#include "merchant.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


//type BRICK(b), XW(x), YW(y), DOOR(d), CORRIDOR(c), GROUND(g)

Floor* Floor::thisFloor = NULL;

Floor* Floor::getInst() {
    
    if (!thisFloor) {
        thisFloor = new Floor();
        atexit(cleanup);
    }
    
    return thisFloor;
}

void Floor::cleanup() {
    delete thisFloor;
}

Floor::Floor() {
    
    action = "";
    ifstream file("floorMap.txt");
    char filein;
    int chamber;
    char type;
    
    for (int row = 0; row < maxRow; row ++) {
        map[row] = new Cell *[maxCol];
    }
    
    for (int row = 0; row < maxRow; row ++) {
        
        for (int col = 0; col < maxCol; col ++) {
            
            file >> noskipws >> filein;
            
            if (filein == 10) {
                file.ignore();
                file >> noskipws >> filein;
            }
            
            if (filein == '-') {
                type = 'x';
                
            }
            else if (filein == ' ') {
                type = 'b';
                
            }
            else if (filein == '#') {
                type = 'c';
                
            }
            else if (filein == '+') {
                type = 'd';
                
            }
            else if (filein == '.') {
                type = 'g';
                
            }
            else {
                type = 'y';
                
            }
            
            if (col >= 2 && col <= 29 && row >= 2 && row <= 7) {
                chamber = 1;
            }
            else if (row >= 2 && row <= 7 && col >= 38 && col <= 59) {
                chamber = 2;
            }
            else if (row >= 2 && row <= 13 && col >= 60 && col <= 76) {
                chamber = 2;
            }
            else if (row >= 9 && row <= 13 && col >= 37 && col <= 50) {
                chamber = 3;
            }
            else if (row >= 14 && row <= 22 && col >= 2 && col <= 25) {
                chamber = 4;
            }
            else if (row >= 15 && row <= 17 && col >= 64 && col <= 76) {
                chamber = 5;
            }
            else if (row >= 18 && row <= 22 && col >= 36 && col <= 76) {
                chamber = 5;
            }
            else {
                chamber = 0;
            }
            map[row][col] = new Cell(type, chamber);
        }
    }
    file.close();
    file.clear();
}

Object* Floor::getObj (int row , int col) {
    return map[row][col]->getCellObj();
}

void Floor::display() {
    char content;

    for (int row = 0; row < maxRow; row ++){
        
        for (int col = 0; col < maxCol; col++){
            
            if (!map[row][col]->getCellObj()){
                content = map[row][col]->getType();
                
                if (content == 'b') {
                    cout << " ";
                }
                else if (content == 'c') {
                    cout << "#";
                }
                else if (content == 'd') {
                    cout << "+";
                }
                else if (content == 'g') {
                    cout << ".";
                }
                else if (content == 'x') {
                    cout << "-";
                }
                else if (content == 'y') {
                    cout << "|";
                }

            }
            else {
                cout << map[row][col]->getCellObj()->getSymbol();
            }
        }
        cout << '\n';
    }
}

void Floor::resetFloor() {
    
    for (int row = 0; row < maxRow; row ++) {
        
        for (int col = 0; col < maxCol; col++) {
            
            if (map[row][col]->getCellObj() != NULL) {
                
                if (map[row][col]->getCellObj()->getType() != 0) {
                    delete map[row][col]->getCellObj();
                }
            }
            map[row][col]->setCellObj(NULL);
        }
    }
}

void Floor::setObj(int row , int col, Object* obj) {
    map[row][col]->setCellObj(obj);
}

void Floor::clearCell(int row , int col){
    if(map[row][col]->getCellObj() != NULL){
        
        delete map[row][col]->getCellObj();
        map[row][col]->setCellObj(NULL);
    }
}

Object* Floor::pcInRange(int row , int col){
    
    for (int x = row - 1; x <= row + 1; x++) {
        
        for (int y = col - 1; y <= col + 1; y++) {
            
            if (x == row && y == col) {
                continue;
            }
            
            if (map[x][y]->getCellObj() == NULL) {
                continue;
            }
            
            if (map[x][y]->getCellObj()->getType() == 'p') {
                return map[x][y]->getCellObj();
            }
        }
    }
    return NULL;
}

Object** Floor::PotionInRange(int row , int col){
    Object** array = new Object*[8];
    
    for (int x = 0; x < 8; x++){
        array[x] = NULL;
    }
    int count = 0;
    
    for (int x = row - 1; x <= row + 1; x++){
        
        for (int y = col- 1; y <= col+ 1; y++){
            
            if (x == row && y == col) {
                continue;
            }
            
            if (map[x][y]->getCellObj() == NULL) {
                continue;
            }
            
            if (map[x][y]->getCellObj()->getType() == 'b'){
                array[count] = map[x][y]->getCellObj();
                count++;
            }
        }
    }
    return array;
}

int Floor::getFloorType(int row , int col){
    return map[row][col]->getType();
}

void Floor::changemsg(string msg){
    action = msg;
}

void Floor::addmsg(std::string s) {
    action += s;
}

void Floor::clearmsg(){
    action = "";
}

void Floor::showMsg(){
    cout << action;
}

Floor::~Floor(){
    for (int row = 0; row < maxRow; row++){
        
        for (int col = 0; col < maxCol; col++){
            delete map[row][col];
        }
        delete[] map[row];
    }
}



bool Floor::chamSpawn(int chamID, Object* obj) {
    int row, column;
    int count = 0;
    
    do{
        if (chamID == 1) {
            row = rand() % 4 + 3;
            column = rand() % 26 + 3;
        }
        
        else if (chamID == 2) {
            column = rand() % 37 + 39;
            
            if (column >= 39 && column <= 60) {
                row = rand() % 4 + 3;
            }
            else if (column == 61) {
                row = rand() % 10 + 3;
            }
            else if (column >= 62 && column <= 69) {
                row = rand() % 8 + 5;
            }
            else if (column >= 70 && column <= 72) {
                row = rand() % 7 + 6;
            }
            else {
                row = rand() % 6 + 7;
            }
        }

        else if (chamID == 3) {
            row = rand() % 3 + 10;
            column = rand() % 12 + 38;
        }

        else if (chamID == 4) {
            row = rand() % 7 + 15;
            column = rand() % 21 + 4;
        }

        else {
            row = rand() % 6 + 16;
            
            if (row >= 16 && row <= 18){
                column = rand() % 11 + 65;
            }
            else {
                column = rand() % 39 + 37;
            }
        }
        count++;
        if (count > 100) {
            return false;
        }
        
    }while(map[row][column]->getCellObj() != NULL);

        if (obj->getType() == 'p'){
        PC *temp = static_cast<PC *>(obj);
        temp->setPosn(row, column);
        temp->setFloor(this);
    }
    
    if (obj->getType() == 'e'){
        Enemy* temp = static_cast<Enemy *>(obj);
        temp->setPosn(row, column);
        temp->setFloor(this);
    }
    
    else if (obj->getType() == 'g'){
        Gold *temp = static_cast<Gold *>(obj);
        Dtreasure *temp2;
        
        if (temp->getGoldType() == "dragon hoard"){
            temp2 = static_cast<Dtreasure *>(temp);
            temp2->setPosn(row, column);
            temp2->createDrag();
        }
    }
    
    map[row][column]->setCellObj(obj);
    return true;
}


int Floor::reCalcRan(int random){
    int newRan;
    newRan = rand() % 5 + 1;
    
    while(random == newRan) {
        newRan = rand() % 5 + 1;
    }
    return newRan;
}

void Floor::spawn(int seed) {
    //random gen = 0
    if (seed == 0){
        
        int random = rand() % 5 + 1;
        int temp = random;
        Object *newObj;
        
        //Player
        chamSpawn(random, PC::getPC());
        

        //Stair
        while(random == temp)
            random = rand() % 5 + 1;
        chamSpawn(random, new Stair);

        //Potion
        for (int x = 0; x < 10; x++) {
            random = rand() % 5 + 1;
            newObj = new Potion;
            while(!chamSpawn(random, newObj)) {
                random = reCalcRan(random);
            }
        }

        
        //Gold
        for (int x = 0; x < 10; x++){
            random = rand() % 5 + 1;
            temp = rand() % 8 + 1;//denominator

            if (temp >= 1 && temp <= 5) {//normal
                newObj = new Gold("normal");
            }
            else if (temp == 6) {// dragon horde
                newObj = new Dtreasure(this);
            }
            else {//small
                newObj = new Gold("small");
            }
            while (!chamSpawn(random, newObj)) {
                random = reCalcRan(random);
            }
        }

        //Enemy
        for (int x = 0; x < 20; x++) {
            random = rand() % 5 + 1;
            temp = rand() % 18 + 1; //denominator
            
            if (temp >= 1 && temp <= 4) {
                newObj = new Enemy("Human");
            }
            else if (temp >= 5 && temp <= 7) {
                newObj = new Enemy("Dwarf");
            }
            else if (temp >= 8 && temp <= 12) {
                newObj = new Enemy("Elf");
            }
            else if (temp == 13 || temp == 14) {
                newObj = new Enemy("Orcs");
            }
            else if (temp == 15 || temp == 16) {
                newObj = new Enemy("Halfling");
            }
            else {//Merchant
                newObj = new Merchant;
            }
            while(!chamSpawn(random, newObj)) {
                random = reCalcRan(random);
            }
        }
    }
    /*
    else if (seed == 1) {
        //Player
        map[3][10]->setCellObj(PC::getPC("small"));
        //Stair
        map[11][43]->setCellObj(new Stair);
        //Potion
        //Gold
        map[5][15]->setCellObj(new Gold("small"));
        map[3][60]->setCellObj(new Gold("small"));
        
        //map[8][69]->setCellObj(new Dtreasure());//dragon T
        
        map[10][47]->setCellObj(new Gold("small"));
        map[17][14]->setCellObj(new Gold("small"));
        map[21][9]->setCellObj(new Gold("small"));
        map[17][68]->setCellObj(new Gold("small"));
        map[17][71]->setCellObj(new Gold("small"));
        //Enemy
        map[4][23]->setCellObj(new Enemy("Dwarf"));
        map[6][10]->setCellObj(new Enemy("Human"));
        map[6][24]->setCellObj(new Enemy("Dragon"));
        map[3][49]->setCellObj(new Enemy("Elf"));
        map[5][49]->setCellObj(new Enemy("Orcs"));
        map[5][60]->setCellObj(new Enemy("Orcs"));
        map[9][63]->setCellObj(new Enemy("Merchant"));
        map[4][23]->setCellObj(new Enemy("Dwarf"));
        
    }*/
}

void Floor::spawnGold(int r, int c){
    map[r][c]->setCellObj(new Gold("merchant hoard"));
}

