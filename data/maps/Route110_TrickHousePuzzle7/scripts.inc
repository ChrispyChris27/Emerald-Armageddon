Route110_TrickHousePuzzle7_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle7_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle7_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle7_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHousePuzzle7_OnFrame
	.byte 0

@ Puzzle Room 7 in RSE uses whatever puzzle Mossdeep Gym uses
@ Because Mossdeep Gym was redesigned for Emerald, theres a good deal of leftover script from the old R/S puzzle

Route110_TrickHousePuzzle7_OnResume:
	call Route110_TrickHousePuzzle7_EventScript_UpdateSwitchMetatiles
	end

Route110_TrickHousePuzzle7_EventScript_UpdateSwitchMetatiles::
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_SetSwitch1MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_SetSwitch2MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_SetSwitch3MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_SetSwitch4MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_SetSwitch5MetatilesOn
	return

@ Leftover from R/S, none of the below metatile scripts are ever called
Route110_TrickHousePuzzle7_EventScript_SetSwitch1MetatilesOn::
	setmetatile 13, 17, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Up, FALSE
	setmetatile 12, 16, METATILE_TrickHousePuzzle_Lever_On, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch2MetatilesOn::
	setmetatile 12, 13, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Up, FALSE
	setmetatile 12, 11, METATILE_TrickHousePuzzle_Lever_On, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch3MetatilesOn::
	setmetatile 7, 12, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Up, FALSE
	setmetatile 5, 10, METATILE_TrickHousePuzzle_Lever_On, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch4MetatilesOn::
	setmetatile 6, 6, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Right_Alt, FALSE
	setmetatile 4, 4, METATILE_TrickHousePuzzle_Lever_On, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch5MetatilesOn::
	setmetatile 8, 4, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Left, FALSE
	setmetatile 7, 5, METATILE_TrickHousePuzzle_Lever_On, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch1MetatilesOff::
	setmetatile 13, 17, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Down, FALSE
	setmetatile 12, 16, METATILE_TrickHousePuzzle_Lever_Off, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch2MetatilesOff::
	setmetatile 12, 13, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Left, FALSE
	setmetatile 12, 11, METATILE_TrickHousePuzzle_Lever_Off, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch3MetatilesOff::
	setmetatile 7, 12, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Down, FALSE
	setmetatile 5, 10, METATILE_TrickHousePuzzle_Lever_Off, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch4MetatilesOff::
	setmetatile 6, 6, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Left_Alt, FALSE
	setmetatile 4, 4, METATILE_TrickHousePuzzle_Lever_Off, TRUE
	return

Route110_TrickHousePuzzle7_EventScript_SetSwitch5MetatilesOff::
	setmetatile 8, 4, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Right, FALSE
	setmetatile 7, 5, METATILE_TrickHousePuzzle_Lever_Off, TRUE
	return

Route110_TrickHousePuzzle7_OnTransition:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1, Route110_TrickHousePuzzle7_EventScript_TeleportedTransition
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5
	end

Route110_TrickHousePuzzle7_EventScript_TeleportedTransition::
	end

Route110_TrickHousePuzzle7_OnLoad:
	call_if_eq VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1, Route110_TrickHousePuzzle7_EventScript_UpdateSwitchMetatiles
	end

Route110_TrickHousePuzzle7_OnFrame:
	map_script_2 VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1, Route110_TrickHousePuzzle7_EventScript_ClearState2
	.2byte 0

Route110_TrickHousePuzzle7_EventScript_ClearState2::
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 0
	end

Route110_TrickHousePuzzle7_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_7_STATE, 0, Route110_TrickHousePuzzle7_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle7_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

@ Unused, leftover from R/S
Route110_TrickHousePuzzle7_EventScript_TeleportPad::
	lockall
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1
	warpteleport MAP_ROUTE110_TRICK_HOUSE_PUZZLE7, 3, 19
	waitstate
	releaseall
	end

