OldMauville_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldMauville_OnTransition
	.byte 0

OldMauville_OnTransition:
	setflag FLAG_VISITED_OLD_MAUVILLE
	end
