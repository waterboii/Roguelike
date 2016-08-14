#include "shade.h"
#include <iostream>

using namespace std;

int Shade::addgold(int val){ return val;}

void Shade::addteatk(TempEffect *&t,int val){
   t->setatk(val);
}

void Shade::addtedef(TempEffect *&t,int val){
   t->setdef(val);
}
