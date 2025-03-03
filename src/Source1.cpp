#include <windows.h>

LRESULT CALLBACK WindowProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
)
{
	const wchar_t CLASS_NAME[] = L"SampleWindowClass";

	WNDCLASS wc = {};

	wc.lpfnWndProc = WindowProc; // УКАЗАТЕЛЬ НА ОКОННУЮ ПРОЦЕДУРУ
	wc.hInstance = hInstance; // ДЕСКРИПТОР ЭКЗЕМПЛЯРА ПРИЛОЖЕНИЯ
	wc.lpszClassName = CLASS_NAME; // ИМЯ КЛАССА ОКНА

	RegisterClass(&wc); // РЕГИСТРАЦИЯ КЛАССА ОКНА

	// СОЗДАНИЕ ОКНА
	HWND hwnd = CreateWindow(
		CLASS_NAME,
		L"Sample Window",
		WS_OVERLAPPEDWINDOW,

		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	if (hwnd == nullptr)
	{
		return 0;
	}

	// ОТОБРАЖЕНИЕ ОКНА
	ShowWindow(hwnd, nCmdShow);

	// ЦИКЛ ОБРАБОТКИ СООБЩЕНИЙ
	MSG msg = {};
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
