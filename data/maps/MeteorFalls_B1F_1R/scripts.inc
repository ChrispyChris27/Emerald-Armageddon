MeteorFalls_B1F_1R_MapScripts::
	.byte 0

MeteorFalls_B1F_1R_Steven_Script::
	lockall
	msgbox MeteorFalls_B1F_StevenText, MSGBOX_NPC
	closemessage
	applymovement LOCALID_MF_STEVEN2, Common_Movement_FaceUp
	waitmovement 0
	removeobject LOCALID_MF_STEVEN2
	playse SE_DOOR
	releaseall
	end

MeteorFalls_B1F_StevenText:
	.string "The energy readings are getting\n"
	.string "stronger.\p"
	.string "Whatever is causing the surge is\n"
	.string "even deeper inside the cave.\p"
	.string "{PLAYER} I hope you're ready for\n"
	.string "lies ahead.\p"
	.string ". . . \p"
	.string "I hope I'm ready for what lies ahead.$"

