CaveOfLegendsSapphireRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SapphireCaveOnLoad
	.byte 0

SapphireCaveOnLoad::
	call_if_unset FLAG_UNLOCK_R_S_VILLAS, SapphireCaveCloseDoor
	end

SapphireCaveCloseDoor::
	setmetatile 39, 32, METATILE_Cave_BrownRockFloor, FALSE
	setmetatile 38, 33, METATILE_Cave_BrownRockNorthBarrier, TRUE
	setmetatile 39, 33, METATILE_Cave_BrownRockNorthBarrier, TRUE
	setmetatile 40, 33, METATILE_Cave_BrownRockNorthBarrier, TRUE
	end
