MeteorCastleThroneRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MeteorCastleThroneRoom_OnFrame
	.byte 0

MeteorCastleThroneRoom_OnFrame::
	map_script_2 VAR_STEVEN_MF_STATE, 4, Cyrus_Event_Script
	.2byte 0

Cyrus_Event_Script::
	lockall
	special StopMapMusic
	msgbox StevenStop, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_GIRATINA, CRY_MODE_NORMAL
	waitmoncry
	applymovement OBJ_EVENT_ID_PLAYER, PlayerApproach
	waitmovement 0
	playmoncry SPECIES_DIALGA, CRY_MODE_NORMAL
	waitmoncry
	playmoncry SPECIES_PALKIA, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_CYRUS, Common_Movement_FaceDown
	waitmovement 0
	msgbox Cyrus_Text1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MF_STEVEN5, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox ThroneRoomStevenText1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CYRUS, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Cyrus_Text2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CYRUS, CyrusDeffeat1







StevenStop:
.string "{PLAYER}! Look out!$"

PlayerApproach:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Cyrus_Text1:
	.string "And who might you be?\p"
	.string ". . .\p"
	.string "So your name is {PLAYER}.\p"
	.string "Your friend STEVEN warned me\n"
	.string "somebody else would be coming.\p"
	.string "My name is CYRUS.\p"
	.string "Long ago I led TEAM GALACTIC in\n"
	.string "the SINNOH region until I entered\l"
	.string "another dimension in my quest to\l"
	.string "form a new world.\p"
	.string "At long last, I have escaped from\n"
	.string "that prison back into this world!\p"
	.string "I hear that I have two mad scientists\n"
	.string "to thank for that stroke of luck.\p"
	.string "While the ancient POKéMON fought,\n"
	.string "the fabric connecting my reality and\l"
	.string "yours was weakened enough for me to\l"
	.string "cross back into this world.\p"
	.string "Now I can finally begin anew my quest\n"
	.string "to create my ideal world!\p"
	.string "With the aid of the POKéMON that I\n"
	.string "captured over the years, I shall\l"
	.string "shape this reality as I see fit!\p"
	.string "Fwahahaha!$"

ThroneRoomStevenText1:
	.string "{PLAYER}, I'm trapped by\n"
	.string "DIALGA and PALKIA!\p"
	.string "You'll have to do something!$"

Cyrus_Text2:
	.string "You wish to stop my plans?\p"
	.string "I've been hardened by the vast\n"
	.string "expanse of nothingness and have\l"
	.string "nothing left to lose.\p"
	.string "Nothing in this world has any\n"
	.string "meaning to me, yet soon all of it\l"
	.string "shall be mine!\p"
	.string "My ideal world. . .\p"
	.string "I have waited so long to escape the\n"
	.string "void, you will not stop me now!$"

CyrusDeffeat1:
	.string "No! I have come too far for\n"
	.string "this to be the end!$"
