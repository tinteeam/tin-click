/*
* Main entry point for the game. Initializes the main window and starts the game loop.
* Tinteeam (C) 2026 Licensed under the MIT License. See LICENSE file in the project root for full license information.
*/

#ifndef UNICODE  
#define UNICODE  
#endif  

#include <Windows.h>  
#include "include/Window.hpp"  
#include "include/warnings.hpp"  

//usings from include/Window.hpp  
using namespace tin_click_inc;  

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, wchar_t* pCmdLine, int nCmdShow)
{  
	MessageBox(NULL, L"This game is under construction.", L"Under Construction", MB_OK | MB_ICONWARNING);  

	tin_click_inc::NotImplWarn::NotImplementedWarn();  

	
	tin_click_inc::MainWindow mainWindow;  
	return mainWindow.GameWindow(hInstance, hPrevInstance, pCmdLine, nCmdShow);  
}
