//Copyright 2020 Kix

#include <Windows.h>
#include <iostream>
#include "Overlay.h"
#include "Config.hpp"
#include "Hook.hpp"
#include "Misc.hpp"
#include "Aimbot.hpp"

typedef void(__fastcall* tDoEvents)(void* ecx, void* edx, int timeout);
tDoEvents oDoEvents;

typedef Player* (__fastcall* tGetLocalPlayerOrNull)(void* ecx, void* edx);
tGetLocalPlayerOrNull oGetLocalPlayerOrNull;

typedef Player* (__fastcall* tGetPlayerOrNull)(void* ecx, void* edx, int idx);
tGetPlayerOrNull oGetPlayerOrNull;

uintptr_t doEventsAddr = 0x3878;
uintptr_t getLocalPlayerOrNullAddr = 0x3B7A;
uintptr_t getPlayeOrNullAddr = 0xB573;

void __fastcall hkDoEvents(void* ecx, void* edx, int timeout)
{
    NetClient* pNetClient = (NetClient*)ecx;
    Player* aimTarget = nullptr;
    float oDist = FLT_MAX;
    float nDist = 0;
    Vector2 screenRes = Vector2((float)(Width / 2), (float)(Height / 2));

    if (pNetClient->status == NetClientStatusConnected)
    {
        oGetLocalPlayerOrNull = (tGetLocalPlayerOrNull)(Offsets::base + getLocalPlayerOrNullAddr);
        oGetPlayerOrNull = (tGetPlayerOrNull)(Offsets::base + getPlayeOrNullAddr);

        Offsets::localPlayer = oGetLocalPlayerOrNull(ecx, edx);

        if (Offsets::localPlayer)
        {
            if (pNetClient->client)
            {
                Offsets::sceneDef = pNetClient->client->LastSceneDef;
                Offsets::draws.clear();

                for (int i = 0; i < 32; i++)
                {
                    Player* cur = oGetPlayerOrNull(ecx, edx, i);

                    if (cur)
                    {
                        if (cur->TeamId == Offsets::localPlayer->TeamId || cur->TeamId > 2) continue;

                        if (!(cur->Health > 0) && !(cur->Health <= 100)) continue;

                        if (cur->PlayerId == Offsets::localPlayer->PlayerId) continue;

                        //Aimbot
                        if (Config::bAimbot && GetAsyncKeyState(VK_RBUTTON))
                        {
                            Vector3 headPos = cur->Eye;

                            Vector2 screenHead;

                            if (Helpers::World2Screen(headPos, screenHead, Offsets::sceneDef))
                            {
                                nDist = DistanceVector2(screenHead, screenRes);

                                if (nDist < oDist)
                                {
                                    oDist = nDist;
                                    aimTarget = cur;
                                }
                            }
                        }

                        //Esp
                        Vector3 feetPos = cur->Position;
                        feetPos.z += 2.5; //Check

                        Vector2 screenFeet;

                        if (Helpers::World2Screen(feetPos, screenFeet, Offsets::sceneDef))
                        {
                            Vector3 headPos = cur->Eye;
                            headPos.z -= 1;

                            Vector2 screenHead;

                            if (Helpers::World2Screen(headPos, screenHead, Offsets::sceneDef))
                            {
                                //Aimbot Get Closest Entity to Crosshair

                                Vector4 draw;

                                double temp1 = pow((screenHead.x - screenFeet.x), 2);
                                double temp2 = pow((screenHead.y - screenFeet.y), 2);
                                double height = sqrt(temp1 + temp2);
                                double width = height / 2;

                                draw.x = screenFeet.x;
                                draw.y = screenFeet.y;
                                draw.z = (float)width;
                                draw.w = (float)height;

                                Offsets::draws.push_back(draw);
                            }
                        }
                    }
                }

                if (aimTarget)
                {
                    Aimbot(aimTarget->Position);
                }
            }
        }
    }

    oDoEvents(ecx, edx, timeout);
}

DWORD WINAPI MainThread(LPVOID hModule)
{
    Offsets::base = Helpers::GetBase();

    RegisterDLLWindowClass((HINSTANCE)hModule);
    TargetWnd = FindWindow(NULL, "OpenSpades 0.1.3 MSVC 19.12.25831.0");
    hWnd = CreateWindowEx(WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_COMPOSITED | WS_EX_TRANSPARENT, "Yeet", "Yeet", WS_EX_TOPMOST | WS_POPUP, 100, 100, 1024, 786, NULL, NULL, NULL, (HINSTANCE)hModule);
    SetLayeredWindowAttributes(hWnd, RGB(0, 0, 0), 0, ULW_COLORKEY);
    SetLayeredWindowAttributes(hWnd, 0, 255, LWA_ALPHA);
    ShowWindow(hWnd, SW_SHOW);
    DirectXInit(hWnd);

    Hook DoEventsHk((BYTE*)(((Offsets::base + doEventsAddr + 0x5) + *(uintptr_t*)(Offsets::base + doEventsAddr + 1))), (BYTE*)hkDoEvents, (BYTE*)&oDoEvents, 5);

    DoEventsHk.Enable();
    printf("Hack Loaded Successfully!\nMade by Kix\n");
    MessageBeep(MB_OK);

    for (;;)
    {
        if (GetAsyncKeyState(VK_END) & 1)
            break;

        if (PeekMessage(&Message, hWnd, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&Message);
            DispatchMessage(&Message);
        }

        TargetWnd = FindWindow(NULL, "OpenSpades 0.1.3 MSVC 19.12.25831.0");
        GetWindowRect(TargetWnd, &TargetRect);
        MoveWindow(hWnd, TargetRect.left, TargetRect.top, TargetRect.right - TargetRect.left, TargetRect.bottom - TargetRect.top, true);

        if (!TargetWnd)
        {
            break;
        }

        //InfAmmo(true); //After you shoot the normal amount of bullets, the bullets wont register
        NoRecoil(Config::bNoRecoil);
        NoSpread(Config::bNoSpread);
        //FullAuto(true); //Causes crash on map change and can't be held down or else kick
        ShootThroughWalls(Config::bShrootTHroughWalls);
        MaxShot(Config::bMaxShot);
        Render();
        Sleep(1);
    }

    printf("Hack Unloading!\nSee you later...\n");

    //DirectXShutdown();

    DoEventsHk.Disable();

    MessageBeep(MB_OK);
    Sleep(100);


    FreeLibraryAndExitThread((HMODULE)hModule, 0);
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        CreateThread(NULL, 0, MainThread, hModule, NULL, NULL);
        DisableThreadLibraryCalls(hModule);
    }

    return TRUE;
}

