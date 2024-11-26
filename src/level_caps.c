#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "level_caps.h"
#include "pokemon.h"


u32 GetCurrentLevelCap(void)
{
    static const u32 sLevelCapFlagMap[][2] =
    {
        {FLAG_WOODS_GRUNT, 12},
        {FLAG_RUSTURF_GRUNT, 19},
        {FLAG_RIVAL_MAUVILLE, 24},
        {FLAG_SLATEPORT_GRUNTS, 27},
        {FLAG_BADGE05_GET, 30},
        {FLAG_RIVAL_110, 35},
        {FLAG_BADGE03_GET, 37},
        {FLAG_FALLARBOR_BOSS, 40},
        {FLAG_CHIMNEY_MAXIE, 43},
        {FLAG_BADGE04_GET, 47},
        {FLAG_GIOVANNI_FALLS, 50},
        {FLAG_BADGE01_GET, 52},
        {FLAG_BADGE02_GET, 55},
        {FLAG_118_GRUNTS,58},
        {FLAG_SHELLY_WINSTITUTE, 60},
        {FLAG_RIVAL_BRIDGE, 61},
        {FLAG_BADGE06_GET, 63},
        {FLAG_RIVAL_LILYCOVE, 66},
        {FLAG_ARCHIE_PYRE, 69},
        {FLAG_HIDEOUT_MAXIE, 74},
        {FLAG_HIDEOUT_MATT, 77},
        {FLAG_BADGE07_GET, 80},
        {FLAG_ROCKET_TAG, 82},
        {FLAG_CAVERN_ARCHIE, 84},
        {FLAG_HIDEOUT_GIOVANNI, 87},
        {FLAG_BADGE08_GET, 89},
        {FLAG_CYRUS_FALLS, 91},
        {FLAG_CYNTHIA_VR, 96},
        {FLAG_IS_CHAMPION, 100},
    };

    u32 i;

    if (B_LEVEL_CAP_TYPE == LEVEL_CAP_FLAG_LIST)
    {
        for (i = 0; i < ARRAY_COUNT(sLevelCapFlagMap); i++)
        {
            if (!FlagGet(sLevelCapFlagMap[i][0]))
                return sLevelCapFlagMap[i][1];
        }
    }
    else if (B_LEVEL_CAP_TYPE == LEVEL_CAP_VARIABLE)
    {
        return VarGet(B_LEVEL_CAP_VARIABLE);
    }

    return MAX_LEVEL;
}

u32 GetSoftLevelCapExpValue(u32 level, u32 expValue)
{
    static const u32 sExpScalingDown[5] = { 4, 8, 16, 32, 64 };
    static const u32 sExpScalingUp[5]   = { 16, 8, 4, 2, 1 };

    u32 levelDifference;
    u32 currentLevelCap = GetCurrentLevelCap();

    if (B_EXP_CAP_TYPE == EXP_CAP_NONE)
        return expValue;

    if (level < currentLevelCap)
    {
        if (B_LEVEL_CAP_EXP_UP)
        {
            levelDifference = currentLevelCap - level;
            if (levelDifference > ARRAY_COUNT(sExpScalingUp))
                return expValue + (expValue / sExpScalingUp[ARRAY_COUNT(sExpScalingUp) - 1]);
            else
                return expValue + (expValue / sExpScalingUp[levelDifference]);
        }
        else
        {
            return expValue;
        }
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_HARD)
    {
        return 0;
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_SOFT)
    {
        levelDifference = level - currentLevelCap;
        if (levelDifference > ARRAY_COUNT(sExpScalingDown))
            return expValue / sExpScalingDown[ARRAY_COUNT(sExpScalingDown) - 1];
        else
            return expValue / sExpScalingDown[levelDifference];
    }
    else
    {
       return expValue;
    }
}