@ All the below switch scripts are unused leftover from R/S
Route110_TrickHousePuzzle7_EventScript_Switch1::
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_SetSwitch1MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_SetSwitch1MetatilesOff
	special DrawWholeMapView
	playse SE_CLICK
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_SetSwitch1On
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_SetSwitch1Off
	end

Route110_TrickHousePuzzle7_EventScript_Switch2::
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_SetSwitch2MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_SetSwitch2MetatilesOff
	special DrawWholeMapView
	playse SE_CLICK
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_SetSwitch2On
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_SetSwitch2Off
	end

Route110_TrickHousePuzzle7_EventScript_Switch3::
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_SetSwitch3MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_SetSwitch3MetatilesOff
	special DrawWholeMapView
	playse SE_CLICK
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_SetSwitch3On
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_SetSwitch3Off
	end

Route110_TrickHousePuzzle7_EventScript_Switch4::
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_SetSwitch4MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_SetSwitch4MetatilesOff
	special DrawWholeMapView
	playse SE_CLICK
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_SetSwitch4On
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_SetSwitch4Off
	end

Route110_TrickHousePuzzle7_EventScript_Switch5::
	lockall
	delay 32
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_SetSwitch5MetatilesOn
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_SetSwitch5MetatilesOff
	special DrawWholeMapView
	playse SE_CLICK
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_SetSwitch5On
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_SetSwitch5Off
	end

@ All the below switch scripts are unused leftover from R/S
Route110_TrickHousePuzzle7_EventScript_SetSwitch1On::
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch1Off::
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch2On::
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch2Off::
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch3On::
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch3Off::
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch4On::
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch4Off::
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch5On::
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5
	releaseall
	end

Route110_TrickHousePuzzle7_EventScript_SetSwitch5Off::
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5
	releaseall
	end

@ From here is where the new, actually used puzzle scripts begin
Route110_TrickHousePuzzle7_EventScript_YellowButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_BlueButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_GreenButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_EventScript_PurpleButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

@ Unused
Route110_TrickHousePuzzle7_EventScript_RedButton::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle TRUE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

Route110_TrickHousePuzzle7_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is huggable.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Seventh_TrickHousePuzzle1_Text:
	.string "Welcome to the Trick House!\p"
	.string "Answer all of our questions\n"
	.string "and earn some fabulous prizes!\p"
	.string "Each time you get a question wrong\n"
	.string "though, one of your prizes will be\l"
	.string "taken away and you'll have to\l"
	.string "fight a battle!\p"
	.string "Today's theme is...\p"
	.string "Pokemath!\n"
	.string "Time to get out a calculator!\p"
	.string "Here's your first question:\p"
	.string "Subtract Porygon-Z's defense stat\n"
	.string "from Porygon-2's to get the\l"
	.string "pokedex number of which pokemon?$"

Quiz_7A_Option_1:
	.string "Beedrill$"

Quiz_7A_Option_2:
	.string "Caterpie$"

Quiz_7A_Option_3:
	.string "Charmeleon$"

Quiz_7A_Option_4:
	.string "Raticate$"

Seventh_Trick_House_Quiz_1::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Seventh_TrickHousePuzzle1_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_7A_Option_1, 0
	dynmultipush Quiz_7A_Option_2, 1
	dynmultipush Quiz_7A_Option_3, 2
	dynmultipush Quiz_7A_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_Two
	case 1, Randomize_Quiz_House_Female_Battle_Two
	case 2, Randomize_Quiz_House_Female_Battle_Two
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Seventh_TrickHousePuzzle2_Text:
	.string "Question two is about square roots!\p"
	.string "What is the square root of the\n"
	.string "lowest base experience yield?$"

Quiz_7B_Option_1:
	.string "4$"

Quiz_7B_Option_2:
	.string "5$"

Quiz_7B_Option_3:
	.string "6$"

Quiz_7B_Option_4:
	.string "7$"

Seventh_Trick_House_Quiz_2::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Seventh_TrickHousePuzzle2_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_7B_Option_1, 0
	dynmultipush Quiz_7B_Option_2, 1
	dynmultipush Quiz_7B_Option_3, 2
	dynmultipush Quiz_7B_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_Two
	case 1, Randomize_Quiz_House_Female_Battle_Two
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Female_Battle_Two
	releaseall
	end

