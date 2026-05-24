@echo off
setlocal

@REM Test the main output exe file if it was compiled succesfully.
@REM Tinteeam (C) 2026 Licensed under the MIT License. See LICENSE file in the project root for full license information.


echo Running build script
call build.bat

if %errorlevel% neq 0 (
	echo Build failed.
	exit /b 1
)

echo running main exe
out\tin-clicker.exe

if %errorlevel% neq 0 (
	echo Execution failed.
	exit /b 1
)

pause