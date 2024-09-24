/*
 * Copyright (C) 2011-2020 Project SkyFire <http://www.projectskyfire.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Battleground.h"
#include "Arena.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "Transport.h"
#include "ScriptedCreature.h"
#include "GameGraveyard.h"

#include "BattlegroundTTP.h"
#include "BattlegroundMgr.h"
#include "Player.h"
#include "WorldPacket.h"
#include "Language.h"
#include <unordered_map>

#include "ScriptMgr.h"
#include "Config.h"

// adding Battleground to the core battlegrounds list
BattlegroundTypeId BATTLEGROUND_TTP = BattlegroundTypeId(871); // value from BattlemasterList.dbc
BattlegroundQueueTypeId BATTLEGROUND_QUEUE_TTP = BattlegroundQueueTypeId(0);

BattlegroundTTP::BattlegroundTTP()
{
    BgObjects.resize(BG_TTP_OBJECT_MAX);
}

BattlegroundTTP::~BattlegroundTTP() { }

void BattlegroundTTP::StartingEventCloseDoors()
{
    for (uint32 i = BG_TTP_OBJECT_DOOR_1; i <= BG_TTP_OBJECT_DOOR_2; ++i)
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);
}

void BattlegroundTTP::StartingEventOpenDoors()
{
    for (uint32 i = BG_TTP_OBJECT_DOOR_1; i <= BG_TTP_OBJECT_DOOR_2; ++i)
        DoorOpen(i);

    for (uint32 i = BG_TTP_OBJECT_BUFF_1; i <= BG_TTP_OBJECT_BUFF_2; ++i)
        SpawnBGObject(i, 60);
}

// void BattlegroundTTP::HandleKillPlayer(Player* player, Player* killer)
// {
//     if (GetStatus() != STATUS_IN_PROGRESS)
//         return;

//     if (!killer)
//     {
//         sLog->outError("BattlegroundTTP: Killer player not found");
//         return;
//     }

//     Battleground::HandleKillPlayer(player, killer);

//     Battleground::UpdateArenaWorldState();
//     CheckArenaWinConditions();
// }

bool BattlegroundTTP::HandlePlayerUnderMap(Player* player)
{
    player->TeleportTo(GetMapId(), 567.313843f, 632.106384f, 380.703339f, player->GetOrientation(), false);
    return true;
}

void BattlegroundTTP::HandleAreaTrigger(Player* /* player */, uint32 trigger)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    switch (trigger)
    {
        case 4536:                                          // buff trigger?
        case 4537:                                          // buff trigger?
            break;
        default:
            break;
    }
}

void BattlegroundTTP::FillInitialWorldStates(WorldPacket &data)
{
    data << uint32(0xE1A) << uint32(1);
    Arena::FillInitialWorldStates(data);
}

bool BattlegroundTTP::SetupBattleground()
{
    // Gates
    if (!AddObject(BG_TTP_OBJECT_DOOR_1, BG_TTP_OBJECT_TYPE_DOOR_1, 502.414f, 633.099f, 380.706f, 0.0308292f, 0.0f, 0.0f, 0.015414f, 0.999881f, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_TTP_OBJECT_DOOR_2, BG_TTP_OBJECT_TYPE_DOOR_2, 632.891f, 633.059f, 380.705f, 3.12778f, 0.0f, 0.0f, 0.999976f, 0.0069045f, RESPAWN_IMMEDIATELY)
    // Buffs
        || !AddObject(BG_TTP_OBJECT_BUFF_1, BG_TTP_OBJECT_TYPE_BUFF_1, 566.788f, 602.743f, 383.68f, 1.5724f, 0.0f, 0.0f, 0.707673f, 0.70654f, 120)
        || !AddObject(BG_TTP_OBJECT_BUFF_2, BG_TTP_OBJECT_TYPE_BUFF_2, 566.661f, 664.311f, 383.681f, 4.66374f, 0.0f, 0.0f, 0.724097f, -0.689698f, 120))
    {
        LOG_ERROR("sql.sql", "BattlegroundTTP: Failed to spawn some object!");
        return false;
    }

    return true;
}

class TigerPeakWorld : public WorldScript
{
	public:
    	TigerPeakWorld() : WorldScript("TigerPeakWorld") { }
};

void AddTigerPeakScripts() {
	new TigerPeakWorld();

	// Add Tol Viron to battleground list
	BattlegroundMgr::bgToQueue[BATTLEGROUND_TTP] = BATTLEGROUND_QUEUE_TTP;
	BattlegroundMgr::bgtypeToBattleground[BATTLEGROUND_TTP] = new BattlegroundTTP;

	BattlegroundMgr::bgTypeToTemplate[BATTLEGROUND_TTP] = [](Battleground *bg_t) -> Battleground * { return new BattlegroundTTP(*(BattlegroundTTP *)bg_t); };

	Player::bgZoneIdToFillWorldStates[6732] = [](Battleground* bg, WorldPacket& data) {
    if (bg && bg->GetBgTypeID(true) == BATTLEGROUND_TTP)
        bg->FillInitialWorldStates(data);
    else
    {
        data << uint32(0xa0f) << uint32(0x0);           // 7
        data << uint32(0xa10) << uint32(0x0);           // 8
        data << uint32(0xa11) << uint32(0x0);           // 9 show
    }
	};
}
