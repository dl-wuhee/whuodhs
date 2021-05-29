#ifndef TESTCALSS_BASE_H_
#define TESTCALSS_BASE_H_

class Base
{
public:
  int public_i;
  int private_i;
  int protected_i;
  Base(const int i1, const int i2, const int i3);
  ~Base();

  virtual void print() const;

private:

protected:
};
#endif
