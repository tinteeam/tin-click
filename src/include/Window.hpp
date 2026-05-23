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

#endif