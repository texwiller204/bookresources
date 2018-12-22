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
template <class T>
void CreateClodMesh::Reorder (T*& ratVertexAttribute)
{
    T* atNewVertexAttribute = new T[m_iVQuantity];
    for (int i = 0; i < m_iVQuantity; i++)
        atNewVertexAttribute[i] = ratVertexAttribute[m_aiVOrdered[i]];
    memcpy(ratVertexAttribute,atNewVertexAttribute,m_iVQuantity*sizeof(T));
    delete[] atNewVertexAttribute;
}
//----------------------------------------------------------------------------