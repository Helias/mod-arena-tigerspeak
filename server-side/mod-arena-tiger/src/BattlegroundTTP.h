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

class AC_GAME_API BattlegroundTTP : public Arena
{
public:
    BattlegroundTTP();
    ~BattlegroundTTP();

    /* inherited from BattlegroundClass */
    void StartingEventCloseDoors() override;
    void StartingEventOpenDoors() override;

    void HandleAreaTrigger(Player* player, uint32 trigger) override;
    bool SetupBattleground() override;
    void FillInitialWorldStates(WorldPacket &d) override;
    bool HandlePlayerUnderMap(Player* player) override;

    uint32 GetZoneId() const { return BATTLEGROUND_TTP_ZONEID; }

};
#endif
