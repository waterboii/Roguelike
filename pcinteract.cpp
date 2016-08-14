//
//  pcinteract.cpp
//  cc3k
//
//  Created by Kaiming Yu on 2014-11-29.
//  Copyright (c) 2014 Kaiming Yu. All rights reserved.
//

#include "pcinteract.h"
#include "PC.h"
#include "enemy.h"
#include "potion.h"
#include "gold.h"
#include "merchant.h"
#include "dragon.h"
#include "dtreasure.h"
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

PCInteract::PCInteract():Interact(){}

//PC = 'p'
//enemy = 'e'
//treasure = 't'
//potion = 'b'
//stair = 's'

void PCInteract::move(Object *o) {
    PC *pc1 = dynamic_cast<PC*>(o);
    if (ob != NULL)
    {
        char targettype = ob->getType();
        if (targettype == 't')
        {
            Gold *gold = dynamic_cast<Gold*>(ob);
            if (gold->getGoldType() == "dragon hoard")
            {
                Dtreasure *dgold = dynamic_cast<Dtreasure*>(ob);
                if (dgold->getDdead() == true)
                {
                    pc1->newGold(gold->goldValue());
                    floor->clearCell(tr, tc);
                    floor->setObj(tr, tc, o);
                    floor->setObj(pr, pc, NULL);
                    pr = tr;
                    pc = tc;
                    string msg =  "You picked up 6 gold. ";
                    floor->changemsg(msg);
                }
                else
                {
                    string msg =  "Evil Dragon is Staring at YOU! ";
                    floor->changemsg(msg);
                }
            }
            else
            {
                int amt = gold->goldValue();
                pc1->newGold(gold->goldValue());
                floor->clearCell(tr, tc);
                floor->setObj(tr, tc, o);
                floor->setObj(pr, pc, NULL);
                pr = tr;
                pc = tc;
                string msg = "";
                stringstream tostr;
                tostr << amt;
                string amount = tostr.str();
                msg = "PC picked up " + amount + " gold.";
                floor->changemsg(msg);
            }
        }
    }
    else
    {
        int ftype = floor->getFloorType(tr, tc);
        if (ftype == 'g' || ftype == 'd' || ftype == 'c')
        {
            string plist = "";
            Object **around = floor->PotionInRange(tr, tc);
            for (int i = 0; i < 8; i++) {
                if (around[i] != NULL && around[i]->getType() == 'b')
                {
                    Potion *p = dynamic_cast<Potion*>(around[i]);
                    if (pc1->checkPotion(p->getVar()) == 1)
                    {
                        plist += p->getVar() + " ";
                    }
                    else
                    {
                        plist += "an unknown ";
                    }
                }
            }
            floor->setObj(tr,tc, o);
            floor->setObj(pr, pc, NULL);
            pr = tr;
            pc = tc;
            
            if (plist == "")
            {
                string msg = "";
                msg = "PC moves " + dir + ". ";
                floor->changemsg(msg);
            }
            
            else
            {
                string msg = "";
                plist += "potion. ";
                msg = "PC moves " + dir + " and sees " + plist;
                floor->changemsg(msg);
            }	
            for (int i = 0; i < 6; i++) {
                around[i] = NULL;
            }
            delete[] around;
            
        }
        
        if (ftype == 'x' || ftype == 'y')
        {
            string msg = "PC tried to walk hit a wall, but wall punched PC back. ";
            floor->changemsg(msg);
        }
        if (ftype == 'b')
        {
            string msg = "Hollow....";
            floor->changemsg(msg);
        }
    }
}

        
void PCInteract::attack(Object *o){
    PC *pc1 = (PC *)o;
    string output;
    if (ob == NULL){
        output = "There's no enemy.";
        floor->changemsg(output);
        return;
    }
    char ttype = ob->getType();
    if (ttype == 'e'){
        Enemy *enemy = dynamic_cast<Enemy *>(ob);
        
        if (enemy->getSymbol() == 'M'){
            Merchant *merchant = dynamic_cast<Merchant *>(ob);
            merchant->setHostile();
        }
        if (pc1->getRace() == "Vampire") {
            pc1->newHP(-5);
        }
        float enemydef = enemy->getDef();
        float PCatk = pc1->getAtk();
        int dmg = ceil((100/(100+enemydef))* PCatk);
        stringstream num;
        num << dmg;
        string damage = num.str();
        stringstream num1;
        enemy->setHP(dmg);
        num1 << enemy->getHP();
        string newhp = num1.str();
        output = "You dealt " + damage + " to " + enemy->getName() + ".(" + newhp + " HP left)";
        floor->changemsg(output);
        
        if (enemy->getHP() <= 0){
            int amt = enemy->dropGold();
            pc1->newGold(amt);
            if (enemy->getSymbol() == 'M'){
                floor->clearCell(tr,tc);
                floor->spawnGold(tr,tc);
            }
            else if(enemy->getSymbol() == 'D'){
                Dragon *dragon = (Dragon *)(enemy);
                dragon->notify();
                floor->clearCell(tr,tc);
            }
            else{
                floor->clearCell(tr,tc);
            }
            
            stringstream temp;
            temp << amt;
            string amount = temp.str();
            output = output + "You got " + amount + " Gold!";
            floor->changemsg(output);
        }
    }
}

void PCInteract::drinkP(PC *p){
    if (ob == NULL){
        return;
    }
    char ttype = ob->getType();
    if (ttype == 'b'){
        Potion *potion = dynamic_cast<Potion *>(ob);
        string type = potion->getVar();
        if (p->checkPotion(type) == 0){
            p->trackPotion(type);
        }
        
        p->newTe(type,potion->getAmount());
        floor->clearCell(tr,tc);
        string output = "Drinking " + type + ".";
        floor->changemsg(output);
    }
}

int PCInteract::getRow(){ return pr; }

int PCInteract::getCol(){ return pc;}