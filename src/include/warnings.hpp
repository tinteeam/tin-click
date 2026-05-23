#ifndef WARNINGS_HPP  
#define WARNINGS_HPP  

namespace tin_click_inc {
    class NotImplWarn {
    public:
        static void NotImplementedWarn() {
            MessageBox(NULL, L"Feature not implemented.", L"Warning", MB_OK | MB_ICONWARNING);
        }
    };
};

#endif // WARNINGS_HPP