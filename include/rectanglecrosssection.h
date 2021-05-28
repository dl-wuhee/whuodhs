// Copyright (c) 2021 李丹

#ifndef INCLUDE_WHUODHS_RECTANGLECROSSSECTION_H_
#define INCLUDE_WHUODHS_RECTANGLECROSSSECTION_H_

namespace whuodhs
{
  class RectangleCrossSection final : public CrossSection
  {
  public:
    RectangleCrossSection();

    ~RectangleCrossSection();

    void update(const double &Zs, const double &Q) override final
    {
      _A = area(Zs, Q);
      
    }
  };

private:
  double _b;
}
#endif
