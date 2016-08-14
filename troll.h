#ifndef __TROLL_H__
#define __TROLL_H__
#include "race.h"
#include <iostream>
class Troll : public Race {
  public:
   int addgold(int);
   void addteatk(TempEffect *&t,int val);
   void addtedef(TempEffect *&t,int val);
};
#endif
