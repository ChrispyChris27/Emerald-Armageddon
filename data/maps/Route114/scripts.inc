Route114_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route114_OnFrame
	.byte 0

Route114_OnTransition:
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH, AbnormalWeather_StartGroudonWeather
	end

Route114_OnLoad:
	call_if_unset FLAG_REGI_DOORS_OPENED, Route114_CloseRegiEntrance
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute114North
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute114South
	end

Route114_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route114_CloseRegiEntrance::
	setmetatile 24, 4, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 24, 5, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_EventScript_Man::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_ROUTE_114_RECEIVED_BERRY, Route114_EventScript_ReceivedBerry
	msgbox Route114_Text_LoveUsingBerryCrushShareBerry, MSGBOX_DEFAULT
	random NUM_ROUTE_114_MAN_BERRIES
	addvar VAR_RESULT, NUM_ROUTE_114_MAN_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_ROUTE_114_RECEIVED_BERRY
	msgbox Route114_Text_TryBerryCrushWithFriends, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_ReceivedBerry::
	msgbox Route114_Text_FunToThinkAboutBerries, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_RoarGentleman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_ROAR, Route114_EventScript_ReceivedRoar
	msgbox Route114_Text_AllMyMonDoesIsRoarTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROAR
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROAR
	msgbox Route114_Text_ExplainRoar, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_ReceivedRoar::
	msgbox Route114_Text_ExplainRoar, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_Poochyena::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POOCHYENA, CRY_MODE_ENCOUNTER
	msgbox Route114_Text_Poochyena, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route114_EventScript_MeteorFallsSign::
	msgbox Route114_Text_MeteorFallsSign, MSGBOX_SIGN
	end

Route114_EventScript_FossilManiacsHouseSign::
	msgbox Route114_Text_FossilManiacsHouseSign, MSGBOX_SIGN
	end

Route114_EventScript_LanettesHouseSign::
	msgbox Route114_Text_LanettesHouse, MSGBOX_SIGN
	end

Route114_EventScript_Lenny::
	trainerbattle_single TRAINER_LENNY, Route114_Text_LennyIntro, Route114_Text_LennyDefeat
	msgbox Route114_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Lucas::
	trainerbattle_single TRAINER_LUCAS_1, Route114_Text_LucasIntro, Route114_Text_LucasDefeat
	msgbox Route114_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Shane::
	trainerbattle_single TRAINER_SHANE, Route114_Text_ShaneIntro, Route114_Text_ShaneDefeat
	msgbox Route114_Text_ShanePostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Nancy::
	trainerbattle_single TRAINER_NANCY, Route114_Text_NancyIntro, Route114_Text_NancyDefeat
	msgbox Route114_Text_NancyPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Steve::
	trainerbattle_single TRAINER_STEVE_1, Route114_Text_SteveIntro, Route114_Text_SteveDefeat, Route114_EventScript_RegisterSteve
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route114_EventScript_RematchSteve
	msgbox Route114_Text_StevePostBattle, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_RegisterSteve::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route114_Text_SteveRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_STEVE_1
	release
	end

Route114_EventScript_RematchSteve::
	trainerbattle_rematch TRAINER_STEVE_1, Route114_Text_SteveRematchIntro, Route114_Text_SteveRematchDefeat
	msgbox Route114_Text_StevePostRematch, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Bernie::
	trainerbattle_single TRAINER_BERNIE_1, Route114_Text_BernieIntro, Route114_Text_BernieDefeat, Route114_EventScript_RegisterBernie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route114_EventScript_RematchBernie
	msgbox Route114_Text_BerniePostBattle, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_RegisterBernie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route114_Text_BernieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BERNIE_1
	release
	end

