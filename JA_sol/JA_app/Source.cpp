#include <windows.h>
#include "stdafx.h"

extern "C" int _stdcall MyProc1(DWORD x, DWORD y);
int _tmain(int argc, _TCHAR* argv[]) 
{
	typedef int(_stdcall *proc)(int);

	HINSTANCE dll = LoadLibrary("JA_dll");
	proc MyProc2 = (proc)GetProcAddress(dll, "MyProc2");

	int x = 3, y = 4, z = 0;
	z = MyProc1(x, y); // wywo³anie procedury asemblerowej z biblioteki
	z = MyProc2(y);

	FreeLibrary(dll);
	return 0;
}