Seventh_TrickHousePuzzle3_Text:
	.string "For question three you'll round\n"
	.string "just like me!\p"
	.string "Rounded to three decimal points,\n"
	.string "what is the standard deviation of\l"
	.string "Fickle Beam's damage?$"

Quiz_7C_Option_1:
	.string "8.944$"

Quiz_7C_Option_2:
	.string "10.198$"

Quiz_7C_Option_3:
	.string "36.661$"

Quiz_7C_Option_4:
	.string "60.926$"

Seventh_Trick_House_Quiz_3::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Seventh_TrickHousePuzzle3_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_7C_Option_1, 0
	dynmultipush Quiz_7C_Option_2, 1
	dynmultipush Quiz_7C_Option_3, 2
	dynmultipush Quiz_7C_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_Two
	case 1, Randomize_Quiz_House_Female_Battle_Two
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Female_Battle_Two
	releaseall
	end

Seventh_TrickHousePuzzle4_Text:
	.string "For question four you'll add some more!\p"
	.string "Add the catch rate of Kabutops to the\n"
	.string "catch rate of Wimpod.\p"
	.string "This is the TM number of which move in\n"
	.string "Scarlet and Violet?$"

Quiz_7D_Option_1:
	.string "Flamethrower$"

Quiz_7D_Option_2:
	.string "Ice Beam$"

Quiz_7D_Option_3:
	.string "Surf$"

Quiz_7D_Option_4:
	.string "Thunderbolt$"

Seventh_Trick_House_Quiz_4::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Seventh_TrickHousePuzzle4_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_7D_Option_1, 0
	dynmultipush Quiz_7D_Option_2, 1
	dynmultipush Quiz_7D_Option_3, 2
	dynmultipush Quiz_7D_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_Two
	case 1, Quiz_House_Correct_Proceed
	case 2, Randomize_Quiz_House_Female_Battle_Two
	case 3, Randomize_Quiz_House_Female_Battle_Two
	releaseall
	end

Seventh_TrickHousePuzzle5_Text:
	.string "For question five you'll have to\n"
	.string "derive!\p"
	.string "Take the derivative of the medium\n"
	.string "slow experience function and\l"
	.string "evaluate it at Cleffa's speed stat.\p"
	.string "What is the only generation five\n"
	.string "pokemon with that base stat total?$"

Quiz_7E_Option_1:
	.string "Alomomola$"

Quiz_7E_Option_2:
	.string "Audino$"

Quiz_7E_Option_3:
	.string "Basculin$"

Quiz_7E_Option_4:
	.string "Emolga$"

Seventh_Trick_House_Quiz_5::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Seventh_TrickHousePuzzle5_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_7E_Option_1, 0
	dynmultipush Quiz_7E_Option_2, 1
	dynmultipush Quiz_7E_Option_3, 2
	dynmultipush Quiz_7E_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_Two
	case 1, Randomize_Quiz_House_Female_Battle_Two
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Female_Battle_Two
	releaseall
	end

Seventh_TrickHousePuzzle6_Text:
	.string "The probability you get question\n"
	.string "six is probably slim!\p"
	.string "Which of the following is least likely?$"

Quiz_7F_Option_1:
	.string "42 speed mon runs from 56 speed mon$"

Quiz_7F_Option_2:
	.string "Catch full HP Avalugg in a Quick Ball$"

Quiz_7F_Option_3:
	.string "Land two Focus Blasts in a row$"

Quiz_7F_Option_4:
	.string "Skill Link King's Rock 5 hit flinch$"

Seventh_Trick_House_Quiz_6::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Seventh_TrickHousePuzzle6_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_7F_Option_1, 0
	dynmultipush Quiz_7F_Option_2, 1
	dynmultipush Quiz_7F_Option_3, 2
	dynmultipush Quiz_7F_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_Two
	case 1, Randomize_Quiz_House_Male_Battle_Two
	case 2, Randomize_Quiz_House_Male_Battle_Two
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Seventh_TrickHousePuzzle7_Text:
	.string "Question seven might be unexpected!\p"
	.string "What is the expected damage of Steelix\n"
	.string "from Stormfront's Iron Tail attack?$"

