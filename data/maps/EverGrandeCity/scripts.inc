EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign:
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and POKéMON.”$"

EverGrande_RogueBattle::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 1, 1, 2
	setwildbattle SPECIES_CHARIZARD_MEGA_Y, 87, ITEM_CHARTI_BERRY
	waitse
	playmoncry SPECIES_CHARIZARD_MEGA_Y, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartRogueWildBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, EverGrandeRogueDefeated
	releaseall
	end

EverGrandeRogueDefeated::
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ROGUE_ZARD_Y
	fadescreen FADE_FROM_BLACK
	goto_if_unset FLAG_TOTEM_DURALUDON, CheckLudiEverGrande
	goto_if_unset FLAG_TOTEM_SHIFTRY, Rt123_OneRogueLeft
	pokenavcall StevenErraticRoguesCalmed
	waitmessage
	setflag FLAG_ERRATIC_TOTEMS
	setvar VAR_ROGUE_STATE, 17
	releaseall
	end

CheckLudiEverGrande::
	goto_if_set FLAG_TOTEM_SHIFTRY, Rt123_OneRogueLeft
	msgbox TwoRoguesLeft, MSGBOX_AUTOCLOSE
	waitmessage
	releaseall
	end

EverGrande_RogueEnters1::
	goto_if_set FLAG_TOTEM_CHARIZARD_MEGA Rt123BattleDone
	lockall
	playmoncry SPECIES_CHARIZARD_MEGA_Y, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE_ZARD_Y, Zard_Movement1
	goto EverGrande_RogueBattle

Zard_Movement1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EverGrande_RogueEnters2::
	goto_if_set FLAG_TOTEM_CHARIZARD_MEGA Rt123BattleDone
	lockall
	playmoncry SPECIES_CHARIZARD_MEGA_Y, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE_ZARD_Y, Zard_Movement2
	goto EverGrande_RogueBattle

Zard_Movement2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

