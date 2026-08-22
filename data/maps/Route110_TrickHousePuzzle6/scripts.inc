Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is my life.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Sixth_TrickHousePuzzle1_Text:
	.string "Welcome to the Trick House!\p"
	.string "Answer all of our questions\n"
	.string "and earn some fabulous prizes!\p"
	.string "Each time you get a question wrong\n"
	.string "though, one of your prizes will be\l"
	.string "taken away and you'll have to\l"
	.string "fight a battle!\p"
	.string "Today's theme is...\p"
	.string "TCG and Mobile Games!\p"
	.string "Here's your first question:\p"
	.string "What is Mew's Sleep Style?$"

Quiz_6A_Option_1:
	.string "Dozing$"

Quiz_6A_Option_2:
	.string "Slumbering$"

Quiz_6A_Option_3:
	.string "Snoozing$"

Sixth_Trick_House_Quiz_1::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Sixth_TrickHousePuzzle1_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_6A_Option_1, 0
	dynmultipush Quiz_6A_Option_2, 1
	dynmultipush Quiz_6A_Option_3, 2
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_Two
	case 1, Randomize_Quiz_House_Female_Battle_Two
	case 2, Quiz_House_Correct_Proceed
	releaseall
	end

Sixth_TrickHousePuzzle2_Text:
	.string "Let me welcome you with\n"
	.string "question two!\p"
	.string "Which of these is not a type of\n"
	.string "card in the TCG?$"

Quiz_6B_Option_1:
	.string "Break$"

Quiz_6B_Option_2:
	.string "Delta Species$"

Quiz_6B_Option_3:
	.string "Legend$"

Quiz_6B_Option_4:
	.string "Level Max$"

Sixth_Trick_House_Quiz_2::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Sixth_TrickHousePuzzle2_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_6B_Option_1, 0
	dynmultipush Quiz_6B_Option_2, 1
	dynmultipush Quiz_6B_Option_3, 2
	dynmultipush Quiz_6B_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_Two
	case 1, Randomize_Quiz_House_Male_Battle_Two
	case 2, Randomize_Quiz_House_Male_Battle_Two
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Sixth_TrickHousePuzzle3_Text:
	.string "A gift from me, it's\n"
	.string "question three!\p"
	.string "Which of these can Magikarp\n"
	.string "not push?$"

Quiz_6C_Option_1:
	.string "Boldore$"

Quiz_6C_Option_2:
	.string "Geodude$"

Quiz_6C_Option_3:
	.string "Golem$"

Quiz_6C_Option_4:
	.string "Steelix$"

Sixth_Trick_House_Quiz_3::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Sixth_TrickHousePuzzle3_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_6C_Option_1, 0
	dynmultipush Quiz_6C_Option_2, 1
	dynmultipush Quiz_6C_Option_3, 2
	dynmultipush Quiz_6C_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_Two
	case 1, Quiz_House_Correct_Proceed
	case 2, Randomize_Quiz_House_Male_Battle_Two
	case 3, Randomize_Quiz_House_Male_Battle_Two
	releaseall
	end

Sixth_TrickHousePuzzle4_Text:
	.string "Try to score with question four!\p"
	.string "Which weather is also a TCG set?$"

Quiz_6D_Option_1:
	.string "Desolate Land$"

Quiz_6D_Option_2:
	.string "Primordial Sea$"

Quiz_6D_Option_3:
	.string "Sandstorm$"

Quiz_6D_Option_4:
	.string "Snowscape$"

Sixth_Trick_House_Quiz_4::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Sixth_TrickHousePuzzle4_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_6D_Option_1, 0
	dynmultipush Quiz_6D_Option_2, 1
	dynmultipush Quiz_6D_Option_3, 2
	dynmultipush Quiz_6D_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_Two
	case 1, Randomize_Quiz_House_Male_Battle_Two
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Male_Battle_Two
	releaseall
	end

Sixth_TrickHousePuzzle5_Text:
	.string "Strive to answer question five!\p"
	.string "What move can Chansey only learn\n"
	.string "in Pokemon Go?$"

Quiz_6E_Option_1:
	.string "Psybeam$"

Quiz_6E_Option_2:
	.string "Psychic$"

Quiz_6E_Option_3:
	.string "Psych Up$"

Quiz_6E_Option_4:
	.string "Psywave$"

Sixth_Trick_House_Quiz_5::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Sixth_TrickHousePuzzle5_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_6E_Option_1, 0
	dynmultipush Quiz_6E_Option_2, 1
	dynmultipush Quiz_6E_Option_3, 2
	dynmultipush Quiz_6E_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Female_Battle_Two
	case 2, Randomize_Quiz_House_Female_Battle_Two
	case 3, Randomize_Quiz_House_Female_Battle_Two
	releaseall
	end

