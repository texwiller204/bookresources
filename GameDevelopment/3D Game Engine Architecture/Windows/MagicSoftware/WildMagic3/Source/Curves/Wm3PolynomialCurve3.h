// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement http://www.wild-magic.com/License/WildMagic3.pdf and
// may not be copied or disclosed except in accordance with the terms of that
// agreement.

#ifndef WM3POLYNOMIALCURVE3_H
#define WM3POLYNOMIALCURVE3_H

#include "Wm3Polynomial1.h"
#include "Wm3SingleCurve3.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM PolynomialCurve3 : public SingleCurve3<Real>
{
public:
    // Construction and destruction.  PolynomialCurve3 accepts responsibility
    // for deleting the input polynomials.
    PolynomialCurve3 (Polynomial1<Real>* pkXPoly, Polynomial1<Real>* pkYPoly,
        Polynomial1<Real>* pkZPoly);

    virtual ~PolynomialCurve3 ();

    int GetDegree () const;
    const Polynomial1<Real>* GetXPolynomial () const;
    const Polynomial1<Real>* GetYPolynomial () const;
    const Polynomial1<Real>* GetZPolynomial () const;

    virtual Vector3<Real> GetPosition (Real fTime) const;
    virtual Vector3<Real> GetFirstDerivative (Real fTime) const;
    virtual Vector3<Real> GetSecondDerivative (Real fTime) const;
    virtual Vector3<Real> GetThirdDerivative (Real fTime) const;

    virtual Real GetVariation (Real fT0, Real fT1,
        const Vector3<Real>* pkP0 = 0, const Vector3<Real>* pkP1 = 0) const;

protected:
    Polynomial1<Real>* m_pkXPoly;
    Polynomial1<Real>* m_pkYPoly;
    Polynomial1<Real>* m_pkZPoly;
    Polynomial1<Real> m_kXDer1, m_kYDer1, m_kZDer1;
    Polynomial1<Real> m_kXDer2, m_kYDer2, m_kZDer2;
    Polynomial1<Real> m_kXDer3, m_kYDer3, m_kZDer3;
};

typedef PolynomialCurve3<float> PolynomialCurve3f;
typedef PolynomialCurve3<double> PolynomialCurve3d;

}

#endif
