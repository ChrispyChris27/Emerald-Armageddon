CaveOfLegendsRubyRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RubyCaveOnLoad
	.byte 0

RubyCaveOnLoad::
	call_if_unset FLAG_UNLOCK_R_S_VILLAS, RubyCaveCloseDoor
	end

RubyCaveCloseDoor::
	setmetatile 5, 32, METATILE_Cave_BrownRockFloor, FALSE
	setmetatile 4, 33, METATILE_Cave_BrownRockNorthBarrier, TRUE
	setmetatile 5, 33, METATILE_Cave_BrownRockNorthBarrier, TRUE
	setmetatile 6, 33, METATILE_Cave_BrownRockNorthBarrier, TRUE
	end
