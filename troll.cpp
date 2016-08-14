#include <iostream>
#include "troll.h"

using namespace std;

int Troll::addgold(int val){ return val;}

void Troll::addteatk(TempEffect *&t,int val){
   t->setatk(val);
}

void Troll::addtedef(TempEffect *&t,int val){
   t->setdef(val);
}
