#include "Overlay.h"
#include "Offsets.hpp"
#include "Visuals.hpp"
#include "Menu.hpp"

int Width = 1980; //#Ghetto
int Height = 1080; //#Ghetto
HWND TargetWnd;
const MARGINS Margin = { -1, -1, Width, Height };
HWND hWnd;
MSG Message; RECT TargetRect;
IDirect3D9Ex* pObject = NULL;
IDirect3DDevice9Ex* pDevice = NULL;
D3DPRESENT_PARAMETERS pParam;
ID3DXLine* pLine = 0;
ID3DXFont* pFont = 0;
Menu* menu;
int fontHeight = 22;

LRESULT CALLBACK Proc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch (Message)
    {
    case WM_PAINT:
        DwmExtendFrameIntoClientArea(hWnd, &Margin);

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    default:
        return DefWindowProc(hWnd, Message, wParam, lParam);
    }

    return 0;
}

BOOL RegisterDLLWindowClass(HINSTANCE hInstance)
{
    WNDCLASSEX OverlayWnd;

    OverlayWnd.cbClsExtra = 0;
    OverlayWnd.cbSize = sizeof(WNDCLASSEX);
    OverlayWnd.cbWndExtra = 0;
    OverlayWnd.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
    OverlayWnd.hCursor = LoadCursor(0, IDC_ARROW);
    OverlayWnd.hIcon = LoadIcon(0, IDI_APPLICATION);
    OverlayWnd.hIconSm = LoadIcon(0, IDI_APPLICATION);
    OverlayWnd.hInstance = hInstance;
    OverlayWnd.lpfnWndProc = Proc;
    OverlayWnd.lpszClassName = "Yeet";
    OverlayWnd.lpszMenuName = "Yeet";
    OverlayWnd.style = CS_HREDRAW | CS_VREDRAW;

    if (!RegisterClassEx(&OverlayWnd))
        return 0;

    return 1;
}

int DirectXInit(HWND hWnd)
{
    if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &pObject)))
        exit(1);

    pParam.BackBufferFormat = D3DFMT_A8R8G8B8;
	pParam.BackBufferWidth = Width;
	pParam.BackBufferHeight = Height;
	pParam.hDeviceWindow = hWnd;
    pParam.MultiSampleQuality = DEFAULT_QUALITY;
    pParam.SwapEffect = D3DSWAPEFFECT_DISCARD;
    pParam.Windowed = true;

    if (FAILED(pObject->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &pParam, 0, &pDevice)))
        exit(1);

	menu = new Menu("OpenSpades Internal by Kix [Insert]");

    return 0;
}

void DirectXShutdown()
{
	pLine->Release();
	pFont->Release();
}

void DrawFilledRect(int x, int y, int w, int h, D3DCOLOR color)
{
	D3DRECT rect = { x, y, x + (LONG)w, y + (LONG)h };
	pDevice->Clear(1, &rect, D3DCLEAR_TARGET, color, 0, 0);
}

void DrawBorderedRect(int x, int y, int w, int h, D3DCOLOR  outercolor, D3DCOLOR  innercolor)
{
	DrawFilledRect(x, y, w, h, outercolor);
	DrawFilledRect(x + 2, y + 2, w - 4, h - 4, innercolor);
}

void DrawLine(int x1, int y1, int x2, int y2, int thickness, D3DCOLOR color)
{

	if (!pLine)
	{
		D3DXCreateLine(pDevice, &pLine);
	}


	D3DXVECTOR2 Line[2];
	Line[0] = D3DXVECTOR2((FLOAT)x1, (FLOAT)y1);
	Line[1] = D3DXVECTOR2((FLOAT)x2, (FLOAT)y2);
	pLine->SetAntialias(true);
	pLine->SetWidth((FLOAT)thickness);
	pLine->Draw(Line, 2, color);
}

void DrawLine(Vector2 src, Vector2 dst, int thickness, D3DCOLOR color)
{
	DrawLine((int)src.x, (int)src.y, (int)dst.x, (int)dst.y, thickness, color);
}

void Draw2DBox(Vector2 pos, Vector2 dimensions, int thickness, D3DCOLOR color)
{
	DrawLine((int)(pos.x - (dimensions.x / 2)), (int)(pos.y - dimensions.y), (int)(pos.x + (dimensions.x / 2)), (int)(pos.y - dimensions.y), thickness, color);
	DrawLine((int)(pos.x + (dimensions.x / 2)), (int)(pos.y - dimensions.y), (int)(pos.x + (dimensions.x / 2)), (int)pos.y, thickness, color);
	DrawLine((int)(pos.x + (dimensions.x / 2)), (int)pos.y, (int)(pos.x - (dimensions.x / 2)), (int)pos.y, thickness, color);
	DrawLine((int)(pos.x - (dimensions.x / 2)), (int)pos.y, (int)(pos.x - (dimensions.x / 2)), (int)(pos.y - dimensions.y), thickness, color);
}

