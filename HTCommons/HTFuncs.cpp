#include "stdafxCommons.h"
#include "HTFuncs.h"

namespace HTFuncs {
	size_t getFileName(_In_ TCHAR CONST * CONST src, _Out_ TCHAR * CONST dest) {
		int j = 0;
		for (int i = 0; src[i]; i++) {
			if (src[i] != '\\') {
				dest[j++] = src[i];
			}
			else {
				j = 0;
			}
		}
		dest[j] = 0;
		return j;
	}
}