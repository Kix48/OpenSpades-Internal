#pragma once

#include <Windows.h>
#include <d3dx9.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dwmapi.h>
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "dwmapi.lib")
#include "Math.hpp"
#include "Config.hpp"

//variable declaration external to be able to use it in .cpp
extern IDirect3D9Ex* pObject;
extern IDirect3DDevice9Ex* pDevice;
extern D3DPRESENT_PARAMETERS pParam;
extern ID3DXLine* pLine;
extern ID3DXFont* pFont;
extern int Render();
extern int Width;
extern int Height;
extern HWND TargetWnd;
extern HWND hWnd;
extern MSG Message;
extern RECT TargetRect;
extern const MARGINS Margin;

LRESULT CALLBACK Proc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);

BOOL RegisterDLLWindowClass(HINSTANCE hInstance);

int DirectXInit(HWND hWnd);

void DirectXShutdown();

void DrawFilledRect(int x, int y, int w, int h, D3DCOLOR color);

void DrawBorderedRect(int x, int y, int w, int h, D3DCOLOR  outercolor, D3DCOLOR  innercolor);

void DrawLine(int x1, int y1, int x2, int y2, int thickness, D3DCOLOR color);

void DrawLine(Vector2 src, Vector2 dst, int thickness, D3DCOLOR color);

void Draw2DBox(Vector2 pos, Vector2 dimensions, int thickness, D3DCOLOR color);

void Draw3DBox(Vector3 top, Vector3 bottom, float angle, int width, int thickness, D3DCOLOR color);

void DrawCircle(int X, int Y, int radius, int numSides, int thickness, D3DCOLOR color);

void DrawString(const char* text, int x, int y, D3DCOLOR color, bool bold);

void DrawStringCentered(const char* text, int x, int y, D3DCOLOR color, bool bold);
