Route113_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route113_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route113_OnTransition
	.byte 0

Route113_OnResume:
	setstepcallback STEP_CB_ASH
	end

Route113_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	call Route113_EventScript_CheckSetAshWeather
	end

Route113_EventScript_CheckSetAshWeather::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_0, 19, Route113_EventScript_DontSetAshWeather
	goto_if_gt VAR_TEMP_0, 84, Route113_EventScript_DontSetAshWeather
	setweather WEATHER_VOLCANIC_ASH
	return

Route113_EventScript_DontSetAshWeather::
	return

Route113_EventScript_Gentleman::
	msgbox Route113_Text_AshCanBeFashionedIntoGlass, MSGBOX_NPC
	end

Route113_EventScript_NinjaBoy::
	msgbox Route113_Text_FunWalkingThroughAsh, MSGBOX_NPC
	end

Route113_EventScript_RouteSign111::
	msgbox Route113_Text_RouteSign111, MSGBOX_SIGN
	end

Route113_EventScript_RouteSignFallarbor::
	msgbox Route113_Text_RouteSignFallarbor, MSGBOX_SIGN
	end

Route113_EventScript_GlassWorkshopSign::
	msgbox Route113_Text_GlassWorkshopSign, MSGBOX_SIGN
	end

Route113_EventScript_TrainerTipsRegisterKeyItems::
	msgbox Route113_Text_TrainerTipsRegisterKeyItems, MSGBOX_SIGN
	end

Route113_EventScript_Jaylen::
	trainerbattle_single TRAINER_JAYLEN, Route113_Text_JaylenIntro, Route113_Text_JaylenDefeat
	msgbox Route113_Text_JaylenPostBattle, MSGBOX_AUTOCLOSE
	end

Route113_EventScript_Dillon::
	trainerbattle_single TRAINER_DILLON, Route113_Text_DillonIntro, Route113_Text_DillonDefeat
	msgbox Route113_Text_DillonPostBattle, MSGBOX_AUTOCLOSE
	end

Route113_EventScript_Madeline::
	trainerbattle_single TRAINER_MADELINE_1, Route113_Text_MadelineIntro, Route113_Text_MadelineDefeat, Route113_EventScript_RegisterMadeline
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route113_EventScript_RematchMadeline
	msgbox Route113_Text_MadelinePostBattle, MSGBOX_DEFAULT
	release
	end

Route113_EventScript_RegisterMadeline::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route113_Text_MadelineRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MADELINE_1
	release
	end

Route113_EventScript_RematchMadeline::
	trainerbattle_rematch TRAINER_MADELINE_1, Route113_Text_MadelineRematchIntro, Route113_Text_MadelineRematchDefeat
	msgbox Route113_Text_MadelinePostRematch, MSGBOX_AUTOCLOSE
	end

Route113_EventScript_Lao::
	trainerbattle_single TRAINER_LAO_1, Route113_Text_LaoIntro, Route113_Text_LaoDefeat, Route113_EventScript_RegisterLao
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route113_EventScript_RematchLao
	msgbox Route113_Text_LaoPostBattle, MSGBOX_DEFAULT
	release
	end

Route113_EventScript_RegisterLao::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route113_Text_LaoRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LAO_1
	release
	end

Route113_EventScript_RematchLao::
	trainerbattle_rematch TRAINER_LAO_1, Route113_Text_LaoRematchIntro, Route113_Text_LaoRematchDefeat
	msgbox Route113_Text_LaoPostRematch, MSGBOX_AUTOCLOSE
	end

Route113_EventScript_Lung::
	trainerbattle_single TRAINER_LUNG, Route113_Text_LungIntro, Route113_Text_LungDefeat
	msgbox Route113_Text_LungPostBattle, MSGBOX_AUTOCLOSE
	end

Route113_EventScript_Tori::
	trainerbattle_double TRAINER_TORI_AND_TIA, Route113_Text_ToriIntro, Route113_Text_ToriDefeat, Route113_Text_ToriNotEnoughMons
	msgbox Route113_Text_ToriPostBattle, MSGBOX_AUTOCLOSE
	end

Route113_EventScript_Tia::
	trainerbattle_double TRAINER_TORI_AND_TIA, Route113_Text_TiaIntro, Route113_Text_TiaDefeat, Route113_Text_TiaNotEnoughMons
	msgbox Route113_Text_TiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route113_EventScript_Sophie::
	trainerbattle_single TRAINER_SOPHIE, Route113_Text_SophieIntro, Route113_Text_SophieDefeat
	msgbox Route113_Text_SophiePostBattle, MSGBOX_AUTOCLOSE
	end

