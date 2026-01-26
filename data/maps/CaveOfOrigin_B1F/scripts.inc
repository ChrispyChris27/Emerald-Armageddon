CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	clearflag FLAG_TOTEM_CHARIZARD_MEGA
	clearflag FLAG_TOTEM_LUDICOLO
	clearflag FLAG_TOTEM_DURALUDON
	clearflag FLAG_TOTEM_SHIFTRY
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Ah, so you are {PLAYER}{KUN}?\n"
	.string "I've heard tales of your exploits.\p"
	.string "My name is Wallace.\p"
	.string "I was once the gym leader of\n"
	.string "Sootopolis, but lately I have been\l"
	.string "more focused on researching ancient\l"
	.string "times in Hoenn.\p"
	.string "For now, I've entrusted my mentor JUAN\n"
	.string "with the GYM's operation.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "I suppose you wish to learn what I've\n"
	.string "discovered so far.\p"
	.string "In ancient times, it appears that most\n"
	.string "who lived in Hoenn resided deep within\l"
	.string "Meteor Falls in an ancient castle.\p"
	.string "The castle was carved out of rock\n"
	.string "formations deep within the cave system.\p"
	.string "While we aren't yet sure why, at some\n"
	.string "point, the castle was sealed off\l"
	.string "from the outside world.\p"
	.string "Presumably, those inside the castle\n"
	.string "when it was sealed ultimately perished\l"
	.string "within the walls meant to protect them.\p"
	.string "One thing we can be sure of from\n"
	.string "artifacts we have uncovered is that\l"
	.string "the people of ancient Hoenn worshipped\l"
	.string "many super-ancient pokémon.\p"
	.string "Groudon and Kyogre, the two pokémon\n"
	.string "wreaking havoc here, are considered\l"
	.string "to be super-ancient pokémon.\p"
	.string "But there aren't just two super-\n"
	.string "ancient pokémon.\p"
	.string "There are more somewhere.\p"
	.string "Somewhere, there is a super-\n"
	.string "ancient pokémon named Rayquaza.\p"
	.string "It's said that it was Rayquaza that\n"
	.string "becalmed the two combatants in\l"
	.string "the distant past.\p"
	.string "Once calmed, Groudon and Kyogre were\n"
	.string "able to create the land and sea in the\l"
	.string "eastern part of Hoenn we inhabit today.\p"
	.string "A fourth pokémon, Regigigas, helped\n"
	.string "tow the land Groudon created to where\l"
	.string "it is today.\p"
	.string "After all of this, Regigigas, Groudon,\n"
	.string "and Kyogre went into deep slumbers.\p"
	.string "Rayquaza however flew off into space.\p"
	.string "It is said that Rayquaza returned to\n"
	.string "Hoenn at some point, but its wherabouts\l"
	.string "have remained unknown.$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "WALLACE: {PLAYER}{KUN}, do you perhaps\n"
	.string "know where RAYQUAZA is now?\p"
	.string "If you do, please tell me.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "WALLACE: The CAVE OF ORIGIN?\p"
	.string "But that's right here!\n"
	.string "I need you to do better than that!\p"
	.string "Please, I need you to think about\n"
	.string "where RAYQUAZA might be right now.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "WALLACE: MT. PYRE?\p"
	.string "But when I met the old lady there\n"
	.string "earlier, she made no mention of it.\p"
	.string "I very much doubt that the old lady\n"
	.string "would try to hide something from me…\p"
	.string "{PLAYER}{KUN}, could you think about this\n"
	.string "more carefully for me?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "WALLACE: Huh? You don't remember?\n"
	.string "Hmm… That's a problem…\p"
	.string "Can't you remember somehow?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "WALLACE: The SKY PILLAR?\p"
	.string "That's it!\n"
	.string "It must be the SKY PILLAR!\p"
	.string "{PLAYER}{KUN}, there's not a moment to lose!\n"
	.string "I'll head to the SKY PILLAR right away!\p"
	.string "Once you have calmed all of the rogue\n"
	.string "POKéMON please meet me there!$"

