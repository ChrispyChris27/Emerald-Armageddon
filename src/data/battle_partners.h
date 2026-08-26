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
#line 80
    [DIFFICULTY_NORMAL][PARTNER_WALLY] =
    {
#line 81
        .trainerName = _("Wally"),
#line 82
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 83
        .trainerPic = TRAINER_PIC_WALLY,
#line 84
        .gender = TRAINER_GENDER_MALE,
#line 85
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 86
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT | AI_FLAG_WILL_SUICIDE | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_TRY_TO_2HKO,
#line 0
        .multiTeamSize = MULTI_TEAM_SIZE_FULL,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 88
            .species = SPECIES_DRIFBLIM,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 88
            .heldItem = ITEM_FLAME_ORB,
#line 91
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 90
            .ability = ABILITY_FLARE_BOOST,
#line 89
            .lvl = 87,
            .ball = POKEBALL_COUNT,
#line 92
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 93
                MOVE_SHADOW_BALL,
                MOVE_WEATHER_BALL,
                MOVE_HURRICANE,
                MOVE_TAILWIND,
            },
            },
            {
#line 98
            .species = SPECIES_TALONFLAME,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 98
            .heldItem = ITEM_PASSHO_BERRY,
#line 101
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 100
            .ability = ABILITY_GALE_WINGS,
#line 99
            .lvl = 87,
            .ball = POKEBALL_COUNT,
#line 102
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 103
                MOVE_WEATHER_BALL,
                MOVE_HURRICANE,
                MOVE_SOLARBEAM,
                MOVE_TAILWIND,
            },
            },
            {
#line 108
            .species = SPECIES_ROSERADE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 108
            .heldItem = ITEM_GRASS_GEM,
#line 111
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 110
            .ability = ABILITY_NATURAL_CURE,
#line 109
            .lvl = 87,
            .ball = POKEBALL_COUNT,
#line 112
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 113
                MOVE_WEATHER_BALL,
                MOVE_SLUDGE_BOMB,
                MOVE_SOLARBEAM,
                MOVE_GIGA_DRAIN,
            },
            },
            {
#line 118
            .species = SPECIES_ALTARIA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 118
            .heldItem = ITEM_YACHE_BERRY,
#line 121
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 120
            .ability = ABILITY_NATURAL_CURE,
#line 119
            .lvl = 87,
            .ball = POKEBALL_COUNT,
#line 122
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 123
                MOVE_WEATHER_BALL,
                MOVE_HURRICANE,
                MOVE_SOLARBEAM,
                MOVE_DRAGON_PULSE,
            },
            },
            {
#line 128
            .species = SPECIES_YANMEGA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 128
            .heldItem = ITEM_FOCUS_SASH,
#line 131
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 130
            .ability = ABILITY_SPEED_BOOST,
#line 129
            .lvl = 87,
            .ball = POKEBALL_COUNT,
#line 132
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 133
                MOVE_HURRICANE,
                MOVE_BUG_BUZZ,
                MOVE_SOLARBEAM,
                MOVE_DETECT,
            },
            },
            {
#line 138
            .species = SPECIES_GALLADE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 138
            .heldItem = ITEM_GALLADITE,
#line 141
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 140
            .ability = ABILITY_SHARPNESS,
#line 139
            .lvl = 87,
            .ball = POKEBALL_COUNT,
#line 142
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 143
                MOVE_AQUA_CUTTER,
                MOVE_SOLAR_BLADE,
                MOVE_SACRED_SWORD,
                MOVE_PSYCHO_CUT,
            },
            },
        },
    },
#line 148
    [DIFFICULTY_NORMAL][PARTNER_STEVEN3] =
    {
#line 149
        .trainerName = _("STEVEN"),
#line 150
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 151
        .trainerPic = TRAINER_PIC_STEVEN,
#line 152
        .gender = TRAINER_GENDER_MALE,
#line 153
        .encounterMusic = TRAINER_ENCOUNTER_MUSIC_MALE,
#line 154
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT | AI_FLAG_WILL_SUICIDE | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_TRY_TO_2HKO,
#line 0
        .multiTeamSize = MULTI_TEAM_SIZE_FULL,
        .partySize = 6,
        .party = (const struct TrainerMon[])
        {
            {
#line 156
            .species = SPECIES_GENESECT_CHILL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 156
            .heldItem = ITEM_CHILL_DRIVE,
#line 158
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 160
            .ability = ABILITY_DOWNLOAD,
#line 157
            .lvl = 91,
            .ball = POKEBALL_COUNT,
#line 159
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 161
                MOVE_TECHNO_BLAST,
                MOVE_PSYCHIC,
                MOVE_FLASH_CANNON,
                MOVE_BUG_BUZZ,
            },
            },
            {
#line 166
            .species = SPECIES_MELMETAL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 166
            .heldItem = ITEM_CHOICE_BAND,
#line 168
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 170
            .ability = ABILITY_IRON_FIST,
#line 167
            .lvl = 82,
            .ball = POKEBALL_COUNT,
#line 169
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 171
                MOVE_DOUBLE_IRON_BASH,
                MOVE_THUNDER_PUNCH,
                MOVE_HIGH_HORSEPOWER,
                MOVE_BULLET_PUNCH,
            },
            },
            {
#line 176
            .species = SPECIES_GHOLDENGO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 176
            .heldItem = ITEM_CHOICE_SPECS,
#line 178
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 177
            .lvl = 91,
            .ball = POKEBALL_COUNT,
#line 179
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 180
                MOVE_MAKE_IT_RAIN,
                MOVE_DAZZLING_GLEAM,
                MOVE_SHADOW_BALL,
                MOVE_POWER_GEM,
            },
            },
            {
#line 185
            .species = SPECIES_IRON_CROWN,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 185
            .heldItem = ITEM_CHOICE_SCARF,
#line 187
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 186
            .lvl = 82,
            .ball = POKEBALL_COUNT,
#line 188
            .nature = NATURE_TIMID,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 189
                MOVE_PSYSHOCK,
                MOVE_AURA_SPHERE,
                MOVE_TACHYON_CUTTER,
                MOVE_THUNDERBOLT,
            },
            },
            {
#line 194
            .species = SPECIES_MAGEARNA,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 194
            .heldItem = ITEM_WHITE_HERB,
#line 196
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 195
            .lvl = 91,
            .ball = POKEBALL_COUNT,
#line 197
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 198
                MOVE_FLEUR_CANNON,
                MOVE_AURA_SPHERE,
                MOVE_FLASH_CANNON,
                MOVE_MOONBLAST,
            },
            },
            {
#line 203
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 203
            .heldItem = ITEM_METAGROSSITE,
#line 205
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 204
            .lvl = 91,
            .ball = POKEBALL_COUNT,
#line 206
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 207
                MOVE_METEOR_MASH,
                MOVE_PSYCHIC_FANGS,
                MOVE_ICE_PUNCH,
                MOVE_BULLET_PUNCH,
            },
            },
        },
    },
