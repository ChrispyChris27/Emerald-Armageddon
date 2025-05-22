.set LOCALID_SIS1, 4
.set LOCALID_SIS2, 5
.set LOCALID_SIS3, 6

NewMap1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewMap1_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewMap1_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, NewMap1_OnTransition
	.byte 0

NewMap1_OnLoad::
	setvar VAR_UNUSED_0x40F7, 0
	end

NewMap1_OnTransition::
	goto_if_eq VAR_ROCKET_HIDEOUT_STATE, 2, NewMap1_Move_Sister
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
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox SistersExit, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SIS2, SisterMovement
	waitmovement 0
	setvar VAR_ROCKET_HIDEOUT_STATE, 2
	setobjectxyperm LOCALID_SIS2, 37, 22
	setobjectmovementtype LOCALID_SIS2, MOVEMENT_TYPE_FACE_LEFT
	releaseall
	end
	
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
	.string "We aren't going to fail like our\n"
	.string "brothers did, are we?$"

Sister3Intro:
	.string "Not if I have anything to\n"
	.string "say about it!\p"
	.string "I'm going to crush you once\n"
	.string "and for all!$"

Sister3Defeat:
	.string "No!\n"
	.string "How could we fail?!?!$"

Sister3Exit:
	.string "We let TEAM ROCKET down.\p"
	.string "We have no choice but to beg\n"
	.string "for forgiveness!$"

SistersExit:
	.string "Go ahead and tell the boss we're\n"
	.string "sorry we didn't stop you.$"

SisterBonus:
	.string "We're just as useless as our brothers.$"

NewMap1_Move_Sister::
	setobjectxyperm LOCALID_SIS2, 37, 22
	setobjectmovementtype LOCALID_SIS2, MOVEMENT_TYPE_FACE_LEFT
	end

SisterMovement:
	walk_right
	face_left
	step_end

Sister1Script::
	msgbox SisterBonus, MSGBOX_NPC
	end

Sister2Script::
	msgbox SistersExit, MSGBOX_NPC
	end

Sister3Script::
	msgbox Sister3Exit, MSGBOX_NPC
	end

Archer_Hideout_Script::
	trainerbattle_single TRAINER_ARCHER_2, Hideout_Archer_Intro, Hideout_Archer_Defeat
	msgbox Hideout_Archer_PostBattle, MSGBOX_AUTOCLOSE
	end

Ariana_Hideout_Script::
	trainerbattle_single TRAINER_ARIANA_2, Hideout_Ariana_Intro, Hideout_Ariana_Defeat
	msgbox Hideout_Ariana_PostBattle, MSGBOX_AUTOCLOSE
	end

Hideout_Archer_Intro:
	.string "We owe a lot of thanks to TEAM\n"
	.string "MAGMA and AQUA, as well as you.\p"
	.string "Their mess caused you to awaken\n"
	.string "RAYQUAZA, which alerted us to its\l"
	.string "presence as well.\p"
	.string "Long ago, RAYQUAZA descended from\n"
	.string "space, which explains why its true\l"
	.string "power is unlocked with the aid of\l"
	.string "the meteorites we've been studying.\p"
	.string "It would appear RAYQUAZA has returned\n"
	.string "to the skies after calming GROUDON\l"
	.string "and KYOGRE.\p"
	.string "The boss is about to board our rocket\n"
	.string "to find and capture RAYQUAZA and it's\l"
	.string "our job to make sure he can!$"

Hideout_Ariana_Intro:
	.string "You again!?!\p"
	.string "Didn't you meddle in our affairs\n"
	.string "enough at the SPACE CENTER?\p"
	.string "Even with your interference, we\n"
	.string "still made off with the rocket fuel\l"
	.string "and we're moments from using it!\p"
	.string "That's right.\p"
	.string "Up these stairs the boss is ready\n"
	.string "to board to go after RAYQUAZA.$"

Hideout_Ariana_Defeat:
	.string "Impossible!\n"
	.string "You've bested us yet again!$"

Hideout_Archer_Defeat:
	.string "No matter!\n"
	.string "The boss will stop you himself!$"

Hideout_Archer_PostBattle:
	.string "GIOVANNI is up these steps.\p"
	.string "He'll be wiping the floor with you.$"

Hideout_Ariana_PostBattle:
	.string "If you intend to intervene further,\n"
	.string "you'll have to act fast.\p"
	.string "Lift off will be any minute now!$"
