//--------------------------------------------------------------------------------------------------------------------//
//                                                EDITOR SCENE CLASS                                                  //
// written by Frederic My                                                                                             //
// fmy@fairyengine.com                                                                                                //
//--------------------------------------------------------------------------------------------------------------------//

//----------------------------------------------- INCLUDES -----------------------------------------------------------//

#include  "stdafx.h"
#include  "EditorScene.h"
#ifdef    _DEBUG
#include  "EditorScene.inl"
#endif

namespace GPG4
{

//----------------------------------------------- STATIC MEMBERS -----------------------------------------------------//

IMPLEMENT_RTTI(CEditorScene,CPersistent);

//--------------------------------------------------------------------------------------------------------------------//
//                                                STREAMING                                                           //
//--------------------------------------------------------------------------------------------------------------------//

bool CEditorScene::Write(CLevelFiles& Level)
  {
  if(!m_spRoot) return true;                                // empty scene
  return m_spRoot->Write(Level);
  }

//--------------------------------------------------------------------------------------------------------------------//

} // namespace
