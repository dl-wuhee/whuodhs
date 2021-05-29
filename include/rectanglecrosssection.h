// Copyright (c) 2021 李丹

#ifndef INCLUDE_WHUODHS_RECTANGLECROSSSECTION_H_
#define INCLUDE_WHUODHS_RECTANGLECROSSSECTION_H_

#include <iostream>
#include "crosssection.h"

namespace whuodhs
{
  template <typename T>
  class RectangleCrossSection  : public CrossSection<T>
  {
  public:
    RectangleCrossSection(const T &zs, const T &zb, const T &b);

    ~RectangleCrossSection();

    void area() override final
    {
      A_ = b_ * h_;
    }

    void print() const override final;
    // void width() override final
    // {

    // }

    // void update(const T & zs, const T & Q) override final
    // {
    //   _A = area(Zs);

    // }

  private:
    T b_;
  };

  template <typename T>
  RectangleCrossSection<T>::RectangleCrossSection(const T &zs, const T &zb, const T &b) : CrossSection<T>(zs, zb), b_(b) {
    area();
  }

  template <typename T>
  void RectangleCrossSection<T>::print() const
  {
    std::cout << "Water Level: " << zs_ << std::endl;
    std::cout << "Bed Level: " << zb_ << std::endl;
    std::cout << "Water Height: " << h_ << std::endl;
    std::cout << "Channel Width: " << b_ << std::endl;
    std::cout << "Area: " << A_ << std::endl;
  }
}
#endif
