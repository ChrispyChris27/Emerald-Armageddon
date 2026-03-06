CaveOfLegendsEmeraldRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EmeraldCaveOnLoad
	.byte 0

EmeraldCaveOnLoad::
	call_if_unset FLAG_UNLOCK_EMERALD_VILLA, EmeraldCaveCloseDoor
	end

EmeraldCaveCloseDoor::
	setmetatile 9, 2, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 10, 2, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 11, 2, METATILE_NavelRock_WhiteRockFace, TRUE
	setmetatile 10, 1, METATILE_NavelRock_GreenRockFace, TRUE
	end


