MeteorCastle2_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MeteorCastle2_OnFrame
	.byte 0

MeteorCastle2_OnFrame::
	map_script_2 VAR_STEVEN_MF_STATE, 3, MeteorCastle2_EventSCript
	.2byte 0

MeteorCastle2_EventSCript::
	lockall
	msgbox MC_Steven1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MCPlayerUp
	waitmovement 0
	applymovement LOCALID_MF_STEVEN4, Common_Movement_FaceDown
	msgbox MC_Steven2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MF_STEVEN4, StevenMoveAround
	waitmovement 0
	msgbox MC_Steven3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MF_STEVEN4, StevenLeave
	waitmovement 0
	removeobject LOCALID_MF_STEVEN4
	setvar VAR_STEVEN_MF_STATE, 4
	releaseall
	end

StevenMoveAround:
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

StevenLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MCPlayerUp:
	walk_up
	walk_up
	step_end

MC_Steven1:
	.string "I don't believe it.\p"
	.string "The legends really were true...$"

MC_Steven2:
	.string "{PLAYER}, welcome to the METEOR\n"
	.string "CASTLE.\p"
	.string "I didn't believe it truly existed,\n"
	.string "but I certainly believe it now.\p"
	.string "Legends said that long ago, an ancient\n"
	.string "ruler constructed the METEOR CASTLE by\l"
	.string "digging into the bedrock deep within\l"
	.string "METEOR FALLS.\p"
	.string "With the help of his servants as well\n"
	.string "as his POKéMON, the ruler created the\l"
	.string "castle for all of them to live in.\p"
	.string "Years later, the ruler passed away,\n"
	.string "leaving the keys to his kingdom with\l"
	.string "his son.\p"
	.string "Unlike his father, the son did not\n"
	.string "appreciate sharing the castle with\l"
	.string "all of his father's servants.\p"
	.string "The son wanted the castle all to\n"
	.string "himself and exiled the servants out\l"
	.string "of METEOR CASTLE.\p"
	.string "As revenge for this act, the servants,\n"
	.string "their families, and their POKéMON\l"
	.string "sealed the castle away within METEOR\l"
	.string "FALLS, leaving the new king inside.\p"
	.string "Presumably, the king starved to death\n"
	.string "after being sealed away.$"

MC_Steven3:
	.string "The energy readings are coming from\n"
	.string "the top of METEOR CASTLE.\p"
	.string "I'm guessing that whatever is causing\n"
	.string "the energy surge may be coming from\l"
	.string "the throne room of the castle.\p"
	.string "It's a long ways up from here.\n"
	.string "I'll meet you at the top.$"

