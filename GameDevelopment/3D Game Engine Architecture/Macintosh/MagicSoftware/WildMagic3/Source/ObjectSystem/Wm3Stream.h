// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement http://www.wild-magic.com/License/WildMagic3.pdf and
// may not be copied or disclosed except in accordance with the terms of that
// agreement.

#ifndef WM3STREAM_H
#define WM3STREAM_H

#include "Wm3System.h"
#include "Wm3String.h"
#include "Wm3StreamVersion.h"
#include "Wm3Stream.mcr"
#include "Wm3SmartPointer.h"

// aggregrate streaming
#include "Wm3ColorRGB.h"
#include "Wm3ColorRGBA.h"
#include "Wm3Matrix2.h"
#include "Wm3Matrix3.h"
#include "Wm3Matrix4.h"
#include "Wm3Plane3.h"
#include "Wm3Quaternion.h"
#include "Wm3Transformation.h"
#include "Wm3Vector2.h"
#include "Wm3Vector3.h"
#include "Wm3Vector4.h"

namespace Wm3
{

class Object;


class WM3_ITEM Stream
{
public:
    // construction and destruction
    Stream ();
    ~Stream ();

    // The objects to process, each object representing an entry into a
    // connected component of the abstract graph.
    bool Insert (Object* pkObject);
    bool Remove (Object* pkObject);
    void RemoveAll ();
    int GetObjectCount ();
    Object* GetObjectAt (int i) const;
    bool IsTopLevel (const Object* pkObject);

    // Memory loads and saves.  Stream does not assume responsibility for the
    // char arrays.  The application must manage the input acBuffer for the
    // call to Load and delete the output racBuffer for the call to Save.
    bool Load (char* acBuffer, int iSize);
    bool Save (char*& racBuffer, int& riSize);

    // file loads and saves
    bool Load (const char* acFilename);
    bool Save (const char* acFilename);

    // Access the array of unique objects, ordered by time of visitation in
    // the Register traversal.  You may use this after a Load or a Save call.
    // If you use it after a Load, changing objects returned by the function
    // GetOrderedObject is valid.  If you use it after a Save, changing
    // objects returned by the function will not affect the saved copy, but
    // it will affect the original objects you streamed.
    int GetOrderedQuantity () const;
    Object* GetOrderedObject (int i) const;

    // file save (ASCII text)
    bool SaveText (const char* acFilename, int iTabSize = 4);

    // support for memory and disk usage
    int GetMemoryUsed () const;
    int GetDiskUsed () const;

    // The version of the last loaded file from disk.  If no file has been
    // loaded, the returned values are -1.
    StreamVersion GetVersion () const;

    // linking support
    class WM3_ITEM Link
    {
    public:
        Link (Object* pkObject);

        void SetObject (Object* pkObject);
        Object* GetObject ();

        int GetQuantity () const;
        Object* GetLinkID ();

        void Add (Object* pkLinkID);

    protected:
        Object* m_pkObject;
        int m_iCurrent;
        TArray<Object*> m_kLinkID;
    };

protected:
    // base level streaming access
    friend class Object;
    bool InsertInMap (Object* pkObject, Link* pkLink);
    void InsertInOrdered (Object* pkObject);

    // version of last loaded file
    StreamVersion m_kVersion;

    // top level object storage
    TArray<Object*> m_apkTopLevel; // need to be able to remove array items

    // registration of objects on Save
    mutable THashTable<Object*,Link*> m_kMap;

    // For saving objects in depth-first order.  If instead the objects are
    // saved based on hash-table order (in m_kMap), then the order of objects
    // for a scene graph can change between different runs of a program since
    // the memory addresses for the objects can change between runs.
    mutable TArray<Object*> m_kOrdered;

    // read/write always applied to buffer in memory
    int m_iBufferSize, m_iBufferNext;
    char* m_acBuffer;

    static const String ms_kTopLevel;

// internal use
public:
    // linking support
    Object* GetFromMap (Object* pkLinkID);

    // debugging support
    int GetBufferSize () const;
    int GetBufferNext () const;

    // native read functions
    void Read (Object*& rpkValue);
    void Read (int iQuantity, Object** apkValue);
    void Read (bool& rbValue);
    void Read (int iQuantity, bool* abValue);
    void Read (char& rcValue);
    void Read (int iQuantity, char* acValue);
    void Read (unsigned char& rucValue);
    void Read (int iQuantity, unsigned char* aucValue);
    void Read (short& rsValue);
    void Read (int iQuantity, short* asValue);
    void Read (unsigned short& rusValue);
    void Read (int iQuantity, unsigned short* ausValue);
    void Read (int& riValue);
    void Read (int iQuantity, int* aiValue);
    void Read (unsigned int& ruiValue);
    void Read (int iQuantity, unsigned int* auiValue);
    void Read (long& rlValue);
    void Read (int iQuantity, long* alValue);
    void Read (unsigned long& rulValue);
    void Read (int iQuantity, unsigned long* aulValue);
    void Read (float& rfValue);
    void Read (int iQuantity, float* afValue);
    void Read (double& rdValue);
    void Read (int iQuantity, double* adValue);

