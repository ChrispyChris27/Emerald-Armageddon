//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/battle_partners.h' to remove #line markers.
//



    [DIFFICULTY_NORMAL][PARTNER_NONE] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },

    [DIFFICULTY_NORMAL][PARTNER_STEVEN] =
    {
        .trainerName = _("STEVEN"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender = 
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_MAGEARNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 0, 0),
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 82,
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .heldItem = ITEM_WHITE_HERB,
            .moves = {
                MOVE_FLEUR_CANNON,
                MOVE_AURA_SPHERE,
                MOVE_FLASH_CANNON,
                MOVE_THUNDERBOLT,
            },
            },
            {
            .species = SPECIES_JIRACHI,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 0, 0),
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 82,
            .nature = NATURE_HASTY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .heldItem = ITEM_LIFE_ORB,
            .moves = {
                MOVE_METEOR_MASH,
                MOVE_ZEN_HEADBUTT,
                MOVE_ICY_WIND,
                MOVE_THUNDERBOLT,
            },
            },
            {
            .species = SPECIES_SOLGALEO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 0, 0),
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 82,
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .heldItem = ITEM_LEFTOVERS,
            .moves = {
                MOVE_SUNSTEEL_STRIKE,
                MOVE_PSYCHIC_FANGS,
                MOVE_FLARE_BLITZ,
                MOVE_STONE_EDGE,
            },
            },
        },
    },