Route113_EventScript_Coby::
	trainerbattle_single TRAINER_COBY, Route113_Text_CobyIntro, Route113_Text_CobyDefeat
	msgbox Route113_Text_CobyPostBattle, MSGBOX_AUTOCLOSE
	end

Route113_EventScript_Lawrence::
	trainerbattle_single TRAINER_LAWRENCE, Route113_Text_LawrenceIntro, Route113_Text_LawrenceDefeat
	msgbox Route113_Text_LawrencePostBattle, MSGBOX_AUTOCLOSE
	end

Route113_EventScript_Wyatt::
	trainerbattle_single TRAINER_WYATT, Route113_Text_WyattIntro, Route113_Text_WyattDefeat
	msgbox Route113_Text_WyattPostBattle, MSGBOX_AUTOCLOSE
	end

Route113_Text_AshCanBeFashionedIntoGlass:
	.string "Wahahaha! Today's technology is a\n"
	.string "wondrous thing!\p"
	.string "Take this volcanic ash here.\n"
	.string "It can be fashioned into glass.$"

Route113_Text_FunWalkingThroughAsh:
	.string "It's fun walking through the volcano's\n"
	.string "ashes on the ground and grass.\p"
	.string "You can see where you walked--it's\n"
	.string "really neat!$"

Route113_Text_RouteSign111:
	.string "ROUTE 113\n"
	.string "{RIGHT_ARROW} ROUTE 111$"

Route113_Text_RouteSignFallarbor:
	.string "ROUTE 113\n"
	.string "{LEFT_ARROW} FALLARBOR TOWN$"

Route113_Text_TrainerTipsRegisterKeyItems:
	.string "TRAINER TIPS\p"
	.string "You may register one of the KEY ITEMS\n"
	.string "in your BAG as SELECT.\p"
	.string "Simply press SELECT to use\n"
	.string "the registered item conveniently.$"

Route113_Text_GlassWorkshopSign:
	.string "GLASS WORKSHOP\n"
	.string "“Turning Volcanic Ash into Glass Items”$"

Route113_EventScript_MintMan::
	lock
	faceplayer
	goto_if_set FLAG_MINTS_3, Route113_GotMints
	msgbox Route113_Text_Give_Mints, MSGBOX_DEFAULT
	giveitem ITEM_RELAXED_MINT
	giveitem ITEM_SASSY_MINT
	setflag FLAG_MINTS_3
	clearflag FLAG_MINTS_4
	goto Route113_GotMints
	release
	end

Route113_GotMints::
	msgbox Route113_Received_Mints, MSGBOX_DEFAULT
	release
	end

Route113_Text_Give_Mints:
	.string "Hello again young traveler!\p"
	.string "It's been awhile since we last met!\p"
	.string "The ashy climate here has proved to\n"
	.string "be ideal for growing some new mints!\p"
	.string "Please put these to good use!$"

Route113_Received_Mints:
	.string "Those mints will allow you to raise\n"
	.string "one of your POKéMON's defenses at the\l"
	.string "expense of their speed.\p"
	.string "A slow tank would be the ideal use\n"
	.string "for these mints.\p"
	.string "I look forward to sharing more mints\n"
	.string "with you in the future!$"

Route113_EventScript_RivalScene1::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route113_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route113_EventScript_PlayBrendanMusic
	applymovement LOCALID_RIVAL113, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route113_EventScript_MayBattle
	goto_if_eq VAR_RESULT, FEMALE, Route113_EventScript_BrendanBattle
	releaseall
	end

Route113_EventScript_RivalScene2::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route113_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route113_EventScript_PlayBrendanMusic
	applymovement LOCALID_RIVAL113, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_RIVAL113, RivalMovementDown2
	waitmovement 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route113_EventScript_MayBattle
	goto_if_eq VAR_RESULT, FEMALE, Route113_EventScript_BrendanBattle
	releaseall
	end

Route113_EventScript_RivalScene3::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route113_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route113_EventScript_PlayBrendanMusic
	applymovement LOCALID_RIVAL113, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_RIVAL113, RivalMovementDown3
	waitmovement 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route113_EventScript_MayBattle
	goto_if_eq VAR_RESULT, FEMALE, Route113_EventScript_BrendanBattle
	releaseall
	end

