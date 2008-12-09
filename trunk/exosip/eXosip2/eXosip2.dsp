# Microsoft Developer Studio Project File - Name="eXosip2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=eXosip2 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "eXosip2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "eXosip2.mak" CFG="eXosip2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "eXosip2 - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "eXosip2 - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "eXosip2 - Win32 Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "EXOSIP2_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\include" /I "..\pthread\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "EXOSIP2_EXPORTS" /D "OSIP_MT" /D "_MT" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib osip2.lib osipparser2.lib ws2_32.lib IPHlpApi.lib /nologo /dll /machine:I386 /libpath:"..\osip2\Release" /libpath:"..\osipparser2\Release" /libpath:"..\pthread\lib"
# SUBTRACT LINK32 /nodefaultlib

!ELSEIF  "$(CFG)" == "eXosip2 - Win32 Debug"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "EXOSIP2_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MD /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "EXOSIP2_EXPORTS" /D "OSIP_MT" /D "_MT" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib osip2.lib /nologo /dll /debug /machine:I386 /pdbtype:sept /libpath:"C:\osip\osip2\Release"

!ENDIF 

# Begin Target

# Name "eXosip2 - Win32 Release"
# Name "eXosip2 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\eXcall_api.c
# End Source File
# Begin Source File

SOURCE=.\eXconf.c
# End Source File
# Begin Source File

SOURCE=.\eXinsubscription_api.c
# End Source File
# Begin Source File

SOURCE=.\eXmessage_api.c
# End Source File
# Begin Source File

SOURCE=.\eXoptions_api.c
# End Source File
# Begin Source File

SOURCE=.\eXosip.c
# End Source File
# Begin Source File

SOURCE=.\eXosip2.def
# End Source File
# Begin Source File

SOURCE=.\eXpublish_api.c
# End Source File
# Begin Source File

SOURCE=.\eXrefer_api.c
# End Source File
# Begin Source File

SOURCE=.\eXregister_api.c
# End Source File
# Begin Source File

SOURCE=.\eXsubscription_api.c
# End Source File
# Begin Source File

SOURCE=.\eXtl.c
# End Source File
# Begin Source File

SOURCE=.\eXtl_dtls.c
# End Source File
# Begin Source File

SOURCE=.\eXtl_tcp.c
# End Source File
# Begin Source File

SOURCE=.\eXtl_tls.c
# End Source File
# Begin Source File

SOURCE=.\eXtl_udp.c
# End Source File
# Begin Source File

SOURCE=.\eXtransport.c
# End Source File
# Begin Source File

SOURCE=.\eXutils.c
# End Source File
# Begin Source File

SOURCE=.\inet_ntop.c
# End Source File
# Begin Source File

SOURCE=.\jauth.c
# End Source File
# Begin Source File

SOURCE=.\jcall.c
# End Source File
# Begin Source File

SOURCE=.\jcallback.c
# End Source File
# Begin Source File

SOURCE=.\jdialog.c
# End Source File
# Begin Source File

SOURCE=.\jevents.c
# End Source File
# Begin Source File

SOURCE=.\jnotify.c
# End Source File
# Begin Source File

SOURCE=.\jpipe.c
# End Source File
# Begin Source File

SOURCE=.\jpublish.c
# End Source File
# Begin Source File

SOURCE=.\jreg.c
# End Source File
# Begin Source File

SOURCE=.\jrequest.c
# End Source File
# Begin Source File

SOURCE=.\jresponse.c
# End Source File
# Begin Source File

SOURCE=.\jsubscribe.c
# End Source File
# Begin Source File

SOURCE=.\misc.c
# End Source File
# Begin Source File

SOURCE=.\sdp_offans.c
# End Source File
# Begin Source File

SOURCE=.\udp.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\eXosip2.h
# End Source File
# Begin Source File

SOURCE=.\eXtransport.h
# End Source File
# Begin Source File

SOURCE=.\inet_ntop.h
# End Source File
# Begin Source File

SOURCE=.\jpipe.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
