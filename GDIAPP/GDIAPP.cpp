//GDIAPP.cpp: 定义应用程序的入口点。
//

#include "stdafx.h"
#include "GDIAPP.h"
#include "math.h"

#define MAX_LOADSTRING 100

// 全局变量: 
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GDIAPP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化: 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GDIAPP));

    MSG msg;

    // 主消息循环: 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GDIAPP));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GDIAPP);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HPEN hPen, hPenOld; //定义画笔
	HBRUSH hBrush, hBrushOld;//定义画刷
	TEXTMETRIC tm; //定义tm用于获取字体信息
	int x = 10, y = 150;
	PAINTSTRUCT ps;
	RECT rect;
	switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择: 
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			hPen = (HPEN)CreatePen(PS_SOLID, 3, RGB(0, 0, 255)); //创建蓝色实线画笔，宽3像素点
			hBrush = (HBRUSH)CreateHatchBrush(HS_CROSS, RGB(255, 0, 0)); //创建红色网格线的画刷
			// TODO: 在此处添加使用 hdc 的任何绘图代码...

			int x1 = 400, y1 = 50, x2 = 900, y2 = 400;
			Rectangle(hdc, x1, y1, x2, y2);
			MoveToEx(hdc, x1, (y1 + y2) / 2, NULL);

			int x3, y3 = (y1 + y2) / 2;
			for (x = 0; x < x2 - x1; ++x)
			{
				y = (1 - sin(2 * 3.14*(x*1.0 / (x2 - x1))))*((y2 - y1) / 2);
				LineTo(hdc, x + x1, y + y3);
				MoveToEx(hdc, x + x1, y + y3, NULL);
			}

			hPenOld = (HPEN)SelectObject(hdc, hPen);//绘制蓝色三角函数曲线
			y3 = (y1 + y2) / 2 - 100;
			for (x = 0; x < x2 - x1; x++)
			{
				y = (1 - sin(2 * 3.14*(x*1.0 / (x2 - x1))))*((y2 - y1) / 2);
				MoveToEx(hdc, x + x1, y + y3, NULL);
				LineTo(hdc, x + x1, y + y3);
			}

			hPenOld = (HPEN)SelectObject(hdc, CreatePen(PS_DASH, 5, RGB(0, 255, 0)));
			y3 = (y1 + y2) / 2 - 200;
			for (x = 0; x < x2 - x1; x++)
			{
				y = (1 - sin(2 * 3.14*(x*1.0 / (x2 - x1))))*((y2 - y1) / 2);
				MoveToEx(hdc, x + x1, y + y3, NULL);
				LineTo(hdc, x + x1, y + y3);
			}

			GetClientRect(hWnd, &rect);
			/*下面用SelectObject函数将创建的画笔和画刷选入Windows系统，选入之后所有的图形函数都会用新建的蓝色画笔画图，用红色的网格画刷填充图形*/

			hPenOld = (HPEN)SelectObject(hdc, hPen);     //选入新画笔，返回旧画笔句柄
			hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);   //选入新画刷，返回旧画刷句柄
			Rectangle(hdc, 100, 10, 180, 80);//画矩形
			
			SelectObject(hdc, hPenOld);
			hBrush = (HBRUSH)CreateHatchBrush(HS_DIAGCROSS, RGB(0, 255, 255));
			hPenOld = (HPEN)SelectObject(hdc, CreatePen(PS_DASH, 5, RGB(100, 255, 100)));
			hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
			Ellipse(hdc, 250, 10, 350, 80); //画椭圆

			SelectObject(hdc, hPenOld);
			hBrush = (HBRUSH)CreateHatchBrush(HS_DIAGCROSS, RGB(80, 255, 255));
			hPenOld = (HPEN)SelectObject(hdc, CreatePen(PS_DASH, 5, RGB(100, 100, 200)));
			hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
			RoundRect(hdc, 100, 210, 180, 280, 50, 50);//画圆角矩形

			SelectObject(hdc, hPenOld);
			hBrush = (HBRUSH)CreateHatchBrush(HS_DIAGCROSS, RGB(45, 0, 0));
			hPenOld = (HPEN)SelectObject(hdc, CreatePen(PS_DASH, 5, RGB(200, 130, 150)));
			hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
			Arc(hdc, 100, 300, 250, 450, 100, 350, 240, 350);//画圆弧

			SelectObject(hdc, hPenOld);
			hBrush = (HBRUSH)CreateHatchBrush(HS_DIAGCROSS, RGB(45, 0, 0));
			hPenOld = (HPEN)SelectObject(hdc, CreatePen(PS_DASH, 5, RGB(200, 130, 150)));
			hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
			Chord(hdc, 100, 500, 250, 650, 100, 550, 240, 600);//画弓形

			SelectObject(hdc, hPenOld);
			hBrush = (HBRUSH)CreateHatchBrush(HS_DIAGCROSS, RGB(180, 150, 80));
			hPenOld = (HPEN)SelectObject(hdc, CreatePen(PS_DASH, 5, RGB(200, 170, 220)));
			hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
			Pie(hdc, 300, 500, 500, 650, 350, 550, 500, 600);//画扇形

			SelectObject(hdc, hBrushOld); //恢复系统默认画刷
			SelectObject(hdc, hPenOld); //恢复系统默认画笔

			GetTextMetrics(hdc, &tm); //将当前字体信息存入tm
			TextOut(hdc, x, y, L"默认系统的字体色彩!", 10);
			SetTextColor(hdc, RGB(255, 0, 0));//设置字体为红色
			y = y + tm.tmHeight + tm.tmExternalLeading; //计算下一行字体输出的纵坐标
			TextOut(hdc, x, y, L"红色的字体色彩!", 8); //用设置的颜色输出文本

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