void Draw3DBox(Vector3 top, Vector3 bottom, float angle, int width, int thickness, D3DCOLOR color)
{
	float height = fabsf(top.z - bottom.z);
	Vector3 b1, b2, b3, b4, t1, t2, t3, t4;
	b1.z = b2.z = b3.z = b4.z = bottom.z;

	b1.x = bottom.x + (cosf((angle + 45.f) * (float)M_PI / 180.f) * width);
	b1.y = bottom.y + (sinf((angle + 45.f) * (float)M_PI / 180.f) * width);

	b2.x = bottom.x + (cosf((angle + 135.f) * (float)M_PI / 180.f) * width);
	b2.y = bottom.y + (sinf((angle + 135.f) * (float)M_PI / 180.f) * width);

	b3.x = bottom.x + (cosf((angle + 225.f) * (float)M_PI / 180.f) * width);
	b3.y = bottom.y + (sinf((angle + 225.f) * (float)M_PI / 180.f) * width);

	b4.x = bottom.x + (cosf((angle + 315.f) * (float)M_PI / 180.f) * width);
	b4.y = bottom.y + (sinf((angle + 315.f) * (float)M_PI / 180.f) * width);

	t1.x = b1.x;
	t1.y = b1.y;
	t1.z = b1.z + height;

	t2.x = b2.x;
	t2.y = b2.y;
	t2.z = b2.z + height;

	t3.x = b3.x;
	t3.y = b3.y;
	t3.z = b3.z + height;

	t4.x = b4.x;
	t4.y = b4.y;
	t4.z = b4.z + height;

	Vector2 b1_2, b2_2, b3_2, b4_2, t1_2, t2_2, t3_2, t4_2;

	if (Helpers::World2Screen(b1, b1_2, Offsets::sceneDef) && Helpers::World2Screen(b2, b2_2, Offsets::sceneDef) && Helpers::World2Screen(b3, b3_2, Offsets::sceneDef) && Helpers::World2Screen(b4, b4_2, Offsets::sceneDef) && Helpers::World2Screen(t1, t1_2, Offsets::sceneDef) && Helpers::World2Screen(t2, t2_2, Offsets::sceneDef) && Helpers::World2Screen(t3, t3_2, Offsets::sceneDef) && Helpers::World2Screen(t4, t4_2, Offsets::sceneDef))
	{
		//Columns
		DrawLine(t1_2, b1_2, thickness, color);
		DrawLine(t2_2, b2_2, thickness, color);
		DrawLine(t3_2, b3_2, thickness, color);
		DrawLine(t4_2, b4_2, thickness, color);

		//Top
		DrawLine(t1_2, t2_2, thickness, color);
		DrawLine(t2_2, t3_2, thickness, color);
		DrawLine(t3_2, t4_2, thickness, color);
		DrawLine(t4_2, t1_2, thickness, color);

		//Bottom
		DrawLine(b1_2, b2_2, thickness, color);
		DrawLine(b2_2, b3_2, thickness, color);
		DrawLine(b3_2, b4_2, thickness, color);
		DrawLine(b4_2, b1_2, thickness, color);
	}
}

void DrawCircle(int X, int Y, int radius, int numSides, int thickness, D3DCOLOR color)
{
	D3DXVECTOR2 Line[128];
	float Step = (float)(M_PI * 2.0 / numSides);
	int Count = 0;
	for (float a = 0; a < M_PI * 2.0; a += Step)
	{
		float X1 = radius * cosf(a) + X;
		float Y1 = radius * sinf(a) + Y;
		float X2 = radius * cosf(a + Step) + X;
		float Y2 = radius * sinf(a + Step) + Y;
		Line[Count].x = X1;
		Line[Count].y = Y1;
		Line[Count + 1].x = X2;
		Line[Count + 1].y = Y2;
		Count += 2;
	}
	pLine->Begin();
	pLine->SetWidth((FLOAT)thickness);
	pLine->Draw(Line, Count, color);
	pLine->End();
}

void DrawString(const char* text, int x, int y, D3DCOLOR color, bool bold)
{
	RECT rect;

	if (!pFont)
		D3DXCreateFontA(pDevice, fontHeight, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &pFont);

	if (bold)
	{
		SetRect(&rect, x + 1, y + 1, x + 1, y + 1);
		pFont->DrawTextA(NULL, text, -1, &rect, DT_LEFT | DT_NOCLIP, D3DCOLOR_ARGB(255, 0, 0, 0));
	}

	SetRect(&rect, x, y, x, y);
	pFont->DrawTextA(NULL, text, -1, &rect, DT_LEFT | DT_NOCLIP, color);
}

void DrawStringCentered(const char* text, int x, int y, D3DCOLOR color, bool bold)
{
	RECT rect;

	if (!pFont)
		D3DXCreateFontA(pDevice, fontHeight, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &pFont);
	if (bold)
	{
		SetRect(&rect, x + 1, y + 1, x + 1, y + 1);
		pFont->DrawTextA(NULL, text, -1, &rect, DT_CENTER | DT_NOCLIP, D3DCOLOR_ARGB(255, 0, 0, 0));
	}

	SetRect(&rect, x, y, x, y);
	pFont->DrawTextA(NULL, text, -1, &rect, DT_CENTER | DT_NOCLIP, color);
}

int Render()
{
    pDevice->Clear(0, 0, D3DCLEAR_TARGET, 0, 1.0f, 0);
    pDevice->BeginScene();

    if (TargetWnd == GetForegroundWindow())
    {
		menu->Draw();
		ESP(Config::bEsp);
    }

    pDevice->EndScene();
    pDevice->PresentEx(0, 0, 0, 0, 0);
    return 0;
}