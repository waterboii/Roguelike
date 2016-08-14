//
//  main.cpp
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#include <cstring>
#include <iostream>
#include "floor.h"
#include "object.h"
#include "PC.h"
#include "enemy.h"
#include "gold.h"
#include "dragon.h"
#include "dtreasure.h"
#include "merchant.h"
#include "potion.h"
#include "stair.h"
#include <cstdlib>
#include <sstream>
#include <fstream>

using namespace std;

int mode = 1;
int level = 1;
PC * startGame(int & level, Floor *&, int, istream & file=cin);
void display(Floor *);
bool won = false;
bool ascended = false;
void spawnFile(istream &, Floor *);

int calcScore(PC* pc){
    int score;
    score = pc->getGold();
    
    return score;
}

bool checkStair(Floor* floor,Object* obj, PC* pc, int mode, istream& file=cin) {

    if (obj != NULL){
        
        if(obj->getType() == 's'){
            if (level == 6){
                cout << "You are Winnner!" << endl;
                cout << "Score: " << calcScore(pc) << endl;
                won = true;
                return true;
            }
            else{
                level++;
                floor->resetFloor();
                /*if (level == 5) {
                    Dtreasure(floor).createDrag();
                    Dtreasure(floor).setPosn(7, 74);
                }*/
                if (mode == 1){
                    floor->spawn();
                }
                else if (mode == 2){
                    spawnFile(file, floor);
                }
                pc->resetTe();
                floor->changemsg("Welcome to the Rogue");
                ascended = true;
                return true;
            }
        }
    }
    return false;
}

bool direcTrap(string& direc){
    if(direc != "no" &&
       direc != "we" &&
       direc != "so" &&
       direc != "ea" &&
       direc != "nw" &&
       direc != "ne" &&
       direc != "se" &&
       direc != "sw"){
        cerr << "Wrong input. Input is one of" << endl;
        cerr << "no, we, so, wa, nw, ne, se, sw" << endl;
        cin.clear();
        cin.ignore();
        return false;
    }
    else
        return true;
}

int main(int argc, char* argv[]){
    
    srand(time(0));
    string cmd;
    string direc;
    Floor* pFloor = NULL;
    PC *pc;
    Object *tempObj;
    ifstream file;
    if (argc > 1){
        stringstream ss(argv[1]);
        string name;
        ss >> name;
        mode = 2;
        file.open(name.c_str());
    }
    
    if (mode == 1) {
        pc = startGame(level, pFloor, mode);
    }
    else {
        pc = startGame(level, pFloor, mode, file);
    }

    while(1){
        if (pc->getHP() <= 0){
            cout << "You are dead" << endl;
            
            cout << "Score: " << calcScore(pc) << endl;
            cout << "So you wanna try again? y/n" << endl;
            cin >> cmd;
            if (cmd == "y")
                cmd = "r";
            else
                cmd = "q";
        }
        else {
            
            if(won){
                
                won = false;
                cout << "Begin your next adventure? y/n" << endl;
                cin >> cmd;
                if (cmd == "y") {
                    cmd = "r";
                }
                else {
                    cmd = "q";
                }
            }
            else {
                cin >> cmd;
            }
        }
        
        if (pc->getRace() == "Troll") {
            pc->newHP(-5);
        }
        
        if (pc->getRace() != "Vampire") {
            if (pc->getHP() > pc->getMaxHP()) {
                pc->newHP(pc->getHP() - pc->getMaxHP());
            }
        }
        if (cmd == "q") {
            file.clear();
            file.close();
            pFloor->resetFloor();
            pFloor->cleanup();
            break;
        }
        else if (cmd == "r"){
            pFloor->resetFloor();
            
            pc = startGame(level, pFloor, mode, file);
            ascended = false;
            file.seekg(0);
        }
        else if (cmd == "u" || cmd == "a"){
            cin >> direc;
            while(!direcTrap(direc)){
                cin >> direc;
            }
            ascended = false;
            if (cmd == "u")
                pc->drinkP(direc);
            else
                pc->PCattack(direc);
        }
        
        else {
            
            if(direcTrap(cmd)){
                int r = pc->getPr();
                int c = pc->getPc();
                
                if (cmd == "no") {
                    tempObj = pFloor->getObj(r-1, c);
                }
                else if (cmd == "ne")
                    tempObj = pFloor->getObj(r-1, c+1);
                else if (cmd == "ea")
                    tempObj = pFloor->getObj(r, c+1);
                else if (cmd == "se")
                    tempObj = pFloor->getObj(r+1, c+1);
                else if (cmd == "so")
                    tempObj = pFloor->getObj(r+1, c);
                else if (cmd == "sw")
                    tempObj = pFloor->getObj(r+1, c-1);
                else if (cmd == "we")
                    tempObj = pFloor->getObj(r, c-1);
                else
                    tempObj = pFloor->getObj(r-1, c-1);
                
                if (mode == 1){
                    
                    if(!checkStair(pFloor, tempObj, pc, mode)){

                        pc->PCmove(cmd);
                        //cout<<"aaaa"<<endl;
                        
                        ascended = false;
                    }
                }
                else {
                    if(!checkStair(pFloor, tempObj, pc, mode, file)){
                        pc->PCmove(cmd);
                        ascended = false;
                    }
                }
                
            }
            
            else {
                continue;
            }
        }
        if (!won && cmd != "r"){
            for (int r = 0; r < maxRow; r++){
                for (int c = 0; c < maxCol; c++){
                    tempObj = pFloor->getObj(r, c);
                    if (tempObj != NULL){
                        if (tempObj->getType() == 'e'){
                            Enemy* enemy = static_cast<Enemy *>(tempObj);
                            enemy->resetMoved();
                        }
                    }
                }
            }
            if (ascended == false){
                for (int r = 0; r < maxRow; r++){
                    for (int c = 0; c < maxCol; c++){
                        tempObj = pFloor->getObj(r, c);
                        if (tempObj != NULL){
                            if (tempObj->getType() == 'e'){
                                Enemy* enemy = static_cast<Enemy *>(tempObj);
                                enemy->randmove();
                            }
                        }
                    }
                }
            }
            display(pFloor);
        }
    }
    return 0;
}

