#pragma once

#include "Overlay.h"

class  Menu
{
private:
	Menu() {};
	~Menu() {};

	const char* title = "";
	bool bOpen = false;
	int nextX = 0;
	int nextY = 0;
	int selOpt = 0;

	void InputHandler()
	{

		if (GetAsyncKeyState(VK_INSERT) & 1) this->bOpen = !this->bOpen;

		if (GetAsyncKeyState(VK_UP) & 1)
		{
			this->selOpt--;
			if (this->selOpt < 0) this->selOpt = 0;
		}

		if (GetAsyncKeyState(VK_DOWN) & 1)
		{
			this->selOpt++;
			if (this->selOpt > 5) this->selOpt = 5;
		}

		if (GetAsyncKeyState(VK_LEFT) & 1)
		{
			switch (this->selOpt)
			{
				case 0:
				{
					Config::bAimbot = false;
					break;
				}

				case 1:
				{
					Config::bEsp = false;
					break;
				}

				case 2:
				{
					Config::bNoRecoil = false;
					break;
				}

				case 3:
				{
					Config::bNoSpread = false;
					break;
				}

				case 4:
				{
					Config::bShrootTHroughWalls = false;
					break;
				}

				case 5:
				{
					Config::bMaxShot = false;
					break;
				}
			}
		}

		if (GetAsyncKeyState(VK_RIGHT) & 1)
		{
			switch (this->selOpt)
			{
				case 0:
				{
					Config::bAimbot = true;
					break;
				}

				case 1:
				{
					Config::bEsp = true;
					break;
				}

				case 2:
				{
					Config::bNoRecoil = true;
					break;
				}

				case 3:
				{
					Config::bNoSpread = true;
					break;
				}

				case 4:
				{
					Config::bShrootTHroughWalls = true;
					break;
				}

				case 5:
				{
					Config::bMaxShot = true;
					break;
				}
			}
		}
	}

public:
	Menu(const char* title)
	{
		this->title = title;
		this->bOpen = true;
		int selOpt = 0;
	}