Route113_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route113_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route113_EventScript_MayBattle::
	msgbox Route113_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route113_EventScript_MayBattleTreecko
	case 1, Route113_EventScript_MayBattleTorchic
	case 2, Route113_EventScript_MayBattleMudkip
	end

Route113_EventScript_MayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route113_Text_MayDefeated
	goto Route113_EventScript_MayDefeated
	end

Route113_EventScript_MayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route113_Text_MayDefeated
	goto Route113_EventScript_MayDefeated
	end

Route113_EventScript_MayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route113_Text_MayDefeated
	goto Route113_EventScript_MayDefeated
	end

Route113_EventScript_MayDefeated::
	msgbox Route113_Text_MayTakeThis, MSGBOX_DEFAULT
	call Route113_EventScript_GiveItemfinder
	msgbox Route113_Text_MayExplainItemfinder, MSGBOX_DEFAULT
	goto Route113_EventScript_RivalExit
	end

Route113_EventScript_BrendanBattle::
	msgbox Route113_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route113_EventScript_BrendanBattleTreecko
	case 1, Route113_EventScript_BrendanBattleTorchic
	case 2, Route113_EventScript_BrendanBattleMudkip
	end

Route113_EventScript_BrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route113_Text_BrendanDefeated
	goto Route113_EventScript_BrendanDefeated
	end

Route113_EventScript_BrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route113_Text_BrendanDefeated
	goto Route113_EventScript_BrendanDefeated
	end

Route113_EventScript_BrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route113_Text_BrendanDefeated
	goto Route113_EventScript_BrendanDefeated
	end

Route113_EventScript_BrendanDefeated::
	msgbox Route113_Text_BrendanTakeThis, MSGBOX_DEFAULT
	call Route113_EventScript_GiveItemfinder
	msgbox Route113_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
	goto Route113_EventScript_RivalExit
	end

Route113_EventScript_GiveItemfinder::
	giveitem ITEM_DOWSING_MACHINE
	return

Route113_EventScript_RivalExit::
	closemessage
	applymovement LOCALID_RIVAL113, RivalMovementExit
	waitmovement 0
	removeobject LOCALID_RIVAL113
	setflag FLAG_RIVAL_113
	setvar VAR_ROUTE113_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route113_Text_MayLetsBattle:
	.string "MAY: Hi, {PLAYER}{KUN}, long time no see!\p"
	.string "While I was searching for other\n"
	.string "POKéMON, my POKéMON grew stronger.\p"
	.string "So…\n"
	.string "How about a little battle?$"

Route113_Text_MayDefeated:
	.string "Yikes!\n"
	.string "You're better than I expected!$"

Route113_Text_MayTakeThis:
	.string "MAY: {PLAYER}{KUN}, you've been busy\n"
	.string "training, too, haven't you?\p"
	.string "I think you deserve a reward!\n"
	.string "This is from me!$"

Route113_Text_MayExplainItemfinder:
	.string "MAY: That's an ITEMFINDER.\p"
	.string "Try it out. If there is an item that's\n"
	.string "not visible, it emits a sound.\p"
	.string "Okay, {PLAYER}{KUN}, let's meet again!\p"
	.string "I know it's a little silly coming from\n"
	.string "me, but I think you should train a lot\l"
	.string "harder for the next time.$"

Route113_Text_BrendanLetsBattle:
	.string "BRENDAN: Hey, {PLAYER}.\n"
	.string "So this is where you were.\l"
	.string "How's it going?\p"
	.string "Have you been raising your POKéMON?\n"
	.string "I'll check for you.$"

Route113_Text_BrendanDefeated:
	.string "Hmm…\n"
	.string "You're pretty good.$"

Route113_Text_BrendanTakeThis:
	.string "BRENDAN: {PLAYER}, you've trained\n"
	.string "without me noticing…\p"
	.string "Good enough!\n"
	.string "Here, take this.$"

Route113_Text_BrendanExplainItemfinder:
	.string "BRENDAN: That's an ITEMFINDER.\p"
	.string "Use it to root around for items that\n"
	.string "aren't visible.\p"
	.string "If it senses something, it emits\n"
	.string "a sound.\p"
	.string "Anyway, I'm off to look for new\n"
	.string "POKéMON.$"

RivalMovementDown2:
	walk_down
	step_end

RivalMovementDown3:
	walk_down
	walk_down
	step_end

RivalMovementExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
	
