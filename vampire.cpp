#include "vampire.h"
#include <iostream>

using namespace std;

int Vampire::addgold(int val){ return val;}

void Vampire::addteatk(TempEffect *&t,int val){
   t->setatk(val);
}

void Vampire::addtedef(TempEffect *&t,int val){
   t->setdef(val);
}

