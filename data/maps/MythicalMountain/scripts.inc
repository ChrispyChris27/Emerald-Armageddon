MythicalMountain_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MythicalMountainOnFrame
	.byte 0

MythicalMountainOnFrame::
	map_script_2 VAR_STEVEN_MF_STATE, 5, MythicalMountainArrival
	.2byte 0

StevenExplainMountainText:
	.string "{PLAYER}, welcome to\n"
	.string "MYTHICAL MOUNTAIN.\p"
	.string "Only very few people know of the\n"
	.string "existence of this island, and now\l"
	.string "you are one of them.\p"
	.string "At the top of the mountain, you\n"
	.string "will find POKéMON that don't exist\l"
	.string "anywhere else in HOENN.\p"
	.string "These POKéMON are incredibly rare\n"
	.string "and equally powerful.\p"
	.string "I imagine that some of them may be\n"
	.string "willing to join you in your quest\l"
	.string "to conquer the POKéMON LEAGUE.\p"
	.string "Feel free to explore the island to\n"
	.string "your heart's content.\p"
	.string "When you're ready to return to\n"
	.string "HOENN, let me know.$"

MythicalMountainArrival::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox StevenExplainMountainText, MSGBOX_AUTOCLOSE
	setvar VAR_STEVEN_MF_STATE, 6
	releaseall
	end

MythicalMountainSteven_Script::
	lockall
	call_if_eq VAR_FACING, DIR_SOUTH, StevenFaceSouth
	call_if_eq VAR_FACING, DIR_WEST, StevenFaceWest
	msgbox StevenReadytoReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MythicalMountainGo
	msgbox MythicalMountainStay, MSGBOX_AUTOCLOSE
	releaseall
	end 

MythicalMountainStay:
	.string "Take your time, there's plenty\n"
	.string "to explore up the mountain.\p"
	.string "When you're ready to return to\n"
	.string "HOENN, let me know.$"

StevenReadytoReturn:
	.string "{PLAYER}, I have some business to\n"
	.string "attend to upon our return to HOENN.\p"
	.string "Once we leave, you won't be able\n"
	.string "to return to MYTHICAL MOUNTAIN.\p"
	.string "Are you ready to return to HOENN?$"


MythicalMountainGo::
	lockall
	closemessage
	applymovement LOCALID_STEVEN_MM, Common_Movement_WalkDown
	waitmovement 0
	removeobject LOCALID_STEVEN_MM
	playse SE_DOOR
	waitse
	call_if_eq VAR_FACING, DIR_SOUTH, PlayerBoardSouthScript
	call_if_eq VAR_FACING, DIR_WEST, PlayerBoardWestScript
	playse SE_DOOR
	waitse
	delay 16
	setvar VAR_0x8004, LOCALID_MOUNTAIN_BOAT
	call Common_EventScript_FerryDepart
	warp MAP_LILYCOVE_CITY_HARBOR, 7, 10
	releaseall
	end

PlayerBoardSouthScript::
	applymovement OBJ_EVENT_ID_PLAYER, PlayerBoardSouth
	waitmovement 0
	return

PlayerBoardWestScript::
	applymovement OBJ_EVENT_ID_PLAYER, PlayerBoardWest
	waitmovement 0
	return

PlayerBoardSouth:
	walk_down
	walk_down
	set_invisible
	step_end

PlayerBoardWest:
	walk_down
	set_invisible
	step_end

StevenFaceSouth::
	applymovement LOCALID_STEVEN_MM, Common_Movement_FaceUp
	waitmovement 0
	return

StevenFaceWest::
	applymovement LOCALID_STEVEN_MM, Common_Movement_FaceRight
	waitmovement 0
	return
