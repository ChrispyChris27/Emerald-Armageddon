Underwater_Route126_MapScripts::
	.byte 0

Underwater_RogueBattle::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_RIGHT, 0, 1, 1, 0, 1
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 2, 1, 2
	setwildbattle SPECIES_TATSUGIRI_CURLY, 87, ITEM_SHELL_BELL, SPECIES_DONDOZO, 87, ITEM_SHELL_BELL
	waitse
	playmoncry SPECIES_TATSUGIRI_CURLY, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_DONDOZO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Tatsudozo_Defeated
	releaseall
	end

Tatsudozo_Defeated::
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setvar VAR_ROGUE_STATE, 15
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ROGUE_SUSHI
	removeobject LOCALID_ROGUE_BOZO
	fadescreen FADE_FROM_BLACK
	pokenavcall StevenPanicText
	waitmessage
	releaseall
	end

Tatsu_Dozo_Enters::
	lockall
	playmoncry SPECIES_TATSUGIRI_CURLY, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_DONDOZO, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE_SUSHI, Sushi_Movement
	applymovement LOCALID_ROGUE_BOZO, Bozo_Movement
	goto Underwater_RogueBattle

StevenPanicText:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Steven: {PLAYER}{KUN}!\p"
	.string "I'm glad you were able to calm\n"
	.string "Dondozo and Mega Tatsugiri but\l"
	.string "you need to get up to Sootopolis!\p"
	.string "You won't believe what's going on\n"
	.string "up here and it's too difficult\l"
	.string "to explain!\p"
	.string "You need to see it for yourself!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Sushi_Movement:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end

Bozo_Movement:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end
