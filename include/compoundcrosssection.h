// Copyright (c) 2021 李丹

#ifndef INCLUDE_WHUODHS_COMPOUNDCROSSSECTION_H_
#define INCLUDE_WHUODHS_COMPOUNDCROSSSECTION_H_

#include <iostream>
#include <cmath>
#include "crosssection.h"

namespace Whuodhs
{
  template <typename T>
    class CompoundCrossSection : public CrossSection<T>
    {
  public:
    CompoundCrossSection(const T &zs, const T & zb, const T & H,
                         const T & Q, const T & n, const T &b1, const T & m1,
                         const T &b0, const T & m0, const T & h0,
                         const T & lx, const T & ly, const T & rx, const T & ry);
    ~CompoundCrossSection() {};
    virtual void print() const override final;
    virtual void update(const T & zs, const T & Q) override final;

    // void update(const T & zs, const T & Q) override final
    // {
    //   _A = area(Zs);

    // }

  private:
    virtual T area() override final;
    virtual T width() override final;
    virtual T wetPerimeter() override final;
    virtual T hydraulicRadius() override final;
    virtual T flowModulus() override final;
    T b1_;
    T m1_;
    T h1_;
    T b0_;
    T m0_;
    T h0_;
    };

  template <typename T>
    T CompoundCrossSection<T>::area()
      {
        if (this->h1_ < 0.0) {
            return (this->b0_ + this->m0_ * this->h_) * this->h_;
        }else 
          {
            return (this->b0_ + this->m0_ * this->h0_) * this->h0_ +
              (this->b0_ + 2.0 * this->b1_ + this->m1_ * this->h1_) * this->h1_;
          }
      }

  template <typename T>
    T CompoundCrossSection<T>::width()
      {
        if (this->h1_ < 0.0){
            return this->b0_ + 2.0 * this->m0_ * this->h_;
        }
        else
          {
            return this->b0_ + 2.0 * this->b1_ + 2.0 * this->m1_ * this->h1_;
          }
      }

  template <typename T>
    T CompoundCrossSection<T>::wetPerimeter()
      {
        if (this->h1_ < 0.0)
          {
        return (this->b0_ + 2.0 * this->h_ * std::pow(1 + this->m0_ * this->m0_, 0.5));
          }
        else
          {
        return (this->b0_ + 2.0 * this->h0_ * std::pow(1 + this->m0_ * this->m0_, 0.5) 
                +
                2.0 * this->b1_ + 2.0 * this->h1_ * std::pow(1 + this->m1_ * this->m1_, 0.5));
          }
      }

  template <typename T>
    T CompoundCrossSection<T>::hydraulicRadius()
      {
        return (area() / wetPerimeter());
      }

  template <typename T>
    T CompoundCrossSection<T>::flowModulus()
      {
        return (this->A_ * std::pow(this->R_, (2.0/3.0)) / this->n_);
      }

  template <typename T>
    CompoundCrossSection<T>::CompoundCrossSection(const T &zs, const T & zb, const T & H, 
                                                  const T & Q, const T & n,
                                                  const T &b1, const T &m1, 
                                                  const T &b0, const T &m0, const T &h0,
                                                  const T & lx, const T & ly,
                                                  const T & rx, const T & ry)
    : CrossSection<T>(zs, zb, H, Q, n, lx, ly, rx, ry)
      {
        this->b0_ = b0;
        this->m0_ = m0;
        this->h0_ = h0;
        this->b1_ = b1;
        this->m1_ = m1;
        this->h1_ = this->h_ - this->h0_;
        this->A_ = area();
        this->B_ = width();
        this->P_ = wetPerimeter();
        this->R_ = hydraulicRadius();
        this->K_ = flowModulus();
        this->mag_ = std::hypot(rx-lx, ry-ly);
        this->ang_ = std::atan((ry-ly) / (rx-lx));
        this->dx_ = 0.5 * (lx + rx);
        this->dy_ = 0.5 * (ly + ry);
        this->v_ = this->Q_ / this->A_;
      }

  template <typename T>
    void CompoundCrossSection<T>::print() const
      {
        std::cout << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "  Current Cross Section Info:" << std::endl;
        std::cout << "  Area: " << this->A_ << std::endl;
        std::cout << "  Surface Width: " << this->B_ << std::endl;
        std::cout << "  Bottom Width: " << this->b0_ << std::endl;
        std::cout << "  Bottom Slope Coefficeint: " << this->m0_ << std::endl;
        std::cout << "  Main Channel Height : " << this->h0_ << std::endl;
        std::cout << "  Floodplain Width: " << this->b1_ << std::endl;
        std::cout << "  Floodplain Slope Coefficeint: " << this->m1_ << std::endl;
        std::cout << "  Floodplain Height : " << this->h1_ << std::endl;
        std::cout << "  Wet Perimeter: " << this->P_ << std::endl;
        std::cout << "  Hydraulic Radius: " << this->R_ << std::endl;
        std::cout << "  Flow Modula: " << this->K_ << std::endl;
        std::cout << "  Manning Coefficient: " << this->n_ << std::endl;
        std::cout << "  Water Level: " << this->zs_ << std::endl;
        std::cout << "  Bed Level: " << this->zb_ << std::endl;
        std::cout << "  Water Depth: " << this->h_ << std::endl;
        std::cout << "  Section Depth: " << this->H_ << std::endl;
        std::cout << "  Flow Discharge: " << this->Q_ << std::endl;
        std::cout << "  Average Velocity: " << this->v_ << std::endl;
        std::cout << "  Section Location: " << std::endl;
        std::cout << "      " << "start point: " <<  std::endl;
        std::cout << "      " << "    x: " << this->lx_ << std::endl;
        std::cout << "      " << "    y: " << this->ly_ << std::endl;
        std::cout << "      " << "end point: " <<  std::endl;
        std::cout << "      " << "    x: " << this->rx_ << std::endl;
        std::cout << "      " << "    y: " << this->ry_ << std::endl;
        std::cout << "      " << "deep point: " <<  std::endl;
        std::cout << "      " << "    x: " << this->dx_ << std::endl;
        std::cout << "      " << "    y: " << this->dy_ << std::endl;
        std::cout << "      " << "length: " << this->mag_ << std::endl;
        std::cout << "      " << "angle:  " << this->ang_ << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << std::endl;
      }

  template <typename T>
    void CompoundCrossSection<T>::update(const T & zs, const T & Q)
      {
        this->zs_ = zs;
        this->h_ = zs - this->zb_;
        this->Q_ = Q;
        this->A_ = area();
        this->B_ = width();
        this->P_ = wetPerimeter();
        this->R_ = hydraulicRadius();
        this->K_ = flowModulus();
        this->v_ = this->Q_ / this->A_;
      }

}
#endif


