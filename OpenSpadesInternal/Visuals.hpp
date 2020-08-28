//Copyright 2020 Kix
#pragma once

#include "Overlay.h"
#include "Config.hpp"
#include "Helpers.hpp"
#include "Math.hpp"

void ESP(bool enable)
{
	if (enable)
	{
		for (unsigned int i = 0; i < Offsets::draws.size(); i++)
		{

			Vector4 cur = Offsets::draws.at(i);

			DrawLine(Width / 2, Height, (int)cur.x, (int)cur.y, 1, Colors::Red);

			Draw2DBox(Vector2(cur.x, cur.y), Vector2(cur.z, cur.w), 1, Colors::Red);
		}
	}
}