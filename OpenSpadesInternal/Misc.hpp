#pragma once

#include "Offsets.hpp"
#include "Helpers.hpp"

uintptr_t infAmmoAddr = 0xD7B0E;
uintptr_t noRecoilAddr = 0xCAAB9;
uintptr_t noSpreadAddr = 0xC9915;
uintptr_t fullAutoAddr = 0xD7AF3;
uintptr_t shootThroughWallsAddr = 0xCA0F0;
uintptr_t maxShotAddr = 0xCA522;

void InfAmmo(bool enable)
{
	if (enable)
	{

		Helpers::Nop((BYTE*)(Offsets::base + infAmmoAddr), 1);
	}
	else
	{
		Helpers::Patch((BYTE*)(Offsets::base + infAmmoAddr), (BYTE*)"\x48", 1);
	}
}

void NoRecoil(bool enable)
{
	if (enable)
	{
		Helpers::Nop((BYTE*)(Offsets::base + noRecoilAddr), 14);
	}
	else
	{
		Helpers::Patch((BYTE*)(Offsets::base + noRecoilAddr), (BYTE*)"\x50\x66\x0F\xD6\x8D\x58\xFE\xFF\xFF\xE8\x2F\x00\xF4\xFF", 14);
	}
}

void NoSpread(bool enable)
{
	if (enable)
	{
		Helpers::Patch((BYTE*)(Offsets::base + noSpreadAddr), (BYTE*)"\xF3\x0F\x10\x05\x20\x33\x2F\x01", 8);
	}
	else
	{
		Helpers::Patch((BYTE*)(Offsets::base + noSpreadAddr), (BYTE*)"\xF3\x0F\x10\x05\x50\x46\x2F\x01", 8);
	}
}

void FullAuto(bool enable)
{
	if (enable)
	{
		if (Offsets::localPlayer->WeaponPtr->ShootingPreviously)
			Offsets::localPlayer->WeaponPtr->NextShotTime = Offsets::localPlayer->WeaponPtr->Time;
	}
}

void ShootThroughWalls(bool enable)
{
	if (enable)
	{
		Helpers::Patch((BYTE*)(Offsets::base + shootThroughWallsAddr), (BYTE*)"\xE9\xE0\x03\x00\x00", 5);
		Helpers::Nop((BYTE*)(Offsets::base + shootThroughWallsAddr + 0x5), 1);
	}
	else
	{
		Helpers::Patch((BYTE*)(Offsets::base + shootThroughWallsAddr), (BYTE*)"\x0F\x84\xDF\x03\x00\x00", 6);
	}
}

void MaxShot(bool enable) //No distance limitation
{
	if (enable)
	{
		Helpers::Nop((BYTE*)(Offsets::base + maxShotAddr), 6);
	}
	else
	{
		Helpers::Patch((BYTE*)(Offsets::base + maxShotAddr), (BYTE*)"\x0F\x86\x6C\xFD\xFF\xFF", 6);
	}
}