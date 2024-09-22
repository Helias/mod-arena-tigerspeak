#ifndef __BATTLEGROUNDTTP_H
#define __BATTLEGROUNDTTP_H

#include "Battleground.h"

class Battleground;

const uint32 BATTLEGROUND_TTP_ZONEID = 1134;

enum BattlegroundTTPObjectTypes
{
    BG_TTP_OBJECT_DOOR_1         = 0,
    BG_TTP_OBJECT_DOOR_2         = 1,
    BG_TTP_OBJECT_BUFF_1         = 2,
    BG_TTP_OBJECT_BUFF_2         = 3,
    BG_TTP_OBJECT_MAX            = 4
};

enum BattlegroundTTPObjects
{
    BG_TTP_OBJECT_TYPE_DOOR_1    = 212921,
    BG_TTP_OBJECT_TYPE_DOOR_2    = 212921,
    BG_TTP_OBJECT_TYPE_BUFF_1    = 184663,
    BG_TTP_OBJECT_TYPE_BUFF_2    = 184664
};

class BattlegroundTTP : public Battleground
{
public:
    BattlegroundTTP();
    ~BattlegroundTTP();

    /* inherited from BattlegroundClass */
    void AddPlayer(Player* player);
    void StartingEventCloseDoors();
    void StartingEventOpenDoors();

    void RemovePlayer(Player* player);
    void HandleAreaTrigger(Player* player, uint32 trigger);
    bool SetupBattleground();
    void Init();
    void FillInitialWorldStates(WorldPacket &d);
    void HandleKillPlayer(Player* player, Player* killer);
    bool HandlePlayerUnderMap(Player* player);

    uint32 GetZoneId() const { return BATTLEGROUND_TTP_ZONEID; }

};
#endif
