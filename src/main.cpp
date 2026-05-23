#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>
#include "include/Window.hpp"



int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	MessageBox(NULL, L"This game is under construction.", L"Under Construction", MB_OK | MB_ICONINFORMATION);
}
