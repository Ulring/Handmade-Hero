/*###################################################################

#File Name: win32_handmade.cpp
#Author: Anass Soulimani
#Email: anasssoulimani@gmail.com
#Creation Date: Sun 18 Oct 2020 05:25:46 AM +01
#Last Modified: Thu 15 Apr 2021 09:04:15 AM +00

###################################################################*/

#include <windows.h>

LRESULT CALLBACK
MainWindowCallback(HWND Window,
				   UINT Message,
				   WPARAM WParam,
				   LPARAM LParam)
{
	LRESULT Result = 0;

	switch(Message)
	{
		case WM_SIZE:
		{
			OutputDebugStringA("WM_SIZE\n");
		} break;
		case WM_DESTROY:
		{
			OutputDebugStringA("WM_DESTROY\n");
		} break;
		case WM_CLOSE:
		{
			OutputDebugStringA("WM_CLOSE\n");
		} break;
		case WM_ACTIVATEAPP:
		{
			OutputDebugStringA("WM_ACTIVATEAPP\n");
		} break;
		case WM_PAINT:
		{
			PAINTSTRUCT Paint;
			HDC DeviceContext = BeginPaint(Window, &Paint);
			int X = Paint.rcPaint.left;
			int Y = Paint.rcPaint.top;
			int Width = Paint.rcPaint.right - Paint.rcPaint.left;
			int Height = Paint.rcPaint.bottom - Paint.rcPaint.top;
			static DWORD Operation = WHITENESS;
 			PatBlt(DeviceContext, X, Y, Width, Height, Operation);
			if(Operation == WHITENESS)
			{
				Operation = BLACKNESS;
			}
			else
			{
				Operation = WHITENESS;
			}
			EndPaint(Window, &Paint);
		} break;

		default:
		{
			//OutputDebugStringA("default\n");
			Result = DefWindowProc(Window, Message, WParam, LParam);
		} break;
	}

	return(Result);
}

int CALLBACK
WinMain(
		HINSTANCE Instance,
		HINSTANCE PrevInstance,
		LPSTR CommandLine,
		int ShowCode)
{
	WNDCLASS WindowClass = {};

	//WindowClass.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
	WindowClass.lpfnWndProc = MainWindowCallback;
	WindowClass.hInstance = Instance;
	//WindowClass.hIcon;
	WindowClass.lpszClassName = "HandmadeHeroWindowClass";

	if(RegisterClassA(&WindowClass))
	{
		HWND WindowHandle =
			CreateWindowExA(
				0,
				WindowClass.lpszClassName,
				"Handmade Hero",
				WS_OVERLAPPEDWINDOW|WS_VISIBLE,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				0,
				0,
				Instance,
				0);
		//if(WindowHandle != NULL)
		if(WindowHandle)
		{
			for(;;){
				MSG Message;
				BOOL MessageResult = GetMessageA(&Message, 0, 0, 0);
				if(MessageResult > 0)
				{
					TranslateMessage(&Message);
					DispatchMessageA(&Message);
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			//TODO(anass): Logging
		}
	}
	else
	{
		//TODO(anass): Logging
	}

	return(0);
}
