#ifndef __GOBLIN_H__
#define __GOBLIN_H__
#include "race.h"
#include <iostream>
class Goblin : public Race {
  public:
   int addgold(int);
   void addteatk(TempEffect *&t,int val);
   void addtedef(TempEffect *&t,int val);
};
#endif
