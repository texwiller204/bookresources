// File: DlgCallbacks.h

#ifndef DLGCALLBACKS_H
#define DLGCALLBACKS_H

#include <windows.h>
#include "globals.h"
#include "CGeometry.h"
#include "ZFX.h"
#include "resources/resource.h"             // menu header


BOOL CALLBACK CB_InfoBox(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CB_NewSectorBox(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CB_LevelAttribBox(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CB_SectorAttribBox(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CB_SectorAmbientBox(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CB_InsertShape(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CB_TextureBox(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CB_TextureBox2(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CB_NewSkinBox(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CB_EditSkinBox(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CB_EditMaterialBox(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CB_EditLightBox(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CB_EntityType(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CB_EditEntDoor(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK CB_RotateObject(HWND, UINT, WPARAM, LPARAM);
#endif