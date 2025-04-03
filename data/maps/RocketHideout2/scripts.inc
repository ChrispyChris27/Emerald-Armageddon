RocketHideout2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout2_OnLoad
	.byte 0

RocketHideout2_OnLoad::
	setvar VAR_UNUSED_0x40F7, 1
	end

RocketHideout_Grunt1_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_1, RocketHideoutGrunt1Intro, RocketHideoutGrunt1Defeat
	msgbox RocketHideoutGrunt1PostBattle, MSGBOX_AUTOCLOSE
	end
