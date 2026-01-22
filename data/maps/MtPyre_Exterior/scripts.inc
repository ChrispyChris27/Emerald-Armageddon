MtPyre_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_OnTransition
	.byte 0

MtPyre_Exterior_OnTransition:
	call MtPyre_Exterior_EventScript_CheckEnterFromSummit
	end

MtPyre_Exterior_EventScript_CheckEnterFromSummit::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, 12, MtPyre_Exterior_EventScript_EnterFromSummit
	return

MtPyre_Exterior_EventScript_EnterFromSummit::
	setweather WEATHER_FOG_HORIZONTAL
	return

MtPyre_Exterior_EventScript_FogTrigger::
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	end

MtPyre_Exterior_EventScript_SunTrigger::
	setweather WEATHER_SUNNY
	doweather
	end

MtPyre_Exterior_ShedinjaBattle::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 0, 4, 0, 0
	setwildbattle SPECIES_SHEDINJA, 69, ITEM_AIR_BALLOON
	waitse
	playmoncry SPECIES_SHEDINJA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartTeraWildBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Shedinja_Defeated
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	releaseall
	end

Shedinja_Defeated::
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setflag FLAG_TOTEM_SHEDINJA
	setvar VAR_ROGUE_STATE, 11 
	applymovement LOCALID_ROGUE10, Shedinja_Leaves
	waitmovement
	removeobject LOCALID_ROGUE10
	pokenavcall ShedinjaCalmedText
	waitmessage
	releaseall
	end

Shedinja_Movement1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Shedinja_Movement2:
	walk_fast_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Shedinja_Leaves:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ShedinjaCalmedText:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Steven: Hey, {PLAYER}{KUN}!\p"
	.string "The energy readings on Mt. Pyre\n"
	.string "are back to normal, what's going\l"
	.string "on over there?\p"
	.string "So Team Aqua had nothing to do with\n"
	.string "the rogue Pokémon after all.\p"
	.string "Still though...\p"
	.string "I'm not sure if we should be\n"
	.string "concerned or impressed that\l"
	.string "Shedinja was able to take \l"
	.string "advantage of that energy surge,\l"
	.string "the terrain, and its ability to\l"
	.string "become almost unstoppable.\p"
	.string "Fortunately you found a way to calm\n"
	.string "it anyways {PLAYER}{KUN}.\p"
	.string "That's all from me for now, now go\n"
	.string "put a stop to whatever Team Aqua\l"
	.string "is doing at the summit!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

MtPyre_Exterior_ShedinjaEnter1::
	lockall
	playmoncry SPECIES_SHEDINJA, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE10, Shedinja_Movement1
	goto MtPyre_Exterior_ShedinjaBattle

MtPyre_Exterior_ShedinjaEnter2::
	lockall
	playmoncry SPECIES_SHEDINJA, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE10, Shedinja_Movement2
	goto MtPyre_Exterior_ShedinjaBattle

PyreRogueCall_Text:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Steven: Hey, {PLAYER}{KUN}!\p"
	.string "Hope this isn't a bad time.\p"
	.string "I'm picking up a massive energy\n"
	.string "surge about half way up Mt. Pyre.\p"
	.string "I'm guessing it's another\n"
	.string "Pokémon that's gone rogue.\p"
	.string "Wait? You're saying Team Aqua\n"
	.string "is up to no good on the summit?\p"
	.string "Listen {PLAYER}{KUN}, please investigate \n"
	.string "what's going on quickly!\p"
	.string "If Team Aqua is involved, who\n"
	.string "knows the extent of what we're\l"
	.string "dealing with!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

MtPyre_RoguePokenavCall::
	pokenavcall PyreRogueCall_Text
	waitmessage
	setvar VAR_ROGUE_STATE, 10
	end

