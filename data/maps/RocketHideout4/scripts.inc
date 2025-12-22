RocketHideout4_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout4_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RocketHideout4_OnFrame
	.byte 0

RocketHideout4_OnLoad::
	setvar VAR_UNUSED_0x40F7, 1
	end

RocketHideout4_OnFrame::
	map_script_2 VAR_ROCKET_HIDEOUT_STATE, 0, RocketHideout4_Brother_Battles
	.2byte 0

RocketHideout4_Brother_Battles::
	lockall
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	applymovement LOCALID_BRO1, Common_Movement_ExclamationMark
	applymovement LOCALID_BRO2, Common_Movement_ExclamationMark
	applymovement LOCALID_BRO3, Common_Movement_ExclamationMark
	applymovement LOCALID_BRO4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox Brother1Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_HIDEOUT_GRUNT_20, Brother1Defeat
	msgbox Brother1Exit, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	msgbox Brother2Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_HIDEOUT_GRUNT_21, Brother2Defeat
	msgbox Brother2Exit, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	msgbox Brother3Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_HIDEOUT_GRUNT_22, Brother3Defeat
	msgbox Brother3Exit, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	msgbox Brother4Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_HIDEOUT_GRUNT_23, Brother4Defeat
	msgbox Brother4Exit, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_BRO1
	removeobject LOCALID_BRO2
	removeobject LOCALID_BRO3
	removeobject LOCALID_BRO4
	setvar VAR_ROCKET_HIDEOUT_STATE, 1
	setflag FLAG_ROCKET_BROS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

Brother1Intro:
	.string "Hold it right there intruder!\p"
	.string "The TEAM ROCKET BROTHERS were warned\n"
	.string "that someone was coming to try and put\l"
	.string "an end to the boss' plan!\p"
	.string "You're going to have to go through the\n"
	.string "four of us first!\p"
	.string "We've been itching for the chance at\n"
	.string "revenge after the defeat you handed us\l"
	.string "at the SPACE CENTER!\p"
	.string "Ready or not, here we come!$"

Brother1Defeat:
	.string "I've softened you up for my brothers!$"

Brother1Exit:
	.string "I've started the job, now the rest\n"
	.string "you can finish it!$"

Brother2Intro: 
	.string "I'm up next!\p"
	.string "Prepare to face my wrath!$"

Brother2Defeat:
	.string "My brothers will finish you off!$"

Brother2Exit:
	.string "It's not over yet but it will\n"
	.string "be soon!$"

Brother3Intro:
	.string "Two down, two to go!\p"
	.string "You won't hold on for much longer!$"

Brother3Defeat:
	.string "My brother will put a stop to you!$"

Brother3Exit:
	.string "Avenge us brother!\p"
	.string "End this meddlesome child!$"

Brother4Intro:
	.string "You may have beaten my brothers but\n"
	.string "I'm stronger than the rest of them!\p"
	.string "Time to stop your meddling for good!$"

Brother4Defeat:
	.string "Brothers. I failed you.$"

Brother4Exit:
	.string "Impossible! We've been defeated again!\p"
	.string "No matter! By now the boss should be\n"
	.string "nearly finished preparing to launch!\p"
	.string "We better go warn him that trouble is\n"
	.string "coming!\p"
	.string "Out of the way!$"

RocketHideout_Grunt17_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_17, RocketHideoutGrunt17Intro, RocketHideoutGrunt17Defeat
	msgbox RocketHideoutGrunt17PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt18_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_18, RocketHideoutGrunt18Intro, RocketHideoutGrunt18Defeat
	msgbox RocketHideoutGrunt18PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt19_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_19, RocketHideoutGrunt19Intro, RocketHideoutGrunt19Defeat
	msgbox RocketHideoutGrunt19PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideoutGrunt17Intro:
	.string "Surrender now or prepare to fight!\p"
	.string "What's that?\n"
	.string "You won't surrender?\p"
	.string "Perfect, I was hoping you would\n"
	.string "choose the hard way!$"

RocketHideoutGrunt17Defeat:
	.string "I surrender!$"

RocketHideoutGrunt17PostBattle:
	.string "We won't quite blast off at the speed\n"
	.string "of light but we'll blast off soon!$"

RocketHideoutGrunt18Intro:
	.string "I've dedicated my life to TEAM\n"
	.string "ROCKET!\p"
	.string "Our grand finale is nearly complete!\p"
	.string "I won't let you interfere!$"

RocketHideoutGrunt18Defeat:
	.string "That battle may be my grand finale.$"

RocketHideoutGrunt18PostBattle:
	.string "My dedication to TEAM ROCKET will\n"
	.string "continue forever!$"

RocketHideoutGrunt19Intro:
	.string "Outside here you'll find the rocket\n"
	.string "we've spent the past year building.\p"
	.string "Or at least you would if you were\n"
	.string "able to defeat me!$"

RocketHideoutGrunt19Defeat:
	.string "I guess you'll see the\n"
	.string "rocket afterall.$"

RocketHideoutGrunt19PostBattle:
	.string "You may still be too late!\p"
	.string "The boss will be boarding any moment!$"
