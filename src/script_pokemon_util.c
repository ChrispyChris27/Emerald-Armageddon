#include "global.h"
#include "battle.h"
#include "battle_gfx_sfx_util.h"
#include "berry.h"
#include "caps.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "event_data.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "ow_synchronize.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "script.h"
#include "sprite.h"
#include "string_util.h"
#include "tv.h"
#include "wild_encounter.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/battle_frontier.h"

static void CB2_ReturnFromChooseHalfParty(void);
static void CB2_ReturnFromChooseBattleFrontierParty(void);
static void HealPlayerBoxes(void);

void HealPlayerParty(void)
{
    u32 i;
    for (i = 0; i < gPlayerPartyCount; i++)
        HealPokemon(&gPlayerParty[i]);
    if (OW_PC_HEAL >= GEN_8)
        HealPlayerBoxes();

    // Recharge Tera Orb, if possible.
    if (B_FLAG_TERA_ORB_CHARGED != 0 && CheckBagHasItem(ITEM_TERA_ORB, 1))
        FlagSet(B_FLAG_TERA_ORB_CHARGED);
}

static void HealPlayerBoxes(void)
{
    int boxId, boxPosition;
    struct BoxPokemon *boxMon;

    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        for (boxPosition = 0; boxPosition < IN_BOX_COUNT; boxPosition++)
        {
            boxMon = &gPokemonStoragePtr->boxes[boxId][boxPosition];
            if (GetBoxMonData(boxMon, MON_DATA_SANITY_HAS_SPECIES))
                HealBoxPokemon(boxMon);
        }
    }
}

u8 ScriptGiveEgg(u16 species)
{
    struct Pokemon mon;
    u8 isEgg;

    CreateEgg(&mon, species, TRUE);
    isEgg = TRUE;
    SetMonData(&mon, MON_DATA_IS_EGG, &isEgg);

    return GiveCapturedMonToPlayer(&mon);
}

void HasEnoughMonsForDoubleBattle(void)
{
    switch (GetMonsStateToDoubles())
    {
    case PLAYER_HAS_TWO_USABLE_MONS:
        gSpecialVar_Result = PLAYER_HAS_TWO_USABLE_MONS;
        break;
    case PLAYER_HAS_ONE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_MON;
        break;
    case PLAYER_HAS_ONE_USABLE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_USABLE_MON;
        break;
    }
}

static bool32 CheckPartyMonHasHeldItem(enum Item item)
{
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);
        if (species != SPECIES_NONE && species != SPECIES_EGG && GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) == item)
            return TRUE;
    }
    return FALSE;
}

bool8 DoesPartyHaveEnigmaBerry(void)
{
    bool8 hasItem = CheckPartyMonHasHeldItem(ITEM_ENIGMA_BERRY_E_READER);
    if (hasItem == TRUE)
        GetBerryNameByBerryType(ItemIdToBerryType(ITEM_ENIGMA_BERRY_E_READER), gStringVar1);

    return hasItem;
}

