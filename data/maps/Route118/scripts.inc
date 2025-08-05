Route118_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
	.byte 0

Route118_OnTransition:
	call GabbyAndTy_EventScript_UpdateLocation
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_StartGroudonWeather
	end

Route118_OnLoad:
	call_if_unset FLAG_REGI_DOORS_OPENED, Route118_CloseRegiEntrance
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_EventScript_PlaceTilesRoute118East
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_EventScript_PlaceTilesRoute118West
	end

Route118_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route118_CloseRegiEntrance::
	setmetatile 72, 5, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 72, 6, METATILE_General_RockWall_GrassBase, TRUE
	return

Route118_EventScript_GoodRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route118_EventScript_ReceivedGoodRod
	msgbox Route118_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route118_EventScript_ReceiveGoodRod
	goto_if_eq VAR_RESULT, NO, Route118_EventScript_DeclineGoodRod
	end

Route118_EventScript_ReceiveGoodRod::
	msgbox Route118_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_GOOD_ROD
	msgbox Route118_Text_TryYourLuckFishing, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_DeclineGoodRod::
	msgbox Route118_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_ReceivedGoodRod::
	msgbox Route118_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_Girl::
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
	end

Route118_EventScript_RouteSignMauville::
	msgbox Route118_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route118_EventScript_RouteSign119::
	msgbox Route118_Text_RouteSign119, MSGBOX_SIGN
	end

Route118_EventScript_StevenTrigger0::
	lockall
	setvar VAR_0x8008, 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenApproachLedge0
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger1::
	lockall
	setvar VAR_0x8008, 1
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger2::
	lockall
	setvar VAR_0x8008, 2
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenApproachLedge2
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end

Route118_EventScript_StevenTrigger::
	playse SE_LEDGE
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenJumpLedge
	waitmovement 0
	delay 30
	msgbox Route118_Text_StevenQuestions, MSGBOX_DEFAULT
	giveitem ITEM_MEGA_RING
	msgbox Route118_Text_StevenMega, MSGBOX_DEFAULT
	giveitem ITEM_MAWILITE
	msgbox Route_118_Text_StevenMawile, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, Route118_EventScript_StevenExit0
	call_if_eq VAR_0x8008, 1, Route118_EventScript_StevenExit1
	call_if_eq VAR_0x8008, 2, Route118_EventScript_StevenExit2
	setvar VAR_ROUTE118_STATE, 1
	removeobject LOCALID_ROUTE118_STEVEN
	releaseall
	end

Route118_EventScript_StevenExit0::
	applymovement LOCALID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenExit0
	waitmovement 0
	return

Route118_EventScript_StevenExit1::
	applymovement LOCALID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenExit1
	waitmovement 0
	return

Route118_EventScript_StevenExit2::
	applymovement LOCALID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenExit2
	waitmovement 0
	return

Route118_Movement_PlayerWatchStevenExit:
	delay_16
	walk_in_place_faster_right
	step_end

Route118_Movement_StevenApproachLedge0:
	walk_left
	step_end

Route118_Movement_StevenApproachLedge2:
	walk_right
	step_end

Route118_Movement_StevenJumpLedge:
	jump_2_down
	delay_16
	walk_down
	step_end

Route118_Movement_StevenExit0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_Movement_StevenExit1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_Movement_StevenExit2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_EventScript_Rose::
	trainerbattle_single TRAINER_ROSE_1, Route118_Text_RoseIntro, Route118_Text_RoseDefeat, Route118_EventScript_RegisterRose
	msgbox Route118_Text_RosePostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_RegisterRose::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route118_Text_RoseRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ROSE_1
	release
	end


Route118_EventScript_Barny::
	trainerbattle_single TRAINER_BARNY, Route118_Text_BarnyIntro, Route118_Text_BarnyDefeat
	msgbox Route118_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Wade::
	trainerbattle_single TRAINER_WADE, Route118_Text_WadeIntro, Route118_Text_WadeDefeat
	msgbox Route118_Text_WadePostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Dalton::
	trainerbattle_single TRAINER_DALTON_1, Route118_Text_DaltonIntro, Route118_Text_DaltonDefeat, Route118_EventScript_RegisterDalton
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route118_EventScript_RematchDalton
	msgbox Route118_Text_DaltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_RegisterDalton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route118_Text_DaltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DALTON_1
	release
	end

