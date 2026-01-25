Route124_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_OnTransition
	.byte 0

Route124_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call_if_unset FLAG_TOTEM_CRYOGONAL, Common_EventScript_SetSnow
	end

Route124_EventScript_HuntersHouseSign::
	msgbox Route124_Text_HuntersHouse, MSGBOX_SIGN
	end

Route124_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER, Route124_Text_SpencerIntro, Route124_Text_SpencerDefeat
	msgbox Route124_Text_SpencerPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Roland::
	trainerbattle_single TRAINER_ROLAND, Route124_Text_RolandIntro, Route124_Text_RolandDefeat
	msgbox Route124_Text_RolandPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Jenny::
	trainerbattle_single TRAINER_JENNY_1, Route124_Text_JennyIntro, Route124_Text_JennyDefeat, Route124_EventScript_RegisterJenny
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route124_EventScript_RematchJenny
	msgbox Route124_Text_JennyPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RegisterJenny::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route124_Text_JennyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JENNY_1
	release
	end

Route124_EventScript_RematchJenny::
	trainerbattle_rematch TRAINER_JENNY_1, Route124_Text_JennyRematchIntro, Route124_Text_JennyRematchDefeat
	msgbox Route124_Text_JennyPostRematch, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE, Route124_Text_GraceIntro, Route124_Text_GraceDefeat
	msgbox Route124_Text_GracePostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD, Route124_Text_ChadIntro, Route124_Text_ChadDefeat
	msgbox Route124_Text_ChadPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Lila::
	trainerbattle_double TRAINER_LILA_AND_ROY_1, Route124_Text_LilaIntro, Route124_Text_LilaDefeat, Route124_Text_LilaNotEnoughMons, Route124_EventScript_RegisterLila
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route124_EventScript_RematchLila
	msgbox Route124_Text_LilaPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RegisterLila::
	msgbox Route124_Text_LilaRoyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LILA_AND_ROY_1
	release
	end

Route124_EventScript_RematchLila::
	trainerbattle_rematch_double TRAINER_LILA_AND_ROY_1, Route124_Text_LilaRematchIntro, Route124_Text_LilaRematchDefeat, Route124_Text_LilaRematchNotEnoughMons
	msgbox Route124_Text_LilaPostRematch, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Roy::
	trainerbattle_double TRAINER_LILA_AND_ROY_1, Route124_Text_RoyIntro, Route124_Text_RoyDefeat, Route124_Text_RoyNotEnoughMons, Route124_EventScript_RegisterRoy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route124_EventScript_RematchRoy
	msgbox Route124_Text_RoyPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_RegisterRoy::
	msgbox Route124_Text_LilaRoyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LILA_AND_ROY_1
	release
	end

Route124_EventScript_RematchRoy::
	trainerbattle_rematch_double TRAINER_LILA_AND_ROY_1, Route124_Text_RoyRematchIntro, Route124_Text_RoyRematchDefeat, Route124_Text_RoyRematchNotEnoughMons
	msgbox Route124_Text_RoyPostRematch, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Declan::
	trainerbattle_single TRAINER_DECLAN, Route124_Text_DeclanIntro, Route124_Text_DeclanDefeat
	msgbox Route124_Text_DeclanPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Isabella::
	trainerbattle_single TRAINER_ISABELLA, Route124_Text_IsabellaIntro, Route124_Text_IsabellaDefeat
	msgbox Route124_Text_IsabellaPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_Text_HuntersHouse:
	.string "Hunter's House$"

Route124_RoguePokenavCall::
	pokenavcall Route124RogueCall_Text
	waitmessage
	setvar VAR_ROGUE_STATE, 12
	end

Route124RogueCall_Text:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Steven: Hey {PLAYER}{KUN}!\n"
	.string "We've got a problem!\p"
	.string "All of a sudden it started\n"
	.string "snowing out of the blue here\l"
	.string "in Mossdeep City!\p"
	.string "Seems the snow has now spread\n"
	.string "to the surrounding areas as well.\p"
	.string "The weather also seems to have\n"
	.string "attracted a team of Spheal to\l"
	.string "Mossdeep which is preventing\l"
	.string "anyone from entering or exiting\l"
	.string "the city.\p"
	.string "They aren't causing any other\n"
	.string "trouble and they are pretty\l"
	.string "cute but...\p"
	.string "If you want to take on the gym\n"
	.string "in Mossdeep you'll need to get\l"
	.string "them out of the way eventually.\p"
	.string "Right before it started snowing\n"
	.string "an energy surge popped up just\l"
	.string "north of here on Route 125.\p"
	.string "Shoal Cave is up there and while\n"
	.string "the tides normally flow in and\l"
	.string "out of the cave depending on the\l"
	.string "time of day, the snow seems to\l"
	.string "have caused the tides to freeze\l"
	.string "up before they can flood the cave.\p"
	.string "{PLAYER}{KUN}, could you investigate\n"
	.string "Shoal Cave?\p"
	.string "I suspect a pokémon in the cave\n"
	.string "has gone rogue and caused the\l"
	.string "snow storm.\p"
	.string "I would check myself but the Spheal\n"
	.string "have me stuck in the City for now.\p"
	.string "If anything changes in the city\n"
	.string "I'll let you know {PLAYER}{KUN}!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