void CreateScriptedWildMon(u16 species, u8 level, enum Item item)
{
    u8 heldItem[2];
    bool8 gmaxFactor = TRUE;
    enum Type teraType;

    ZeroEnemyPartyMons();
    u32 personality = GetMonPersonality(species,
        GetSynchronizedGender(STATIC_WILDMON_ORIGIN, species),
        GetSynchronizedNature(STATIC_WILDMON_ORIGIN, species),
        RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(&gEnemyParty[0], species, level, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gEnemyParty[0]);
    if (item)
    {
        heldItem[0] = item;
        heldItem[1] = item >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem);
    }

    if (species == SPECIES_CENTISKORCH || species == SPECIES_SANDACONDA || species == SPECIES_DURALUDON || species == SPECIES_ORBEETLE)
        SetMonData(&gEnemyParty[0], MON_DATA_GIGANTAMAX_FACTOR, &gmaxFactor);

    if (species == SPECIES_CRYOGONAL || species == SPECIES_SHEDINJA)
    {
        teraType = TYPE_ELECTRIC;
        SetMonData(&gEnemyParty[0], MON_DATA_TERA_TYPE, &teraType);
    }

    if (gBattleTypeFlags == BATTLE_TYPE_ROGUE || gBattleTypeFlags == BATTLE_TYPE_ROGUE_GMAX || gBattleTypeFlags == BATTLE_TYPE_ROGUE_TERA)
    {
        u8 ivs = 31;

        SetMonData(&gEnemyParty[0], MON_DATA_ATK_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_DEF_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_SPATK_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_SPDEF_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_SPEED_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_HP_IV, &ivs);
    }

    if(species == SPECIES_CENTISKORCH)
    {
        u16 move1 = MOVE_FIRE_LASH;
        u16 move2 = MOVE_LEECH_LIFE;
        u16 move3 = MOVE_POWER_WHIP;
        u16 move4 = MOVE_THUNDER_FANG;
        u8 nature = NATURE_JOLLY;
        u8 ability = 0;

        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &ability);
    }

    if(species == SPECIES_CRYOGONAL)
    {
        u16 move1 = MOVE_BLIZZARD;
        u16 move2 = MOVE_TERA_BLAST;
        u16 move3 = MOVE_EARTH_POWER;
        u16 move4 = MOVE_RECOVER;
        u8 nature = NATURE_MODEST;
        u8 ability = 0;

        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &ability);
    }

    if(species == SPECIES_SHEDINJA)
    {
        u16 move1 = MOVE_SPIRIT_SHACKLE;
        u16 move2 = MOVE_ATTACK_ORDER;
        u16 move3 = MOVE_TERA_BLAST;
        u16 move4 = MOVE_MAGIC_COAT;
        u8 nature = NATURE_JOLLY;

        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
    }

    if(species == SPECIES_SIGILYPH)
    {
        u16 move1 = MOVE_STORED_POWER;
        u16 move2 = MOVE_DAZZLING_GLEAM;
        u16 move3 = MOVE_COSMIC_POWER;
        u16 move4 = MOVE_ROOST;
        u8 nature = NATURE_TIMID;
        u8 ability = 1;

        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &ability);
    }

    if(species == SPECIES_ABSOL_MEGA)
    {
        u16 move1 = MOVE_NIGHT_SLASH;
        u16 move2 = MOVE_PLAY_ROUGH;
        u16 move3 = MOVE_SHADOW_CLAW;
        u16 move4 = MOVE_ROCK_SLIDE;
        u8 nature = NATURE_JOLLY;

        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
    }

    if(species == SPECIES_SABLEYE)
    {
        u16 move1 = MOVE_KNOCK_OFF;
        u16 move2 = MOVE_SHADOW_SNEAK;
        u16 move3 = MOVE_WILL_O_WISP;
        u16 move4 = MOVE_POISON_JAB;
        u8 nature = NATURE_JOLLY;
        u8 ability = 1;

        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &ability);
    }

    if(species == SPECIES_SANDACONDA)
    {
        u16 move1 = MOVE_EARTHQUAKE;
        u16 move2 = MOVE_STONE_EDGE;
        u16 move3 = MOVE_BODY_PRESS;
        u16 move4 = MOVE_IRON_HEAD;
        u8 nature = NATURE_JOLLY;
        u8 ability = 0;

        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &ability);
    }

    if(species == SPECIES_MAGNEZONE)
    {
        u16 move1 = MOVE_THUNDERBOLT;
        u16 move2 = MOVE_FLASH_CANNON;
        u16 move3 = MOVE_TERA_BLAST;
        u16 move4 = MOVE_BODY_PRESS;
        u8 nature = NATURE_MODEST;
        u8 ability = 2;
        teraType = TYPE_DRAGON;

        SetMonData(&gEnemyParty[0], MON_DATA_TERA_TYPE, &teraType);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &ability);
    }

    if(species == SPECIES_KILOWATTREL)
    {
        u16 move1 = MOVE_RISING_VOLTAGE;
        u16 move2 = MOVE_HURRICANE;
        u16 move3 = MOVE_WEATHER_BALL;
        u16 move4 = MOVE_ROOST;
        u8 nature = NATURE_MODEST;
        u8 ability = 2;
        teraType = TYPE_WATER;

        SetMonData(&gEnemyParty[0], MON_DATA_TERA_TYPE, &teraType);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &ability);
    }

    if(species == SPECIES_ROARING_MOON)
    {
        u16 move1 = MOVE_DRAGON_RUSH;
        u16 move2 = MOVE_THROAT_CHOP;
        u16 move3 = MOVE_TERA_BLAST;
        u16 move4 = MOVE_ROOST;
        u8 nature = NATURE_ADAMANT;
        teraType = TYPE_STEEL;

        SetMonData(&gEnemyParty[0], MON_DATA_TERA_TYPE, &teraType);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
    }

    if(species == SPECIES_CHARIZARD_MEGA_Y)
    {
        u16 move1 = MOVE_HURRICANE;
        u16 move2 = MOVE_WEATHER_BALL;
        u16 move3 = MOVE_SOLARBEAM;
        u16 move4 = MOVE_EARTH_POWER;
        u8 nature = NATURE_MODEST;

        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
    }

    if(species == SPECIES_DURALUDON)
    {
        u16 move1 = MOVE_DRACO_METEOR;
        u16 move2 = MOVE_STEEL_BEAM;
        u16 move3 = MOVE_EARTH_POWER;
        u16 move4 = MOVE_WEATHER_BALL;
        u8 nature = NATURE_MODEST;
        u8 ability = 2;

        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &ability);
    }

    if(species == SPECIES_IRON_JUGULIS)
    {
        u16 move1 = MOVE_DRAGON_PULSE;
        u16 move2 = MOVE_DARK_PULSE;
        u16 move3 = MOVE_TERA_BLAST;
        u16 move4 = MOVE_EARTH_POWER;
        u8 nature = NATURE_MODEST;
        teraType = TYPE_STEEL;

        SetMonData(&gEnemyParty[0], MON_DATA_TERA_TYPE, &teraType);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
    }

    if(species == SPECIES_AERODACTYL_MEGA)
    {
        u16 move1 = MOVE_BRAVE_BIRD;
        u16 move2 = MOVE_HEAD_SMASH;
        u16 move3 = MOVE_EARTHQUAKE;
        u16 move4 = MOVE_ROOST;
        u8 nature = NATURE_ADAMANT;

        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
    }

    if(species == SPECIES_NECROZMA_ULTRA)
    {
        u16 move1 = MOVE_PHOTON_GEYSER;
        u16 move2 = MOVE_DRAGON_PULSE;
        u16 move3 = MOVE_HEAT_WAVE;
        u16 move4 = MOVE_MOONLIGHT;
        u8 nature = NATURE_MODEST;

        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
    }

    if(species == SPECIES_MAGIKARP)
    {
        u16 move1 = MOVE_HYDRO_PUMP;
        u16 move2 = MOVE_BOUNCE;
        u16 move3 = MOVE_FLAIL;
        u16 move4 = MOVE_FACADE;
        u8 nature = NATURE_HASTY;
        bool32 shiny = TRUE;

        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[0], MON_DATA_IS_SHINY, &shiny);

    }

    if(species == SPECIES_ORBEETLE)
    {
        u16 move1 = MOVE_HURRICANE;
        u16 move2 = MOVE_BUG_BUZZ;
        u16 move3 = MOVE_PSYCHIC;
        u16 move4 = MOVE_SLUDGE_BOMB;
        u8 nature = NATURE_MODEST;
        u8 ability = 1;

        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &ability);
    }

}
void CreateScriptedDoubleWildMon(u16 species1, u8 level1, enum Item item1, u16 species2, u8 level2, enum Item item2)
{
    u8 heldItem1[2];
    u8 heldItem2[2];

    ZeroEnemyPartyMons();
    u32 personality = GetMonPersonality(species1,
        GetSynchronizedGender(STATIC_WILDMON_ORIGIN, species1),
        GetSynchronizedNature(STATIC_WILDMON_ORIGIN, species1),
        RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(&gEnemyParty[0], species1, level1, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gEnemyParty[0]);
    if (item1)
    {
        heldItem1[0] = item1;
        heldItem1[1] = item1 >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem1);
    }

    personality = GetMonPersonality(species2,
        GetSynchronizedGender(STATIC_WILDMON_ORIGIN, species2),
        GetSynchronizedNature(STATIC_WILDMON_ORIGIN, species2),
        RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(&gEnemyParty[1], species2, level2, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gEnemyParty[1]);
    if (item2)
    {
        heldItem2[0] = item2;
        heldItem2[1] = item2 >> 8;
        SetMonData(&gEnemyParty[1], MON_DATA_HELD_ITEM, heldItem2);
    }

    if(species1 == SPECIES_LUDICOLO)
    {
        u16 move1 = MOVE_WEATHER_BALL;
        u16 move2 = MOVE_ICE_BEAM;
        u16 move3 = MOVE_SOLARBEAM;
        u16 move4 = MOVE_FOCUS_BLAST;
        u8 nature = NATURE_MODEST;
        u8 ability = 0;
        u8 ivs = 31;

        SetMonData(&gEnemyParty[0], MON_DATA_ATK_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_DEF_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_SPATK_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_SPDEF_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_SPEED_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_HP_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &ability);
    }

    if(species2 == SPECIES_SHIFTRY)
    {
        u16 move1 = MOVE_WEATHER_BALL;
        u16 move2 = MOVE_DARK_PULSE;
        u16 move3 = MOVE_SOLARBEAM;
        u16 move4 = MOVE_HURRICANE;
        u8 nature = NATURE_MODEST;
        u8 ability = 0;
        u8 ivs = 31;

        SetMonData(&gEnemyParty[1], MON_DATA_ATK_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_DEF_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPATK_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPDEF_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPEED_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_HP_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[1], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[1], MON_DATA_ABILITY_NUM, &ability);
    }

    if(species1 == SPECIES_DHELMISE)
    {
        u16 move1 = MOVE_ANCHOR_SHOT;
        u16 move2 = MOVE_POWER_WHIP;
        u16 move3 = MOVE_SPIRIT_SHACKLE;
        u16 move4 = MOVE_LIQUIDATION;
        u8 nature = NATURE_ADAMANT;
        u8 ivs = 31;

        SetMonData(&gEnemyParty[0], MON_DATA_ATK_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_DEF_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_SPATK_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_SPDEF_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_SPEED_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_HP_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
    }

    if(species2 == SPECIES_RELICANTH)
    {
        u16 move1 = MOVE_HEAD_SMASH;
        u16 move2 = MOVE_WAVE_CRASH;
        u16 move3 = MOVE_ICE_SPINNER;
        u16 move4 = MOVE_BODY_PRESS;
        u8 nature = NATURE_JOLLY;
        u8 ability = 1;
        u8 ivs = 31;

        SetMonData(&gEnemyParty[1], MON_DATA_ATK_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_DEF_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPATK_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPDEF_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPEED_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_HP_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[1], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[1], MON_DATA_ABILITY_NUM, &ability);
    }

    if(species1 == SPECIES_TATSUGIRI_CURLY)
    {
        u16 move1 = MOVE_MUDDY_WATER;
        u16 move2 = MOVE_ICE_BEAM;
        u16 move3 = MOVE_DRAGON_PULSE;
        u16 move4 = MOVE_DARK_PULSE;
        u8 nature = NATURE_TIMID;
        u8 ivs = 31;

        SetMonData(&gEnemyParty[0], MON_DATA_ATK_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_DEF_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_SPATK_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_SPDEF_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_SPEED_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_HP_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
    }

    if(species2 == SPECIES_DONDOZO)
    {
        u16 move1 = MOVE_ORDER_UP;
        u16 move2 = MOVE_WAVE_CRASH;
        u16 move3 = MOVE_ICE_SPINNER;
        u16 move4 = MOVE_EARTHQUAKE;
        u8 nature = NATURE_JOLLY;
        u8 ability = 1;
        u8 ivs = 31;

        SetMonData(&gEnemyParty[1], MON_DATA_ATK_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_DEF_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPATK_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPDEF_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPEED_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_HP_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[1], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[1], MON_DATA_ABILITY_NUM, &ability);
    }

    if(species1 == SPECIES_MILOTIC)
    {
        u16 move1 = MOVE_MUDDY_WATER;
        u16 move2 = MOVE_ICE_BEAM;
        u16 move3 = MOVE_ALLURING_VOICE;
        u16 move4 = MOVE_HYDRO_PUMP;
        u8 nature = NATURE_TIMID;
        u8 ivs = 31;
        u8 ability = 1;

        SetMonData(&gEnemyParty[0], MON_DATA_ATK_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_DEF_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_SPATK_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_SPDEF_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_SPEED_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_HP_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[1], MON_DATA_ABILITY_NUM, &ability);
    }

    if(species2 == SPECIES_GYARADOS_MEGA)
    {
        u16 move1 = MOVE_DRAGON_DANCE;
        u16 move2 = MOVE_WAVE_CRASH;
        u16 move3 = MOVE_STONE_EDGE;
        u16 move4 = MOVE_CRUNCH;
        u8 nature = NATURE_JOLLY;
        u8 ivs = 31;

        SetMonData(&gEnemyParty[1], MON_DATA_ATK_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_DEF_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPATK_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPDEF_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPEED_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_HP_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[1], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[1], MON_DATA_HIDDEN_NATURE, &nature);
    }

    if(species1 == SPECIES_KABUTOPS)
    {
        u16 move1 = MOVE_STONE_EDGE;
        u16 move2 = MOVE_WAVE_CRASH;
        u16 move3 = MOVE_DRILL_RUN;
        u16 move4 = MOVE_LEECH_LIFE;
        u8 nature = NATURE_ADAMANT;
        u8 ability = 0;
        u8 ivs = 31;

        SetMonData(&gEnemyParty[1], MON_DATA_ATK_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_DEF_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPATK_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPDEF_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPEED_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_HP_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &ability);
    }

    if(species2 == SPECIES_OMASTAR)
    {
        u16 move1 = MOVE_POWER_GEM;
        u16 move2 = MOVE_HYDRO_PUMP;
        u16 move3 = MOVE_EARTH_POWER;
        u16 move4 = MOVE_ICE_BEAM;
        u8 nature = NATURE_MODEST;
        u8 ability = 0;
        u8 ivs = 31;

        SetMonData(&gEnemyParty[1], MON_DATA_ATK_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_DEF_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPATK_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPDEF_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_SPEED_IV, &ivs);
        SetMonData(&gEnemyParty[1], MON_DATA_HP_IV, &ivs);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE1, &move1);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE2, &move2);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE3, &move3);
        SetMonData(&gEnemyParty[0], MON_DATA_MOVE4, &move4);
        SetMonData(&gEnemyParty[0], MON_DATA_HIDDEN_NATURE, &nature);
        SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &ability);
    }
}

