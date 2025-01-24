.set LOCAL_ID_GRUNT_1, 24
.set LOCAL_ID_GRUNT_2, 25 
.set LOCAL_ID_GIOVANNI, 26
.set LOCAL_ID_ROXANNE, 27

Route115_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route115_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route115_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route115_OnFrame
	.byte 0

Route115_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST, AbnormalWeather_EventScript_PlaceTilesRoute115West
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST, AbnormalWeather_EventScript_PlaceTilesRoute115East
	end

Route115_OnTransition:
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST, AbnormalWeather_StartGroudonWeather
	end

Route115_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route115_EventScript_Woman::
	msgbox Route115_Text_NeverKnowWhenCavePokemonWillAppear, MSGBOX_NPC
	end

Route115_EventScript_RouteSignRustboro::
	msgbox Route115_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route115_EventScript_MeteorFallsSign::
	msgbox Route115_Text_MeteorFallsSign, MSGBOX_SIGN
	end

Route115_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY_1, Route115_Text_TimothyIntro, Route115_Text_TimothyDefeat, Route115_EventScript_RegisterTimothy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchTimothy
	msgbox Route115_Text_TimothyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterTimothy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_TimothyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIMOTHY_1
	release
	end

Route115_EventScript_RematchTimothy::
	trainerbattle_rematch TRAINER_TIMOTHY_1, Route115_Text_TimothyRematchIntro, Route115_Text_TimothyRematchDefeat
	msgbox Route115_Text_TimothyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Koichi::
	trainerbattle_single TRAINER_KOICHI, Route115_Text_KoichiIntro, Route115_Text_KoichiDefeat
	msgbox Route115_Text_KoichiPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Nob::
	trainerbattle_single TRAINER_NOB_1, Route115_Text_NobIntro, Route115_Text_NobDefeat, Route115_EventScript_RegisterNob
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchNob
	msgbox Route115_Text_NobPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterNob::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_NobRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NOB_1
	release
	end

Route115_EventScript_RematchNob::
	trainerbattle_rematch TRAINER_NOB_1, Route115_Text_NobRematchIntro, Route115_Text_NobRematchDefeat
	msgbox Route115_Text_NobPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Cyndy::
	trainerbattle_single TRAINER_CYNDY_1, Route115_Text_CyndyIntro, Route115_Text_CyndyDefeat, Route115_EventScript_RegisterCyndy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchCyndy
	msgbox Route115_Text_CyndyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterCyndy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_CyndyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CYNDY_1
	release
	end

Route115_EventScript_RematchCyndy::
	trainerbattle_rematch TRAINER_CYNDY_1, Route115_Text_CyndyRematchIntro, Route115_Text_CyndyRematchDefeat
	msgbox Route115_Text_CyndyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Hector::
	trainerbattle_single TRAINER_HECTOR, Route115_Text_HectorIntro, Route115_Text_HectorDefeat
	msgbox Route115_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Kyra::
	trainerbattle_single TRAINER_KYRA, Route115_Text_KyraIntro, Route115_Text_KyraDefeat
	msgbox Route115_Text_KyraPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Jaiden::
	trainerbattle_single TRAINER_JAIDEN, Route115_Text_JaidenIntro, Route115_Text_JaidenDefeat
	msgbox Route115_Text_JaidenPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Alix::
	trainerbattle_single TRAINER_ALIX, Route115_Text_AlixIntro, Route115_Text_AlixDefeat
	msgbox Route115_Text_AlixPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Helene::
	trainerbattle_single TRAINER_HELENE, Route115_Text_HeleneIntro, Route115_Text_HeleneDefeat
	msgbox Route115_Text_HelenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Marlene::
	trainerbattle_single TRAINER_MARLENE, Route115_Text_MarleneIntro, Route115_Text_MarleneDefeat
	msgbox Route115_Text_MarlenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_Text_NeverKnowWhenCavePokemonWillAppear:
	.string "Exploring a cave isn't like walking\n"
	.string "on a road.\p"
	.string "You never know when wild POKéMON will\n"
	.string "appear. It's full of suspense.$"

Route115_Text_RouteSignRustboro:
	.string "ROUTE 115\n"
	.string "{DOWN_ARROW} RUSTBORO CITY$"

Route115_Text_MeteorFallsSign:
	.string "METEOR FALLS\n"
	.string "FALLARBOR TOWN THROUGH HERE$"

Route115_Text_Grunt15Intro:
	.string "Hey! You aren't a member of TEAM\n"
	.string "ROCKET!\p"
	.string "I can't let you get any closer\n"
	.string "to the boss!$"

Route115_Text_Grunt15Defeat:
	.string "Maybe you should join TEAM ROCKET?$"

Route115_Text_Grunt15PostBattle:
	.string "If you won't join us, at least\n"
	.string "stay out of our way!$"

Route115_EventScript_Grunt15::
	trainerbattle_single TRAINER_FALLS_GRUNT_15, Route115_Text_Grunt15Intro, Route115_Text_Grunt15Defeat
	msgbox Route115_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

