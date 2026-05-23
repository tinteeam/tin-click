#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>
#include "include/Window.hpp"
#include "include/warnings.hpp"

//usings from include/Window.hpp
using namespace tin_click_inc;



int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	MessageBox(NULL, L"This game is under construction.", L"Under Construction", MB_OK | MB_ICONWARNING);

	tin_click_inc::NotImplWarn::NotImplementedWarn();
}
