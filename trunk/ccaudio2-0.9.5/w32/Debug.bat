@echo off
rem bootstrap framework when no pre-packaged setuo.exe is available

echo Bootstrapping framework from Debugd Libraries

if exist "C:\Program Files\GNU Telephony" goto common

echo Creating C:\Program Files\GNU Telephony...

mkdir "C:\Program Files\GNU Telephony"
mkdir "C:\Program Files\GNU Telephony\CAPE Framework"
mkdir "C:\Program Files\GNU Telephony\CAPE Framework\Include"
mkdir "C:\Program Files\GNU Telephony\CAPE Framework\Include\cc++"
mkdir "C:\Program Files\GNU Telephony\CAPE Framework\Import"
mkdir "C:\Program Files\GNU Telephony\CAPE Framework .NET"
mkdir "C:\Program Files\GNU Telephony\CAPE Framework .NET\Include"
mkdir "C:\Program Files\GNU Telephony\CAPE Framework .NET\Include\cc++"
mkdir "C:\Program Files\GNU Telephony\CAPE Framework .NET\Import"

:common

if exist "C:\Program Files\Common Files\CAPE Framework" goto include

echo Creating C:\Program Files\Common Files\CAPE Framework...

mkdir "C:\Program Files\Common Files\CAPE Framework"
mkdir "C:\Program Files\Common Files\CAPE Framework\Runtime"
mkdir "C:\Program Files\Common Files\CAPE Framework\Audio Codecs"
mkdir "C:\Program Files\Common Files\CAPE Framework .NET"
mkdir "C:\Program Files\Common Files\CAPE Framework .NET\Runtime"
mkdir "C:\Program Files\Common Files\CAPE Framework .NET\Audio Codecs"

:include

echo Copying include files...

copy /y ..\src\audio.h "C:\Program Files\GNU Telephony\CAPE Framework\Include\cc++"
copy /y ..\src\audio.h "C:\Program Files\GNU Telephony\CAPE Framework .NET\Include\cc++"

if not exist "Debug .NET\ccaudio2.lib" goto compat

echo Copying import library...
copy /y "Debug .NET\ccaudio2.lib" "C:\Program Files\GNU Telephony\CAPE Framework .NET\Import"

echo Copying runtime library...
copy /y "Debug .NET\ccaudio2.dll" "C:\Program Files\Common Files\CAPE Framework .NET\Runtime"

echo Copying codecs...
copy /y "Debug .NET\*.rll" "C:\Program Files\Common Files\CAPE Framework .NET\Audio Codecs"

echo Copying exec...
copy /y "Debug .NET\audiotool.exe" "C:\Program Files\Common Files\CAPE Framework .NET\Runtime"

:compat

if not exist Debug\ccaudio2.lib goto finish

echo Copying import library...
copy /y Debug\ccaudio2.lib "C:\Program Files\GNU Telephony\CAPE Framework\Import"

echo Copying runtime library...
copy /y Debug\ccaudio2.dll "C:\Program Files\Common Files\CAPE Framework\Runtime"

echo Copying codecs...
copy /y Debug\*.rll "C:\Program Files\Common Files\CAPE Framework\Audio Codecs"

echo Copying exec...
copy /y Debug\audiotool.exe "C:\Program Files\Common Files\CAPE Framework\runtime"

:finish

echo Updating registry...

regedit /s ccaudio2.reg

