.set LOCALID_SIS1, 4
.set LOCALID_SIS2, 5
.set LOCALID_SIS3, 6

NewMap1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewMap1_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewMap1_OnFrame
	.byte 0

NewMap1_OnLoad::
	setvar VAR_UNUSED_0x40F7, 0
	end

NewMap1_OnFrame::
	map_script_2 VAR_ROCKET_HIDEOUT_STATE, 1, NewMap1_Sister_Battles
	.2byte 0

NewMap1_Sister_Battles::
	lockall
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	applymovement LOCALID_SIS1, Common_Movement_ExclamationMark
	applymovement LOCALID_SIS2, Common_Movement_ExclamationMark
	applymovement LOCALID_SIS3, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Sister1Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_HIDEOUT_GRUNT_24, Sister1Defeat
	msgbox Sister1Exit, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	msgbox Sister2Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_HIDEOUT_GRUNT_25, Sister2Defeat
	msgbox Sister2Exit, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	msgbox Sister3Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_HIDEOUT_GRUNT_26, Sister3Defeat
	msgbox Sister3Exit, MSGBOX_DEFAULT
	
NewMap1_EventScript_Giovanni::
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setflag FLAG_HIDEOUT_GIOVANNI
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN

Sister1Intro:
	.string "I'm not surprised our useless\n"
	.string "brothers couldn't stop you.\p"
	.string "Fortunately us sisters will prevent\n"
	.string "you from interfering with the boss.\p"
	.string "It's too late for you to turn around!\p"
	.string "Prepare for trouble and make it triple!$"

Sister1Defeat:
	.string "My sisters will pick up my slack.$"

Sister1Exit:
	.string "You're strong but not strong enough\n"
	.string "to take on my sisters too!$"

Sister2Intro:
	.string "I'll be taking over now.\p"
	.string "Prepare to lose!$"

Sister2Defeat:
	.string "I wasn't prepared to lose!$"

Sister2Exit:
