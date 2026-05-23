@echo off
setlocal

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