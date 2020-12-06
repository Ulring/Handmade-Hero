/*###################################################################

#File Name: win32_handmade.cpp
#Author: Anass Soulimani 
#Email: anasssoulimani@gmail.com
#Creation Date: Sun 18 Oct 2020 05:25:46 AM +01
#Last Modified: Tue 20 Oct 2020 02:09:28 AM +01

###################################################################*/

#include <windows.h>

int CALLBACK 
WinMain(
		HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpCmdLine,
		int nCmdShow)
{
	MessageBoxA(0, "This is Handmade Hero.", "Handmade Hero", MB_OK|MB_ICONINFORMATION);
	return(0);
}
