%windir%\microsoft.net\framework\v3.5\msbuild /property:Configuration=Release commoncpp2-1.6.3\w32\common.sln
@IF %ERRORLEVEL% NEQ 0 PAUSE
%windir%\microsoft.net\framework\v3.5\msbuild /property:Configuration=Release ccrtp-1.6.2\w32\msvcpp\ccrtp1.sln
@IF %ERRORLEVEL% NEQ 0 PAUSE
%windir%\microsoft.net\framework\v3.5\msbuild /property:Configuration=Release fox-1.7.18\windows\vcpp\win32.sln
@IF %ERRORLEVEL% NEQ 0 PAUSE
%windir%\microsoft.net\framework\v3.5\msbuild /property:Configuration=Release ccaudio2-0.9.5\w32\ccaudio2.sln
@IF %ERRORLEVEL% NEQ 0 PAUSE
%windir%\microsoft.net\framework\v3.5\msbuild /property:Configuration=Release ccscript3-0.8.0\w32\ccscript3.sln
@IF %ERRORLEVEL% NEQ 0 PAUSE
%windir%\microsoft.net\framework\v3.5\msbuild /property:Configuration=Release bayonne2-2.0.2\w32\bayonne.sln
@IF %ERRORLEVEL% NEQ 0 PAUSE