Sixth_TrickHousePuzzle6_Text:
	.string "Don't brick question six!\p"
	.string "Which of these Pokemon does not\n"
	.string "have a gold star card?$"

Quiz_6F_Option_1:
	.string "Deoxys$"

Quiz_6F_Option_2:
	.string "Entei$"

Quiz_6F_Option_3:
	.string "Latias$"

Quiz_6F_Option_4:
	.string "Metagross$"

Sixth_Trick_House_Quiz_6::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Sixth_TrickHousePuzzle6_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_6F_Option_1, 0
	dynmultipush Quiz_6F_Option_2, 1
	dynmultipush Quiz_6F_Option_3, 2
	dynmultipush Quiz_6F_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Female_Battle_Two
	case 2, Randomize_Quiz_House_Female_Battle_Two
	case 3, Randomize_Quiz_House_Female_Battle_Two
	releaseall
	end

Sixth_TrickHousePuzzle7_Text:
	.string "Next you're gettin' question seven!\p"
	.string "Which of these Pokemon does not\n"
	.string "have a minigame in Pokemon Friends?$"

Quiz_6G_Option_1:
	.string "Lechonk$"

Quiz_6G_Option_2:
	.string "Pansage$"

Quiz_6G_Option_3:
	.string "Tinkatuff$"

Quiz_6G_Option_4:
	.string "Yamper$"

Sixth_Trick_House_Quiz_7::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Sixth_TrickHousePuzzle7_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_6G_Option_1, 0
	dynmultipush Quiz_6G_Option_2, 1
	dynmultipush Quiz_6G_Option_3, 2
	dynmultipush Quiz_6G_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Male_Battle_Two
	case 2, Randomize_Quiz_House_Male_Battle_Two
	case 3, Randomize_Quiz_House_Male_Battle_Two
	releaseall
	end

Sixth_TrickHousePuzzle8_Text:
	.string "You can't wait for question eight!\p"
	.string "Who is the fourth Pokemon to join\n"
	.string "the team in Pokemon Cafe Remix?$"

Quiz_6H_Option_1:
	.string "Piplup$"

Quiz_6H_Option_2:
	.string "Rowlett$"

Quiz_6H_Option_3:
	.string "Tepig$"

Quiz_6H_Option_4:
	.string "Timburr$"

Sixth_Trick_House_Quiz_8::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Sixth_TrickHousePuzzle8_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_6H_Option_1, 0
	dynmultipush Quiz_6H_Option_2, 1
	dynmultipush Quiz_6H_Option_3, 2
	dynmultipush Quiz_6H_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_Two
	case 1, Randomize_Quiz_House_Male_Battle_Two
	case 2, Randomize_Quiz_House_Male_Battle_Two
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Sixth_TrickHousePuzzle9_Text:
	.string "It's high time for question nine!\p"
	.string "Which of these is not a TCG set?$"

Quiz_6I_Option_1:
	.string "Legendary Forces$"

Quiz_6I_Option_2:
	.string "Phantom Forces$"

Quiz_6I_Option_3:
	.string "Temporal Forces$"

Quiz_6I_Option_4:
	.string "Unseen Forces$"

Sixth_Trick_House_Quiz_9::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Sixth_TrickHousePuzzle9_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_6I_Option_1, 0
	dynmultipush Quiz_6I_Option_2, 1
	dynmultipush Quiz_6I_Option_3, 2
	dynmultipush Quiz_6I_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Female_Battle_Two
	case 2, Randomize_Quiz_House_Female_Battle_Two
	case 3, Randomize_Quiz_House_Female_Battle_Two
	releaseall
	end

Sixth_TrickHousePuzzle10_Text:
	.string "You've reached the end!\n"
	.string "It's question ten!\p"
	.string "What's the bonus type in the Parched\n"
	.string "Peak stage of Pokemon Quest?$"

Quiz_6J_Option_1:
	.string "Fire$"

Quiz_6J_Option_2:
	.string "Flying$"

Quiz_6J_Option_3:
	.string "Ground$"

Quiz_6J_Option_4:
	.string "Rock$"

Sixth_Trick_House_Quiz_10::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Sixth_TrickHousePuzzle10_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_6J_Option_1, 0
	dynmultipush Quiz_6J_Option_2, 1
	dynmultipush Quiz_6J_Option_3, 2
	dynmultipush Quiz_6J_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Female_Battle_Two
	case 2, Randomize_Quiz_House_Female_Battle_Two
	case 3, Randomize_Quiz_House_Female_Battle_Two
	releaseall
	end

