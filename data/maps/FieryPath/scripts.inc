FieryPath_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
	.byte 0

FieryPath_OnTransition:
	call_if_unset FLAG_LANDMARK_FIERY_PATH, FieryPath_EventScript_MoveScottToFallarbor
	setflag FLAG_LANDMARK_FIERY_PATH
	end

FieryPath_EventScript_MoveScottToFallarbor::
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	clearflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	return

FieryPathCentiEnter1::
	lockall
	playmoncry SPECIES_CENTISKORCH, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE3, Centiskorch_Movement1
	goto FieryPath_CentiskorchBattle

FieryPathCentiEnter2::
	lockall
	playmoncry SPECIES_CENTISKORCH, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE3, Centiskorch_Movement2
	goto FieryPath_CentiskorchBattle

FieryPathCentiEnter3::
	lockall
	playmoncry SPECIES_CENTISKORCH, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE3, Centiskorch_Movement3
	goto FieryPath_CentiskorchBattle

FieryPath_CentiskorchBattle::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	setflag FLAG_WILD_DYNAMAX_BATTLE
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 1, 0, 0, 1
	setwildbattle SPECIES_CENTISKORCH, 44, ITEM_CHARTI_BERRY
	waitse
	playmoncry SPECIES_CENTISKORCH, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartGigantamaxWildBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Centiskorch_Defeated
	releaseall
	end

Centiskorch_Defeated::
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setflag FLAG_TOTEM_CENTISKORCH
	clearflag FLAG_WILD_DYNAMAX_BATTLE
	setvar VAR_ROGUE_STATE, 4 
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ROGUE3
	fadescreen FADE_FROM_BLACK
	pokenavcall CentiCalmedText
	waitmessage
	releaseall
	end


Centiskorch_Movement1:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	face_down
	step_end

Centiskorch_Movement2:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	face_down
	step_end

Centiskorch_Movement3:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	face_down
	step_end

CentiCalmedText:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Steven: Hey, {PLAYER}{KUN}!\p"
	.string "The energy readings have dissipated.\p"
	.string "That Centiskorch seems to have\n"
	.string "returned to the wild.\p"
	.string "Still, I can't believe it was able\n"
	.string "to Gigantamax all on its own.\p"
	.string "Normally that phenomenon is only\n"
	.string "observed in the Galar region.\p"
	.string "Whatever the source of these\n"
	.string "energy surges is, it must be \l"
	.string "incredibly strong.\p"
	.string "Thanks again for your help {PLAYER}{KUN}.\p"
	.string "If any other energy surges pop up\n"
	.string "I'll be sure to ask for your help.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
