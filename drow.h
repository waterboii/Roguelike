#ifndef __DROW_H__
#define __DROW_H__
#include "race.h"
#include <iostream>

class Drow : public Race {
  public:
   int addgold(int);
   void addteatk(TempEffect *&t,int val);
   void addtedef(TempEffect *&t,int val);
};
#endif
