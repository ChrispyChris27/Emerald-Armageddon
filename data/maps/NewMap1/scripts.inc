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
	goto_if_eq VAR_ROCKET_HIDEOUT_STATE, 3, NewMap1_Move_Sister
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
	lockall
	goto_if_unset FLAG_HIDEOUT_SCIENTIST, Scientist_Gio_Meeting
	applymovement LOCALID_GIO, Common_Movement_FacePlayer
	msgbox Hideout_GioIntro2
	trainerbattle_no_intro TRAINER_GIOVANNI_2, HideoutGioDefeat
	msgbox Hideout_GioExit1, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_GIO, GioMovement
	waitmovement 0
	msgbox Hideout_GioExit2, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_GIO, GioMovement
	waitmovement 0
	msgbox Hideout_GioExit3, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_NORMAL
	waitmoncry
	addobject LOCALID_RAY
	applymovement LOCALID_RAY, Rayquaza_Movement
	waitmovement 0
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_NORMAL
	applymovement LOCALID_GIO, GioMovement2
	waitmovement 0
	msgbox Hideout_GioExit4, MSGBOX_AUTOCLOSE
	applymovement LOCALID_GIO, Common_Movement_FaceLeft
	waitmovement 0
	msgbox Hideout_GioExit5, MSGBOX_AUTOCLOSE
	closemessage
	delay 20
	playse SE_M_DETECT
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	fadescreen FADE_TO_WHITE
	removeobject LOCALID_RAY
	clearflag FLAG_HIDEOUT_MEGA_RAY
	addobject LOCALID_MEGARAY
	waitmovement 0
	delay 200
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_RAYQUAZA_MEGA, CRY_MODE_NORMAL
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 24  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 150
	playmoncry SPECIES_RAYQUAZA_MEGA, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_GIO, Common_Movement_FaceDown
	msgbox Hideout_GioExit6, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_RAYQUAZA_MEGA, CRY_MODE_NORMAL
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_GIO, Common_Movement_FaceLeft
	waitmovement 0
	msgbox Hideout_GioExit7, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_RAYQUAZA_MEGA, CRY_MODE_NORMAL
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_GIO, Common_Movement_FaceDown
	waitmovement 0
	msgbox Hideout_GioExit8, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_RAYQUAZA_MEGA, CRY_MODE_NORMAL
	setvar VAR_0x8004, 3  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_MEGARAY, Rayquaza_Descends
	waitmovement 0
	playmoncry SPECIES_RAYQUAZA_MEGA, CRY_MODE_NORMAL
	setvar VAR_0x8004, 4  @ vertical pan
	setvar VAR_0x8005, 4  @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	setvar VAR_ROCKET_HIDEOUT_STATE, 3
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1
	setwildbattle SPECIES_RAYQUAZA_MEGA, 90, ITEM_METEORITE
	special BattleSetup_StartLegendaryBattle
	waitstate
	playmoncry SPECIES_RAYQUAZA_MEGA, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_MEGARAY, Rayquaza_Leaves
	waitmovement 0
	removeobject LOCALID_MEGARAY
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox Hideout_GioExit9, MSGBOX_AUTOCLOSE
	delay 32
	applymovement LOCALID_GIO, Common_Movement_FaceDown
	waitmovement 0
	msgbox Hideout_GioExit10, MSGBOX_AUTOCLOSE
	delay 32
	applymovement LOCALID_GIO, Common_Movement_FaceUp
	waitmovement 0
	msgbox Hideout_GioExit11, MSGBOX_AUTOCLOSE
	delay 32
	applymovement LOCALID_GIO, Common_Movement_FaceDown
	waitmovement 0
	msgbox Hideout_GioExit12, MSGBOX_AUTOCLOSE
	giveitem ITEM_KANGASKHANITE
	msgbox Hideout_GioExit13, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK 
	removeobject LOCALID_GIO
	removeobject LOCALID_SIS1
	removeobject LOCALID_SIS2
	removeobject LOCALID_SIS3
	removeobject LOCALID_ARIANA
	removeobject LOCALID_ARCHER
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setflag FLAG_HIDEOUT_GIOVANNI
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setvar VAR_ROCKET_HIDEOUT_STATE, 4
	fadescreen FADE_FROM_BLACK
	releaseall
	end

