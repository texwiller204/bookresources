// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement http://www.wild-magic.com/License/WildMagic3.pdf and
// may not be copied or disclosed except in accordance with the terms of that
// agreement.

#include "TestBumpMap.h"

WM3_WINDOW_APPLICATION(TestBumpMap);

//----------------------------------------------------------------------------
TestBumpMap::TestBumpMap ()
    :
    WindowApplication3("TestBumpMap",0,0,640,480,ColorRGB(1.0f,1.0f,1.0f))
{
}
//----------------------------------------------------------------------------
bool TestBumpMap::OnInitialize ()
{
    if ( !WindowApplication3::OnInitialize() )
        return false;

    // create the scene
    m_spkScene = new Node;
    Node* pkTrnNode = new Node;
    m_spkScene->AttachChild(pkTrnNode);
    pkTrnNode->AttachChild(CreateModel());

    // center-and-fit
    m_spkScene->UpdateGS();
    pkTrnNode->Local.SetTranslate(-m_spkScene->WorldBound->GetCenter());
    m_spkCamera->SetFrustum(-0.55f,0.55f,-0.4125f,0.4125f,1.0f,100.0f);
    Vector3f kCDir(0.0f,0.0f,1.0f);
    Vector3f kCUp(0.0f,1.0f,0.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    Vector3f kCLoc = -2.0f*m_spkScene->WorldBound->GetRadius()*kCDir;
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    // initial update of objects
    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    InitializeCameraMotion(0.01f,0.001f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void TestBumpMap::OnTerminate ()
{
    m_spkScene = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void TestBumpMap::OnIdle ()
{
    MeasureTime();

    MoveCamera();

    if ( MoveObject() )
        m_spkScene->UpdateGS();

    m_pkRenderer->ClearBuffers();
    if ( m_pkRenderer->BeginScene() )
    {
        m_pkRenderer->DrawScene(m_spkScene);
        DrawFrameRate(8,GetHeight()-8,ColorRGBA::WHITE);
        m_pkRenderer->EndScene();
    }
    m_pkRenderer->DisplayBackBuffer();

    UpdateFrameCount();
}
//----------------------------------------------------------------------------
bool TestBumpMap::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if ( WindowApplication3::OnKeyDown(ucKey,iX,iY) )
        return true;

    switch ( ucKey )
    {
    case 's':
    case 'S':
        TestStream();
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
TriMesh* TestBumpMap::CreateModel ()
{
    // create a square mesh
    Vector3f* akVertex = new Vector3f[4];
    akVertex[0] = Vector3f(-0.5f,0.0f,-0.5f);
    akVertex[1] = Vector3f(-0.5f,0.0f, 0.5f);
    akVertex[2] = Vector3f( 0.5f,0.0f, 0.5f);
    akVertex[3] = Vector3f( 0.5f,0.0f,-0.5f);
    Vector3fArray* pkVertices = new Vector3fArray(4,akVertex);

    Vector3f* akNormal = new Vector3f[4];
    akNormal[0] = Vector3f::UNIT_Y;
    akNormal[1] = Vector3f::UNIT_Y;
    akNormal[2] = Vector3f::UNIT_Y;
    akNormal[3] = Vector3f::UNIT_Y;
    Vector3fArray* pkNormals = new Vector3fArray(4,akNormal);

    int* aiIndex = new int[6];
    aiIndex[0] = 0;  aiIndex[1] = 1;  aiIndex[2] = 3;
    aiIndex[3] = 3;  aiIndex[4] = 1;  aiIndex[5] = 2;
    IntArray* pkIndices = new IntArray(6,aiIndex);

    TriMesh* pkSquare = new TriMesh(pkVertices,pkIndices,false);
    pkSquare->Normals = pkNormals;

    // position/orient the square
    pkSquare->Local.SetRotate(Matrix3f().FromAxisAngle(Vector3f::UNIT_X,
        -0.25f*Mathf::PI));
    pkSquare->Local.SetTranslate(Vector3f(0.0f,-1.0f,0.0f));

    // attach a material
    MaterialState* pkMS = new MaterialState;
    pkMS->Ambient = ColorRGBA(0.8f,0.8f,0.8f,1.0f);
    pkMS->Diffuse = ColorRGBA(0.9f,0.9f,0.9f,1.0f);
    pkSquare->SetGlobalState(pkMS);

    // create a bump map effect
    Image* pkPrimary = Image::Load(
        System::GetPath("../../Data/Wmif/SunFire.wmif"));
    Image* pkNormalMap = Image::Load(
        System::GetPath("../../Data/Wmif/NormalMap.wmif"));

    Vector2f* akUV = new Vector2f[4];
    akUV[0] = Vector2f(1.0f,0.0f);
    akUV[1] = Vector2f(1.0f,1.0f);
    akUV[2] = Vector2f(0.0f,1.0f);
    akUV[3] = Vector2f(0.0f,0.0f);
    Vector2fArray* pkUVs = new Vector2fArray(4,akUV);

    Light* pkLight = new Light(Light::LT_POINT);
    pkLight->Ambient = ColorRGBA(0.2f,0.2f,0.2f,1.0f);
    pkLight->Diffuse = ColorRGBA(0.8f,0.8f,0.8f,1.0f);
    pkLight->SetLocation(Vector3f(0.0f,1.5f,0.0f));
    pkLight->UpdateGS();

    BumpMapEffect* pkEffect = new BumpMapEffect(pkPrimary,pkUVs,pkNormalMap,
        pkUVs,pkLight);
    pkSquare->SetEffect(pkEffect);

    return pkSquare;
}
//----------------------------------------------------------------------------
void TestBumpMap::TestStream ()
{
    Stream kOStream;
    kOStream.Insert(m_spkScene);
    kOStream.Save("TestBumpMap.wmof");

    Stream kIStream;
    kIStream.Load("TestBumpMap.wmof");
    NodePtr spkScene = (Node*)kIStream.GetObjectAt(0);
}
//----------------------------------------------------------------------------
