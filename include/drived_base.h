#ifndef TESTCALSS_DRIVEDBASE_H_
#define TESTCALSS_DRIVEDBASE_H_

#include <iostream>
#include "base.h"

class DrivedBase : public Base
{
public:
  DrivedBase(int i1, int i2);
  ~DrivedBase();
  virtual void print()  const override final;
private:
  int d_i;
};
#endif
