SkyPillar_Top_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_Top_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Top_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SkyPillar_Top_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, SkyPillarTopOnLoad
	.byte 0

SkyPillar_Top_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SkyPillar_Top_EventScript_TryRemoveRayquaza
	end

SkyPillar_Top_EventScript_TryRemoveRayquaza::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

SkyPillar_Top_OnTransition:
	call_if_lt VAR_SKY_PILLAR_STATE, 2, SkyPillar_Top_EventScript_SetCleanLayout
	call_if_ge VAR_SKY_PILLAR_STATE, 2, SkyPillar_Top_EventScript_TryShowRayquaza
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call_if_set FLAG_SYS_WEATHER_CTRL, SkyPillarChangeMusic
	end

SkyPillar_Top_EventScript_SetCleanLayout::
	setmaplayoutindex LAYOUT_SKY_PILLAR_TOP_CLEAN
	setobjectmovementtype LOCALID_RAYQUAZA_SLEEPING, MOVEMENT_TYPE_FACE_DOWN
	return

SkyPillar_Top_EventScript_TryShowRayquaza::
	call_if_unset FLAG_DEFEATED_RAYQUAZA, SkyPillar_Top_EventScript_ShowRayquaza
	return

SkyPillar_Top_EventScript_ShowRayquaza::
	clearflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA_STILL
	return

SkyPillar_Top_OnWarp:
	map_script_2 VAR_SKY_PILLAR_STATE, 0, SkyPillar_Top_EventScript_RayquazaFaceDown
	.2byte 0

SkyPillar_Top_EventScript_RayquazaFaceDown::
	turnobject LOCALID_RAYQUAZA_SLEEPING, DIR_SOUTH
	end

SkyPillar_Top_EventScript_Rayquaza::
	lockall
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_RAYQUAZA, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SkyPillar_Top_EventScript_DefeatedRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SkyPillar_Top_EventScript_RanFromRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SkyPillar_Top_EventScript_RanFromRayquaza
	setflag FLAG_DEFEATED_RAYQUAZA
	releaseall
	end

SkyPillar_Top_EventScript_DefeatedRayquaza::
	setflag FLAG_DEFEATED_RAYQUAZA
	goto SkyPillar_Top_EventScript_DefeatedRayquaza2
	end

SkyPillar_Top_EventScript_RanFromRayquaza::
	setvar VAR_0x8004, SPECIES_RAYQUAZA
	goto SkyPillar_Top_EventScript_RanFromRayquaza2
	end

SkyPillar_Top_EventScript_DefeatedRayquaza2::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

SkyPillar_Top_EventScript_RanFromRayquaza2::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	releaseall
	end

SkyPillar_Top_EventScript_AwakenRayquaza::
	lockall
	fadeoutbgm 1
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SkyPillar_Top_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_RAYQUAZA_SLEEPING, SkyPillar_Top_Movement_RayquazaStir
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	applymovement LOCALID_RAYQUAZA_SLEEPING, SkyPillar_Top_Movement_RayquazaFlyOff
	waitmovement 0
	removeobject LOCALID_RAYQUAZA_SLEEPING
	msgbox SkyPillar_Top_Text_RayquazaFlewOff, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadeinbgm 1
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SkyPillar_Top_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 5
	setvar VAR_SKY_PILLAR_STATE, 1
	setvar VAR_SKY_PILLAR_RAYQUAZA_CRY_DONE, 2
	releaseall
	end

@ Rayquaza has unusual movement frames
@ See comments, or sAnimTable_Rayquaza
SkyPillar_Top_Movement_RayquazaStir:
	delay_16
	walk_in_place_left  @ Coiled, awake
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_left  @ Coiled, mouth open
	delay_16
	walk_in_place_right  @ Normal, awake
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SkyPillar_Top_Movement_RayquazaFlyOff:
	delay_16
	walk_in_place_down  @ Coiled, asleep
	delay_8
	walk_in_place_right  @ Normal, awake
	delay_8
	walk_faster_up  @ Fly up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

