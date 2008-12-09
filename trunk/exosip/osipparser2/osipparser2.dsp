# Microsoft Developer Studio Project File - Name="osipparser2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=osipparser2 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "osipparser2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "osipparser2.mak" CFG="osipparser2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "osipparser2 - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "osipparser2 - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "osipparser2 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "OSIPPARSER2_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "OSIPPARSER2_EXPORTS" /D "OSIP_MT" /D "_MT" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386

!ELSEIF  "$(CFG)" == "osipparser2 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "OSIPPARSER2_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "OSIPPARSER2_EXPORTS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "osipparser2 - Win32 Release"
# Name "osipparser2 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\osip_accept.c
# End Source File
# Begin Source File

SOURCE=.\osip_accept_encoding.c
# End Source File
# Begin Source File

SOURCE=.\osip_accept_language.c
# End Source File
# Begin Source File

SOURCE=.\osip_alert_info.c
# End Source File
# Begin Source File

SOURCE=.\osip_allow.c
# End Source File
# Begin Source File

SOURCE=.\osip_authentication_info.c
# End Source File
# Begin Source File

SOURCE=.\osip_authorization.c
# End Source File
# Begin Source File

SOURCE=.\osip_body.c
# End Source File
# Begin Source File

SOURCE=.\osip_call_id.c
# End Source File
# Begin Source File

SOURCE=.\osip_call_info.c
# End Source File
# Begin Source File

SOURCE=.\osip_contact.c
# End Source File
# Begin Source File

SOURCE=.\osip_content_disposition.c
# End Source File
# Begin Source File

SOURCE=.\osip_content_encoding.c
# End Source File
# Begin Source File

SOURCE=.\osip_content_length.c
# End Source File
# Begin Source File

SOURCE=.\osip_content_type.c
# End Source File
# Begin Source File

SOURCE=.\osip_cseq.c
# End Source File
# Begin Source File

SOURCE=.\osip_error_info.c
# End Source File
# Begin Source File

SOURCE=.\osip_from.c
# End Source File
# Begin Source File

SOURCE=.\osip_header.c
# End Source File
# Begin Source File

SOURCE=.\osip_list.c
# End Source File
# Begin Source File

SOURCE=.\osip_md5c.c
# End Source File
# Begin Source File

SOURCE=.\osip_message.c
# End Source File
# Begin Source File

SOURCE=.\osip_message_parse.c
# End Source File
# Begin Source File

SOURCE=.\osip_message_to_str.c
# End Source File
# Begin Source File

SOURCE=.\osip_mime_version.c
# End Source File
# Begin Source File

SOURCE=.\osip_parser_cfg.c
# End Source File
# Begin Source File

SOURCE=.\osip_port.c
# End Source File
# Begin Source File

SOURCE=.\osip_proxy_authenticate.c
# End Source File
# Begin Source File

SOURCE=.\osip_proxy_authentication_info.c
# End Source File
# Begin Source File

SOURCE=.\osip_proxy_authorization.c
# End Source File
# Begin Source File

SOURCE=.\osip_record_route.c
# End Source File
# Begin Source File

SOURCE=.\osip_route.c
# End Source File
# Begin Source File

SOURCE=.\osip_to.c
# End Source File
# Begin Source File

SOURCE=.\osip_uri.c
# End Source File
# Begin Source File

SOURCE=.\osip_via.c
# End Source File
# Begin Source File

SOURCE=.\osip_www_authenticate.c
# End Source File
# Begin Source File

SOURCE=.\osipparser2.def
# End Source File
# Begin Source File

SOURCE=.\sdp_accessor.c
# End Source File
# Begin Source File

SOURCE=.\sdp_message.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\parser.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
