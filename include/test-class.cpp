#include <iostream>

using namespace std;

class Base
{
public:
    int public_i;

    Base(const int &i1, const int &i2, const int &i3)
    {
        public_i = i1;
        private_i = i2;
        protected_i = i3;
    }
    ~Base(){}

    virtual void print() const;

private:
    int private_i;

protected:
    int protected_i;
};

class DrivedBase : public Base
{
    public:
    DrivedBase(const int &i1, const int &i2, const int &i3, const int &i4);
    ~DrivedBase();

    void print() const
    {
        cout << public_i << "," << protected_i << endl;
        cout << myprivate_i;
    }

private:
    int myprivate_i;

};

DrivedBase::DrivedBase(const int &i1, const int &i2, const int &i3, const int &i4) : Base(i1, i2, i3), myprivate_i(i4){}

DrivedBase::~DrivedBase()
{

}

int main()
{
    DrivedBase test(1, 2, 3, 4);
    test.print();
}