	void Draw()
	{
		this->nextX = Width / 2;
		this->nextY = 30;

		InputHandler();

		DrawStringCentered(this->title, nextX, nextY + (0 * 20), Colors::Purple, false);

		if (bOpen)
		{
			switch (this->selOpt)
			{
				case 0:
				{
					DrawStringCentered("Aimbot", nextX, nextY + (1 * 20), Colors::Yellow, false);

					if(Config::bEsp)
						DrawStringCentered("ESP", nextX, nextY + (2 * 20), Colors::Green, false);
					else
						DrawStringCentered("ESP", nextX, nextY + (2 * 20), Colors::Red, false);

					if (Config::bNoRecoil)
						DrawStringCentered("No Recoil", nextX, nextY + (3 * 20), Colors::Green, false);
					else
						DrawStringCentered("No Recoil", nextX, nextY + (3 * 20), Colors::Red, false);

					if (Config::bNoSpread)
						DrawStringCentered("No Spread", nextX, nextY + (4 * 20), Colors::Green, false);
					else
						DrawStringCentered("No Spread", nextX, nextY + (4 * 20), Colors::Red, false);

					if (Config::bShrootTHroughWalls)
						DrawStringCentered("Shoot Through Walls", nextX, nextY + (5 * 20), Colors::Green, false);
					else
						DrawStringCentered("Shoot Through Walls", nextX, nextY + (5 * 20), Colors::Red, false);

					if (Config::bMaxShot)
						DrawStringCentered("Max Shot", nextX, nextY + (6 * 20), Colors::Green, false);
					else
						DrawStringCentered("Max Shot", nextX, nextY + (6 * 20), Colors::Red, false);

					break;
				}

				case 1:
				{
					if(Config::bAimbot)
						DrawStringCentered("Aimbot", nextX, nextY + (1 * 20), Colors::Green, false);
					else
						DrawStringCentered("Aimbot", nextX, nextY + (1 * 20), Colors::Red, false);

					DrawStringCentered("ESP", nextX, nextY + (2 * 20), Colors::Yellow, false);

					if (Config::bNoRecoil)
						DrawStringCentered("No Recoil", nextX, nextY + (3 * 20), Colors::Green, false);
					else
						DrawStringCentered("No Recoil", nextX, nextY + (3 * 20), Colors::Red, false);

					if (Config::bNoSpread)
						DrawStringCentered("No Spread", nextX, nextY + (4 * 20), Colors::Green, false);
					else
						DrawStringCentered("No Spread", nextX, nextY + (4 * 20), Colors::Red, false);

					if (Config::bShrootTHroughWalls)
						DrawStringCentered("Shoot Through Walls", nextX, nextY + (5 * 20), Colors::Green, false);
					else
						DrawStringCentered("Shoot Through Walls", nextX, nextY + (5 * 20), Colors::Red, false);

					if (Config::bMaxShot)
						DrawStringCentered("Max Shot", nextX, nextY + (6 * 20), Colors::Green, false);
					else
						DrawStringCentered("Max Shot", nextX, nextY + (6 * 20), Colors::Red, false);

					break;
				}

				case 2:
				{
					if (Config::bAimbot)
						DrawStringCentered("Aimbot", nextX, nextY + (1 * 20), Colors::Green, false);
					else
						DrawStringCentered("Aimbot", nextX, nextY + (1 * 20), Colors::Red, false);

					if (Config::bEsp)
						DrawStringCentered("ESP", nextX, nextY + (2 * 20), Colors::Green, false);
					else
						DrawStringCentered("ESP", nextX, nextY + (2 * 20), Colors::Red, false);

						DrawStringCentered("No Recoil", nextX, nextY + (3 * 20), Colors::Yellow, false);

					if (Config::bNoSpread)
						DrawStringCentered("No Spread", nextX, nextY + (4 * 20), Colors::Green, false);
					else
						DrawStringCentered("No Spread", nextX, nextY + (4 * 20), Colors::Red, false);

					if (Config::bShrootTHroughWalls)
						DrawStringCentered("Shoot Through Walls", nextX, nextY + (5 * 20), Colors::Green, false);
					else
						DrawStringCentered("Shoot Through Walls", nextX, nextY + (5 * 20), Colors::Red, false);

					if (Config::bMaxShot)
						DrawStringCentered("Max Shot", nextX, nextY + (6 * 20), Colors::Green, false);
					else
						DrawStringCentered("Max Shot", nextX, nextY + (6 * 20), Colors::Red, false);

					break;
				}

				case 3:
				{
					if (Config::bAimbot)
						DrawStringCentered("Aimbot", nextX, nextY + (1 * 20), Colors::Green, false);
					else
						DrawStringCentered("Aimbot", nextX, nextY + (1 * 20), Colors::Red, false);

					if (Config::bEsp)
						DrawStringCentered("ESP", nextX, nextY + (2 * 20), Colors::Green, false);
					else
						DrawStringCentered("ESP", nextX, nextY + (2 * 20), Colors::Red, false);

					if (Config::bNoRecoil)
						DrawStringCentered("No Recoil", nextX, nextY + (3 * 20), Colors::Green, false);
					else
						DrawStringCentered("No Recoil", nextX, nextY + (3 * 20), Colors::Red, false);

					DrawStringCentered("No Spread", nextX, nextY + (4 * 20), Colors::Yellow, false);

					if (Config::bShrootTHroughWalls)
						DrawStringCentered("Shoot Through Walls", nextX, nextY + (5 * 20), Colors::Green, false);
					else
						DrawStringCentered("Shoot Through Walls", nextX, nextY + (5 * 20), Colors::Red, false);

					if (Config::bMaxShot)
						DrawStringCentered("Max Shot", nextX, nextY + (6 * 20), Colors::Green, false);
					else
						DrawStringCentered("Max Shot", nextX, nextY + (6 * 20), Colors::Red, false);

					break;
				}

				case 4:
				{
					if (Config::bAimbot)
						DrawStringCentered("Aimbot", nextX, nextY + (1 * 20), Colors::Green, false);
					else
						DrawStringCentered("Aimbot", nextX, nextY + (1 * 20), Colors::Red, false);

					if (Config::bEsp)
						DrawStringCentered("ESP", nextX, nextY + (2 * 20), Colors::Green, false);
					else
						DrawStringCentered("ESP", nextX, nextY + (2 * 20), Colors::Red, false);

					if (Config::bNoRecoil)
						DrawStringCentered("No Recoil", nextX, nextY + (3 * 20), Colors::Green, false);
					else
						DrawStringCentered("No Recoil", nextX, nextY + (3 * 20), Colors::Red, false);

					if (Config::bNoSpread)
						DrawStringCentered("No Spread", nextX, nextY + (4 * 20), Colors::Green, false);
					else
						DrawStringCentered("No Spread", nextX, nextY + (4 * 20), Colors::Red, false);

					DrawStringCentered("Shoot Through Walls", nextX, nextY + (5 * 20), Colors::Yellow, false);

					if (Config::bMaxShot)
						DrawStringCentered("Max Shot", nextX, nextY + (6 * 20), Colors::Green, false);
					else
						DrawStringCentered("Max Shot", nextX, nextY + (6 * 20), Colors::Red, false);

					break;
				}

				case 5:
				{
					if (Config::bAimbot)
						DrawStringCentered("Aimbot", nextX, nextY + (1 * 20), Colors::Green, false);
					else
						DrawStringCentered("Aimbot", nextX, nextY + (1 * 20), Colors::Red, false);

					if (Config::bEsp)
						DrawStringCentered("ESP", nextX, nextY + (2 * 20), Colors::Green, false);
					else
						DrawStringCentered("ESP", nextX, nextY + (2 * 20), Colors::Red, false);

					if (Config::bNoRecoil)
						DrawStringCentered("No Recoil", nextX, nextY + (3 * 20), Colors::Green, false);
					else
						DrawStringCentered("No Recoil", nextX, nextY + (3 * 20), Colors::Red, false);

					if (Config::bNoSpread)
						DrawStringCentered("No Spread", nextX, nextY + (4 * 20), Colors::Green, false);
					else
						DrawStringCentered("No Spread", nextX, nextY + (4 * 20), Colors::Red, false);

					if (Config::bShrootTHroughWalls)
						DrawStringCentered("Shoot Through Walls", nextX, nextY + (5 * 20), Colors::Green, false);
					else
						DrawStringCentered("Shoot Through Walls", nextX, nextY + (5 * 20), Colors::Red, false);

					DrawStringCentered("Max Shot", nextX, nextY + (6 * 20), Colors::Yellow, false);

					break;
				}
			}
		}
	}
};