PetalburgTombInside_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PetalburgTombInside_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PetalburgTombInside_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgTombInside_OnTransition
	.byte 0

PetalburgTombInside_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, PetalburgTombInside_EventScript_TryRemoveGenesect
	end

PetalburgTombInside_EventScript_TryRemoveGenesect::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

PetalburgTombInside_OnLoad:
	call_if_unset FLAG_GENESECT_PUZZLE, PetalburgTombInside_EventScript_HideRegiEntrance
	end

PetalburgTombInside_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

PetalburgTombInside_OnTransition:
	call_if_unset FLAG_DEFEATED_GENESECT, PetalburgTombInside_EventScript_ShowGenesect
	end

PetalburgTombInside_EventScript_ShowGenesect::
	clearflag FLAG_HIDE_GENESECT
	return

PetalburgTombInside_EventScript_CaveEntranceMiddle::
	lockall
	goto_if_set FLAG_GENESECT_PUZZLE, PetalburgTombInside_EventScript_BigHoleInWall
	braillemsgbox Petalburg_Tomb_Braille
	goto PetalburgTombInside_CheckGenesect
	releaseall
	end

PetalburgTombInside_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

PetalburgTombInside_EventScript_CaveEntranceSide::
	lockall
	braillemsgbox Petalburg_Tomb_Braille
	goto_if_unset FLAG_GENESECT_PUZZLE, PetalburgTombInside_CheckGenesect
	releaseall
	end

PetalburgTombInside_EventScript_Genesect::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GENESECT, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_GENESECT, 80
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PetalburgTombInside_EventScript_DefeatedGenesect
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PetalburgTombInside_EventScript_RanFromGenesect
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PetalburgTombInside_EventScript_RanFromGenesect
	setflag FLAG_DEFEATED_GENESECT
	release
	end

PetalburgTombInside_EventScript_DefeatedGenesect::
	setflag FLAG_DEFEATED_GENESECT
	goto Common_EventScript_RemoveStaticPokemon
	end

PetalburgTombInside_EventScript_RanFromGenesect::
	setvar VAR_0x8004, SPECIES_GENESECT
	goto Common_EventScript_LegendaryFlewAway
	end

PetalburgTombNothing::
	releaseall
	end

PetalburgTombInside_CheckGenesect::
	specialvar VAR_RESULT, ShouldAwakenGenesect
	goto_if_eq VAR_RESULT, FALSE, PetalburgTombNothing
	callnative DoBrailleGenesectEffect
	releaseall
	end

SelectDriveScript::
	braillemsgbox Select_Drive_Braille
	dynmultipush Text_ChooseBurn, 0
	dynmultipush Text_ChooseChill, 1
	dynmultipush Text_ChooseDouse, 2
	dynmultipush Text_ChooseShock, 3
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, GiveBurnDrive
	case 1, GiveChillDrive
	case 2, GiveDouseDrive
	case 3, GiveShockDrive
	releaseall
	end

Text_ChooseBurn:
	.string "Option 1$"

Text_ChooseChill:
	.string "Option 2$"

Text_ChooseDouse:
	.string "Option 3$"

Text_ChooseShock:
	.string "Option 4$"

GiveBurnDrive::
	giveitem ITEM_BURN_DRIVE
	removeobject LOCALID_DRIVE
	releaseall
	end

GiveChillDrive::
	giveitem ITEM_CHILL_DRIVE
	removeobject LOCALID_DRIVE
	releaseall
	end

GiveDouseDrive::
	giveitem ITEM_DOUSE_DRIVE
	removeobject LOCALID_DRIVE
	releaseall
	end

GiveShockDrive::
	giveitem ITEM_SHOCK_DRIVE
	removeobject LOCALID_DRIVE
	releaseall
	end

