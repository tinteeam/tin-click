/*
* Warning messageboxes for tin-click. Used to alert the user of unimplemented features or other warnings.
* Tinteeam (C) 2026 Licensed under the MIT License. See LICENSE file in the project root for full license information.
*/

#ifndef WARNINGS_HPP  
#define WARNINGS_HPP  

#ifndef UNICODE  
#define UNICODE  
#endif  

#include <Windows.h> 

namespace tin_click_inc {
    class NotImplWarn {
    public:
        static void NotImplementedWarn() {
            MessageBox(NULL, L"Feature not implemented.", L"Warning", MB_OK | MB_ICONWARNING);
        }
    };
    class DevWarn {
    public:
        static void UnderDev() {
            MessageBox(NULL, L"This feature is under development.", L"Warning", MB_OK | MB_ICONWARNING);
        }

		static void Deprecated() {
			MessageBox(NULL, L"This feature is deprecated and may be removed in future versions.", L"Warning", MB_OK | MB_ICONWARNING);
		}
    };

    class GeneralWarn {
	public:
		static void ShowWarning(LPCWSTR message, LPCWSTR title) {
			MessageBox(NULL, message, title, MB_OK | MB_ICONWARNING);
		}
    };
};

#endif // WARNINGS_HPP