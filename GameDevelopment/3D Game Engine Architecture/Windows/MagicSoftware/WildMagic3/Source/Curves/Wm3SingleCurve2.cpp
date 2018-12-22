// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement http://www.wild-magic.com/License/WildMagic3.pdf and
// may not be copied or disclosed except in accordance with the terms of that
// agreement.

#include "Wm3SingleCurve2.h"
#include "Wm3Integrate1.h"

namespace Wm3
{
//----------------------------------------------------------------------------
template <class Real>
SingleCurve2<Real>::SingleCurve2 (Real fTMin, Real fTMax)
    :
    Curve2<Real>(fTMin,fTMax)
{
}
//----------------------------------------------------------------------------
template <class Real>
Real SingleCurve2<Real>::GetSpeedWithData (Real fTime, void* pvData)
{
    return ((Curve2<Real>*)pvData)->GetSpeed(fTime);
}
//----------------------------------------------------------------------------
template <class Real>
Real SingleCurve2<Real>::GetLength (Real fT0, Real fT1) const
{
    assert( m_fTMin <= fT0 && fT0 <= m_fTMax );
    assert( m_fTMin <= fT1 && fT1 <= m_fTMax );
    assert( fT0 <= fT1 );

    return Integrate1<Real>::RombergIntegral(8,fT0,fT1,GetSpeedWithData,
        (void*)this);
}
//----------------------------------------------------------------------------
template <class Real>
Real SingleCurve2<Real>::GetTime (Real fLength, int iIterations,
    Real fTolerance) const
{
    if ( fLength <= (Real)0.0 )
        return m_fTMin;

    if ( fLength >= GetTotalLength() )
        return m_fTMax;

    // initial guess for Newton's method
    Real fRatio = fLength/GetTotalLength();
    Real fOmRatio = ((Real)1.0) - fRatio;
    Real fTime = fOmRatio*m_fTMin + fRatio*m_fTMax;

    for (int i = 0; i < iIterations; i++)
    {
        Real fDifference = GetLength(m_fTMin,fTime) - fLength;
        if ( Math<Real>::FAbs(fDifference) < fTolerance )
            return fTime;

        fTime -= fDifference/GetSpeed(fTime);
    }

    // Newton's method failed.  If this happens, increase iterations or
    // tolerance or integration accuracy.
    return Math<Real>::MAX_REAL;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
// float
template WM3_ITEM
class SingleCurve2<float>;

// double
template WM3_ITEM
class SingleCurve2<double>;
//----------------------------------------------------------------------------
}
