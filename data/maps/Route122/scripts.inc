Route122_MapScripts::
	.byte 0

Route122GruntText:
	.string "TEAM AQUA is busy in MT. PYRE\n"
	.string "right now!\p"
	.string "I'm not supposed to let anyone\n"
	.string "in until the boss says otherwise!$"

Route122EventScript_Grunt::
	msgbox Route122GruntText, MSGBOX_NPC
	end

