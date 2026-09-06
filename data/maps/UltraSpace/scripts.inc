UltraSpace_MapScripts::
map_script MAP_SCRIPT_ON_FRAME_TABLE, Ultra_Space_OnFrame
	.byte 0

Ultra_Space_OnFrame:
	map_script_2 VAR_DISTORTION_WORLD_STATE, 10, UltraSpaceEventScript
	.2byte 0

UltraSpaceEventScript::
	lockall
	destroyfollowernpc
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement
	delay 60
	msgbox StevenUltraSpace1, MSGBOX_AUTOCLOSE
	delay 30
	msgbox ArceusUltraSpace1, MSGBOX_AUTOCLOSE
	applymovement LOCALID_ARCEUS_SPACE, WalkToDeoxys
	applymovement LOCALID_STEVEN_SPACE, WalkToDeoxys
	delay 15
	applymovement LOCALID_PLAYER, WalkToDeoxys
	waitmovement
	msgbox StevenUltraSpace2, MSGBOX_AUTOCLOSE
	delay 30
	msgbox ArceusUltraSpace2, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_DEOXYS_SPEED, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_DEOXYS_DEFENSE, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_DEOXYS_ATTACK, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_DEOXYS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox StevenUltraSpace3, MSGBOX_AUTOCLOSE
	applymovement LOCALID_DEOA, DeoxysAMovement
	applymovement LOCALID_DEON, DeoxysNMovement
	applymovement LOCALID_DEOD, DeoxysDMovement
	applymovement LOCALID_DEOS, DeoxysSMovement
	waitmovementall
	clearflag FLAG_NO_CATCH_WILD
	setflag FLAG_NO_WHITE_OUT
	addvar VAR_DISTORTION_WORLD_STATE, 1
	settotemboost B_POSITION_OPPONENT_RIGHT, 2, 2, 2, 2, 2
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 2, 2, 2, 2
	setwildbattle SPECIES_DEOXYS_DEFENSE, 94, ITEM_NONE, SPECIES_DEOXYS_SPEED, 94, ITEM_NONE
	playmoncry SPECIES_DEOXYS_SPEED, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_DEOXYS_DEFENSE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_DEOA
	removeobject LOCALID_DEOS
	removeobject LOCALID_DEOD
	removeobject LOCALID_DEON
	special HealPlayerParty
	clearflag FLAG_NO_WHITE_OUT
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_ARCEUS
	clearflag FLAG_STEVEN_CASTLE_DIST
	call ShowPlayerCastleClone
	addvar VAR_STEVEN_MF_STATE, 1
	fadescreenswapbuffers FADE_FROM_BLACK
	applymovement LOCALID_STEVEN_SPACE, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement
	msgbox PostDeoxysSteven1, MSGBOX_AUTOCLOSE
	delay 30
	applymovement LOCALID_ARCEUS_SPACE, Common_Movement_FaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement
	msgbox PostDeoxysArceus1, MSGBOX_AUTOCLOSE
	waitmessage
	delay 60
	warp MAP_METEOR_CASTLE_THRONE_ROOM, 15, 20
	waitstate
	releaseall
	end

WalkToDeoxys:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DeoxysAMovement:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

DeoxysNMovement:
	walk_down
	walk_down
	walk_down
	face_left
	step_end

DeoxysDMovement:
	walk_down
	step_end

DeoxysSMovement:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	face_up
	step_end

StevenUltraSpace1:
	.string "Steven: So this is Ultra Space\p"
	.string "It's so... empty.$"

ArceusUltraSpace1:
	.string "Arceus: I sense… chaos ahead…\p"
	.string "Beings of space… have gone rogue\n"
	.string "from excess energy…\p"
	.string "We must calm them to proceed.$"

StevenUltraSpace2:
	.string "Steven: Whoah, those are Deoxys!\n"
	.string "I've read about them.\p"
	.string "They are said to originate from\n"
	.string "meteors and can take on different\l"
	.string "forms focusing on attack, defense,\l"
	.string "or speed.$"

ArceusUltraSpace2:
	.string "Arceus: Deoxys…\p"
	.string "We wish to pass through Ultra Space\n"
	.string "to save the universe…\p"
	.string "Please let us proceed…$"

StevenUltraSpace3:	
	.string "Steven: I don't think they're\n"
	.string "happy to see us!\p"
	.string "{PLAYER}!\n"
	.string "Look out!$"

PostDeoxysSteven1:
	.string "Steven: It seems that the Deoxys\n"
	.string "calmed down after we battled them.\p"
	.string "They just needed to release some\n"
	.string "of that excess energy.$"

PostDeoxysArceus1:
	.string "Arceus: The path is clear from here.\p"
	.string "We can make our way back to your\n"
	.string "world by continuing along this path.\p"
	.string "There's no time to waste.\p"
	.string "If we do, there might never be\n"
	.string "time to waste again.$"

ShowPlayerCastleClone::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, CastleShowMale
	goto_if_eq VAR_RESULT, FEMALE, CastleShowFemale
	return

CastleShowMale::
	clearflag FLAG_CASTLE_MALE_PLAYER
	return

CastleShowFemale::
	clearflag FLAG_CASTLE_FEMALE_PLAYER
	return
