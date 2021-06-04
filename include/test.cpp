#include "rectanglecrosssection.h"
#include "trapezoidcrosssection.h"
#include "compoundcrosssection.h"

using namespace Whuodhs;
int main()
{
    RectangleCrossSection<double> rcs[3] = 
    {
      RectangleCrossSection<double>(1.0, -2.0, 100.0, 30.0, 0.02, 3.0, 0.0, 0.0, 0.0, 3.0),
      RectangleCrossSection<double>(2.0, -2.0, 100.0, 30.0, 0.02, 3.0, 100.0, 0.0, 100.0, 3.0),
      RectangleCrossSection<double>(3.0, -2.0, 100.0, 30.0, 0.02, 3.0, 200.0, 0.0, 200.0, 3.0)
    };
  //for (int i=0; i<3; i++)
    //{
      //rcs[i].print();
      //rcs[i].update(10.0 * i, 100.0);
      //rcs[i].print();
    //}
  rcs[0].print();

  RectangleCrossSection<double> rcs3 = RectangleCrossSection<double>(rcs[0], 100, 100, -1.0);
  rcs3.print();

    TrapezoidCrossSection<double> tcs[3] = 
    {
      TrapezoidCrossSection<double>(1.0, -2.0, 100.0, 30.0, 0.02, 3.0, 2.0, 0.0, 0.0, 0.0, 3.0),
      TrapezoidCrossSection<double>(2.0, -2.0, 100.0, 30.0, 0.02, 3.0, 2.0, 100.0, 0.0, 100.0, 3.0),
      TrapezoidCrossSection<double>(3.0, -2.0, 100.0, 30.0, 0.02, 3.0, 2.0, 200.0, 0.0, 200.0, 3.0)
    };
  for (int i=0; i<3; i++)
    {
      //tcs[i].print();
      tcs[i].update(10.0 * i, 100.0);
      //tcs[i].print();
    }
    tcs[0].print();

    TrapezoidCrossSection<double> tcs3 = TrapezoidCrossSection<double>(tcs[0], 100, 100, -1.0);
    tcs3.print();


    CompoundCrossSection<double> ccs[3] = 
    {
      CompoundCrossSection<double>(1.0, -2.0, 100.0, 30.0, 0.02, 2.0, 1.0, 2.0, 1.0, 1.0, 0.0, 0.0, 0.0, 3.0),
      CompoundCrossSection<double>(2.0, -2.0, 100.0, 30.0, 0.02, 2.0, 1.0, 2.0, 1.0, 1.0, 100.0, 0.0, 100.0, 3.0),
      CompoundCrossSection<double>(3.0, -2.0, 100.0, 30.0, 0.02, 2.0, 1.0, 2.0, 1.0, 1.0, 200.0, 0.0, 200.0, 3.0)
    };
  for (int i=0; i<3; i++)
    {
      //ccs[i].print();
      ccs[i].update(10.0 * i, 100.0);
      //ccs[i].print();
    }
}
