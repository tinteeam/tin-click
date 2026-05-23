/* 
* Tin-click Window creation and handling code.
* Tinteeam (C) 2026 Licensed under the MIT License. See LICENSE file in the project root for full license information.
*/

// includes
#include "Window.hpp"
#include <iostream>

//usings from the standard library
using std::string;


class MainWindow
{
public:
	string title;

};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Setup the window process WindowProc, which will handle messages sent to the window. 
// This is a callback function that will be called by the Windows operating system when certain events occur (like painting the window, closing it, etc.). 
// The function takes in parameters that provide information about the event and allows us to respond accordingly.
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}