Route118_EventScript_RematchDalton::
	trainerbattle_rematch TRAINER_DALTON_1, Route118_Text_DaltonRematchIntro, Route118_Text_DaltonRematchDefeat
	msgbox Route118_Text_DaltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Perry::
	trainerbattle_single TRAINER_PERRY, Route118_Text_PerryIntro, Route118_Text_PerryDefeat
	msgbox Route118_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Chester::
	trainerbattle_single TRAINER_CHESTER, Route118_Text_ChesterIntro, Route118_Text_ChesterDefeat
	msgbox Route118_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Deandre::
	trainerbattle_single TRAINER_DEANDRE, Route118_Text_DeandreIntro, Route118_Text_DeandreDefeat
	msgbox Route118_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
	end

Route118_Text_StevenQuestions:
	.string "STEVEN: Hi, {PLAYER}{KUN}!\p"
	.string "It's me, STEVEN!\n"
	.string "We met in the cave near DEWFORD.\p"
	.string "Have you met many kinds of POKéMON\n"
	.string "since I last saw you?\p"
	.string "There are many, many kinds of POKéMON\n"
	.string "in this wide world of ours.\p"
	.string "If you wanted to raise only your\n"
	.string "favorites, that's fine.\p"
	.string "Perhaps you find it more fun to \n"
	.string "raise all sorts of POKéMON.\p"
	.string "Regardless, I think this will help\n"
	.string "you continue getting stronger.$"

Route118_Text_StevenMega:
	.string "That MEGA RING allows certain species\n"
	.string "of POKéMON to transform into a more\l"
	.string "powerful form in battle.\p"
	.string "Not every POKéMON is capable of MEGA\n"
	.string "EVOLUTION however.\p"
	.string "The POKéMON you intend to MEGA EVOLVE\n"
	.string "also needs to be holding its MEGA STONE.\p"
	.string "You will likely encounter some of these\n"
	.string "stones throughout your travels, but \l"
	.string "allow me to start off your collection \l"
	.string "with this one.$"

Route_118_Text_StevenMawile:
	.string "The MAWILITE allows MAWILE to mega\n"
	.string "evolve.\p"
	.string "MAWILE is one of the many STEEL type\n"
	.string "POKéMON I adore.\p"
	.string "Please put its mega stone to good use.\p"
	.string "By the way, I heard that TEAM AQUA was\n"
	.string "recently sighted nearby.\p"
	.string "I have matters I must attend to but\n"
	.string "perhaps you could pay them a visit?\p"
	.string "I'm sure our paths will cross again.\p"
	.string "Farewell for now.$"

Route118_Text_YouAgreeGoodRodIsGood:
	.string "Hmm!\n"
	.string "A GOOD ROD is really good!\p"
	.string "Wouldn't you agree?$"

Route118_Text_IdenticalMindsTakeThis:
	.string "Hmm!\n"
	.string "We're of identical minds!\p"
	.string "Hmm!\n"
	.string "Take this GOOD ROD!$"

Route118_Text_TryYourLuckFishing:
	.string "Wherever there's water, try your luck\n"
	.string "at fishing.$"

Route118_Text_DontYouLikeToFish:
	.string "Don't you like to fish?$"

Route118_Text_TryCatchingMonWithGoodRod:
	.string "Try catching all sorts of POKéMON\n"
	.string "with your GOOD ROD.$"

Route118_Text_CanCrossRiversWithSurf:
	.string "Even if there isn't a boat, you can\n"
	.string "cross rivers and the sea if you have\l"
	.string "a POKéMON that knows SURF.\p"
	.string "POKéMON can be counted on to do so\n"
	.string "much!$"

Route118_Text_RouteSignMauville:
	.string "ROUTE 118\n"
	.string "{LEFT_ARROW} MAUVILLE CITY$"

