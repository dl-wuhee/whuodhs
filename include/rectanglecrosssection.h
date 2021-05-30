// Copyright (c) 2021 李丹

#ifndef INCLUDE_WHUODHS_RECTANGLECROSSSECTION_H_
#define INCLUDE_WHUODHS_RECTANGLECROSSSECTION_H_

#include <iostream>
#include <cmath>
#include "crosssection.h"

namespace Whuodhs
{
  template <typename T>
    class RectangleCrossSection : public CrossSection<T>
    {
  public:
    RectangleCrossSection(const RectangleCrossSection<T> & rcs, 
                          const T & mx = 0.0,
                          const T & my = 0.0,
                          const T & rang = 0.0,
                          const T & zb = 0.0,
                          const T & zs = 0.0);
    RectangleCrossSection(const T &zs, const T & zb, const T & H,
                          const T & Q, const T & n, const T &b,
                          const T & lx, const T & ly, const T & rx, const T & ry);
    ~RectangleCrossSection() {};
    virtual void print() const override final;
    virtual void update(const T & zs, const T & Q) override final;
  private:
    virtual T area() override final;
    virtual T width() override final;
    virtual T wetPerimeter() override final;
    virtual T hydraulicRadius() override final;
    virtual T flowModulus() override final;
    T b_;
    };

  template <typename T>
    T RectangleCrossSection<T>::area()
      {
        return this->b_ * this->h_;
      }

  template <typename T>
    T RectangleCrossSection<T>::width()
      {
        return this->b_;
      }

  template <typename T>
    T RectangleCrossSection<T>::wetPerimeter()
      {
        return (this->b_ + 2.0 * this->h_);
      }

  template <typename T>
    T RectangleCrossSection<T>::hydraulicRadius()
      {
        return (area() / wetPerimeter());
      }

  template <typename T>
    T RectangleCrossSection<T>::flowModulus()
      {
        return (this->A_ * std::pow(this->R_, (2.0/3.0)) / this->n_);
      }

  template <typename T>
    RectangleCrossSection<T>::RectangleCrossSection(const RectangleCrossSection<T> & rcs,
                                                    const T & mx,
                                                    const T & my,
                                                    const T & rang,
                                                    const T & zb,
                                                    const T & zs)
      {
        this->zb_ = rcs.zb_;
        this->zs_ = rcs.zs_;
        this->b_ = rcs.b_;
        this->Q_ = rcs.Q_;
        this->mag_ = rcs.mag_;
        this->ang_ = rcs.ang_;
        this->lx_ = rcs.lx_;
        this->ly_ = rcs.ly_;
        this->rx_ = rcs.rx_;
        this->ry_ = rcs.ry_;
        this->dx_ = rcs.dx_;
        this->dy_ = rcs.dy_;

        //this->zb_ = zb;

        this->A_ = area();
        this->B_ = width();
        this->P_ = wetPerimeter();
        this->R_ = hydraulicRadius();
        this->K_ = flowModulus();
        this->v_ = this->Q_ / this->A_;
      }

  template <typename T>
    RectangleCrossSection<T>::RectangleCrossSection(const T &zs, const T & zb, const T & H, 
                                                    const T & Q, const T & n, const T &b,
                                                    const T & lx, const T & ly, 
                                                    const T & rx, const T & ry)
    : CrossSection<T>(zs, zb, H, Q, n, lx, ly, rx, ry)
      {
        this->b_ = b;
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
    void RectangleCrossSection<T>::print() const
      {
        std::cout << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "  Current Cross Section Info:" << std::endl;
        std::cout << "  Area: " << this->A_ << std::endl;
        std::cout << "  Surface Width: " << this->B_ << std::endl;
        std::cout << "  Bottom Width: " << this->b_ << std::endl;
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
    void RectangleCrossSection<T>::update(const T & zs, const T & Q)
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
