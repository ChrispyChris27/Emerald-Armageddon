TransistorTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TransistorTunnel_OnResume
	map_script MAP_SCRIPT_ON_LOAD, TransistorTunnel_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, TransistorTunnel_OnTransition
	.byte 0

TransistorTunnel_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TransistorTunnel_EventScript_TryRemoveRegieleki
	end

TransistorTunnel_EventScript_TryRemoveRegieleki::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

TransistorTunnel_OnLoad:
	call_if_unset FLAG_REGIELEKI_PUZZLE, TransistorTunnel_EventScript_HideRegiEntrance
	end

TransistorTunnel_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

TransistorTunnel_OnTransition:
	call_if_unset FLAG_DEFEATED_REGIELEKI, TransistorTunnel_EventScript_ShowRegieleki
	end

TransistorTunnel_EventScript_ShowRegieleki::
	clearflag FLAG_HIDE_REGIELEKI
	return

TransistorTunnel_EventScript_CaveEntranceMiddle::
	lockall
	goto_if_set FLAG_REGIELEKI_PUZZLE, TransistorTunnel_EventScript_BigHoleInWall
	braillemsgbox Transistor_Braille_Electric
	releaseall
	end

TransistorTunnel_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

TransistorTunnel_EventScript_CaveEntranceSide::
	lockall
	braillemsgbox Transistor_Braille_Electric
	releaseall
	end

TransistorTunnel_EventScript_Regieleki::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIELEKI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIELEKI, 80
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TransistorTunnel_EventScript_DefeatedRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TransistorTunnel_EventScript_RanFromRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TransistorTunnel_EventScript_RanFromRegieleki
	setflag FLAG_DEFEATED_REGIELEKI
	release
	end

TransistorTunnel_EventScript_DefeatedRegieleki::
	setflag FLAG_DEFEATED_REGIELEKI
	goto Common_EventScript_RemoveStaticPokemon
	end

TransistorTunnel_EventScript_RanFromRegieleki::
	setvar VAR_0x8004, SPECIES_REGIELEKI
	goto Common_EventScript_LegendaryFlewAway
	end

TransistorTunnel_Puzzle_Fail::
	releaseall
	end

TransistorTunnel_Regieleki_Puzzle::
	lockall
	specialvar VAR_RESULT, Regieleki_Check
	goto_if_eq VAR_RESULT, FALSE, TransistorTunnel_Puzzle_Fail
	special DoBrailleRegielekiEffect
	setvar VAR_REGIELEKI_STATUS, 1
	releaseall
	end
