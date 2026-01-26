Route122_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route122_OnTransition
	.byte 0

Route122_OnTransition::
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

Route122GruntText:
	.string "TEAM AQUA is busy in MT. PYRE\n"
	.string "right now!\p"
	.string "I'm not supposed to let anyone\n"
	.string "in until the boss says otherwise!$"

Route122EventScript_Grunt::
	msgbox Route122GruntText, MSGBOX_NPC
	end

