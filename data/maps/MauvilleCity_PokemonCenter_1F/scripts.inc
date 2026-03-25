MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx::
	special SetMauvilleOldManObjEventGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_MAUVILLE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings:
	.string "That man over there, he says weird\n"
	.string "things!\p"
	.string "He's funny in a weird way.\n"
	.string "I doubt I'll forget about him!$"

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner:
	.string "When I accessed the RECORD CORNER,\n"
	.string "the data for what's hot in DEWFORD\l"
	.string "got updated.\p"
	.string "Now that bit of data is the same\n"
	.string "as my friend's!$"

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun:
	.string "A RECORD CORNER opened upstairs in\n"
	.string "the POKéMON CENTER.\p"
	.string "I don't know what it's about, but it\n"
	.string "sounds fun. I'll go check it out!$"

Inflict_Status_Text_1:
	.string "Would you like me to inflict one of\n"
	.string "your pokémon with a status condition?$"

InflictStatus_Text_Later:
	.string "Let me know if you change your mind.$"

InflictStatus_Text_Options:
	.string "Which status condition should I\n"
	.string "inflict your pokémon with?$"

InflictStatus1_Text_Poison:
	.string "Poison$"

InflictStatus1_Text_Paralysis:
	.string "Paralysis$"

InflictStatus1_Text_Sleep:
	.string "Sleep$"

InflictStatus1_Text_Burn:
	.string "Burn$"

InflictStatus1_Text_Freeze:
	.string "Freeze$"

InflictStatus1_Text_Close:
	.string "Cancel$"

WhoShouldPoisonText:
	.string "Which pokémon should I poison?$"

WhoShouldParalyzeText:
	.string "Which pokémon should I paralyze?$"

WhoShouldSleepText:
	.string "Which pokémon should I put to sleep?$"

WhoShouldBurnText:
	.string "Which pokémon should I burn?$"

WhoShouldFreezeText:
	.string "Which pokémon should I freeze?$"

CannotPoisonText:
	.string "I can't poison that pokémon!$"

CannotParalyzeText:
	.string "I can't paralyze that pokémon!$"

CannotSleepText:
	.string "I can't put that pokémon to sleep!$"

CannotBurnText:
	.string "I can't burn that pokémon!$"

CannotFreezeText:
	.string "I can't freeze that pokémon!$"

YourPokemonIsPoisonText:
	.string "Done!\n"
	.string "Your pokémon has been poisoned!\p"
	.string "Let me know if you would like me\n"
	.string "to status another of your pokémon.$"

YourPokemonIsParalyzeText:
	.string "Done!\n"
	.string "Your pokémon has been paralyzed!\p"
	.string "Let me know if you would like me\n"
	.string "to status another of your pokémon.$"

YourPokemonIsSleepText:
	.string "Done!\n"
	.string "Your pokémon has been put to sleep!\p"
	.string "Let me know if you would like me\n"
	.string "to status another of your pokémon.$"

YourPokemonIsBurnText:
	.string "Done!\n"
	.string "Your pokémon has been burned!\p"
	.string "Let me know if you would like me\n"
	.string "to status another of your pokémon.$"

YourPokemonIsFrozenText:
	.string "Done!\n"
	.string "Your pokémon has been frozen!\p"
	.string "Let me know if you would like me\n"
	.string "to status another of your pokémon.$"

PreStatusTrainer::
	lock
	faceplayer
	msgbox Inflict_Status_Text_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SetStatusScript
	closemessage
	msgbox InflictStatus_Text_Later, MSGBOX_AUTOCLOSE
	release
	end

InflictStatus1_Close::
	msgbox InflictStatus_Text_Later, MSGBOX_AUTOCLOSE
	release
	end

SetStatusScript::
	msgbox InflictStatus_Text_Options, MSGBOX_DEFAULT
	dynmultipush InflictStatus1_Text_Poison, 0
	dynmultipush InflictStatus1_Text_Paralysis, 1
	dynmultipush InflictStatus1_Text_Sleep, 2
	dynmultipush InflictStatus1_Text_Burn, 3
	dynmultipush InflictStatus1_Text_Freeze, 4
	dynmultipush InflictStatus1_Text_Close, 5
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, InflictStatus1_Single_Poison
	case 1, InflictStatus1_Single_Paralyze
	case 2, InflictStatus1_Single_Sleep
	case 3, InflictStatus1_Single_Burn
	case 4, InflictStatus1_Single_Freeze
	case 5, InflictStatus1_Close
	case MULTI_B_PRESSED, InflictStatus1_Close
	releaseall
	end

InflictStatus1_Single_Poison::
	msgbox WhoShouldPoisonText, MSGBOX_AUTOCLOSE
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, InflictStatus1_Close
	specialvar VAR_RESULT, CanPoison
	goto_if_eq VAR_RESULT, FALSE, CannotInflictStatusPoison
	setstatus1 STATUS1_POISON, VAR_0x8004
	msgbox YourPokemonIsPoisonText, MSGBOX_NPC
	release
	end

CannotInflictStatusPoison::
	msgbox CannotPoisonText, MSGBOX_NPC
	release
	end

InflictStatus1_Single_Sleep::
	msgbox WhoShouldSleepText, MSGBOX_AUTOCLOSE
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, InflictStatus1_Close
	specialvar VAR_RESULT, CanSleep
	goto_if_eq VAR_RESULT, FALSE, CannotInflictStatusSleep
	setstatus1 STATUS1_SLEEP, VAR_0x8004
	msgbox YourPokemonIsSleepText, MSGBOX_NPC
	release
	end

CannotInflictStatusSleep::
	msgbox CannotSleepText, MSGBOX_NPC
	release
	end

InflictStatus1_Single_Paralyze::
	msgbox WhoShouldParalyzeText, MSGBOX_AUTOCLOSE
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, InflictStatus1_Close
	specialvar VAR_RESULT, CanParalyze
	goto_if_eq VAR_RESULT, FALSE, CannotInflictStatusParalyze
	setstatus1 STATUS1_PARALYSIS, VAR_0x8004
	msgbox YourPokemonIsParalyzeText, MSGBOX_NPC
	release
	end

CannotInflictStatusParalyze::
	msgbox CannotParalyzeText, MSGBOX_NPC
	release
	end

InflictStatus1_Single_Burn::
	msgbox WhoShouldBurnText, MSGBOX_AUTOCLOSE
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, InflictStatus1_Close
	specialvar VAR_RESULT, CanBurn
	goto_if_eq VAR_RESULT, FALSE, CannotInflictStatusBurn
	setstatus1 STATUS1_BURN, VAR_0x8004
	msgbox YourPokemonIsBurnText, MSGBOX_NPC
	release
	end

CannotInflictStatusBurn::
	msgbox CannotBurnText, MSGBOX_NPC
	release
	end

InflictStatus1_Single_Freeze::
	msgbox WhoShouldFreezeText, MSGBOX_AUTOCLOSE
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, InflictStatus1_Close
	specialvar VAR_RESULT, CanFreeze
	goto_if_eq VAR_RESULT, FALSE, CannotInflictStatusFreeze
	setstatus1 STATUS1_FREEZE, VAR_0x8004
	msgbox YourPokemonIsFrozenText, MSGBOX_NPC
	release
	end

CannotInflictStatusFreeze::
	msgbox CannotFreezeText, MSGBOX_NPC
	release
	end

