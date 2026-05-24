#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <Windows.h>

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

#endif