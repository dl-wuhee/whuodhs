// Copyright (c) 2021 李丹

#ifndef INCLUDE_WHUODHS_CROSSSECION_H_
#define INCLUDE_WHUODHS_CROSSSECION_H_

#include <cmath>
#include "coordinate.h"

namespace Whuodhs
{
  template <typename T>
    class CrossSection
      {
    public:
      CrossSection();
      CrossSection(const T & zs, const T & zb, const T & H, const T & Q, const T & n, 
                                  const Coord2<T> & lp, const Coord2<T> & rp, const Coord2<T> & dp = Coord2<T>(0.0, 0.0));
      virtual ~CrossSection() {};
      //virtual void flowModulus() = 0;
      virtual void print() const = 0;
      virtual void update(const T & zs, const T & Q) = 0;
    protected:
      virtual T area() = 0;
      virtual T width() = 0;
      virtual T wetPerimeter() = 0;
      virtual T hydraulicRadius() = 0;  
      virtual T flowModulus() = 0;
      // A_: area
      T A_;
      // B_: water width
      T B_;
      // P_: wet perimeter
      T P_;
      // R_: hydraulic radius
      T R_;
      // n_: roughness coefficient, manning coefficient
      T n_;
      // K_: flow modulus
      T K_;
      // zs_: water suface level
      T zs_;
      // zb_: bed level
      T zb_;
      // H_: cross section depth
      T H_;
      // h_: water depth
      T h_;
      // Q_: flow discharge
      T Q_;
      // v_: average velocity
      T v_;
      // lx_, ly_: coordinate of the start point of the cross section
      Coord2<T> lp_;
      // rx_, ry_: coordinate of the end point of the cross section
      Coord2<T> rp_;
      // dx_, dy_: coordinate of the deepest point of the cross section
      Coord2<T> dp_;
      // l_: length of the cross section
      T mag_;
      // alpha_: angle of the cross section
      T ang_;
      };


  template <typename T>
    CrossSection<T>::CrossSection()
      {
        A_ = 0.0;
        B_ = 0.0;
        P_ = 0.0;
        R_ = 0.0;
        n_ = 0.0;
        K_ = 0.0;
        zs_ = 0.0;
        zb_ = 0.0;
        H_ = 0.0;
        h_ = 0.0;
        Q_ = 0.0;
        v_ = 0.0;
        lp_ = Coord2<T>(0.0, 0.0);
        rp_ = Coord2<T>(0.0, 0.0);
        dp_ = Coord2<T>(0.0, 0.0);
        mag_ = 0.0;
        ang_ = 0.0;
      }

  template <typename T>
    CrossSection<T>::CrossSection(const T & zs, const T & zb, const T & H, const T & Q, const T & n, 
                                  const Coord2<T> & lp, const Coord2<T> &rp, const Coord2<T> & dp)
      {
        zs_ = zs;
        zb_ = zb;
        H_ = H;
        Q_ = Q;
        n_ = n;

        lp_ = lp;
        rp_ = rp;
        dp_ = dp;

        h_ = zs_ - zb_;
      }


}

#endif