void ScriptSetMonMoveSlot(u8 monIndex, enum Move move, u8 slot)
{
// Allows monIndex to go out of bounds of gPlayerParty. Doesn't occur in vanilla
#ifdef BUGFIX
    if (monIndex >= PARTY_SIZE)
#else
    if (monIndex > PARTY_SIZE)
#endif
        monIndex = gPlayerPartyCount - 1;

    SetMonMoveSlot(&gPlayerParty[monIndex], move, slot);
}

// Note: When control returns to the event script, gSpecialVar_Result will be
// TRUE if the party selection was successful.
void ChooseHalfPartyForBattle(void)
{
    gMain.savedCallback = CB2_ReturnFromChooseHalfParty;
    VarSet(VAR_FRONTIER_FACILITY, FACILITY_MULTI_OR_EREADER);
    InitChooseHalfPartyForBattle(0);
}

static void CB2_ReturnFromChooseHalfParty(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = FALSE;
        break;
    default:
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ChoosePartyForBattleFrontier(void)
{
    gMain.savedCallback = CB2_ReturnFromChooseBattleFrontierParty;
    InitChooseHalfPartyForBattle(gSpecialVar_0x8004 + 1);
}

static void CB2_ReturnFromChooseBattleFrontierParty(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = FALSE;
        break;
    default:
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ReducePlayerPartyToSelectedMons(void)
{
    struct Pokemon party[MAX_FRONTIER_PARTY_SIZE];
    int i;

    CpuFill32(0, party, sizeof party);

    // copy the selected Pokémon according to the order.
    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        if (gSelectedOrderFromParty[i]) // as long as the order keeps going (did the player select 1 mon? 2? 3?), do not stop
            party[i] = gPlayerParty[gSelectedOrderFromParty[i] - 1]; // index is 0 based, not literal

    CpuFill32(0, gPlayerParty, sizeof gPlayerParty);

    // overwrite the first 4 with the order copied to.
    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        gPlayerParty[i] = party[i];

    CalculatePlayerPartyCount();
}

void CanHyperTrain(struct ScriptContext *ctx)
{
    u32 stat = ScriptReadByte(ctx);
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1);

    assertf(stat < NUM_STATS, "invalid stat: %d", stat)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    CalculatePlayerPartyCount();
    assertf(partyIndex < gPlayerPartyCount, "invalid party index: %d", partyIndex)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    if (!GetMonData(&gPlayerParty[partyIndex], MON_DATA_HYPER_TRAINED_HP + stat)
     && GetMonData(&gPlayerParty[partyIndex], MON_DATA_HP_IV + stat) < MAX_PER_STAT_IVS)
    {
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void HyperTrain(struct ScriptContext *ctx)
{
    u32 stat = ScriptReadByte(ctx);
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);

    assertf(stat < NUM_STATS, "invalid stat: %d", stat)
    {
        return;
    }

    CalculatePlayerPartyCount();
    assertf(partyIndex < gPlayerPartyCount, "invalid party index: %d", partyIndex)
    {
        return;
    }

    bool32 data = TRUE;
    SetMonData(&gPlayerParty[partyIndex], MON_DATA_HYPER_TRAINED_HP + stat, &data);
    CalculateMonStats(&gPlayerParty[partyIndex]);
}

void HasGigantamaxFactor(struct ScriptContext *ctx)
{
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1);

    if (partyIndex < PARTY_SIZE)
        gSpecialVar_Result = GetMonData(&gPlayerParty[partyIndex], MON_DATA_GIGANTAMAX_FACTOR);
    else
        gSpecialVar_Result = FALSE;
}

void ToggleGigantamaxFactor(struct ScriptContext *ctx)
{
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);

    gSpecialVar_Result = FALSE;

    if (partyIndex < PARTY_SIZE)
    {
        bool32 gigantamaxFactor;

        if (gSpeciesInfo[SanitizeSpeciesId(GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES))].isMythical)
            return;

        gigantamaxFactor = GetMonData(&gPlayerParty[partyIndex], MON_DATA_GIGANTAMAX_FACTOR);
        gigantamaxFactor = !gigantamaxFactor;
        SetMonData(&gPlayerParty[partyIndex], MON_DATA_GIGANTAMAX_FACTOR, &gigantamaxFactor);
        gSpecialVar_Result = TRUE;
    }
}

