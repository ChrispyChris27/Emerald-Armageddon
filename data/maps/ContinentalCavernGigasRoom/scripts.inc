ContinentalCavernGigasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, GigasRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, GigasRoom_OnTransition
	.byte 0

GigasRoom_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, EventScript_TryRemoveRegigigas
	end

EventScript_TryRemoveRegigigas::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

GigasRoom_OnTransition:
	call_if_unset FLAG_DEFEATED_REGIGIGAS, EventScript_ShowRegigigas
	end

EventScript_ShowRegigigas::
	clearflag FLAG_HIDE_REGIGIGAS
	return

EventScript_DefeatedRegigigas::
	setflag FLAG_DEFEATED_REGIGIGAS
	goto Common_EventScript_RemoveStaticPokemon
	end

EventScript_RanFromRegigigas::
	setvar VAR_0x8004, SPECIES_REGIGIGAS
	goto Common_EventScript_LegendaryFlewAway
	end

Regigigas_Text:
	.string "It appears to be a statue.\p"
	.string "There is an inscription at the\n"
	.string "base of the statue...\p"
	.string "'Legends say this statue was once a\n"
	.string "powerful POKéMON that towed the\l"
	.string "continents together with ropes.\p"
	.string "The POKéMON, exhausted from this\n"
	.string "act, went into a deep, deep, sleep.\p"
	.string "Before entering it's slumber, the\n"
	.string "POKéMON created five other POKéMON\l"
	.string "to protect it while it rested.\p"
	.string "The first POKéMON was shaped from\n"
	.string "the tallest mountain and carved\l"
	.string "out of rock from the cliffside.\p"
	.string "The second was formed from freezing\n"
	.string "the purest water in the world and\l"
	.string "shaving down the resulting ice block.\p"
	.string "The third was created from magma that\n"
	.string "solidified into a steel harder than\l"
	.string "diamonds under immense pressure.\p"
	.string "The fourth was brought to life from\n"
	.string "the hottest lightning bolt after it\l"
	.string "struck a powerful generator.\p"
	.string "The final POKéMON was born from the\n"
	.string "pearl of the most ferocious dragons\l"
	.string "after absorbing their powerful energy.\p"
	.string "It is said that these five legendary\n"
	.string "giants eventually scattered themselves\l"
	.string "across the world, returning to where\l"
	.string "they were first created.\p"
	.string "The legends state that the only way\n"
	.string "to awaken the sleeping giant is to\l"
	.string "reunite the powers of rock, ice, steel,\l"
	.string "lightning, and the dragons and return\l"
	.string "them all to their creator.'$"

Statue_Motionless:
	.string "The statue is completely motionless.\n"
	.string "The POKéMON remains in a deep slumber.$"

Regigigas_Awakens:
	.string "The statue is moving!\n"
	.string "The slumbering giant has awakened!$"

Regigigas_No_Battle::
	msgbox Statue_Motionless, MSGBOX_DEFAULT
	release
	end

Regigigas_Event_Script::
	lock
	msgbox Regigigas_Text, MSGBOX_DEFAULT
	waitmessage
	specialvar VAR_RESULT, CheckPartyForRegis
	goto_if_eq VAR_RESULT, FALSE, Regigigas_No_Battle
	delay 30
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_NORMAL
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	setobjectmovementtype LOCALID_REGIGIGAS, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	msgbox Regigigas_Awakens, MSGBOX_AUTOCLOSE
	waitse
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIGIGAS, 85
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, EventScript_DefeatedRegigigas
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, EventScript_RanFromRegigigas
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, EventScript_RanFromRegigigas
	setflag FLAG_DEFEATED_REGIGIGAS
	release
	end




