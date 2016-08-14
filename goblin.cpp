#include <iostream>
#include "goblin.h"

using namespace std;

int Goblin::addgold(int val){
    int final = val + 5;
    return final;
}

void Goblin::addteatk(TempEffect *&t,int val){
   t->setatk(val);
}

void Goblin::addtedef(TempEffect *&t,int val){
   t->setdef(val);
}

