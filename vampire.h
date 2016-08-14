#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__
#include "race.h"
#include <iostream>
class Vampire : public Race {
  public:
   int addgold(int);
   void addteatk(TempEffect *&t,int val);
   void addtedef(TempEffect *&t,int val);
};
#endif