RayquazaShakes::
	lockall
	playmoncry SPECIES_RAYQUAZA_MEGA, CRY_MODE_NORMAL
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	releaseall
	end

RayquazaBattle::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_MEGARAY, Rayquaza_Descends
	waitmovement 0
	playmoncry SPECIES_RAYQUAZA_MEGA, CRY_MODE_NORMAL
	setvar VAR_0x8004, 4  @ vertical pan
	setvar VAR_0x8005, 4  @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	setwildbattle SPECIES_RAYQUAZA_MEGA, 90, ITEM_METEORITE
	special BattleSetup_StartLegendaryBattle
	waitstate
	playmoncry SPECIES_RAYQUAZA_MEGA, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_MEGARAY, Rayquaza_Leaves
	waitmovement 0
	removeobject LOCALID_MEGARAY
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox Hideout_GioExit9, MSGBOX_AUTOCLOSE
	delay 32
	applymovement LOCALID_GIO, Common_Movement_FaceDown
	waitmovement 0
	msgbox Hideout_GioExit10, MSGBOX_AUTOCLOSE
	delay 32
	applymovement LOCALID_GIO, Common_Movement_FaceUp
	waitmovement 0
	msgbox Hideout_GioExit11, MSGBOX_AUTOCLOSE
	delay 32
	applymovement LOCALID_GIO, Common_Movement_FaceDown
	waitmovement 0
	msgbox Hideout_GioExit12, MSGBOX_AUTOCLOSE
	giveitem ITEM_KANGASKHANITE
	msgbox Hideout_GioExit13, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK 
	removeobject LOCALID_GIO
	removeobject LOCALID_SIS1
	removeobject LOCALID_SIS2
	removeobject LOCALID_SIS3
	removeobject LOCALID_ARIANA
	removeobject LOCALID_ARCHER
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setflag FLAG_HIDEOUT_GIOVANNI
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setvar VAR_ROCKET_HIDEOUT_STATE, 4
	fadescreen FADE_FROM_BLACK
	releaseall
	end

Scientist_Gio_Meeting::
	applymovement LOCALID_SCI, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Hideout_ScientistIntro, MSGBOX_AUTOCLOSE
	applymovement LOCALID_GIO, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Hideout_GioIntro1, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SCI, Common_Movement_FaceUp
	waitmovement 0
	removeobject LOCALID_SCI
	playse SE_DOOR
	delay 32
	goto NewMap1_EventScript_Giovanni

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

Hideout_ScientistIntro:
	.string "The fuel tanks are loaded and all\n"
	.string "systems are functioning properly.\p"
	.string "We are ready to start boarding!$"

Hideout_GioIntro1:
	.string "Excellent.\p"
	.string "Prepare the crew for departure.$"

Hideout_GioIntro2:
	.string "You again.\p"
	.string "Haven't you meddled in my affairs\n"
	.string "enough already?\p"
	.string "Still I suppose I owe you some\n"
	.string "measure of gratitude.\p"
	.string "You may have bested all of my grunts,\n"
	.string "but you were also of great help to us.\p"
	.string "It was you after all that found and\n"
	.string "summoned the great RAYQUAZA alerting\l"
	.string "us to its location.\p"
	.string "After resolving the conflict between\n"
	.string "KYOGRE and GROUDON, we witnessed\l"
	.string "RAYQUAZA return to the sky.\p"
	.string "We had suspected that there was a link\n"
	.string "between RAYQUAZA and outer space which\l"
	.string "is why we swiped the rocket fuel from\l"
	.string "the SPACE CENTER.\p"
	.string "Thanks to you, we've confirmed our\n"
	.string "suspicions were correct.\p"
	.string "Now that RAYQUAZA has returned to\n"
	.string "outer space, I too must follow!\p"
	.string "The most powerful POKéMON out of this\n"
	.string "world will soon be mine!\p"
	.string "There is just one more task that must\n"
	.string "be completed before I board this rocket\l"
	.string "and fulfill my dreams.\p"
	.string "I must vanquish you once and for all!$"