Route114_EventScript_RematchBernie::
	trainerbattle_rematch TRAINER_BERNIE_1, Route114_Text_BernieRematchIntro, Route114_Text_BernieRematchDefeat
	msgbox Route114_Text_BerniePostRematch, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Claude::
	trainerbattle_single TRAINER_CLAUDE, Route114_Text_ClaudeIntro, Route114_Text_ClaudeDefeat
	msgbox Route114_Text_ClaudePostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Nolan::
	trainerbattle_single TRAINER_NOLAN, Route114_Text_NolanIntro, Route114_Text_NolanDefeat
	msgbox Route114_Text_NolanPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Tyra::
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_TyraIntro, Route114_Text_TyraDefeat, Route114_Text_TyraNotEnoughMons
	msgbox Route114_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Ivy::
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_IvyIntro, Route114_Text_IvyDefeat, Route114_Text_IvyNotEnoughMons
	msgbox Route114_Text_IvyPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Angelina::
	trainerbattle_single TRAINER_ANGELINA, Route114_Text_AngelinaIntro, Route114_Text_AngelinaDefeat
	msgbox Route114_Text_AngelinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Charlotte::
	trainerbattle_single TRAINER_CHARLOTTE, Route114_Text_CharlotteIntro, Route114_Text_CharlotteDefeat
	msgbox Route114_Text_CharlottePostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Kai::
	trainerbattle_single TRAINER_KAI, Route114_Text_KaiIntro, Route114_Text_KaiDefeat
	msgbox Route114_Text_KaiPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_Text_AllMyMonDoesIsRoarTakeThis:
	.string "All my POKéMON does is ROAR…\n"
	.string "No one dares to come near me…\p"
	.string "Sigh… If you would, please take\n"
	.string "this TM away…$"

Route114_Text_ExplainRoar:
	.string "TM05 contains ROAR.\n"
	.string "A ROAR sends POKéMON scurrying.$"

Route114_Text_Poochyena:
	.string "Bow! Bowwow!$"

Route114_Text_MeteorFallsSign:
	.string "METEOR FALLS\n"
	.string "RUSTBORO CITY THROUGH HERE$"

Route114_Text_FossilManiacsHouseSign:
	.string "FOSSIL MANIAC'S HOUSE\n"
	.string "“Fossils gratefully accepted!”$"

Route114_Text_LanettesHouse:
	.string "LANETTE'S HOUSE$"

Route114_Text_Grunt1Intro:
	.string "Who are you?\p"
	.string "You dare meddle with TEAM ROCKET?$"

Route114_Text_Grunt1Defeat:
	.string "You meddlesome monkey!$"

Route114_Text_Grunt1PostBattle:
	.string "You won't stop the rest of us!$"

Route114_EventScript_Grunt1::
	trainerbattle_single TRAINER_FALLS_GRUNT_1, Route114_Text_Grunt1Intro, Route114_Text_Grunt1Defeat
	msgbox Route114_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route114_Text_Grunt2Intro:
	.string "We at TEAM ROCKET come from the\n"
	.string "KANTO region!\p"
	.string "What are we doing here?\p"
	.string "It's a secret!$"

Route114_Text_Grunt2Defeat:
	.string "My lips are sealed!$"

Route114_Text_Grunt2PostBattle:
	.string "I won't be telling you anything!$"

Route114_EventScript_Grunt2::
	trainerbattle_single TRAINER_FALLS_GRUNT_2, Route114_Text_Grunt2Intro, Route114_Text_Grunt2Defeat
	msgbox Route114_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route114_Text_Grunt3Intro:
	.string "We're after something in METEOR FALLS.\p"
	.string "I can't let you get in our way!$"

Route114_Text_Grunt3Defeat:
	.string "At least I stalled you for awhile.$"

Route114_Text_Grunt3PostBattle:
	.string "Whatever we're after, it must be\n"
	.string "important to have come all the way here.$"

Route114_EventScript_Grunt3::
	trainerbattle_single TRAINER_FALLS_GRUNT_3, Route114_Text_Grunt3Intro, Route114_Text_Grunt3Defeat
	msgbox Route114_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