Route118_Text_RouteSign119:
	.string "ROUTE 118\n"
	.string "{UP_ARROW} ROUTE 119$"

Route118_Text_Grunt1:
	.string "What are you looking at punk?\p"
	.string "TEAM MAGMA has business in these\n"
	.string "parts so you better get lost!$"

Route118_Text_Grunt2:
	.string "The boss was looking for a source\n"
	.string "of energy that was strong enough to\l"
	.string "awaken GROUDON.\p"
	.string "Oh no! I wasn't supposed to mention\n"
	.string "GROUDON!$"

Route118_EventScript_Grunt1::
	msgbox Route118_Text_Grunt1, MSGBOX_NPC
	end

Route118_EventScript_Grunt2::
	msgbox Route118_Text_Grunt2, MSGBOX_NPC
	end

MeetFangTutor:
	.string "Many POKéMON utilize their jaws to\n"
	.string "inflict damage in battle.\p"
	.string "I have mastered this art and could\n"
	.string "teach your POKéMON how to use their\l"
	.string "fangs in battle.$"

FangTutorTeachMove:
	.string "Which move should I teach your POKéMON?$"

FangTutorShouldTeach:
	.string "What do you say? Shall I teach your\n"
	.string "POKéMON a move that uses fangs?$"

FangTutorChooseMon:
	.string "Which POKéMON should I teach?$"

FangTutorDontTeachText:
	.string "If you change your mind, I would be\n"
	.string "happy to teach your POKéMON later.$"

FangTutorTaughtMove:
	.string "Done! Your POKéMON has learned a\n"
	.string "new technique for battle!\p"
	.string "If you ever want me to teach another\n"
	.string "move to your POKéMON let me know.$"

FangTutorScript::
	lock
	faceplayer
	goto_if_unset FLAG_MET_FANG_TUTOR, MeetFangTutorScript
	goto FangTutorTeachMoveScript
	release
	end

MeetFangTutorScript::
	msgbox MeetFangTutor, MSGBOX_DEFAULT
	setflag FLAG_MET_FANG_TUTOR
	goto FangTutorTeachMoveScript
	release
	end

FangTutorSuccess::
	msgbox FangTutorTaughtMove, MSGBOX_DEFAULT
	release
	end

FangTutorTeachMoveScript::
	msgbox FangTutorShouldTeach, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FangTutorDeclined
	msgbox FangTutorTeachMove, MSGBOX_DEFAULT
	waitmessage
	multichoice 20, 0, MULTI_FANG_TUTOR, FALSE
	switch VAR_RESULT
	case 0, TeachFireFang
	case 1, TeachIceFang
	case 2, TeachThunderFang
	case 3, TeachPoisonFang
	case 4, TeachHyperFang
	case 5, TeachPsychicFangs
	case MULTI_B_PRESSED, FangTutorDeclined
	release
	end

FangTutorDeclined::
	msgbox FangTutorDontTeachText, MSGBOX_AUTOCLOSE
	release
	end

TeachFireFang::
	msgbox FangTutorChooseMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_FIRE_FANG
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, FangTutorDeclined
	goto FangTutorSuccess
	release
	end

TeachIceFang::
	msgbox FangTutorChooseMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_ICE_FANG
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, FangTutorDeclined
	goto FangTutorSuccess
	release
	end

TeachThunderFang::
	msgbox FangTutorChooseMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_THUNDER_FANG
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, FangTutorDeclined
	goto FangTutorSuccess
	release
	end

TeachPoisonFang::
	msgbox FangTutorChooseMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_POISON_FANG
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, FangTutorDeclined
	goto FangTutorSuccess
	release
	end

TeachHyperFang::
	msgbox FangTutorChooseMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_HYPER_FANG
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, FangTutorDeclined
	goto FangTutorSuccess
	release
	end

TeachPsychicFangs::
	msgbox FangTutorChooseMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_PSYCHIC_FANGS
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, FangTutorDeclined
	goto FangTutorSuccess
	release
	end
