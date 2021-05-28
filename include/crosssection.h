// Copyright (c) 2021 李丹

#ifndef INCLUDE_WHUODHS_CROSSSECvoidION_H_
#define INCLUDE_WHUODHS_CROSSSECvoidION_H_

namespace whuodhs
{
    class CrossSection
    {
    public:
        CrossSection();

        CrossSection(const double &Zs, const double &Q);

        virtual ~CrossSection();

        virtual void update();

    protected:
        // _A: area
        double _A;

        // _B: surface width
        double _B;

        // _P: wet perimeter
        double _P;

        // _R: hydraulic radius
        double _R;

        // _n: roughness coefficient, manning coefficient
        double _n;

        // _K: flow modulus
        double _K;

        // _Zs: water suface level
        double _Zs;

        // _Zb: bed level
        double _Zb;

        // _h: water depth
        double _h;

        // _Q: flow discharge
        double _Q;

        // _v: average velocity
        double _v;

        // _lCoord: cooridnate of the start point of the cross section
        double _lx;
        double _ly;

        // _rCoord: cooridnate of the end point of the cross section
        double _rx;
        double _ry;

        // _L: length of the cross section
        double _L;
    };
}

#endif
