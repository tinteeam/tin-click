/*
* 
* Window.hpp - declaration for the main window class and utility functions for safe release and assertions and other D2D methods.
* Tinteeam (C) 2026 Licensed under the MIT License. See LICENSE file in the project root for full license information.
* 
*/

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <Windows.h>

//Direct2D(D2D) headers includes
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>

namespace tin_click_inc {

    class MainWindow {
    public:
        int GameWindow(
            HINSTANCE hInstance,
            HINSTANCE hPrevInstance,
            wchar_t* pCmdLine,
            int nCmdShow
        );
    };
}


template<class Interface>
inline void SafeRelease(
    Interface** ppInterfaceToRelease)
{
    if (*ppInterfaceToRelease != NULL)
    {
        (*ppInterfaceToRelease)->Release();
        (*ppInterfaceToRelease) = NULL;
    }
}

#ifndef Assert
#if defined( DEBUG ) || defined( _DEBUG )
#define Assert(b) do {if (!(b)) {OutputDebugStringA("Assert: " #b "\n");}} while(0)
#else
#define Assert(b)
#endif //DEBUG || _DEBUG
#endif

#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif


class GameApp
{
public:
    GameApp();
    ~GameApp();

    // Register the window class and call methods for instantiating drawing resources
    HRESULT Initialize();

    // Process and dispatch messages
    void RunMessageLoop();

	bool IsReady() const;

private:
    HRESULT CreateDeviceIndependentResources();
    HRESULT CreateDeviceResources();

    HRESULT CreateGridPatternBrush(
        ID2D1RenderTarget* pRenderTarget,
        ID2D1BitmapBrush** ppBitmapBrush
    );

    void DiscardDeviceResources();

    HRESULT OnRender();

    void OnResize(
        UINT width,
        UINT height
    );

    static LRESULT CALLBACK WndProc(
        HWND hWnd,
        UINT message,
        WPARAM wParam,
        LPARAM lParam
    );

    HRESULT LoadResourceBitmap(
        ID2D1RenderTarget* pRenderTarget,
        IWICImagingFactory* pIWICFactory,
        PCWSTR resourceName,
        PCWSTR resourceType,
        UINT destinationWidth,
        UINT destinationHeight,
        ID2D1Bitmap** ppBitmap
    );

    HRESULT LoadBitmapFromFile(
        ID2D1RenderTarget* pRenderTarget,
        IWICImagingFactory* pIWICFactory,
        PCWSTR uri,
        UINT destinationWidth,
        UINT destinationHeight,
        ID2D1Bitmap** ppBitmap
    );

private:
    HWND m_hwnd;
    ID2D1Factory* m_pD2DFactory;
    IWICImagingFactory* m_pWICFactory;
    IDWriteFactory* m_pDWriteFactory;
    ID2D1HwndRenderTarget* m_pRenderTarget;
    IDWriteTextFormat* m_pTextFormat;
    ID2D1PathGeometry* m_pPathGeometry;
    ID2D1LinearGradientBrush* m_pLinearGradientBrush;
    ID2D1SolidColorBrush* m_pBlackBrush;
    ID2D1BitmapBrush* m_pGridPatternBitmapBrush;
    ID2D1Bitmap* m_pBitmap;
    ID2D1Bitmap* m_pAnotherBitmap;
};

#endif