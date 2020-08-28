//Copyright 2020 Kix
#pragma once

#include <Windows.h>
#include <stdint.h>
#include <string>
#include <vector>
#include "Math.hpp"

enum class WeaponType : int32_t
{
	RIFLE_WEAPON = 0,
	SMG_WEAPON = 1,
	SHOTGUN_WEAPON = 2
};

enum class ToolType : int32_t
{
	ToolSpade = 0,
	ToolBlock = 1,
	ToolWeapon = 2,
	ToolGrenade = 3
};

enum NetClientStatus
{
	NetClientStatusNotConnected = 0,
	NetClientStatusConnecting,
	NetClientStatusReceivingMap,
	NetClientStatusConnected
};

class Player
{
public:
	class World* WorldPtr; //0x0000
	Vector3 Position; //0x0004
	Vector3 Velocity; //0x0010
	Vector3 Orientation; //0x001C
	Vector3 Eye; //0x0028
	char pad_0034[2]; //0x0034
	bool Airborne; //0x0036
	bool Wade; //0x0037
	ToolType ToolType; //0x0038
	WeaponType WeaponType; //0x003C
	class Weapon* WeaponPtr; //0x0040
	int32_t PlayerId; //0x0044
	int32_t TeamId; //0x0048
	char pad_004C[12]; //0x004C
	int32_t Health; //0x0058
	int32_t Grenades; //0x005C
	int32_t Blocks; //0x0060
	IntVector3 BlockColor; //0x0064
	float MoveDistance; //0x0070
	int32_t MoveSteps; //0x0074
	bool LastJump; //0x0078
	char pad_0079[7]; //0x0079
	float NextJumpTime; //0x0080
	float NextSpadeTime; //0x0084
	char pad_0088[8]; //0x0088
	float NextGrenadeTime; //0x0090
	float NextBlockTime; //0x0094
	bool HoldingGrenade; //0x0098
	char pad_0099[3]; //0x0099
	float GrenadeTime; //0x009C
	bool BlockCursorActive; //0x00A0
	bool BlockCursorDragging; //0x00A1
	char pad_00A2[2]; //0x00A2
	IntVector3 BlockCursorPos; //0x00A4
	IntVector3 BlockCursorDragPos; //0x00B0
	bool LastSingleBlockBuilSeqDone; //0x00BC
	char pad_00BD[3]; //0x00BD
	float LastReloadTime; //0x00C0
	bool PendingPlaceBLock; //0x00C4
	bool PendingRestockBlock; //0x00C5
	char pad_00C6[2]; //0x00C6
	IntVector3 PendingPlaceBlockPos; //0x00C8
	bool ReloadingServerSide; //0x00D4
	char pad_00D5[3]; //0x00D5
	float RespawnTime; //0x00D8
}; //Size: 0x00DC

class Team
{
public:
	IntVector3 Color; //0x0000
	std::string Name; //0x000C
}; //Size: 0x0024

class World
{
public:
	char pad_0000[16]; //0x0000
	float Time; //0x0010
	IntVector3 FogColor; //0x0014
	class Team Teams[3]; //0x0020
	char pad_008C[8]; //0x008C
	class EntityList* EntityListPtr; //0x0094
	char pad_0098[8]; //0x0098
	class PlayerPersistentList* PlayerPersistentsPtr; //0x00A0
	char pad_00A4[8]; //0x00A4
	int32_t LocalPlayerIndex; //0x00AC
}; //Size: 0x023C

class EntityList
{
public:
	class Player* Players[32]; //0x0000
}; //Size: 0x0080

class Weapon
{
public:
	char pad_0000[4]; //0x0000
	class World* WorldPtr; //0x0004
	class Player* OwnerPtr; //0x0008
	float Time; //0x000C
	bool Shooting; //0x0010
	bool ShootingPreviously; //0x0011
	bool Reloading; //0x0012
	char pad_0013[1]; //0x0013
	float NextShotTime; //0x0014
	float ReloadStartTime; //0x0018
	float ReloadEndTime; //0x001C
	int32_t SlowReloadLeftCount; //0x0020
	bool LastDryFire; //0x0024
	char pad_0025[3]; //0x0025
	int32_t Ammo; //0x0028
	int32_t Stock; //0x002C
}; //Size: 0x0044

class PlayerPersistent
{
public:
	std::string Name; //0x0000
	int32_t Kills; //0x0018
}; //Size: 0x001C

class PlayerPersistentList
{
public:
	class PlayerPersistent PlayerPersistents[32]; //0x0000
}; //Size: 0x0380

class SceneDefinition
{
public:
	int32_t ViewportLeft; //0x0000
	int32_t ViewportTop; //0x0004
	int32_t ViewportWidth; //0x0008
	int32_t ViewportHeight; //0x000C
	float FovX; //0x0010
	float FovY; //0x0014
	Vector3 ViewOrigin; //0x0018
	Vector3 ViewAxis[3]; //0x0024
	float zNear; //0x0048
	float zFar; //0x004C
	bool SkipWorld; //0x0050
	char pad_0051[3]; //0x0051
	float DepthOfFieldFocalLength; //0x0054
	float DepthOfFieldNearBlurStrength; //0x0058
	float DepthOfFieldFarBlurStrength; //0x005C
	uint32_t Time; //0x0060
	bool DenyCameraBlur; //0x0064
	char pad_0065[3]; //0x0065
	float BlurVignette; //0x0068
	float GlobalBlur; //0x006C
	float Saturation; //0x0070
	float RadialBlur; //0x0074
	char pad_0078[28]; //0x0078

}; //Size: 0x0094

class Client
{
public:
	char pad_0000[148]; //0x0000
	float Time; //0x0094
	char pad_0098[12]; //0x0098
	float TimeSinceInit; //0x00A4
	char pad_00A8[136]; //0x00A8
	class SceneDefinition LastSceneDef; //0x0130
	char pad_01C4[124]; //0x01C4
	bool ScoreboardVisible; //0x0240
	bool FlashlightOn; //0x0241
	char pad_0242[202]; //0x0242

}; //Size: 0x030C

class NetClient
{
public:
	Client* client;
	NetClientStatus status;
};

namespace Offsets
{
	inline uintptr_t base = 0;
	inline World* world = 0;
	inline EntityList* entityList = 0;
	inline Player* localPlayer = 0;
	inline SceneDefinition sceneDef = {};
	inline std::vector<Vector4> draws = {};
}