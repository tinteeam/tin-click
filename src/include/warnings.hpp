/*
* Warning messageboxes for tin-click. Used to alert the user of unimplemented features or other warnings.
* Tinteeam (C) 2026 Licensed under the MIT License. See LICENSE file in the project root for full license information.
*/

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