// Copyright (c) 2021 李丹

#ifndef INCLUDE_WHUODHS_CROSSSECION_H_
#define INCLUDE_WHUODHS_CROSSSECION_H_

#include <cmath>

namespace Whuodhs
{
  template <typename T>
    class CrossSection
      {
    public:
      CrossSection();
      CrossSection(const T & zs, const T & zb, const T & H, const T & Q, const T & n, 
                                  const T & lx, const T & ly, const T &rx, const T & ry);
      virtual ~CrossSection() {};
      //virtual void flowModulus() = 0;
      virtual void print() const = 0;
      virtual void update(const T & zs, const T & Q) = 0;


      // void velocity()
      // {
      //     v_ = Q_ / A_;
      // }

      // void length()
      // {
      //     l_ = std::hypot(rx_ - lx_, ry_ - ly_);
      // }

      // void angle()
      // {
      //     alpha_ = std::atan(ry_ - ly_, rx_ - lx_);
      // }

      // virtual void update(const T &zs, const T &Q);

    protected:
      virtual T area() = 0;
      virtual T width() = 0;
      virtual T wetPerimeter() = 0;
      virtual T hydraulicRadius() = 0;
      virtual T flowModulus() = 0;

      // A_: area
      T A_;
      // B_: surface width
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
      T lx_;
      T ly_;
      // rx_, ry_: coordinate of the end point of the cross section
      T rx_;
      T ry_;
      // dx_, dy_: coordinate of the deepest point of the cross section
      T dx_;
      T dy_;
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
        lx_ = 0.0;
        ly_ = 0.0;
        rx_ = 0.0;
        ry_ = 0.0;
        dx_ = 0.0;
        dy_ = 0.0;
        mag_ = 0.0;
        ang_ = 0.0;
      }

  template <typename T>
    CrossSection<T>::CrossSection(const T & zs, const T & zb, const T & H, const T & Q, const T & n, 
                                  const T & lx, const T & ly, const T &rx, const T & ry)
      {
        zs_ = zs;
        zb_ = zb;
        H_ = H;
        Q_ = Q;
        n_ = n;

        lx_ = lx;
        ly_ = ly;
        rx_ = rx;
        ry_ = ry;

        h_ = zs_ - zb_;
      }


}

#endif
