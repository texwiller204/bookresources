// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement http://www.wild-magic.com/License/WildMagic3.pdf and
// may not be copied or disclosed except in accordance with the terms of that
// agreement.

#ifndef WM3DISTSEGMENT3RECTANGLE3_H
#define WM3DISTSEGMENT3RECTANGLE3_H

#include "Wm3Distance.h"
#include "Wm3Segment3.h"
#include "Wm3Rectangle3.h"

namespace Wm3
{

template <class Real>
class WM3_ITEM DistSegment3Rectangle3 : public Distance<Real,Vector3<Real> >
{
public:
    DistSegment3Rectangle3 (const Segment3<Real>& rkSegment,
        const Rectangle3<Real>& rkRectangle);

    // object access
    const Segment3<Real>& GetSegment () const;
    const Rectangle3<Real>& GetRectangle () const;

    // static distance queries
    virtual Real Get ();
    virtual Real GetSquared ();

    // function calculations for dynamic distance queries
    virtual Real Get (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);
    virtual Real GetSquared (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);

private:
    const Segment3<Real>& m_rkSegment;
    const Rectangle3<Real>& m_rkRectangle;
};

typedef DistSegment3Rectangle3<float> DistSegment3Rectangle3f;
typedef DistSegment3Rectangle3<double> DistSegment3Rectangle3d;

}

#endif