SkyPillar_Top_Movement_CameraPanUp:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

SkyPillar_Top_Movement_CameraPanDown:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

SkyPillar_Top_Text_RayquazaFlewOff:
	.string "The awakened RAYQUAZA flew off…$"

StevenErraticEmergency:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Steven: Hey, {PLAYER}{KUN}!\p"
	.string "You may have an emergency on your\n"
	.string "hands pretty quick!\p"
	.string "Archie and Maxie have left\n"
	.string "Sootopolis City!\p"
	.string "I overheard them talking about\n"
	.string "putting a stop to this themselves\l"
	.string "before they left shortly after\l"
	.string "Wallace did.\p"
	.string "I'm busy handling things here in\n"
	.string "Sootopolis but I called one of\l"
	.string "your friends who should be\l"
	.string "arriving as backup shortly!\p"
	.string "{PLAYER}{KUN} you have to stop\n"
	.string "Archie and Maxie and awaken\l"
	.string "Rayquaza at any cost!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

ArchieSkyPillarMovement:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	face_left
	step_end

MaxieSkyPillarMovement:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

WallySkyPillarMovement:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

ArchiePillar1:
	.string "Archie: {PLAYER}, thank you very\n"
	.string "much for leading us to Rayquaza!\p"
	.string "Unfortunately for you it's crucial\n"
	.string "that Maxie and I are the ones who\l"
	.string "awaken Rayquaza and save the day!\p"
	.string "To repay Hoenn for all the trouble\n"
	.string "we've caused we'll be the ones to\l"
	.string "take it from here!\p"
	.string "Please step out of the way!$"

MaxiePillar1:
	.string "Maxie: I must confess I wasn't sold\n"
	.string "on Archie's plan, and I hate the\l"
	.string "idea of teaming up with him.\p"
	.string "That being said, it would be fitting\n"
	.string "for us to be the ones to save the\l"
	.string "day after all the damage we've done.\p"
	.string "Unfortunately, I don't imagine you'll\n"
	.string "be letting us do this willingly, so I\l"
	.string "hope you're ready for a fight!$"

ArchiePillar2:
	.string "Archie: It's two against one!\p"
	.string "Why don't you just move aside\n"
	.string "and let us handle this!$"

WallyPillar1:
	.string "{PLAYER}!\n"
	.string "I'm here!$"

WallyPillar2:
	.string "Wally: {PLAYER}, I came here as soon\n"
	.string "as I got word from Steven!\p"
	.string "He said you might need some assitance.\p"
	.string "I hope I've grown strong enough to be\n"
	.string "of some actual help, but I'll try\l"
	.string "my absolute hardest!$"

MaxiePillar2:
	.string "Maxie: So it's two on two afterall.\p"
	.string "I'd call that a fair fight.\p"
	.string "Prepare to step aside and let us\n"
	.string "right our wrongs!$"

MaxieDoubleDefeated:
	.string "Very well, you shall right\n"
	.string "our wrongs once again.$"

ArchieDoubleDefeated:
	.string "This is all Maxie's fault!\n"
	.string "I could have taken you down!$"

ArchiePillar3:
	.string "Archie: ………\p"
	.string "We really have caused irreperable\n"
	.string "harm to Hoenn…\p"
	.string "I think it's time to hang it up…$"

MaxiePillar3:
	.string "Maxie: {PLAYER}, please awaken\n"
	.string "Rayquaza and undo our mistakes.\p"
	.string "We will return to Sootopolis and\n"
	.string "do what we can to make amends there.$"

WallyPillar3:
	.string "Wally: We did it {PLAYER}!\p"
	.string "I knew you were strong but I wasn't\n"
	.string "sure I really had what it takes.\p"
	.string "I'm headed back home to my family,\n"
	.string "please awaken Rayquaza and save Hoenn!$"

WallyPostWhiteOut:
	.string "I'm ready when you are {PLAYER}!\n"
	.string "We have to stop Archie and Maxie!$"

