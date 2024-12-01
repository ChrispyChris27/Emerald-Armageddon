#ifndef GUARD_CONSTANTS_BERRY_H
#define GUARD_CONSTANTS_BERRY_H

#define BERRY_NONE 0

#define BERRY_FIRMNESS_UNKNOWN     0
#define BERRY_FIRMNESS_VERY_SOFT   1
#define BERRY_FIRMNESS_SOFT        2
#define BERRY_FIRMNESS_HARD        3
#define BERRY_FIRMNESS_VERY_HARD   4
#define BERRY_FIRMNESS_SUPER_HARD  5

#define BERRY_COLOR_RED    0
#define BERRY_COLOR_BLUE   1
#define BERRY_COLOR_PURPLE 2
#define BERRY_COLOR_GREEN  3
#define BERRY_COLOR_YELLOW 4
#define BERRY_COLOR_PINK   5

#define FLAVOR_SPICY   0
#define FLAVOR_DRY     1
#define FLAVOR_SWEET   2
#define FLAVOR_BITTER  3
#define FLAVOR_SOUR    4
#define FLAVOR_COUNT   5

#define BERRY_STAGE_NO_BERRY    0  // there is no tree planted and the soil is completely flat.
#define BERRY_STAGE_PLANTED     1
#define BERRY_STAGE_SPROUTED    2
#define BERRY_STAGE_TALLER      3
#define BERRY_STAGE_FLOWERING   4
#define BERRY_STAGE_BERRIES     5
#define BERRY_STAGE_TRUNK       6 // These follow BERRY_STAGE_BERRIES to preserve save compatibility
#define BERRY_STAGE_BUDDING     7
#define BERRY_STAGE_SPARKLING   255

// Berries can be watered in the following stages:
// - BERRY_STAGE_PLANTED
// - BERRY_STAGE_SPROUTED
// - BERRY_STAGE_TALLER
// - BERRY_STAGE_FLOWERING
#define NUM_WATER_STAGES 4

