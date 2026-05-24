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
	LPCWSTR ConstructionMessage = L"This game is under construction. Please check on later. Development is underway.";
	LPCWSTR ConstructionTitle = L"Under Construction";

	MessageBox(NULL, ConstructionMessage, ConstructionTitle, MB_OK | MB_ICONWARNING);  

	tin_click_inc::GeneralWarn::ShowWarning(L"This game might be unstable or may have any other issues. Please report them to https://github.com/tinteeam/tin-click/issues", L"Please report issues");


	if (SUCCEEDED(CoInitialize(NULL))) {
		{
			GameApp app;
			if (SUCCEEDED(app.Initialize()))
			{
				app.RunMessageLoop();
			}
		}

		CoUninitialize();
	}

	return 0;
}
