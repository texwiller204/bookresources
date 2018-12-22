// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement http://www.wild-magic.com/License/WildMagic3.pdf and
// may not be copied or disclosed except in accordance with the terms of that
// agreement.

#ifndef WM3REVOLUTIONSURFACE_H
#define WM3REVOLUTIONSURFACE_H

#include "Wm3TriMesh.h"
#include "Wm3Curve2.h"

namespace Wm3
{

class WM3_ITEM RevolutionSurface : public TriMesh
{
    WM3_DECLARE_RTTI;
    WM3_DECLARE_NAME_ID;
    WM3_DECLARE_STREAM;

public:
    // The axis of revolution is the z-axis.  You can obtain arbitrary axes
    // after the fact by applying translations and rotations to the object.
    // The curve of revolution is (x(t),z(t)) with t in [tmin,tmax] and
    // z(t) > 0.  It is also assumed to be non-self-intersecting.  When the
    // curve is open, three cases to consider:  If z(tmin) and z(tmax) are
    // both positive, the surface topology is that of a cylinder (use
    // REV_CYLINDER_TOPOLOGY).  If exactly one of z(tmin) or z(tmax) is zero,
    // the surface topology is that of a disk (use REV_DISK_TOPOLOGY).  If
    // z(tmin) and z(tmax) are both zero, the surface topology is that of a
    // sphere (use REV_SPHERE_TOPOLOGY).  When the curve of revolution is
    // closed so that (x(tmin),z(tmin)) and (x(tmax),z(tmax)) are the same
    // point, the surface topology is that of a torus.  For now, rather than
    // having the surface object determine the type of curve, use the
    // Topology enumerated values to provide this information.

    enum // Topology
    {
        REV_DISK_TOPOLOGY,
        REV_CYLINDER_TOPOLOGY,
        REV_SPHERE_TOPOLOGY,
        REV_TORUS_TOPOLOGY
    };

    // Construction and destruction.  The caller is responsible for deleting
    // the input curve.
    RevolutionSurface (Curve2f* pkCurve, float fXCenter, int eTopology,
        int iCurveSamples, int iRadialSamples, bool bWantNormals,
        bool bWantColors, bool bWantUVs, bool bSampleByArcLength,
        bool bOutsideView);

    virtual ~RevolutionSurface ();

    // member access
    int GetCurveSamples () const;
    int GetRadialSamples () const;
    void SetCurve (Curve2f* pkCurve);
    const Curve2f* GetCurve () const;
    int GetTopology () const;
    bool& SampleByArcLength ();
    bool GetSampleByArcLength () const;

    // Modify vertices and normals when the curve itself changes over time.
    // You are responsible for maintaining the topology of the curve.  For
    // example, if your constructor input was REV_SPHERE_TOPOLOGY, you should
    // not change the curve to produce a non-spherical topology.
    void UpdateSurface ();

protected:
    RevolutionSurface ();

    void ComputeSampleData ();
    void UpdateDisk ();
    void UpdateCylinder ();
    void UpdateSphere ();
    void UpdateTorus ();

    Curve2f* m_pkCurve;
    float m_fXCenter;
    int m_eTopology;
    int m_iCurveSamples, m_iRadialSamples;
    float* m_afSin;
    float* m_afCos;
    Vector3f* m_akSample;
    bool m_bSampleByArcLength;
};

WM3_REGISTER_STREAM(RevolutionSurface);
typedef Pointer<RevolutionSurface> RevolutionSurfacePtr;
#include "Wm3RevolutionSurface.inl"

}

#endif
