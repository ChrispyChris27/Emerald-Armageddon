//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file see expansion PR #7154
//

#line 1 "src/data/battle_partners.party"

#line 1
    [DIFFICULTY_NORMAL][PARTNER_NONE] =
    {
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7
        .trainerBackPic = TRAINER_BACK_PIC_BRENDAN,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 9
    [DIFFICULTY_NORMAL][PARTNER_STEVEN] =
    {
#line 10
        .trainerName = _("STEVEN"),
#line 11
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 12
        .trainerPic = TRAINER_PIC_STEVEN,
        .encounterMusic_gender =
#line 14
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 16
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT | AI_FLAG_WILL_SUICIDE | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_TRY_TO_2HKO,
#line 15
        .trainerBackPic = TRAINER_BACK_PIC_STEVEN,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 18
            .species = SPECIES_MAGEARNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 18
            .heldItem = ITEM_WHITE_HERB,
#line 20
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 19
            .lvl = 82,
#line 21
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 22
                MOVE_FLEUR_CANNON,
                MOVE_AURA_SPHERE,
                MOVE_FLASH_CANNON,
                MOVE_THUNDERBOLT,
            },
            },
            {
#line 27
            .species = SPECIES_JIRACHI,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 27
            .heldItem = ITEM_LEFTOVERS,
#line 29
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 28
            .lvl = 82,
#line 30
            .nature = NATURE_HASTY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 31
                MOVE_METEOR_MASH,
                MOVE_ZEN_HEADBUTT,
                MOVE_ICY_WIND,
                MOVE_THUNDERBOLT,
            },
            },
            {
#line 36
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 36
            .heldItem = ITEM_METAGROSSITE,
#line 38
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 37
            .lvl = 82,
#line 39
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 40
                MOVE_METEOR_MASH,
                MOVE_PSYCHIC_FANGS,
                MOVE_ICE_PUNCH,
                MOVE_BULLET_PUNCH,
            },
            },
        },
    },
#line 45
    [DIFFICULTY_NORMAL][PARTNER_STEVEN2] =
    {
#line 46
        .trainerName = _("STEVEN"),
#line 47
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 48
        .trainerPic = TRAINER_PIC_STEVEN,
        .encounterMusic_gender =
#line 50
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 52
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT | AI_FLAG_WILL_SUICIDE | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_TRY_TO_2HKO,
#line 51
        .trainerBackPic = TRAINER_BACK_PIC_STEVEN,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 54
            .species = SPECIES_GENESECT_CHILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 54
            .heldItem = ITEM_CHILL_DRIVE,
#line 56
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 55
            .lvl = 91,
#line 57
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 58
                MOVE_TECHNO_BLAST,
                MOVE_PSYCHIC,
                MOVE_FLASH_CANNON,
                MOVE_BUG_BUZZ,
            },
            },
            {
#line 63
            .species = SPECIES_MAGEARNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 63
            .heldItem = ITEM_WHITE_HERB,
#line 65
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 64
            .lvl = 91,
#line 66
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 67
                MOVE_FLEUR_CANNON,
                MOVE_AURA_SPHERE,
                MOVE_FLASH_CANNON,
                MOVE_MOONBLAST,
            },
            },
            {
#line 72
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 72
            .heldItem = ITEM_METAGROSSITE,
#line 74
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 73
            .lvl = 91,
#line 75
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 76
                MOVE_METEOR_MASH,
                MOVE_PSYCHIC_FANGS,
                MOVE_ICE_PUNCH,
                MOVE_BULLET_PUNCH,
            },
            },
        },
    },
