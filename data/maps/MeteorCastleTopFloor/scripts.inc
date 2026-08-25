MeteorCastleTopFloor_MapScripts::
	.byte 0

MeteorCastle_Fossils_Enter::
	lockall
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_OMASTAR, CRY_MODE_ENCOUNTER
	applymovement LOCALID_TOTEM_KABU, Kabutops_Movement1
	applymovement LOCALID_TOTEM_HELIX, Omastar_Movement1
	waitmovement
	setweather WEATHER_RAIN
	doweather
	delay 60
	applymovement LOCALID_TOTEM_KABU, Kabutops_Movement2
	applymovement LOCALID_TOTEM_HELIX, Omastar_Movement2
	goto MeteorCastleFossilsBattle

MeteorCastleFossilsBattle::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 2, 1, 2, 1
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 2, 1, 2, 1
	setwildbattle SPECIES_KABUTOPS, 94, ITEM_MUSCLE_BAND, SPECIES_OMASTAR, 94, ITEM_WISE_GLASSES
	waitse
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_OMASTAR, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RogueFossilsDefeated
	releaseall
	end

RogueFossilsDefeated::
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setvar VAR_ROGUE_STATE, 21
	resetweather
	doweather
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_OMASTAR, CRY_MODE_ENCOUNTER
	applymovement LOCALID_TOTEM_KABU, Kabutops_Movement3
	applymovement LOCALID_TOTEM_HELIX, Omastar_Movement3
	waitmovement
	waitmovement
	removeobject LOCALID_TOTEM_KABU
	removeobject LOCALID_TOTEM_HELIX
	releaseall
	end

Kabutops_Movement1:
	walk_down
	walk_down
	walk_left
	delay_16
	delay_8
	walk_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_up
	delay_16
	delay_8
	face_right
	delay_16
	delay_8
	face_down
	step_end

Omastar_Movement1:
	walk_down
	walk_down
	walk_right
	delay_16
	delay_8
	walk_left
	delay_16
	delay_8
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	step_end

Kabutops_Movement2:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

Omastar_Movement2:
	walk_down
	walk_down
	walk_down
	face_left
	step_end

Kabutops_Movement3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Omastar_Movement3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorCastleJugulis_Enter::
	lockall
	playmoncry SPECIES_IRON_JUGULIS, CRY_MODE_ENCOUNTER
	applymovement LOCALID_TOTEM_JUG, Jug_Movement1
	goto MeteorCastleJugulisBattle

MeteorCastleJugulisBattle::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 2, 2, 2
	setwildbattle SPECIES_IRON_JUGULIS, 94, ITEM_LIFE_ORB
	waitse
	playmoncry SPECIES_IRON_JUGULIS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartTeraWildBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Jugulis_Defeated
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	releaseall
	end

Jugulis_Defeated::
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setvar VAR_ROGUE_STATE, 22 
	playmoncry SPECIES_IRON_JUGULIS, CRY_MODE_ENCOUNTER
	applymovement LOCALID_TOTEM_JUG, Jug_Movement2
	waitmovement
	removeobject LOCALID_TOTEM_JUG
	releaseall
	end

Jug_Movement1:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Jug_Movement2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MeteorCastleOrbeetle_Enter::
	lockall
	playmoncry SPECIES_ORBEETLE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_TOTEM_BEETLE, Beetle_Movement1
	goto MeteorCastleBeetleBattle

MeteorCastleBeetleBattle::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 2, 2, 2
	setwildbattle SPECIES_ORBEETLE, 94, ITEM_ASSAULT_VEST
	waitse
	playmoncry SPECIES_ORBEETLE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartGigantamaxWildBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Beetle_Defeated
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	releaseall
	end

Beetle_Defeated::
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setvar VAR_ROGUE_STATE, 23 
	playmoncry SPECIES_ORBEETLE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_TOTEM_BEETLE, Beetle_Movement2
	waitmovement
	removeobject LOCALID_TOTEM_BEETLE
	pokenavcall StevenCastleCall
	releaseall
	end

Beetle_Movement1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Beetle_Movement2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

StevenCastleCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Steven: Hey, {PLAYER}{KUN}!\p"
	.string "You should almost be at the\n"
	.string "throne room by now.\p"
	.string "Be warned, there is a massive\n"
	.string "concentration of energy just\l"
	.string "ahead of you.\p"
	.string "I'll be right behind you once\n"
	.string "I calm down this rogue Iron\l"
	.string "Valiant but please don't wait!\p"
	.string "I'll catch up when I can but\n"
	.string "we need to resolve this as\l"
	.string "soon as possible!\p"
	.string "This is what you've been\n"
	.string "training for {PLAYER}{KUN}!\p"
	.string "Good luck!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

MeteorCastleNecrozma_Enter::
	lockall
	playbgm MUS_NONE, TRUE
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement
	delay 60
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement
	delay 60
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, CameraPantoNecrozma1
	waitmovement
	playse SE_M_COSMIC_POWER
	waitse
	setvar VAR_0x8004, 3  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	addobject LOCALID_ULTRA_NECRO
	playmoncry SPECIES_NECROZMA_ULTRA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 120
	applymovement LOCALID_CAMERA, CameraPanAwayNecro
	waitmovement
	special RemoveCameraObject
	delay 150
	applymovement LOCALID_ULTRA_NECRO, Necro_Movement1
	setvar VAR_0x8004, 5  @ vertical pan
	setvar VAR_0x8005, 5  @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	goto MeteorCastleNecrozmaBattle

MeteorCastleNecrozmaBattle::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	setflag FLAG_TOTEM_ULTRA_NECROZMA
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 2, 2, 1, 2
	setwildbattle SPECIES_NECROZMA_ULTRA, 94, ITEM_SHELL_BELL
	waitse
	playmoncry SPECIES_NECROZMA_ULTRA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Necro_Defeated
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	releaseall
	end

Necro_Defeated::
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	clearflag FLAG_TOTEM_NECROZMA
	setvar VAR_ROGUE_STATE, 24 
	fadescreenswapbuffers FADE_TO_BLACK
	playmoncry SPECIES_NECROZMA_ULTRA, CRY_MODE_ENCOUNTER
	waitmoncry
	removeobject LOCALID_ULTRA_NECRO
	addobject LOCALID_STEVEN_CASTLE_TOP
	playse SE_M_COSMIC_POWER
	waitse
	fadescreenswapbuffers FADE_FROM_BLACK
	playbgm MUS_NCASTLE, TRUE
	applymovement LOCALID_PLAYER, PlayerMoveRightCastle
	applymovement LOCALID_STEVEN_CASTLE_TOP, Steven_Climb_Stairs
	waitmovement LOCALID_STEVEN_CASTLE_TOP 
	msgbox NecroDefeated_Text, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement LOCALID_STEVEN_CASTLE_TOP, StevenEnterThroneRoom
	waitmovement
	removeobject LOCALID_STEVEN_CASTLE_TOP
	playse SE_DOOR
	waitse
	releaseall
	end

CameraPantoNecrozma1:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

Necro_Movement1:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

CameraPanAwayNecro:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

Steven_Climb_Stairs:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

NecroDefeated_Text:
	.string "{PLAYER}{KUN}, I got here\n"
	.string "as quickly as I could.\p"
	.string "So I was right.\p"
	.string "It was Ultra Necrozma that was\n"
	.string "responsible for everything.\p"
	.string "Just as it tried to destroy Hoenn\n"
	.string "in ancient times it once again\l"
	.string "attempted to cause chaos.\p"
	.string "Thanks to you, Necrozma has been\n"
	.string "sent back to its own dimension\l"
	.string "once again, hopefully for good.\p"
	.string "Still, after all these years why\n"
	.string "was it now that Necrozma was able\l"
	.string "to return?\p"
	.string "Something must have weakened the\n"
	.string "barrier between our worlds, allowing\l"
	.string "Necrozma to cross into our dimension.\p"
	.string "Hmmm...\p"
	.string "The energy spikes appear to be gone,\n"
	.string "but there is still residual energy\l"
	.string "leaking out of the throne room.\p"
	.string "{PLAYER}{KUN}, we should investigate\n"
	.string "the throne room.\p"
	.string "While Necrozma has been banished once\n"
	.string "again thanks to you, it's possible\l"
	.string "Necrozma wasn't the only pokémon\l"
	.string "that crossed into our dimension.\p"
	.string "If there are others, we'll need to\n"
	.string "prevent them from escaping as well.$"

StevenEnterThroneRoom:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PlayerMoveRightCastle:
	walk_right
	face_left
	step_end