Route114_Text_Grunt4Intro:
	.string "The boss told us to look out for\n"
	.string "anyone who might get in our way!$"

Route114_Text_Grunt4Defeat:
	.string "I hope the boss forgives me!$"

Route114_Text_Grunt4PostBattle:
	.string "I may have failed to stop you\n"
	.string "but I did manage to stall you!$"

Route114_EventScript_Grunt4::
	trainerbattle_single TRAINER_FALLS_GRUNT_4, Route114_Text_Grunt4Intro, Route114_Text_Grunt4Defeat
	msgbox Route114_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route114_Text_Grunt5Intro:
	.string "I was told we were going on\n"
	.string "vacation but this isn't what\l"
	.string "I had in mind.$"

Route114_Text_Grunt5Defeat:
	.string "I wanted to be at a beach!$"

Route114_Text_Grunt5PostBattle:
	.string "I heard HOENN had too much water.\p"
	.string "Well where is it?!?!\p"
	.string "I was hoping to relax at a beach.$"

Route114_EventScript_Grunt5::
	trainerbattle_single TRAINER_FALLS_GRUNT_5, Route114_Text_Grunt5Intro, Route114_Text_Grunt5Defeat
	msgbox Route114_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

Route114_Text_Grunt6Intro:
	.string "We at TEAM ROCKET are always after\n"
	.string "rare POKéMON.\p"
	.string "We came to see what HOENN has to offer!$"

Route114_Text_Grunt6Defeat:
	.string "Apparently you're what HOENN has\n"
	.string "to offer...$"

Route114_Text_Grunt6PostBattle:
	.string "I was hoping to catch a NINCADA\n"
	.string "while I was here but they don't\l"
	.string "to be living around here.$"

Route114_EventScript_Grunt6::
	trainerbattle_single TRAINER_FALLS_GRUNT_6, Route114_Text_Grunt6Intro, Route114_Text_Grunt6Defeat
	msgbox Route114_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

Route114_Text_Grunt7Intro:
	.string "Do you think there are meteorites\n"
	.string "in METEOR FALLS?\p"
	.string "I think that's what the boss is after!$"

Route114_Text_Grunt7Defeat:
	.string "I feel like I've been struck by a\n"
	.string "meteor$"

Route114_Text_Grunt7PostBattle:
	.string "Did you know there's a city in the\n"
	.string "SINNOH region where meteorites can\l"
	.string "be found?$"

Route114_EventScript_Grunt7::
	trainerbattle_single TRAINER_FALLS_GRUNT_7, Route114_Text_Grunt7Intro, Route114_Text_Grunt7Defeat
	msgbox Route114_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

Route114_Text_Grunt8Intro:
	.string "I hear there are some fossil POKéMON\n"
	.string "that can be found in METEOR FALLS!$"

Route114_Text_Grunt8Defeat:
	.string "Oops! All fainted!$"

Route114_Text_Grunt8PostBattle:
	.string "Fossil POKéMON are cool and all but\n"
	.string "our boss is after something bigger.$"

Route114_EventScript_Grunt8::
	trainerbattle_single TRAINER_FALLS_GRUNT_8, Route114_Text_Grunt8Intro, Route114_Text_Grunt8Defeat
	msgbox Route114_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

Route114_Text_Grunt9Intro:
	.string "Stop right there!\p"
	.string "Nobody is allowed in METEOR FALLS!\n"
	.string "until the boss finds what he's after!$"

Route114_Text_Grunt9Defeat:
	.string "I did what I could to slow you down.$"

Route114_Text_Grunt9PostBattle:
	.string "By now you're probably too late!\p"
	.string "I'm sure we've found what we came for!$"

Route114_EventScript_Grunt9::
	trainerbattle_single TRAINER_FALLS_GRUNT_9, Route114_Text_Grunt9Intro, Route114_Text_Grunt9Defeat
	msgbox Route114_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end