Quiz_7G_Option_1:
	.string "50$"

Quiz_7G_Option_2:
	.string "75$"

Quiz_7G_Option_3:
	.string "100$"

Quiz_7G_Option_4:
	.string "150$"

Seventh_Trick_House_Quiz_7::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Seventh_TrickHousePuzzle7_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_7G_Option_1, 0
	dynmultipush Quiz_7G_Option_2, 1
	dynmultipush Quiz_7G_Option_3, 2
	dynmultipush Quiz_7G_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_Two
	case 1, Randomize_Quiz_House_Male_Battle_Two
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Male_Battle_Two
	releaseall
	end

Seventh_TrickHousePuzzle8_Text:
	.string "Let's integrate for question eight!\p"
	.string "What number do you get when you\n"
	.string "integrate 2x with respect to x from\l"
	.string "a lower bound of the amount of pokemon\l"
	.string "that have a speed stat of five to the\l"
	.string "upper bound of the amount of dots on\l"
	.string "each Regi's face?$"

Quiz_7H_Option_1:
	.string "4$"

Quiz_7H_Option_2:
	.string "8$"

Quiz_7H_Option_3:
	.string "40$"

Quiz_7H_Option_4:
	.string "80$"

Seventh_Trick_House_Quiz_8::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Seventh_TrickHousePuzzle8_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_7H_Option_1, 0
	dynmultipush Quiz_7H_Option_2, 1
	dynmultipush Quiz_7H_Option_3, 2
	dynmultipush Quiz_7H_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_Two
	case 1, Randomize_Quiz_House_Female_Battle_Two
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Female_Battle_Two
	releaseall
	end

Seventh_TrickHousePuzzle9_Text:
	.string "For question nine it's odd stat time!\p"
	.string "Add Parasect's pokedex number to the\n"
	.string "level Deino evolves at.\p"
	.string "What is the only pokemon whose base\n"
	.string "attack is equal to that number?$"

Quiz_7I_Option_1:
	.string "Durant$"

Quiz_7I_Option_2:
	.string "Exploud$"

Quiz_7I_Option_3:
	.string "Heatmor$"

Quiz_7I_Option_4:
	.string "Toxicroak$"

Seventh_Trick_House_Quiz_9::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Seventh_TrickHousePuzzle9_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_7I_Option_1, 0
	dynmultipush Quiz_7I_Option_2, 1
	dynmultipush Quiz_7I_Option_3, 2
	dynmultipush Quiz_7I_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_Two
	case 1, Randomize_Quiz_House_Male_Battle_Two
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Male_Battle_Two
	releaseall
	end

Seventh_TrickHousePuzzle10_Text:
	.string "I hope you're confident you can\n"
	.string "answer question ten!\p"
	.string "Which of the following is a 95%\n"
	.string "confidence interval for the percentage\l"
	.string "of Clemont's inventions that prove to\l"
	.string "be successful based on the sample size\l"
	.string "of the 70 inventions shown in the anime?$"

Quiz_7J_Option_1:
	.string "(.2449, .4694)$"

Quiz_7J_Option_2:
	.string "(.2571, .4571)$"

Quiz_7J_Option_3:
	.string "(.2661, .4481)$"

Quiz_7J_Option_4:
	.string "(.2901, .4241)$"

Seventh_Trick_House_Quiz_10::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Seventh_TrickHousePuzzle10_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_7J_Option_1, 0
	dynmultipush Quiz_7J_Option_2, 1
	dynmultipush Quiz_7J_Option_3, 2
	dynmultipush Quiz_7J_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Male_Battle_Two
	case 2, Randomize_Quiz_House_Male_Battle_Two
	case 3, Randomize_Quiz_House_Male_Battle_Two
	releaseall
	end

