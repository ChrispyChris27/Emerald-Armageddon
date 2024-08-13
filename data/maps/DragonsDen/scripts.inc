DragonsDen_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, DragonsDen_OnResume
	map_script MAP_SCRIPT_ON_LOAD, DragonsDen_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, DragonsDen_OnTransition
	.byte 0

DragonsDen_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DragonsDen_EventScript_TryRemoveRegidrago
	end

DragonsDen_EventScript_TryRemoveRegidrago::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

DragonsDen_OnLoad:
	call_if_unset FLAG_REGIDRAGO_PUZZLE, DragonsDen_EventScript_HideRegiEntrance
	end

DragonsDen_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

DragonsDen_OnTransition:
	call_if_unset FLAG_DEFEATED_REGIDRAGO, DragonsDen_EventScript_ShowRegidrago
	end

DragonsDen_EventScript_ShowRegidrago::
	clearflag FLAG_HIDE_REGIDRAGO
	return

DragonsDen_EventScript_CaveEntranceMiddle::
	lockall
	goto_if_set FLAG_REGIDRAGO_PUZZLE, DragonsDen_EventScript_BigHoleInWall
	braillemsgbox Dragons_Den_Braille
	releaseall
	end

DragonsDen_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

DragonsDen_EventScript_CaveEntranceSide::
	lockall
	braillemsgbox Dragons_Den_Braille
	releaseall
	end

DragonsDen_EventScript_Regidrago::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIDRAGO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIDRAGO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DragonsDen_EventScript_DefeatedRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DragonsDen_EventScript_RanFromRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DragonsDen_EventScript_RanFromRegidrago
	setflag FLAG_DEFEATED_REGIDRAGO
	release
	end

DragonsDen_EventScript_DefeatedRegidrago::
	setflag FLAG_DEFEATED_REGIDRAGO
	goto Common_EventScript_RemoveStaticPokemon
	end

DragonsDen_EventScript_RanFromRegidrago::
	setvar VAR_0x8004, SPECIES_REGIDRAGO
	goto Common_EventScript_LegendaryFlewAway
	end

DragonsDen_Puzzle_Fail::
	releaseall
	end

DragonsDen_Regidrago_Puzzle::
	lockall
	specialvar VAR_RESULT, Regidrago_Check
	goto_if_eq VAR_RESULT, FALSE, DragonsDen_Puzzle_Fail
	special DoBrailleRegidragoEffect
	setvar VAR_REGIDRAGO_STATUS, 1
	releaseall
	end