    // aggregrate read functions
    void Read (String& rkValue);
    void Read (int iQuantity, String* akValue);
    void Read (ColorRGB& rkValue);
    void Read (int iQuantity, ColorRGB* akValue);
    void Read (ColorRGBA& rkValue);
    void Read (int iQuantity, ColorRGBA* akValue);
    void Read (Matrix2f& rkValue);
    void Read (int iQuantity, Matrix2f* akValue);
    void Read (Matrix3f& rkValue);
    void Read (int iQuantity, Matrix3f* akValue);
    void Read (Matrix4f& rkValue);
    void Read (int iQuantity, Matrix4f* akValue);
    void Read (Plane3f& rkValue);
    void Read (int iQuantity, Plane3f* akValue);
    void Read (Quaternionf& rkValue);
    void Read (int iQuantity, Quaternionf* akValue);
    void Read (Vector2f& rkValue);
    void Read (int iQuantity, Vector2f* akValue);
    void Read (Vector3f& rkValue);
    void Read (int iQuantity, Vector3f* akValue);
    void Read (Vector4f& rkValue);
    void Read (int iQuantity, Vector4f* akValue);
    void Read (Matrix2d& rkValue);
    void Read (int iQuantity, Matrix2d* akValue);
    void Read (Matrix3d& rkValue);
    void Read (int iQuantity, Matrix3d* akValue);
    void Read (Matrix4d& rkValue);
    void Read (int iQuantity, Matrix4d* akValue);
    void Read (Plane3d& rkValue);
    void Read (int iQuantity, Plane3d* akValue);
    void Read (Quaterniond& rkValue);
    void Read (int iQuantity, Quaterniond* akValue);
    void Read (Vector2d& rkValue);
    void Read (int iQuantity, Vector2d* akValue);
    void Read (Vector3d& rkValue);
    void Read (int iQuantity, Vector3d* akValue);
    void Read (Vector4d& rkValue);
    void Read (int iQuantity, Vector4d* akValue);
    void Read (Transformation& rkValue);
    void Read (int iQuantity, Transformation* akValue);

    // native write functions
    void Write (const Object* pkValue);
    void Write (int iQuantity, Object** const apkValue);
    void Write (const Pointer<Object>& rspkValue);
    void Write (int iQuantity, const Pointer<Object>* aspkValue);
    void Write (bool bValue);
    void Write (int iQuantity, const bool* abValue);
    void Write (char cValue);
    void Write (int iQuantity, const char* acValue);
    void Write (unsigned char ucValue);
    void Write (int iQuantity, const unsigned char* aucValue);
    void Write (short sValue);
    void Write (int iQuantity, const short* asValue);
    void Write (unsigned short usValue);
    void Write (int iQuantity, const unsigned short* ausValue);
    void Write (int iValue);
    void Write (int iQuantity, const int* aiValue);
    void Write (unsigned int uiValue);
    void Write (int iQuantity, const unsigned int* auiValue);
    void Write (long lValue);
    void Write (int iQuantity, const long* alValue);
    void Write (unsigned long ulValue);
    void Write (int iQuantity, const unsigned long* aulValue);
    void Write (float fValue);
    void Write (int iQuantity, const float* afValue);
    void Write (double dValue);
    void Write (int iQuantity, const double* adValue);

    // aggregrate write functions
    void Write (const String& rkValue);
    void Write (int iQuantity, const String* akValue);
    void Write (const ColorRGB& rkValue);
    void Write (int iQuantity, const ColorRGB* akValue);
    void Write (const ColorRGBA& rkValue);
    void Write (int iQuantity, const ColorRGBA* akValue);
    void Write (const Matrix2f& rkValue);
    void Write (int iQuantity, const Matrix2f* akValue);
    void Write (const Matrix3f& rkValue);
    void Write (int iQuantity, const Matrix3f* akValue);
    void Write (const Matrix4f& rkValue);
    void Write (int iQuantity, const Matrix4f* akValue);
    void Write (const Plane3f& rkValue);
    void Write (int iQuantity, const Plane3f* akValue);
    void Write (const Quaternionf& rkValue);
    void Write (int iQuantity, const Quaternionf* akValue);
    void Write (const Vector2f& rkValue);
    void Write (int iQuantity, const Vector2f* akValue);
    void Write (const Vector3f& rkValue);
    void Write (int iQuantity, const Vector3f* akValue);
    void Write (const Vector4f& rkValue);
    void Write (int iQuantity, const Vector4f* akValue);
    void Write (const Matrix2d& rkValue);
    void Write (int iQuantity, const Matrix2d* akValue);
    void Write (const Matrix3d& rkValue);
    void Write (int iQuantity, const Matrix3d* akValue);
    void Write (const Matrix4d& rkValue);
    void Write (int iQuantity, const Matrix4d* akValue);
    void Write (const Plane3d& rkValue);
    void Write (int iQuantity, const Plane3d* akValue);
    void Write (const Quaterniond& rkValue);
    void Write (int iQuantity, const Quaterniond* akValue);
    void Write (const Vector2d& rkValue);
    void Write (int iQuantity, const Vector2d* akValue);
    void Write (const Vector3d& rkValue);
    void Write (int iQuantity, const Vector3d* akValue);
    void Write (const Vector4d& rkValue);
    void Write (int iQuantity, const Vector4d* akValue);
    void Write (const Transformation& rkValue);
    void Write (int iQuantity, const Transformation* akValue);
};

typedef Object* (*FactoryFunction)(Stream&);
#include "Wm3Stream.inl"

}

#endif