PC* startGame(int& level, Floor*& floor, int mode, istream& file){
    
    PC* pc;
    char cmd;
    bool badinput = false;
    for (int i = 0; i < 80; i++) {
        cout << '\n';
    }
    
    cout << "Welcome to CC3K" << endl;
    cout << "Choose your race:  ~" << endl;
    cout << "Drow    (d)\n";
    cout << "Vampire (v)\n";
    cout << "Troll   (t)\n";
    cout << "Goblin  (g)\n";
    cout << "Shade   (s)\n";
    
    do {
        cin >> cmd;
        
        if (cmd != 'd' && cmd != 'v' && cmd != 't' && cmd != 'g' && cmd != 's'){
            cout << "Character can be selected from drow(d), vampire(v), ";
            cout << "troll(t), goblin(g) and shade(s)\n";
            badinput = true;
        }
        
        else {
            
            badinput = false;
            
            PC::resetPC();
            if (cmd == 'd')
                pc = PC::getPC("Drow");
            else if (cmd == 'v')
                pc = PC::getPC("Vampire");
            else if (cmd == 't')
                pc = PC::getPC("Troll");
            else if (cmd == 'g')
                pc = PC::getPC("Goblin");
            else {
                pc = PC::getPC("Shade");
            }
        }
    } while(badinput);
    
    level = 1;
    floor = Floor::getInst();

    if (mode == 1)
    {
        floor->spawn();
        
    }
    
    else if (mode == 2)
    {
        spawnFile(file, floor);
    }
    floor->changemsg("Player character has spawned");
    display(floor);
    
    return pc;
}

void spawnFile(istream &file, Floor* floor){
    char read;
    
    for (int r = 0; r < maxRow; r++){
        for (int c = 0; c < maxCol; c++){
            file >> noskipws >> read;
            if (read == 10){
                file.ignore();
                file >> noskipws >> read;
            }
            if (read >= 48 && read <= 57){
                if (read >= 48 && r <= 53){
                    floor->setObj(r, c, new Potion);
                }
                else{
                    switch (read){
                        case '6':
                            floor->setObj(r, c, new Gold("small"));
                            break;
                        case '7':
                            floor->setObj(r, c, new Gold("normal"));
                            break;
                        case '8':
                            floor->setObj(r, c, new Gold("merchant hoard"));
                            break;
                        case '9':
                            Dtreasure* dt = new Dtreasure(floor);
                            dt->createDrag();
                            floor->setObj(r, c, dt);
                            break;
                    }
                }
            }
            else if (read >= 65 && read <= 90){
                Enemy* enemy = NULL;
                switch(read){
                    case 'H':
                        enemy = new Enemy("Human");
                        break;
                    case 'W':
                        enemy = new Enemy("Dwarf");
                        break;	
                    case 'E':
                        enemy = new Enemy("Elf");
                        break;	
                    case 'O':
                        enemy = new Enemy("Orcs");
                        break;	
                    case 'L':
                        enemy = new Enemy("Halfling");
                        break;
                    case 'M':
                        enemy = new Merchant;
                        break;
                    default:
                        enemy = NULL;
                        break;
                }
                if (enemy != NULL){
                    enemy->setPosn(r, c);
                    enemy->setFloor(floor);
                    floor->setObj(r, c, enemy);
                }
            }
            else if (read == '@'){
                PC* pc = PC::getPC();
                pc->setFloor(floor);
                pc->setPosn(r, c);
                floor->setObj(r, c, pc);
            }
            else if (read == 92){
                floor->setObj(r, c, new Stair);
            }
        }
    }
}

void display(Floor* floor){
    PC* pc = PC::getPC();
    floor->display();
    cout << "Race: " << pc->getRace();
    cout << " Gold: " << pc->getGold();
    cout << "\t\t\t\t\t\tFloor " << level << endl;
    cout << "HP: " << pc->getHP() << endl;
    cout << "Atk: " << pc->getAtk() << endl;
    cout << "Def: " << pc->getDef() << endl;
    cout << "Action: ";
    floor->showMsg();
    cout << endl;
    floor->clearmsg();
}
