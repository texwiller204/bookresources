# Microsoft Developer Studio Project File - Name="FogRoom" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 60000
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=FogRoom - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "FogRoom.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "FogRoom.mak" CFG="FogRoom - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "FogRoom - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "FogRoom - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "FogRoom"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "FogRoom - Win32 Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "FOGROOM_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\..\include" /I "..\..\shared" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "FOGROOM_EXPORTS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 d3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib /nologo /dll /machine:I386 /out:"fogroom.dll"

!ELSEIF  "$(CFG)" == "FogRoom - Win32 Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "FOGROOM_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\..\include" /I "..\..\shared" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "FOGROOM_EXPORTS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 d3dx8dt.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib /nologo /dll /debug /machine:I386 /out:"fogroom.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "FogRoom - Win32 Release"
# Name "FogRoom - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\shared\eb_property.cpp
# End Source File
# Begin Source File

SOURCE=.\fog.nvv

!IF  "$(CFG)" == "FogRoom - Win32 Release"

# Begin Custom Build
InputPath=.\fog.nvv

"fog.vso" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	..\..\nvasm fog.nvv

# End Custom Build

!ELSEIF  "$(CFG)" == "FogRoom - Win32 Debug"

# Begin Custom Build
InputPath=.\fog.nvv

"fog.vso" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	..\..\nvasm fog.nvv

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\fog_world.nvv

!IF  "$(CFG)" == "FogRoom - Win32 Release"

# Begin Custom Build
InputPath=.\fog_world.nvv

"fog_world.vso" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	..\..\nvasm fog_world.nvv

# End Custom Build

!ELSEIF  "$(CFG)" == "FogRoom - Win32 Debug"

# Begin Custom Build
InputPath=.\fog_world.nvv

"fog_world.vso" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	..\..\nvasm fog_world.nvv

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\CommonSrc\nvfile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\CommonSrc\nvframe.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\CommonSrc\nvmesh.cpp
# End Source File
# Begin Source File

SOURCE=.\shader_Fog.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\fog.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Include\nvdevice.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Include\nvframe.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Include\nvmesh.h
# End Source File
# Begin Source File

SOURCE=..\..\..\Include\NVWalkCamera.h
# End Source File
# Begin Source File

SOURCE=.\shader_Fog.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
