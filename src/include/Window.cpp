/* 
* Tin-click Window creation and handling code.
* Tinteeam (C) 2026 Licensed under the MIT License. See LICENSE file in the project root for full license information.
*/

#ifndef UNICODE
#define UNICODE
#endif

// includes
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <wchar.h>
#include <math.h>
#include "Window.hpp"
#include <iostream>

//Direct2D(D2D) headers includes
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>

//WindowProc declaration
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


//usings from the standard library
using std::string;

namespace tin_click_inc {
    
    
        int MainWindow::GameWindow(HINSTANCE hInstance,
            HINSTANCE hPrevInstance,
            wchar_t* pCmdLine,
            int nCmdShow) {
        
            const wchar_t CLASS_NAME[] = L"Sample Window Class";

            WNDCLASS wc = { };

            wc.lpfnWndProc = WindowProc;
            wc.hInstance = hInstance;
            wc.lpszClassName = CLASS_NAME;

            RegisterClass(&wc);
			HWND hwnd = CreateWindowEx(
				0,                              // Optional window styles.
				CLASS_NAME,                     // Window class
				L"Tin-click",    // Window text
				WS_OVERLAPPEDWINDOW,            // Window style
				// Size and position
				CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
				NULL,       // Parent window    
				NULL,       // Menu
				hInstance,  // Instance handle
				NULL        // Additional application data
			);

			if (hwnd == NULL)
			{
				return -1;
			}

			ShowWindow(hwnd, nCmdShow);

			// Run the message loop.
			MSG msg = { };

            while (GetMessage(&msg, NULL, 0, 0) > 0)
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }

			return 1;
        };

    
}




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