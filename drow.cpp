#include <iostream>
#include "drow.h"

using namespace std;


int Drow::addgold(int val){ return val;}

void Drow::addteatk(TempEffect *&t,int val){
   int final = val * 1.5;
   t->setatk(final);
}

void Drow::addtedef(TempEffect *&t,int val){
   int final = val * 1.5;
   t->setdef(final);
}