void CheckTeraType(struct ScriptContext *ctx)
{
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1);

    gSpecialVar_Result = TYPE_NONE;

    if (partyIndex < PARTY_SIZE)
        gSpecialVar_Result = GetMonData(&gPlayerParty[partyIndex], MON_DATA_TERA_TYPE);
}

void SetTeraType(struct ScriptContext *ctx)
{
    enum Type type = ScriptReadByte(ctx);
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);

    if (type < NUMBER_OF_MON_TYPES && partyIndex < PARTY_SIZE)
        SetMonData(&gPlayerParty[partyIndex], MON_DATA_TERA_TYPE, &type);
}

/* Creates a Pokemon via script
 * if side/slot are assigned, it will create the mon at the assigned party location
 * if slot == PARTY_SIZE, it will give the mon to first available party or storage slot
 */
static u32 ScriptGiveMonParameterized(u8 side, u8 slot, u16 species, u8 level, enum Item item, enum PokeBall ball, u8 nature, u8 abilityNum, u8 gender, u16 *evs, u16 *ivs, enum Move *moves, enum ShinyMode shinyMode, bool8 gmaxFactor, enum Type teraType, u8 dmaxLevel)
{
    struct Pokemon mon;
    u32 i;
    bool32 isShiny;

    u32 personality = GetMonPersonality(species, gender, nature, RANDOM_UNOWN_LETTER);
    CreateMon(&mon, species, level, personality, OTID_STRUCT_PLAYER_ID);

    // shininess
    if (shinyMode == SHINY_MODE_ALWAYS || (P_FLAG_FORCE_SHINY != 0 && FlagGet(P_FLAG_FORCE_SHINY)))
        isShiny = TRUE;
    else if (shinyMode == SHINY_MODE_NEVER || (P_FLAG_FORCE_NO_SHINY != 0 && FlagGet(P_FLAG_FORCE_NO_SHINY)))
        isShiny = FALSE;
    else
        isShiny = GetMonData(&mon, MON_DATA_IS_SHINY);

    SetMonData(&mon, MON_DATA_IS_SHINY, &isShiny);

    // gigantamax factor
    SetMonData(&mon, MON_DATA_GIGANTAMAX_FACTOR, &gmaxFactor);

    // Dynamax Level
    SetMonData(&mon, MON_DATA_DYNAMAX_LEVEL, &dmaxLevel);

    // tera type
    if (teraType == TYPE_NONE || teraType == TYPE_MYSTERY || teraType >= NUMBER_OF_MON_TYPES)
        teraType = GetTeraTypeFromPersonality(&mon);
    SetMonData(&mon, MON_DATA_TERA_TYPE, &teraType);

    // EV and IV
    for (i = 0; i < NUM_STATS; i++)
    {
        // EV
        if (evs[i] <= MAX_PER_STAT_EVS)
            SetMonData(&mon, MON_DATA_HP_EV + i, &evs[i]);

        // IV
        if (ivs[i] <= MAX_PER_STAT_IVS)
            SetMonData(&mon, MON_DATA_HP_IV + i, &ivs[i]);
    }
    CalculateMonStats(&mon);

    // moves
    bool32 all_default_flag = TRUE;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_DEFAULT)
        {
            all_default_flag = FALSE;
            break;
        }
    }
    if (all_default_flag)
    {
        GiveMonInitialMoveset(&mon);
    }
    else
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (moves[i] == MOVE_NONE)
                break;
            if (moves[i] < MOVES_COUNT)
            {
                SetMonMoveSlot(&mon, moves[i], i);
            }
            else if (moves[i] == MOVE_DEFAULT)
            {
                GiveMonDefaultMove(&mon, i);
                continue;
            }
            else
            {
                assertf(FALSE, "invalid move: %d", moves[i]) {}
            }
        }
    }

    // ability
     if (gSpeciesInfo[species].isStarter)
    {
        abilityNum = 2;
    }
    else if (abilityNum != NUM_ABILITY_PERSONALITY)
    {
        assertf(abilityNum < NUM_ABILITY_SLOTS && GetAbilityBySpecies(species, abilityNum) != ABILITY_NONE,
                "invalid ability num %d for species %d", abilityNum, species)
        {
            // If the ability num is invalid, we loop to find a valid one
            do {
                abilityNum = Random() % NUM_ABILITY_SLOTS; // includes hidden abilities
            } while (GetAbilityBySpecies(species, abilityNum) == ABILITY_NONE);
        }
        SetMonData(&mon, MON_DATA_ABILITY_NUM, &abilityNum);
    }

    // ball
    if (ball > POKEBALL_COUNT)
        ball = BALL_POKE;
    SetMonData(&mon, MON_DATA_POKEBALL, &ball);

    // held item
    SetMonData(&mon, MON_DATA_HELD_ITEM, &item);

    u8 location = METLOC_FATEFUL_ENCOUNTER;

    SetMonData(&mon, MON_DATA_MET_LOCATION, &location);

    // In case a mon with a form changing item is given. Eg: SPECIES_ARCEUS_NORMAL with ITEM_SPLASH_PLATE will transform into SPECIES_ARCEUS_WATER upon gifted.
    TryFormChange(&mon, FORM_CHANGE_ITEM_HOLD);

    if (side == B_SIDE_PLAYER)
        return GiveScriptedMonToPlayer(&mon, slot);

    assertf(slot < PARTY_SIZE, "invalid slot: %d", slot)
    {
        return MON_CANT_GIVE;
    }
    CopyMon(&gEnemyParty[slot], &mon, sizeof(struct Pokemon));
    return MON_GIVEN_TO_PARTY;
}

