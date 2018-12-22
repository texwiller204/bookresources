// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement http://www.wild-magic.com/License/WildMagic3.pdf and
// may not be copied or disclosed except in accordance with the terms of that
// agreement.

#ifndef WM3INTPAKIMANONUNIFORM1_H
#define WM3INTPAKIMANONUNIFORM1_H

#include "Wm3IntpAkima1.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM IntpAkimaNonuniform1 : public IntpAkima1<Real>
{
public:
    // Construction and destruction.  IntpAkimaNonuniform1 does not
    // accept responsibility for deleting the input arrays.  The application
    // must do so.  The interpolator is for arbitrarily spaced x-values.
    IntpAkimaNonuniform1 (int iQuantity, Real* afX, Real* afF);
    virtual ~IntpAkimaNonuniform1 ();

    const Real* GetX () const;
    virtual Real GetXMin () const;
    virtual Real GetXMax () const;

protected:
    virtual bool Lookup (Real fX, int& riIndex, Real& rfDX) const;

    Real* m_afX;
};

typedef IntpAkimaNonuniform1<float> IntpAkimaNonuniform1f;
typedef IntpAkimaNonuniform1<double> IntpAkimaNonuniform1d;

}

#endif
