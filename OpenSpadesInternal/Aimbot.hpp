#pragma once

#include "Offsets.hpp"
#include "Helpers.hpp"
#include "Math.hpp"

float smooth = 4.f;

void Aimbot(Vector3 pos)
{
	Vector2 screen;
	if (!Helpers::World2Screen(pos, screen, Offsets::sceneDef))
		return;

    INPUT Input = { 0 };
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_MOVE;
    Input.mi.dx = (LONG)((screen.x - Width / 2) / smooth);
    Input.mi.dy = (LONG)((screen.y - Height / 2) / smooth);
    SendInput(1, &Input, sizeof(INPUT));
}