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
	.string "We'll have to continue moving\n"
	.string "deeper into the cave system.\p"
	.string "{PLAYER}{KUN} I hope you're ready\n"
	.string "for what lies ahead.\p"
	.string ". . . \p"
	.string "I hope I'm ready for what lies ahead.$"

