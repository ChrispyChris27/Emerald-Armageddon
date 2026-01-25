ShoalCave_LowTideIceRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShoalCave_LowTideIceRoom_OnTransition
	.byte 0

ShoalCave_LowTideIceRoom_OnTransition:
	call_if_unset FLAG_TOTEM_CRYOGONAL, Common_EventScript_SetSnow
	end

ShoalCave_CryogonalBattle::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 1, 1, 2
	setwildbattle SPECIES_CRYOGONAL, 80, ITEM_LUM_BERRY
	waitse
	playmoncry SPECIES_CRYOGONAL, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartTeraWildBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Cryogonal_Defeated
	releaseall
	end

Cryogonal_Defeated::
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setflag FLAG_TOTEM_CRYOGONAL
	setvar VAR_ROGUE_STATE, 13
	fadescreen FADE_TO_BLACK
	setweather WEATHER_NONE
	doweather
	removeobject LOCALID_ROGUE_CRYO
	fadescreen FADE_FROM_BLACK
	pokenavcall CryogonalCalmedText
	waitmessage
	releaseall
	end

Cryogonal_Enters1::
	lockall
	playmoncry SPECIES_CRYOGONAL, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE_CRYO, Cryogonal_Movement1
	goto ShoalCave_CryogonalBattle

Cryogonal_Movement1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Cryogonal_Enters2::
	lockall
	playmoncry SPECIES_CRYOGONAL, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE_CRYO, Cryogonal_Movement2
	goto ShoalCave_CryogonalBattle

Cryogonal_Movement2:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Cryogonal_Enters3::
	lockall
	playmoncry SPECIES_CRYOGONAL, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE_CRYO, Cryogonal_Movement3
	goto ShoalCave_CryogonalBattle

Cryogonal_Movement3:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CryogonalCalmedText:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Steven: Hey {PLAYER}{KUN},\n"
	.string "great news!\p"
	.string "The snow storm has subsided and\n"
	.string "the weather is back to normal.\p"
	.string "The spheal have also rolled on\n"
	.string "back to Shoal Cave now.\p"
	.string "So it was a rogue Cryogonal that\n"
	.string "was responsible for all of this.\p"
	.string "It seems that when Cryogonal\n"
	.string "absorbed all that energy, it\l"
	.string "became strong enough to change\l"
	.string "the weather as it saw fit.\p"
	.string "It's concerning that the rogue\n"
	.string "pokémon seem to getting more\l"
	.string "and more powerful.\p"
	.string "First Kilowattrel used the existing\n"
	.string "rain storm to its advantage.\p"
	.string "Then Shedinja became almost\n"
	.string "unkillable.\p"
	.string "And now Cryogonal going one step\n"
	.string "further and manipulating the\l"
	.string "weather on its own.\p"
	.string "Things could get even more\n"
	.string "difficult from here.\p"
	.string "For now though, I can get back\n"
	.string "to my research and you can take\l"
	.string "on the Mossdeep City Gym.\p"
	.string "I'll see you soon {PLAYER}{KUN}.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

