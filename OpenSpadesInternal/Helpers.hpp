//Copyright 2020 Kix
#pragma once

#include <Windows.h>
#include "Offsets.hpp"
#include "Math.hpp"

namespace Helpers
{
	static void Patch(BYTE* dst, BYTE* src, unsigned int size)
	{
		DWORD oldprotect;
		VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);

		memcpy(dst, src, size);
		VirtualProtect(dst, size, oldprotect, &oldprotect);
	}

	static void Nop(BYTE* dst, unsigned int size)
	{
		DWORD oldprotect;
		VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
		memset(dst, 0x90, size);
		VirtualProtect(dst, size, oldprotect, &oldprotect);
	}

	static uintptr_t GetBase()
	{
		return (uintptr_t)GetModuleHandle("OpenSpades.exe");
	}

	static bool World2Screen(Vector3 v, Vector2& out, SceneDefinition lastSceneDef)
	{
		v -= lastSceneDef.ViewOrigin;

		// transform to NDC
		Vector3 v2;
		v2.x = Vector3::Dot(v, lastSceneDef.ViewAxis[0]);
		v2.y = Vector3::Dot(v, lastSceneDef.ViewAxis[1]);
		v2.z = Vector3::Dot(v, lastSceneDef.ViewAxis[2]);

		if (v2.z < 0.1f)
			return false;

		float tanX = tanf(lastSceneDef.FovX * .5f);
		float tanY = tanf(lastSceneDef.FovY * .5f);

		v2.x /= tanX * v2.z;
		v2.y /= tanY * v2.z;

		// transform to IRenderer 2D coord
		out.x = (v2.x + 1.f) / 2.f * Width;
		out.y = (-v2.y + 1.f) / 2.f * Height;

		return true;
	}

	static bool IsEntValid(Player* ent)
	{
		if (ent->Health <= 0) return false;
		else return true;
	}
}