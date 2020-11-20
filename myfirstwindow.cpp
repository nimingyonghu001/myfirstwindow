//myfirstwindow
#include<windows.h>
#include"resource1.h"
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int CmdShow)
{
	//设计窗口
	WNDCLASS wc = { 0 };
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON1));//LoadIcon(NULL,IDI_ERROR);/LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON1));
	wc.hCursor = LoadCursor(NULL, IDC_IBEAM);
	wc.hbrBackground = CreateSolidBrush(RGB(150, 150, 150));
	wc.lpszMenuName = NULL;
	wc.lpszClassName = L"MyFirstWindow";

	//注册窗口
	if (0 == RegisterClass(&wc))
	{
		return 0;
	}
	//创建窗口
	HWND hWnd=CreateWindow(
		L"MyFirstWindow",
		L"welcome to my world",
		WS_BORDER| WS_VSCROLL| WS_CAPTION|WS_SYSMENU|WS_MAXIMIZEBOX|WS_MINIMIZEBOX,
		300,200,
		800,600,
		NULL,
		NULL,
		hInstance,
		NULL,
		);
	if (hWnd == NULL)
	{
		return 0;
	}

	//显示窗口
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	//消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//将虚拟键消息转换为字符消息
		TranslateMessage(&msg);
		//再将消息分发给各个句柄处理
		DispatchMessage(&msg);
	}
	return 0;
}
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//窗口彻底销毁句柄
	switch (uMsg)
	{
		//从用户界面销毁窗口
		//窗口关闭消息
	case WM_CLOSE:
		//销毁窗口
		DestroyWindow(hWnd);
		break;

		//从后台销毁窗口
		//窗口销毁消息
	case WM_DESTROY:
		//发出一个销毁消息
		PostQuitMessage(0);//WM_QUIT
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
