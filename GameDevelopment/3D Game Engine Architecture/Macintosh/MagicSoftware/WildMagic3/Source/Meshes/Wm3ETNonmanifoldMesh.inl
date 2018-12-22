// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement http://www.wild-magic.com/License/WildMagic3.pdf and
// may not be copied or disclosed except in accordance with the terms of that
// agreement.

//----------------------------------------------------------------------------
inline int ETNonmanifoldMesh::GetEdgeQuantity () const
{
    return (int)m_kEMap.size();
}
//----------------------------------------------------------------------------
inline const ETNonmanifoldMesh::EMap& ETNonmanifoldMesh::GetEdges () const
{
    return m_kEMap;
}
//----------------------------------------------------------------------------
inline int ETNonmanifoldMesh::GetTriangleQuantity () const
{
    return (int)m_kTMap.size();
}
//----------------------------------------------------------------------------
inline const ETNonmanifoldMesh::TMap& ETNonmanifoldMesh::GetTriangles () const
{
    return m_kTMap;
}
//----------------------------------------------------------------------------
