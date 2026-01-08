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

FieryPath_CentiskorchBattle::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	setflag FLAG_WILD_DYNAMAX_BATTLE
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1
	setwildbattle SPECIES_CENTISKORCH, 45, ITEM_CHARTI_BERRY
	waitse
	playmoncry SPECIES_CENTISKORCH, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartGigantamaxWildBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	waitstate
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setflag FLAG_TOTEM_CENTISKORCH
	setvar VAR_ROGUE_STATE, 
	releaseall
	end
