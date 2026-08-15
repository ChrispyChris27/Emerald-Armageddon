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
#line 20
            .ability = ABILITY_IRON_FIST,
#line 17
            .lvl = 82,
            .ball = POKEBALL_COUNT,
#line 19
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 21
                MOVE_DOUBLE_IRON_BASH,
                MOVE_THUNDER_PUNCH,
                MOVE_HIGH_HORSEPOWER,
                MOVE_BULLET_PUNCH,
            },
            },
            {
#line 26
            .species = SPECIES_IRON_CROWN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 26
            .heldItem = ITEM_LEFTOVERS,
#line 28
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 27
            .lvl = 82,
            .ball = POKEBALL_COUNT,
#line 29
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 30
                MOVE_PSYSHOCK,
                MOVE_FOCUS_BLAST,
                MOVE_TACHYON_CUTTER,
                MOVE_THUNDER,
            },
            },
            {
#line 35
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 35
            .heldItem = ITEM_METAGROSSITE,
#line 37
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 36
            .lvl = 82,
            .ball = POKEBALL_COUNT,
#line 38
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 39
                MOVE_METEOR_MASH,
                MOVE_PSYCHIC_FANGS,
                MOVE_STONE_EDGE,
                MOVE_ICE_PUNCH,
            },
            },
        },
    },
#line 44
    [DIFFICULTY_NORMAL][PARTNER_STEVEN2] =
    {
#line 45
        .trainerName = _("STEVEN"),
#line 46
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 47
        .trainerPic = TRAINER_PIC_STEVEN,
#line 48
        .gender = TRAINER_GENDER_MALE,
#line 49
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 50
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT | AI_FLAG_WILL_SUICIDE | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_TRY_TO_2HKO,
#line 0
        .multiTeamSize = MULTI_TEAM_SIZE_FULL,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 52
            .species = SPECIES_GENESECT_CHILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 52
            .heldItem = ITEM_CHILL_DRIVE,
#line 54
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 56
            .ability = ABILITY_DOWNLOAD,
#line 53
            .lvl = 91,
            .ball = POKEBALL_COUNT,
#line 55
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 57
                MOVE_TECHNO_BLAST,
                MOVE_PSYCHIC,
                MOVE_FLASH_CANNON,
                MOVE_BUG_BUZZ,
            },
            },
            {
#line 62
            .species = SPECIES_MAGEARNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 62
            .heldItem = ITEM_WHITE_HERB,
#line 64
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 63
            .lvl = 91,
            .ball = POKEBALL_COUNT,
#line 65
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 66
                MOVE_FLEUR_CANNON,
                MOVE_AURA_SPHERE,
                MOVE_FLASH_CANNON,
                MOVE_MOONBLAST,
            },
            },
            {
#line 71
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 71
            .heldItem = ITEM_METAGROSSITE,
#line 73
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 72
            .lvl = 91,
            .ball = POKEBALL_COUNT,
#line 74
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 75
                MOVE_METEOR_MASH,
                MOVE_PSYCHIC_FANGS,
                MOVE_ICE_PUNCH,
                MOVE_BULLET_PUNCH,
            },
            },
        },
    },