Route115_Text_Grunt16Intro:
	.string "I'm sure our boss could absolutely\n"
	.string "crush you, but I'll beat you myself\l"
	.string "so he doesn't waste his time!$"

Route115_Text_Grunt16Defeat:
	.string "I'll watch the boss wipe the floor\n"
	.string "with you!$"

Route115_Text_Grunt16PostBattle:
	.string "The boss is going to crush you\n"
	.string "like a REGIGIGAS crushes the earth!$"

Route115_EventScript_Grunt16::
	trainerbattle_single TRAINER_FALLS_GRUNT_16, Route115_Text_Grunt16Intro, Route115_Text_Grunt16Defeat
	msgbox Route115_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

Route115_Text_GiovanniPreBattle:
	.string "You must be who I was warned about.\p"
	.string "Allow me to introduce myself.\p"
	.string "I am GIOVANNI! The LEADER of TEAM\n"
	.string "ROCKET!\p"
	.string "You may have beaten all of my grunts\n"
	.string "but you're too late to stop our plans!\p"
	.string "You see, a long time ago a powerful,\n"
	.string "ancient POKéMON descended from outer\l"
	.string "space into the HOENN region.\p"
	.string "Legends say this POKéMON was able to\n"
	.string "harness the power of METEORITES to\l"
	.string "achieve incredible power!\p"
	.string "I intend to find this POKéMON and\n"
	.string "unlock this power!\p"
	.string "Fwahahahaha!!!!\p"
	.string "That useless TEAM MAGMA may have\n"
	.string "beaten us to the largest METEORITE,\l"
	.string "but it turns out that METEOR FALLS\l"
	.string "itself is filled with particles and\l"
	.string "dust that come from METEORITES.\p"
	.string "Our research here is now complete,\n"
	.string "and phase two of our plan can now\l"
	.string "commence!\p"
	.string "I've already captured the strongest\n"
	.string "POKéMON in KANTO, and soon enough the\l"
	.string "strongest POKéMON in HOENN will also\l"
	.string "be mine!\p"
	.string "Of course, now that you know this,\n"
	.string "I'll have to stop you from meddling\l"
	.string "with my plans anymore.\p"
	.string "Allow me to introduce you do a world\n"
	.string "of pain and suffering!$"

Route115_Text_GiovanniDefeat:
	.string "You do have impressive power.$"

Route115_Text_GiovanniPostBattle:
	.string "I see now how you were able to so\n"
	.string "effortlessly defeat my grunts.\p"
	.string "It doesn't matter though. We've\n"
	.string "gotten what we came here for.\p"
	.string "There is much to do, I don't have\n"
	.string "have the time for any more chit chat!\p"
	.string "We will be on our way now, and you\n"
	.string "would do well to stay clear of us in\l"
	.string "the future!$"

Route115_Movement_Giovanni:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route115_Movement_Player:
	walk_down
	walk_right
	face_left
	step_end

Route115_Movement_Roxanne:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route115_Text_Roxanne:
	.string "Are they finally gone?\p"
	.string "Thank you for your help in\n"
	.string "clearing those TEAM ROCKET\l"
	.string "fellows out of METEOR FALLS.\p"
	.string "I was researching some rocks in\n"
	.string "the deeper parts of the cave with\l"
	.string "ROXANNE when those hooligans arrived.\p"
	.string "We probably could have beaten them\n"
	.string "in battle ourselves, but we decided\l"
	.string "to wait it out and see what we could\l"
	.string "learn about why they were here.\p"
	.string "Oh, so you know as well?\p"
	.string "That they are trying to use the\n"
	.string "METEORITES to somehow awaken the\l"
	.string "powers of a super ancient POKéMON.\p"
	.string "I'm unsure what POKéMON they may be\n"
	.string "looking for unfortunately.\p"
	.string "Well, since we finished our research,\n"
	.string "ROXANNE should have arrived back at\l"
	.string "the RUSTBORO CITY GYM.\p"
	.string "You should show her the power\n"
	.string "that allowed you to defeat all those\l"
	.string "TEAM ROCKET thugs.$"

Route115_EventScript_Giovanni::
	lockall
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	applymovement LOCAL_ID_GIOVANNI, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route115_Text_GiovanniPreBattle, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GIOVANNI_1, Route115_Text_GiovanniDefeat
	msgbox Route115_Text_GiovanniPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_GIOVANNI, Route115_Movement_Giovanni
	waitmovement 0
	removeobject LOCAL_ID_GIOVANNI
	removeobject LOCAL_ID_GRUNT_1
	removeobject LOCAL_ID_GRUNT_2
	setflag FLAG_GIOVANNI_FALLS
	clearflag FLAG_115_ROXANNE
	addobject LOCAL_ID_ROXANNE
	applymovement LOCAL_ID_ROXANNE, Route115_Movement_Giovanni
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox Route115_Text_Roxanne, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route115_Movement_Player
	waitmovement 0
	applymovement LOCAL_ID_ROXANNE, Route115_Movement_Roxanne
	waitmovement 0
	removeobject LOCAL_ID_ROXANNE
	releaseall
	end

