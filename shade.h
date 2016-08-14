#ifndef __SHADE_H__
#define __SHADE_H__
#include "race.h"

class Shade : public Race {
  public:
   int addgold(int);
   void addteatk(TempEffect *&t,int val);
   void addtedef(TempEffect *&t,int val);
};
#endif
