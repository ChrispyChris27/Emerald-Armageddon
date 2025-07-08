SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Hi, hi! I'm the NAME RATER!\n"
	.string "I'm the fortune-teller of names!\p"
	.string "I shall be pleased to rate your\n"
	.string "POKéMON's nickname.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Which POKéMON's nickname should\n"
	.string "I critique?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hmmm… {STR_VAR_1}, is it? That is\n"
	.string "quite a fine name you bestowed.\p"
	.string "But! What say you, if I were to\n"
	.string "suggest a slightly better name?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ah, good. Then, what shall the new\n"
	.string "nickname be?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Done! From now on, this POKéMON\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It is a better name than before!\n"
	.string "How fortunate for you!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "I see.\n"
	.string "Do come visit again.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Done! From now on, this POKéMON\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It looks no different from before,\n"
	.string "and yet, this is vastly superior!\p"
	.string "How fortunate for you!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hmmm… {STR_VAR_1} it is!\p"
	.string "This is a magnificent nickname!\n"
	.string "It is impeccably beyond reproach!\p"
	.string "You'll do well to cherish your\n"
	.string "{STR_VAR_1} now and beyond.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Now, now.\n"
	.string "That is merely an EGG!$"

HyperTrainerIntroText:
	.string "Back in the olden days I used to\n"
	.string "rate the nicknames of POKéMON.\p"
	.string "Unfortunately times change and there\n"
	.string "is no need for such a job anymore.\p"
	.string "Since I retired from rating names, I\n"
	.string "dedicated my life to training POKéMON.\p"
	.string "I was eventually able to unlock the\n"
	.string "true power of any POKéMON.\p"
	.string "Now I am enjoying my retirement by\n"
	.string "collecting all manner of BOTTLE CAPS\l"
	.string "That I can find.\p"
	.string "If you find any BOTTLE CAPS on your\n"
	.string "journey that you are willing to part\l"
	.string "with, I would be happy to unlock the\l"
	.string "full potential of your POKéMON.$"

HyperTrainNoCapText:
	.string "If you find any BOTTLE CAPS on your\n"
	.string "journey that you are willing to part\l"
	.string "with, I would be happy to unlock the\l"
	.string "full potential of your POKéMON.$"

DeclineHyperTraining:
	.string "So you'd prefer to hold onto your\n"
	.string "BOTTLE CAP for now.\p"
	.string "Very well.\n"
	.string "I can respect a fellow collector.\p"
	.string "If you find any BOTTLE CAPS on your\n"
	.string "journey that you are willing to part\l"
	.string "with, I would be happy to unlock the\l"
	.string "full potential of your POKéMON.$"

GoldBottleCapInBag:
	.string "Oh my!\p"
	.string "That BOTTLE CAP seems to be\n"
	.string "glittering like gold!\p"
	.string "If you are willing, I would max the\n"
	.string "power of not just one, but all of\l"
	.string "your POKéMON'S stats in exchange for\l"
	.string "that beautiful golden BOTTLE CAP!\p"
	.string "What do you say?$"

KeepGoldGiveRegular:
	.string "I understand the desire to keep such\n"
	.string "a beautiful BOTTLE CAP to yourself.\p"
	.string "It seems that isn't the only BOTTLE\n"
	.string "CAP you have though.\p"
	.string "Shall I train one of your POKéMON'S\n"
	.string "stats in exchange for one of your\l"
	.string "other BOTTLE CAPS?$"

GoldCapSelectMon:
	.string "Amazing!\n"
	.string "Astounding!\l"
	.string "Incredible!\p"
	.string "Which of your POKéMON shall achieve\n"
	.string "their maximum potential?$"

GoldHyperTrainingComplete:
	.string "Done!\p"
	.string "Your POKéMON has unlocked its\n"
	.string "maximum potential!\p"
	.string "If you would like me to train another\n"
	.string "of your POKéMON, come back with\l"
	.string "another BOTTLE CAP.$"

RegCapSelectMon:
	.string "Which of your POKéMON should I train?$"

RegCapSelectStat:
	.string "Which of this POKéMON's stats should\n"
	.string "I unlock the full potential of?$"

CantHyperTrain:
	.string "This POKéMON has already achieved its\n"
	.string "maximum potential in that stat!\p"
	.string "I can't train it to be any stronger!$"

RegCapComplete:
	.string "Done!\p"
	.string "Your POKéMON has unlocked the\n"
	.string "full potential of one of its stats!\p"
	.string "If you would like me to train another\n"
	.string "POKéMON or another of this one's stats,\l"
	.string "come back with another BOTTLE CAP.$"

AllStatsMaxed:
	.string "This POKéMON has already achieved its\n"
	.string "maximum potential!\p"
	.string "It is a truly flawless specimen!\n"
	.string "Even I cannot improve its ability!$"

CantTrainEgg:
	.string "Why this is merely an EGG!\p"
	.string "Even I cannot unlock the full\n"
	.string "potential of an EGG!\p"
	.string "Once your EGG hatches I can train\n"
	.string "the POKéMON that was inside.$"