HideoutGioDefeat:
	.string "Inconceivable!\n"
	.string "Yet again I have lost!$"

Hideout_GioExit1:
	.string "Blast it all!\p"
	.string "I don't care that you've beaten\n"
	.string "me yet again!\p"
	.string "RAYQUAZA shall be mine!$"

Hideout_GioExit2:
	.string "That sound...\p"
	.string "I recognize it...$"

Hideout_GioExit3:
	.string "RAYQUAZA!\p"
	.string "Is that you?!?!$"

Hideout_GioExit4:
	.string "Fwahahaha!\p"
	.string "It would appear that my trip to\n"
	.string "space is no longer necessary!\p"
	.string "RAYQUAZA has come to me on its own!$"

Hideout_GioExit5:
	.string "RAYQUAZA!\p"
	.string "I have in my possession the\n"
	.string "METEORITE you need to unlock\l"
	.string "your true power!\p"
	.string "Join me and we shall conquer all\n"
	.string "of HOENN!$"

Hideout_GioExit6:
	.string "Fwahahaha!\p"
	.string "Behold the true power of RAYQUAZA!\p"
	.string "With MEGA RAYQUAZA at my command\n"
	.string "I will be truly unstoppable!$"

Hideout_GioExit7:
	.string "RAYQUAZA, what are you doing?!?\p"
	.string "Why won't you listen to me?!?$"

Hideout_GioExit8:
	.string "RAYQUAZA is going berserk!\p"
	.string "It is even more powerful than\n"
	.string "I could have imagined!\p"
	.string "I can't control it!\p"
	.string "{PLAYER}!\p"
	.string "You will have to calm RAYQUAZA\n"
	.string "before our entire hideout crumbles!$"

Hideout_GioExit9:
	.string ". . .\n"
	.string ". . .$"

Hideout_GioExit10:
	.string "There goes MEGA RAYQUAZA...\p"
	.string "Even the most powerful POKéMON\n"
	.string "was no match for you.$"

Hideout_GioExit11:
	.string "I have no use for this rocket\n"
	.string "anymore.\p"
	.string "There's no doubt that RAYQUAZA is\n"
	.string "long gone by now.\p"
	.string "Just like MAXIE and ARCHIE before me,\n"
	.string "I failed to achieve my dream.$"

Hideout_GioExit12:
	.string "Despite all that we did, you still\n"
	.string "saved us all by calming MEGA RAYQUAZA.\p"
	.string "Starting today, TEAM ROCKET will cease\n"
	.string "all operations in HOENN.\p"
	.string "I must come to terms with the fact that\n"
	.string "in the end it was my own weakness that\l"
	.string "prevented me from capturing RAYQUAZA.\p"
	.string "We will be abandoning this hideout now.\n"
	.string "Do with it as you see fit.\p"
	.string "As thanks for saving us all, please\n"
	.string "take this as well.$"

Hideout_GioExit13:
	.string "Perhaps one day, TEAM ROCKET will cross\n"
	.string "paths with you again.$"
	

Rayquaza_Leaves:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Rayquaza_Descends:
	walk_down
	face_right
	step_end

Rayquaza_Movement:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

GioMovement:
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	face_down
	delay_16
	step_end

GioMovement2:
	face_left
	delay_16
	delay_16
	face_down
	delay_16
	step_end