SkyPillar_Top_EventScript_DoubleBattle::
	lockall
	pokenavcall StevenErraticEmergency
	waitmessage
	playse SE_DOOR
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	addobject LOCALID_PILLAR_ARCHIE
	delay 16
	applymovement LOCALID_PILLAR_ARCHIE, Common_Movement_WalkLeft
	waitmovement
	playse SE_DOOR
	addobject LOCALID_PILLAR_MAXIE
	delay 16
	applymovement LOCALID_PILLAR_ARCHIE, ArchieSkyPillarMovement
	applymovement LOCALID_PILLAR_MAXIE, MaxieSkyPillarMovement
	waitmovement
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement
	msgbox ArchiePillar1, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement
	msgbox MaxiePillar1, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement
	msgbox ArchiePillar2, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement
	msgbox WallyPillar1, MSGBOX_AUTOCLOSE
	waitmessage
	playse SE_DOOR
	addobject LOCALID_PILLAR_WALLY
	clearflag FLAG_PILLAR_BOSSES
	clearflag FLAG_PILLAR_WALLY
	setvar VAR_SKY_PILLAR_RAYQUAZA_CRY_DONE, 1
	applymovement LOCALID_PILLAR_WALLY, WallySkyPillarMovement
	waitmovement
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	msgbox WallyPillar2, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement
	msgbox MaxiePillar2, MSGBOX_AUTOCLOSE
	closemessage
	multi_2_vs_2 TRAINER_MAXIE_DOUBLE, MaxieDoubleDefeated, TRAINER_ARCHIE_DOUBLE, ArchieDoubleDefeated, PARTNER_WALLY
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SkyPillarVictoryDouble
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut

SkyPillarVictoryDouble::
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement
	msgbox ArchiePillar3, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement
	msgbox MaxiePillar3, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_PILLAR_MAXIE
	removeobject LOCALID_PILLAR_ARCHIE
	setflag FLAG_ERRATIC_12V12
	fadescreenswapbuffers FADE_FROM_BLACK
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement
	msgbox WallyPillar3, MSGBOX_AUTOCLOSE
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_PILLAR_WALLY
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

SkyPillarChangeMusic::
	playbgm MUS_ABNORMAL_WEATHER, TRUE 
	return

SkyPillarMaxieScriptAfterWhiteOut::
	lockall
	msgbox MaxiePillar2, MSGBOX_NPC
	closemessage
	multi_2_vs_2 TRAINER_MAXIE_DOUBLE, MaxieDoubleDefeated, TRAINER_ARCHIE_DOUBLE, ArchieDoubleDefeated, PARTNER_WALLY
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SkyPillarVictoryDoubleAfterWhiteOut
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut

SkyPillarWallyScriptAfterWhiteOut::
	msgbox WallyPostWhiteOut, MSGBOX_NPC
	end

SkyPillarTopSetPositionsForBattle::
	setobjectxyperm LOCALID_PILLAR_WALLY, 15, 12
	setobjectmovementtype LOCALID_PILLAR_WALLY, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_PILLAR_ARCHIE, 15, 11
	setobjectxyperm LOCALID_PILLAR_MAXIE, 14, 11
	end

SkyPillarVictoryDoubleAfterWhiteOut::
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement
	msgbox ArchiePillar3, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement
	msgbox MaxiePillar3, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_PILLAR_MAXIE
	removeobject LOCALID_PILLAR_ARCHIE
	setflag FLAG_ERRATIC_12V12
	fadescreenswapbuffers FADE_FROM_BLACK
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_PILLAR_WALLY, Common_Movement_FaceLeft
	waitmovement
	msgbox WallyPillar3, MSGBOX_AUTOCLOSE
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_PILLAR_WALLY
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

SkyPillarTopOnLoad::
call_if_eq VAR_SKY_PILLAR_RAYQUAZA_CRY_DONE, 1, SkyPillarTopSetPositionsForBattle
end

