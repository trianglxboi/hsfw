@echo off

set PREMAKE_BIN=.\vendor\premake\bin\windows-x86_64\premake5.exe
set SUPPORT_STR=- only 2017, 2019 and 2022 versions are supported.

set argc=0
for %%x in (%*) do (
   set /A argc+=1
   set "argVec[!argc!]=%%~x"
)

if not %argc% == 1 (
	echo Provide only one command line argument and make it the Visual Studio version required %SUPPORT_STR%
	pause
	exit
)

set vs=1997
if %1 == 2017 (
	set /A vs=2017
) else if %1 == 2019 (
	set /A vs=2019
) else if %1 == 2022 (
	set /A vs=2022
) else (
	echo Unsupported Visual Studio version '%1' was supplied from the command line %SUPPORT_STR%
	pause
	exit
)

echo Selected Visual Studio version %vs%.
pushd %~dp0\..\..\

if not exist %PREMAKE_BIN% (
	echo The premake binary at '%PREMAKE_BIN%' could not be located, make sure it exists and you have run the script from the appropriate path.
	pause
	exit
)

call %PREMAKE_BIN% vs%vs%
pause
exit
