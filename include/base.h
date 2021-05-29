#ifndef TESTCALSS_BASE_H_
#define TESTCALSS_BASE_H_

class Base
{
public:
  Base(int i) {b_i = i;}
  virtual ~Base() {}
  // Note: pure virtual function print
  // if not include =0, link will give error
  virtual void print() const = 0;
protected:
  int b_i;
};
#endif
