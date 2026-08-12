CaveOfLegends4_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CaveOfLegends4OnLoad
	.byte 0

CaveOfLegends4OnLoad::
	call_if_unset FLAG_DEFEATED_MOSSDEEP_GYM, CloseCaveOfLegendsDoors
	end

CloseCaveOfLegendsDoors::
	setmetatile 3, 2, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 4, 2, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 5, 2, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 9, 2, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 10, 2, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 11, 2, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 15, 2, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 16, 2, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 17, 2, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 3, 1, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 4, 1, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 5, 1, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 9, 1, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 10, 1, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 11, 1, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 15, 1, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 16, 1, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 17, 1, METATILE_NavelRock_WhiteRockFace, TRUE
	end
