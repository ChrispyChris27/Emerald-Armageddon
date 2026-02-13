RocketHideout1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout1_OnLoad
	.byte 0

RocketHideout1_OnLoad::
	setvar VAR_BATTLE_START, 0
	end
