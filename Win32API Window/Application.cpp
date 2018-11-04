#include <windows.h> //Windows header file.

//Callback WindowProcedure function.
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

//Windows API command.
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	//Window class so you can create multiple windows from this class.
	WNDCLASSW wc = { 0 };

	//Set background color
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	//Set type of cursor to show arrow is default
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	//Set hInstance
	wc.hInstance = hInst;
	//Set class name string L" used for any wc.l functions. Used to help use create windows under the same class.
	wc.lpszClassName = L"WindowClass";
	//Set windows procedure name. Used to manage interaction with the window. Window procedure function at top.
	wc.lpfnWndProc = WindowProcedure;

	//Registers window using wc class
	if (!RegisterClassW(&wc))
		return -1;

	//Create window (Class name (wc.lpszClassName), Window name, Window Style and make window visible on opening, Where to spawn window (x,y), Resolution (Height, Width), Dont need to use menus yet so return null
	CreateWindowW(L"WindowClass", L"Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

	//Message structure for loop below
	MSG msg = { 0 };

	//Need a loop so that the application is kept open.
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		//Translate message for proccessing
		TranslateMessage(&msg);
		//Dispatch message to proccessing
		DispatchMessage(&msg);
	}

	//Make sure it returns 0
	return 0;
}

//Define window procedure function
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	//Check message for values
	switch (msg)
	{
	case WM_DESTROY: //When you press the x button quit application
		PostQuitMessage(0); //Quit type
		return 0;
	default: //Take care of messages we are not proccessing
		return DefWindowProcW(hWnd, msg, wp, lp); //Use values defined in function
	}
}