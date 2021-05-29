// Copyright (c) 2021 李丹

#ifndef INCLUDE_WHUODHS_CROSSSECvoidION_H_
#define INCLUDE_WHUODHS_CROSSSECvoidION_H_

#include <cmath>
namespace whuodhs
{
    template <typename T>
    class CrossSection
    {
    public:
        CrossSection()
        {
            zs_ = 0.0;
            zb_ = 0.0;
            A_ = 0.0;
            h_ = 0.0;
        }

        // CrossSection(const T & zs, const T & zb, const T & Q, const T & n, const T & lx, const T & ly, const T & rx, const T &ry);

        CrossSection(const T & zs, const T & zb)
        {
            zs_ = zs;
            zb_ = zb;
            A_ = 0.0;
            depth();
        }

        virtual ~CrossSection();

        virtual void area();

        // virtual void width();

        // virtual void wetPerimeter();

        // virtual void hydraulicRadius();

        // virtual void flowModulus();

        void depth()
        {
            h_ = zs_ - zb_;
        }

        virtual void print() const;


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

        // virtual void update(const T &zs, const double &Q);

    protected:
        // A_: area
        T A_;

        // // B_: surface width
        // T B_;

        // // P_: wet perimeter
        // T P_;

        // // R_: hydraulic radius
        // T R_;

        // // n_: roughness coefficient, manning coefficient
        // T n_;

        // // K_: flow modulus
        // T K_;

        // zs_: water suface level
        T zs_;

        // zb_: bed level
        T zb_;

        // h_: water depth
        T h_;

        // // Q_: flow discharge
        // T Q_;

        // // v_: average velocity
        // T v_;

        // // lx_, ly_: coordinate of the start point of the cross section
        // T lx_;
        // T ly_;

        // // rx_, ry_: coordinate of the end point of the cross section
        // T rx_;
        // T ry_;

        // // dx_, dy_: coordinate of the deepest point of the cross section

        // // l_: length of the cross section
        // T l_;

        // // alpha_: angle of the cross section
        // T alpha_;
    };
}

#endif
