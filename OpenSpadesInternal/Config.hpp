#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3d9.lib")

namespace Config
{
	inline bool bEsp = false;
	inline bool bAimbot = false;
	inline bool bNoRecoil = false;
	inline bool bNoSpread = false;
	inline bool bShrootTHroughWalls = false;
	inline bool bMaxShot = false;
}

namespace Colors
{
	const D3DCOLOR Red = D3DCOLOR_RGBA(255, 0, 0, 255);
	const D3DCOLOR Orange = D3DCOLOR_RGBA(255, 100, 0, 255);
	const D3DCOLOR Yellow = D3DCOLOR_RGBA(255, 255, 0, 255);
	const D3DCOLOR Green = D3DCOLOR_RGBA(0, 255, 0, 255);
	const D3DCOLOR Turquoise = D3DCOLOR_RGBA(0, 255, 255, 255);
	const D3DCOLOR Blue = D3DCOLOR_RGBA(0, 0, 255, 255);
	const D3DCOLOR Purple = D3DCOLOR_RGBA(130, 0, 255, 255);
	const D3DCOLOR Pink = D3DCOLOR_RGBA(255, 0, 255, 255);
	const D3DCOLOR Black = D3DCOLOR_RGBA(0, 0, 0, 255);
	const D3DCOLOR Gray = D3DCOLOR_RGBA(69, 69, 69, 255);
	const D3DCOLOR White = D3DCOLOR_RGBA(255, 255, 255, 255);
}