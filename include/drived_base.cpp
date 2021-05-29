#include "drived_base.h"

DrivedBase::DrivedBase(int i1, int i2): Base(i1)
{
  d_i = i2;
}

DrivedBase::~DrivedBase()
{
  std::cout << "~DrivedBase" << std::endl;
}

void DrivedBase::print() const
{
  std::cout << b_i << std::endl;
  std::cout << d_i << std::endl;
}