// IDs for berry tree objects, indexes into berryTrees in SaveBlock1
// Named for whatever berry is initially planted there on a new game
// Those with no initial berry are named "soil"
#define BERRY_TREE_ROUTE_102_PECHA    1
#define BERRY_TREE_ROUTE_102_ORAN     2
#define BERRY_TREE_ROUTE_104_ORAN_0   3
#define BERRY_TREE_ROUTE_104_ORAN_1   4
#define BERRY_TREE_ROUTE_103_GREPA    5
#define BERRY_TREE_ROUTE_103_LEPPA    6
#define BERRY_TREE_ROUTE_103_TAMATO   7
#define BERRY_TREE_ROUTE_104_CHERI_1  8
#define BERRY_TREE_ROUTE_104_CHESTO   9
#define BERRY_TREE_ROUTE_104_LEPPA    10
#define BERRY_TREE_ROUTE_104_ORAN_2   11
#define BERRY_TREE_ROUTE_104_CHERI    12
#define BERRY_TREE_ROUTE_104_PECHA    13
#define BERRY_TREE_ROUTE_123_OCCA     14
#define BERRY_TREE_ROUTE_123_PASSHO   15
#define BERRY_TREE_ROUTE_110_NANAB_1  16
#define BERRY_TREE_ROUTE_110_PERSIM   17
#define BERRY_TREE_ROUTE_110_ASPEAR   18
#define BERRY_TREE_ROUTE_111_RAZZ_1   19
#define BERRY_TREE_ROUTE_111_CORNN    20
#define BERRY_TREE_ROUTE_112_RAWST_1  21
#define BERRY_TREE_ROUTE_112_PECHA_1  22
#define BERRY_TREE_ROUTE_112_CHESTO   23
#define BERRY_TREE_ROUTE_112_RAWST_2  24
#define BERRY_TREE_ROUTE_116_PINAP_1  25
#define BERRY_TREE_ROUTE_116_HONDEW   26
#define BERRY_TREE_ROUTE_117_WEPEAR_1 27
#define BERRY_TREE_ROUTE_117_MAGOST   28
#define BERRY_TREE_ROUTE_117_RABUTA   29
#define BERRY_TREE_ROUTE_123_WACAN    30
#define BERRY_TREE_ROUTE_118_SITRUS_1 31
#define BERRY_TREE_ROUTE_118_SITRUS_3 32
#define BERRY_TREE_ROUTE_118_SITRUS_2 33
#define BERRY_TREE_ROUTE_119_MICLE    34
#define BERRY_TREE_ROUTE_119_KEE      35
#define BERRY_TREE_ROUTE_119_MARANGA  36
#define BERRY_TREE_ROUTE_120_MICLE    37
#define BERRY_TREE_ROUTE_120_ROWAP    38
#define BERRY_TREE_ROUTE_120_JABOCA   39
#define BERRY_TREE_ROUTE_120_STARF    40
#define BERRY_TREE_ROUTE_120_LANSAT   41
#define BERRY_TREE_ROUTE_120_IAPAPA   42
#define BERRY_TREE_ROUTE_120_AGUAV    43
#define BERRY_TREE_ROUTE_120_MAGO     44
#define BERRY_TREE_ROUTE_120_WIKI     45
#define BERRY_TREE_ROUTE_120_FIGY     46
#define BERRY_TREE_ROUTE_121_PAMTRE   47
#define BERRY_TREE_ROUTE_121_WATMEL   48
#define BERRY_TREE_ROUTE_121_DURIN    49
#define BERRY_TREE_ROUTE_121_BELUE    50
#define BERRY_TREE_ROUTE_121_SITRUS_1 51
#define BERRY_TREE_ROUTE_121_LUM_1    52
#define BERRY_TREE_ROUTE_121_LUM_2    53
#define BERRY_TREE_ROUTE_121_SITRUS_2 54
#define BERRY_TREE_ROUTE_115_BLUK_1   55
#define BERRY_TREE_ROUTE_115_CUSTAP   56
#define BERRY_TREE_UNUSED             57
#define BERRY_TREE_ROUTE_123_RINDO    58
#define BERRY_TREE_ROUTE_123_YACHE    59
#define BERRY_TREE_ROUTE_123_CHOPLE   60
#define BERRY_TREE_ROUTE_123_KEBIA    61
#define BERRY_TREE_ROUTE_123_COBA     62
#define BERRY_TREE_ROUTE_123_SHUCA    63
#define BERRY_TREE_ROUTE_123_PAYAPA   64
#define BERRY_TREE_ROUTE_123_TANGA    65
#define BERRY_TREE_ROUTE_116_SPELON   66
#define BERRY_TREE_ROUTE_116_NOMEL    67
#define BERRY_TREE_ROUTE_114_PERSIM_1 68
#define BERRY_TREE_ROUTE_115_KELPSY   69
#define BERRY_TREE_ROUTE_115_APICOT   70
#define BERRY_TREE_ROUTE_115_GANLON   71
#define BERRY_TREE_ROUTE_123_CHARTI   72
#define BERRY_TREE_ROUTE_123_KASIB    73
#define BERRY_TREE_ROUTE_123_HABAN    74
#define BERRY_TREE_ROUTE_104_RAWST    75
#define BERRY_TREE_ROUTE_104_CHERI_2  76
#define BERRY_TREE_ROUTE_114_ASPEAR   77
#define BERRY_TREE_ROUTE_114_CHESTO   78
#define BERRY_TREE_ROUTE_123_COLBUR   79
#define BERRY_TREE_ROUTE_111_POMEG    80
#define BERRY_TREE_ROUTE_111_QUALOT   81
#define BERRY_TREE_ROUTE_130_ENIGMA   82
#define BERRY_TREE_ROUTE_119_JABOCA   83
#define BERRY_TREE_ROUTE_119_ROWAP    84
#define BERRY_TREE_ROUTE_119_SITRUS   85
#define BERRY_TREE_ROUTE_119_LEPPA    86
#define BERRY_TREE_ROUTE_123_LIECHI   87
#define BERRY_TREE_ROUTE_123_PETAYA   88
#define BERRY_TREE_ROUTE_123_SALAC    89
#define BERRY_TREE_ROUTE_123_BABIRI   90
#define BERRY_TREE_ROUTE_123_CHILAN   91
#define BERRY_TREE_ROUTE_123_ROSELI   92
// Remainder are unused

#define BERRY_TREES_COUNT 128

#endif // GUARD_CONSTANTS_BERRY_H
