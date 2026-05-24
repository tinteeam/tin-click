#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <Windows.h>

namespace tin_click_inc {
	class ErrorHandler {
	public:
		static void ShowError(LPCWSTR message, LPCWSTR title) {
			MessageBox(NULL, message, title, MB_OK | MB_ICONERROR);
		}
	};
};

#endif // ERRORS_HPP