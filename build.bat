@echo off
setlocal

echo Entering Visual Studio development environment...

call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"

if %errorlevel% neq 0 (
    echo Failed to initialize Visual Studio environment.
    exit /b 1
)

echo Creating build directory...

if not exist out (
    mkdir out
)

cd out

echo Generating Ninja build files...

cmake .. ^
    -G "Ninja" ^
    -DCMAKE_BUILD_TYPE=Release

if %errorlevel% neq 0 (
    echo CMake generation failed.
    exit /b 1
)

echo Building...

ninja

if %errorlevel% neq 0 (
    echo Build failed.
    exit /b 1
)

echo Making sure the assets are placed in the output directory...

if not exist assets (
    echo assets directory not found. Copying directory...
    xcopy /s /y ..\assets .\assets
)


echo Done.
pause