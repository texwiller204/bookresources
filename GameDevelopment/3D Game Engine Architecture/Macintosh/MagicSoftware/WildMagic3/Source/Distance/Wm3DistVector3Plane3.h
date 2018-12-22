// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement http://www.wild-magic.com/License/WildMagic3.pdf and
// may not be copied or disclosed except in accordance with the terms of that
// agreement.

#ifndef WM3DISTVECTOR3PLANE3_H
#define WM3DISTVECTOR3PLANE3_H

#include "Wm3Distance.h"
#include "Wm3Plane3.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM DistVector3Plane3 : public Distance<Real,Vector3<Real> >
{
public:
    DistVector3Plane3 (const Vector3<Real>& rkVector,
        const Plane3<Real>& rkPlane);

    // object access
    const Vector3<Real>& GetVector () const;
    const Plane3<Real>& GetPlane () const;

    // static distance queries
    virtual Real Get ();
    virtual Real GetSquared ();

    // function calculations for dynamic distance queries
    virtual Real Get (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);
    virtual Real GetSquared (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);

private:
    const Vector3<Real>& m_rkVector;
    const Plane3<Real>& m_rkPlane;
};

typedef DistVector3Plane3<float> DistVector3Plane3f;
typedef DistVector3Plane3<double> DistVector3Plane3d;

}

#endif
