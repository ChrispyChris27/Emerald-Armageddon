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
#line 5
        .gender = TRAINER_GENDER_MALE,
#line 6
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 0
        .multiTeamSize = MULTI_TEAM_SIZE_FULL,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 8
    [DIFFICULTY_NORMAL][PARTNER_STEVEN] =
    {
#line 9
        .trainerName = _("STEVEN"),
#line 10
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11
        .trainerPic = TRAINER_PIC_STEVEN,
#line 12
        .gender = TRAINER_GENDER_MALE,
#line 13
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 14
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT | AI_FLAG_WILL_SUICIDE | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_TRY_TO_2HKO,
#line 0
        .multiTeamSize = MULTI_TEAM_SIZE_FULL,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 16
            .species = SPECIES_MELMETAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 16
            .heldItem = ITEM_PUNCHING_GLOVE,
#line 18
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 17
            .lvl = 82,
            .ball = POKEBALL_COUNT,
#line 19
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 20
                MOVE_DOUBLE_IRON_BASH,
                MOVE_THUNDER_PUNCH,
                MOVE_HIGH_HORSEPOWER,
                MOVE_BULLET_PUNCH,
            },
            },
            {
#line 25
            .species = SPECIES_IRON_CROWN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 25
            .heldItem = ITEM_LEFTOVERS,
#line 27
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 26
            .lvl = 82,
            .ball = POKEBALL_COUNT,
#line 28
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 29
                MOVE_PSYSHOCK,
                MOVE_FOCUS_BLAST,
                MOVE_TACHYON_CUTTER,
                MOVE_THUNDER,
            },
            },
            {
#line 34
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 34
            .heldItem = ITEM_METAGROSSITE,
#line 36
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 35
            .lvl = 82,
            .ball = POKEBALL_COUNT,
#line 37
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 38
                MOVE_METEOR_MASH,
                MOVE_PSYCHIC_FANGS,
                MOVE_STONE_EDGE,
                MOVE_ICE_PUNCH,
            },
            },
        },
    },
#line 43
    [DIFFICULTY_NORMAL][PARTNER_STEVEN2] =
    {
#line 44
        .trainerName = _("STEVEN"),
#line 45
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 46
        .trainerPic = TRAINER_PIC_STEVEN,
#line 47
        .gender = TRAINER_GENDER_MALE,
#line 48
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 49
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT | AI_FLAG_WILL_SUICIDE | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_TRY_TO_2HKO,
#line 0
        .multiTeamSize = MULTI_TEAM_SIZE_FULL,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 51
            .species = SPECIES_GENESECT_CHILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 51
            .heldItem = ITEM_CHILL_DRIVE,
#line 53
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 55
            .ability = ABILITY_DOWNLOAD,
#line 52
            .lvl = 91,
            .ball = POKEBALL_COUNT,
#line 54
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 56
                MOVE_TECHNO_BLAST,
                MOVE_PSYCHIC,
                MOVE_FLASH_CANNON,
                MOVE_BUG_BUZZ,
            },
            },
            {
#line 61
            .species = SPECIES_MAGEARNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 61
            .heldItem = ITEM_WHITE_HERB,
#line 63
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 62
            .lvl = 91,
            .ball = POKEBALL_COUNT,
#line 64
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 65
                MOVE_FLEUR_CANNON,
                MOVE_AURA_SPHERE,
                MOVE_FLASH_CANNON,
                MOVE_MOONBLAST,
            },
            },
            {
#line 70
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 70
            .heldItem = ITEM_METAGROSSITE,
#line 72
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 71
            .lvl = 91,
            .ball = POKEBALL_COUNT,
#line 73
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 74
                MOVE_METEOR_MASH,
                MOVE_PSYCHIC_FANGS,
                MOVE_ICE_PUNCH,
                MOVE_BULLET_PUNCH,
            },
            },
        },
    },
