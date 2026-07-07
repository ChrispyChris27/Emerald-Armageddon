Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“Quiz Master is fabulous.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

First_TrickHousePuzzle1_Text:
	.string "Welcome to the Trick House!\p"
	.string "Answer all of our questions\n"
	.string "and earn some fabulous prizes!\p"
	.string "Each time you get a question wrong\n"
	.string "though, one of your prizes will be\l"
	.string "taken away and you'll have to\l"
	.string "fight a battle!\p"
	.string "Todays theme is...\p"
	.string "Basic Game Knowledge!\p"
	.string "Here's your first question:\p"
	.string "Which Regi is the first one\n"
	.string "in the Pokedex?$"

Quiz_1A_Option_1:
	.string "Regice$"

Quiz_1A_Option_2:
	.string "Regirock$"

Quiz_1A_Option_3:
	.string "Registeel$"

First_TrickHousePuzzle2_Text:
	.string "It's time for question two!\p"
	.string "Excluding SIlvally and Arceus\n"
	.string "what is the only type that has\l"
	.string "yet to be given to a legendary?$"

Quiz_1B_Option_1:
	.string "Bug$"

Quiz_1B_Option_2:
	.string "Ghost$"

Quiz_1B_Option_3:
	.string "Poison$"

Quiz_1B_Option_4:
	.string "Normal$"

First_Trick_House_Quiz_1::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox First_TrickHousePuzzle1_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_1A_Option_1, 0
	dynmultipush Quiz_1A_Option_2, 1
	dynmultipush Quiz_1A_Option_3, 2
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_One
	case 1, Quiz_House_Correct_Proceed
	case 2, Randomize_Quiz_House_Female_Battle_One
	releaseall
	end

First_Trick_House_Quiz_2::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox First_TrickHousePuzzle2_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_1B_Option_1, 0
	dynmultipush Quiz_1B_Option_2, 1
	dynmultipush Quiz_1B_Option_3, 2
	dynmultipush Quiz_1B_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Female_Battle_One
	case 2, Randomize_Quiz_House_Female_Battle_One
	case 3, Randomize_Quiz_House_Female_Battle_One
	releaseall
	end

First_TrickHousePuzzle3_Text:
	.string "Allow me...to ask question three.\p"
	.string "Which of these types does not\n"
	.string "have a recoil move?$"

Quiz_1C_Option_1:
	.string "Ground$"

Quiz_1C_Option_2:
	.string "Fairy$"

Quiz_1C_Option_3:
	.string "Fighting$"

Quiz_1C_Option_4:
	.string "Water$"

First_Trick_House_Quiz_3::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox First_TrickHousePuzzle3_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_1C_Option_1, 0
	dynmultipush Quiz_1C_Option_2, 1
	dynmultipush Quiz_1C_Option_3, 2
	dynmultipush Quiz_1C_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Male_Battle_One
	case 2, Randomize_Quiz_House_Male_Battle_One
	case 3, Randomize_Quiz_House_Male_Battle_One
	releaseall
	end

First_TrickHousePuzzle4_Text:
	.string "I won't be a bore, here's\n"
	.string "question four!\p"
	.string "Which OHKO move was not\n"
	.string "introduced in Generation I?$"

Quiz_1D_Option_1:
	.string "Fissure$"

Quiz_1D_Option_2:
	.string "Guillotine$"

Quiz_1D_Option_3:
	.string "Horn Drill$"

Quiz_1D_Option_4:
	.string "Sheer Cold$"

First_Trick_House_Quiz_4::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox First_TrickHousePuzzle4_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_1D_Option_1, 0
	dynmultipush Quiz_1D_Option_2, 1
	dynmultipush Quiz_1D_Option_3, 2
	dynmultipush Quiz_1D_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Randomize_Quiz_House_Male_Battle_One
	case 2, Randomize_Quiz_House_Male_Battle_One
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

First_TrickHousePuzzle5_Text:
	.string "Let's liven things up with\n"
	.string "question five!\p"
	.string "Which of these abilities has\n"
	.string "NEVER been able to be traced?$"

Quiz_1E_Option_1:
	.string "Flower Gift$"

Quiz_1E_Option_2:
	.string "Forecast$"

Quiz_1E_Option_3:
	.string "Power of Alchemy$"

Quiz_1E_Option_4:
	.string "Trace$"

First_Trick_House_Quiz_5::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox First_TrickHousePuzzle5_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_1E_Option_1, 0
	dynmultipush Quiz_1E_Option_2, 1
	dynmultipush Quiz_1E_Option_3, 2
	dynmultipush Quiz_1E_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_One
	case 1, Randomize_Quiz_House_Female_Battle_One
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Female_Battle_One
	releaseall
	end

First_TrickHousePuzzle6_Text:
	.string "Hope you are slick, here's\n"
	.string "question six!\p"
	.string "Which of these pokemon and their\n"
	.string "evolution lines did not have a\l"
	.string "signature move in generation I?$"

Quiz_1F_Option_1:
	.string "Chansey$"

Quiz_1F_Option_2:
	.string "Ekans$"

Quiz_1F_Option_3:
	.string "Exeggcute$"

Quiz_1F_Option_4:
	.string "Magikarp$"

First_Trick_House_Quiz_6::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox First_TrickHousePuzzle6_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_1F_Option_1, 0
	dynmultipush Quiz_1F_Option_2, 1
	dynmultipush Quiz_1F_Option_3, 2
	dynmultipush Quiz_1F_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Female_Battle_One
	case 2, Randomize_Quiz_House_Female_Battle_One
	case 3, Randomize_Quiz_House_Female_Battle_One
	releaseall
	end