u32 ScriptGiveMon(u16 species, u8 level, enum Item item)
{
    struct Pokemon mon;
    u8 heldItem[2];

    CreateRandomMon(&mon, species, level);
    if (item)
    {
        heldItem[0] = item;
        heldItem[1] = item >> 8;
        SetMonData(&mon, MON_DATA_HELD_ITEM, heldItem);
    }

    return GiveScriptedMonToPlayer(&mon, PARTY_SIZE);
}

#define PARSE_FLAG(n, default_) (flags & (1 << (n))) ? VarGet(ScriptReadHalfword(ctx)) : (default_)

#define ADD_MOVE_IF_NOT_DEFAULT(i, move)               \
    if (move && move != MOVE_DEFAULT)                  \
    {                                                  \
        moves[i] = move;                               \
        i++;                                           \
    }

#define ADD_MOVE_IF_DEFAULT(i, move)                   \
    if (moves[i] == MOVE_NONE && move == MOVE_DEFAULT) \
    {                                                  \
        moves[i] = MOVE_DEFAULT;                       \
        i++;                                           \
    }

/* Give or create a mon to either player or opponent
 */


void ScrCmd_createmon(struct ScriptContext *ctx)
{
    u8 side            = ScriptReadByte(ctx);
    u8 slot            = ScriptReadByte(ctx);
    u16 species        = VarGet(ScriptReadHalfword(ctx));
    u8 level           = VarGet(ScriptReadHalfword(ctx));

    u32 flags          = ScriptReadWord(ctx);
    enum Item item     = PARSE_FLAG(0, ITEM_NONE);
    enum PokeBall ball = PARSE_FLAG(1, BALL_POKE);
    u8 nature          = PARSE_FLAG(2, NATURE_RANDOM);
    u8 abilityNum      = PARSE_FLAG(3, NUM_ABILITY_PERSONALITY);
    u8 gender          = PARSE_FLAG(4, MON_GENDER_RANDOM);

    u32 i;
    u16 evs[NUM_STATS];
    for (i = 0; i < NUM_STATS; i++)
    {
        evs[i] = PARSE_FLAG(5 + i, 0);
        assertf(evs[i] <= MAX_PER_STAT_EVS, "invalid ev value of %d above maximum of %d", evs[i], MAX_PER_STAT_EVS)
        {
            evs[i] = MAX_PER_STAT_EVS;
        }
    }

    u16 ivs[NUM_STATS];
    u32 nonFixedIvCount = 0;
    enum Stat availableIVs[NUM_STATS];
    enum Stat selectedIvs[NUM_STATS];
    for (i = 0; i < NUM_STATS; i++)
    {
        ivs[i] = PARSE_FLAG(11 + i, USE_RANDOM_IVS);
        assertf(ivs[i] <= USE_RANDOM_IVS, "invalid iv value of %d above maximum of %d", ivs[i], MAX_PER_STAT_IVS)
        {
            ivs[i] = MAX_PER_STAT_IVS;
        }
        if (ivs[i] == USE_RANDOM_IVS)
        {
            availableIVs[nonFixedIvCount] = i;
            ivs[i] = Random() % (MAX_PER_STAT_IVS + 1);
            nonFixedIvCount++;
        }
    }

    // Perfect IV calculation
    if (gSpeciesInfo[species].perfectIVCount != 0)
    {
        // Select the IVs that will be perfected.
        for (i = 0; i < nonFixedIvCount && i < gSpeciesInfo[species].perfectIVCount; i++)
        {
            u8 index = Random() % (nonFixedIvCount - i);
            selectedIvs[i] = availableIVs[index];
            RemoveIVIndexFromList(availableIVs, index);
        }
        for (i = 0; i < nonFixedIvCount && i < gSpeciesInfo[species].perfectIVCount; i++)
        {
            ivs[selectedIvs[i]] = MAX_PER_STAT_IVS;
        }
    }

    enum Move move1          = PARSE_FLAG(17, MOVE_DEFAULT);
    enum Move move2          = PARSE_FLAG(18, MOVE_DEFAULT);
    enum Move move3          = PARSE_FLAG(19, MOVE_DEFAULT);
    enum Move move4          = PARSE_FLAG(20, MOVE_DEFAULT);
    enum ShinyMode shinyMode = PARSE_FLAG(21, SHINY_MODE_RANDOM);
    bool8 gmaxFactor         = PARSE_FLAG(22, FALSE);
    enum Type teraType       = PARSE_FLAG(23, NUMBER_OF_MON_TYPES);
    u8 dmaxLevel             = PARSE_FLAG(24, 0);

    enum Move moves[MAX_MON_MOVES];
    for (i = 0; i < MAX_MON_MOVES; i++)
        moves[i] = MOVE_NONE;

    i = 0;
    //Reorder moves to put non-default moves first, default moves second and empty moves last
    ADD_MOVE_IF_NOT_DEFAULT(i, move1)
    ADD_MOVE_IF_NOT_DEFAULT(i, move2)
    ADD_MOVE_IF_NOT_DEFAULT(i, move3)
    ADD_MOVE_IF_NOT_DEFAULT(i, move4)
    ADD_MOVE_IF_DEFAULT(i, move1)
    ADD_MOVE_IF_DEFAULT(i, move2)
    ADD_MOVE_IF_DEFAULT(i, move3)
    ADD_MOVE_IF_DEFAULT(i, move4)

    enum GeneratedMonOrigin origin;
    if (side == 0)
    {
        Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
        origin = GIFTMON_ORIGIN;
    }
    else
    {
        Script_RequestEffects(SCREFF_V1);
        origin = STATIC_WILDMON_ORIGIN;
    }

    if (gender == MON_GENDER_MAY_CUTE_CHARM)
        gender = GetSynchronizedGender(origin, species);
    if (nature == NATURE_MAY_SYNCHRONIZE)
        nature = GetSynchronizedNature(origin, species);

    gSpecialVar_Result = ScriptGiveMonParameterized(side, slot, species, level, item, ball, nature, abilityNum, gender, evs, ivs, moves, shinyMode, gmaxFactor, teraType, dmaxLevel);
}

