MeteorCastle_MapScripts::
	.byte 0

MeteorCastle_Steven_Script::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_MF_STEVEN3, Common_Movement_FaceRight
	waitmovement 0
	msgbox MeteorCastle_Steven_Text, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MF_STEVEN3, MeteorCastle_Steven_Movement
	waitmovement 0
	removeobject LOCALID_MF_STEVEN3
	playse SE_DOOR
	setvar VAR_STEVEN_MF_STATE, 3
	releaseall
	end

MeteorCastle_Steven_Text:
	.string "I don't understand.\p"
	.string "I thought this was as deep as\n"
	.string "METEOR FALLS went.\p"
	.string "Unless...\n"
	.string "The legends were true...\p"
	.string "Well, here goes nothing.\p"
	.string "There's clearly more of the\n"
	.string "cave system to explore.\p"
	.string "{PLAYER}, you and I may both be\n"
	.string "in for a shock when we walk through\l"
	.string "that door.$"

MeteorCastle_Steven_Movement:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
