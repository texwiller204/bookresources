# Microsoft Developer Studio Project File - Name="TextureMasking" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 60000
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TextureMasking - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TextureMasking.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TextureMasking.mak" CFG="TextureMasking - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TextureMasking - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "TextureMasking - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "TextureMasking"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TextureMasking - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /Zi /O2 /I "Common\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib advapi32.lib comdlg32.lib shell32.lib uuid.lib d3d8.lib d3dx8.lib winmm.lib /nologo /subsystem:windows /map /debug /machine:I386

!ELSEIF  "$(CFG)" == "TextureMasking - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "Common\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib advapi32.lib comdlg32.lib shell32.lib uuid.lib d3d8.lib d3dx8.lib winmm.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "TextureMasking - Win32 Release"
# Name "TextureMasking - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Branch.cpp
# End Source File
# Begin Source File

SOURCE=.\Branches.cpp
# End Source File
# Begin Source File

SOURCE=.\BranchNoise.cpp
# End Source File
# Begin Source File

SOURCE=.\Leaves.cpp
# End Source File
# Begin Source File

SOURCE=.\Random.cpp
# End Source File
# Begin Source File

SOURCE=.\TextureMasking.cpp
# End Source File
# Begin Source File

SOURCE=.\Tree.cpp
# End Source File
# Begin Source File

SOURCE=.\winmain.rc
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Branch.h
# End Source File
# Begin Source File

SOURCE=.\Branches.h
# End Source File
# Begin Source File

SOURCE=.\BranchNoise.h
# End Source File
# Begin Source File

SOURCE=.\Leaves.h
# End Source File
# Begin Source File

SOURCE=.\Random.h
# End Source File
# Begin Source File

SOURCE=.\TextureMasking.h
# End Source File
# Begin Source File

SOURCE=.\tree.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\directx.ico
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# End Group
# Begin Group "Common"

# PROP Default_Filter ""
# Begin Group "Src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Common\src\d3dapp.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\src\d3dutil.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\src\dxutil.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\src\nvcomplexmesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\src\nvcomplexmeshpass.cpp
# End Source File
# End Group
# Begin Group "Include"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=.\Common\include\d3dapp.h
# End Source File
# Begin Source File

SOURCE=.\Common\include\d3dres.h
# End Source File
# Begin Source File

SOURCE=.\Common\include\d3dutil.h
# End Source File
# Begin Source File

SOURCE=.\Common\include\dxutil.h
# End Source File
# Begin Source File

SOURCE=.\Common\include\nvcomplexmesh.h
# End Source File
# Begin Source File

SOURCE=.\Common\include\nvcomplexmeshpass.h
# End Source File
# Begin Source File

SOURCE=.\Common\include\nvdebug.h
# End Source File
# Begin Source File

SOURCE=.\Common\include\nvinc.h
# End Source File
# Begin Source File

SOURCE=.\Common\include\nvmaterialresource.h
# End Source File
# Begin Source File

SOURCE=.\Common\include\nvresourcemanager.h
# End Source File
# Begin Source File

SOURCE=.\Common\include\nvstatemanager.h
# End Source File
# Begin Source File

SOURCE=.\Common\include\nvtext.h
# End Source File
# Begin Source File

SOURCE=.\Common\include\nvtexture.h
# End Source File
# Begin Source File

SOURCE=.\Common\include\nvtextureresource.h
# End Source File
# Begin Source File

SOURCE=.\Common\include\NVWalkCamera.h
# End Source File
# Begin Source File

SOURCE=.\Common\include\singleton.h
# End Source File
# End Group
# End Group
# End Target
# End Project