SlateportCity_HyperTraining::
	lock
	faceplayer
	goto_if_unset FLAG_TRAINER_MET, HyperTrainerIntro
	checkitem ITEM_GOLD_BOTTLE_CAP
	goto_if_eq VAR_RESULT, FALSE, HyperTrainNoGoldCap
	msgbox GoldBottleCapInBag, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, HyperTrainGoldCap
	checkitem ITEM_BOTTLE_CAP
	goto_if_eq VAR_RESULT, FALSE, HyperTrainingDeclined
	msgbox KeepGoldGiveRegular, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, HyperTrainRegCap
	goto HyperTrainingDeclined

HyperTrainerIntro::
	msgbox HyperTrainerIntroText, MSGBOX_AUTOCLOSE
	setflag FLAG_TRAINER_MET
	release
	end

HyperTrainingDeclined:
	msgbox DeclineHyperTraining, MSGBOX_AUTOCLOSE
	release
	end

HyperTrainNoCap::
	msgbox HyperTrainNoCapText, MSGBOX_AUTOCLOSE
	release
	end

HyperTrainNoGoldCap::
	checkitem ITEM_BOTTLE_CAP
	goto_if_eq VAR_RESULT, FALSE, HyperTrainNoCap
	goto HyperTrainRegCap

HyperTrainGoldCap::
	msgbox GoldCapSelectMon, MSGBOX_AUTOCLOSE
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, HyperTrainingDeclined
	specialvar VAR_0x8004, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, CannotTrainEgg
	canhypertrain STAT_HP, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, HyperTrainAllStats
	canhypertrain STAT_ATK, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, HyperTrainAllStats
	canhypertrain STAT_DEF, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, HyperTrainAllStats
	canhypertrain STAT_SPATK, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, HyperTrainAllStats
	canhypertrain STAT_SPDEF, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, HyperTrainAllStats
	canhypertrain STAT_SPEED, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, HyperTrainAllStats
	msgbox AllStatsMaxed, MSGBOX_AUTOCLOSE
	release
	end

HyperTrainAllStats::
	hypertrain STAT_ATK, VAR_0x8004
	hypertrain STAT_DEF, VAR_0x8004
	hypertrain STAT_SPATK, VAR_0x8004
	hypertrain STAT_SPDEF, VAR_0x8004
	hypertrain STAT_HP, VAR_0x8004
	hypertrain STAT_SPEED, VAR_0x8004
	msgbox GoldHyperTrainingComplete, MSGBOX_AUTOCLOSE
	release
	end

HyperTrainRegCap::
	msgbox RegCapSelectMon, MSGBOX_AUTOCLOSE
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, HyperTrainingDeclined
	specialvar VAR_0x8004, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, CannotTrainEgg
	msgbox RegCapSelectStat, MSGBOX_DEFAULT
	waitmessage
	multichoice 20, 1, MULTI_HYPER_TRAIN, TRUE
	switch VAR_RESULT
	case 0, HyperTrainHP
	case 1, HyperTrainAttack
	case 2, HyperTrainDefense
	case 3, HyperTrainSpAttack
	case 4, HyperTrainSpDef
	case 5, HyperTrainSpeed
	case MULTI_B_PRESSED, HyperTrainingDeclined

HyperTrainStatMaxed::
	msgbox CantHyperTrain, MSGBOX_AUTOCLOSE
	release
	end

RegCapTrainingComplete::
	msgbox RegCapComplete, MSGBOX_AUTOCLOSE
	release
	end

HyperTrainHP::
	canhypertrain STAT_HP, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, HyperTrainStatMaxed
	hypertrain STAT_HP, VAR_0x8004
	goto RegCapTrainingComplete

HyperTrainAttack::
	canhypertrain STAT_ATK, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, HyperTrainStatMaxed
	hypertrain STAT_ATK, VAR_0x8004
	goto RegCapTrainingComplete

HyperTrainDefense::
	canhypertrain STAT_DEF, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, HyperTrainStatMaxed
	hypertrain STAT_DEF, VAR_0x8004
	goto RegCapTrainingComplete

HyperTrainSpAttack::
	canhypertrain STAT_SPATK, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, HyperTrainStatMaxed
	hypertrain STAT_SPATK, VAR_0x8004
	goto RegCapTrainingComplete

HyperTrainSpDef::
	canhypertrain STAT_SPDEF, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, HyperTrainStatMaxed
	hypertrain STAT_SPDEF, VAR_0x8004
	goto RegCapTrainingComplete

HyperTrainSpeed::
	canhypertrain STAT_SPEED, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, HyperTrainStatMaxed
	hypertrain STAT_SPEED, VAR_0x8004
	goto RegCapTrainingComplete

CannotTrainEgg::
	msgbox CantTrainEgg, MSGBOX_AUTOCLOSE
	release
	end