#undef PARSE_FLAG

void Script_GetChosenMonOffensiveEVs(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_ATK_EV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPATK_EV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPEED_EV), STR_CONV_MODE_LEFT_ALIGN, 3);
}

void Script_GetChosenMonDefensiveEVs(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HP_EV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_DEF_EV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPDEF_EV), STR_CONV_MODE_LEFT_ALIGN, 3);
}

void Script_GetChosenMonOffensiveIVs(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_ATK_IV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPATK_IV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPEED_IV), STR_CONV_MODE_LEFT_ALIGN, 3);
}

void Script_GetChosenMonDefensiveIVs(void)
{
    ConvertIntToDecimalStringN(gStringVar1, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HP_IV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_DEF_IV), STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPDEF_IV), STR_CONV_MODE_LEFT_ALIGN, 3);
}

void Script_SetStatus1(struct ScriptContext *ctx)
{
    u32 status1 = VarGet(ScriptReadHalfword(ctx));
    u32 slot = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);

    if (slot >= PARTY_SIZE)
    {
        u16 species;

        for (slot = 0; slot < PARTY_SIZE; slot++)
        {
            species = GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES);
            if (species != SPECIES_NONE
             && species != SPECIES_EGG
             && GetMonData(&gPlayerParty[slot], MON_DATA_HP) != 0)
                SetMonData(&gPlayerParty[slot], MON_DATA_STATUS, &status1);
        }
    }
    else
    {
        SetMonData(&gPlayerParty[slot], MON_DATA_STATUS, &status1);
    }
}

void HealUnfainted(void)
{
    u32 i;
    for (i = 0; i < gPlayerPartyCount; i++)
        if (GetMonData(&gPlayerParty[i], MON_DATA_HP) != 0)
        HealPokemon(&gPlayerParty[i]);
    if (OW_PC_HEAL >= GEN_8)
        HealPlayerBoxes();

    // Recharge Tera Orb, if possible.
    if (B_FLAG_TERA_ORB_CHARGED != 0 && CheckBagHasItem(ITEM_TERA_ORB, 1))
        FlagSet(B_FLAG_TERA_ORB_CHARGED);
}

void Script_SetKO(struct ScriptContext *ctx)
{
    u32 slot = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);

    if (slot < PARTY_SIZE)
    {
        u32 hp = 0;
        SetMonData(&gPlayerParty[slot], MON_DATA_HP, &hp);
    }
}
