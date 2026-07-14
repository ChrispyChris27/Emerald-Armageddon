Route110_TrickHousePuzzle5_MapScripts::
	.byte 0

Route110_TrickHousePuzzle5_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_5_STATE, 0, Route110_TrickHousePuzzle5_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle5_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_5_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle5_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is a genius.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Fifth_TrickHousePuzzle1_Text:
	.string "Welcome to the Trick House!\p"
	.string "Answer all of our questions\n"
	.string "and earn some fabulous prizes!\p"
	.string "Each time you get a question wrong\n"
	.string "though, one of your prizes will be\l"
	.string "taken away and you'll have to\l"
	.string "fight a battle!\p"
	.string "Today's theme is...\p"
	.string "Spin Off Games!\p"
	.string "Here's your first question:\p"
	.string "Which Pokemon's primal form is fought\n"
	.string "in Pokemon Mystery Dungeon?$"

Quiz_5A_Option_1:
	.string "Dialga$"

Quiz_5A_Option_2:
	.string "Groudon$"

Quiz_5A_Option_3:
	.string "Kyogre$"

Quiz_5A_Option_4:
	.string "Palkia$"

Fifth_Trick_House_Quiz_1::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fifth_TrickHousePuzzle1_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_5A_Option_1, 0
	dynmultipush Quiz_5A_Option_2, 1
	dynmultipush Quiz_5A_Option_3, 2
	dynmultipush Quiz_5A_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Female_Battle_Two
	case 2, Randomize_Quiz_House_Female_Battle_Two
	case 3, Randomize_Quiz_House_Female_Battle_Two
	releaseall
	end

Fifth_TrickHousePuzzle2_Text:
	.string "Question two was spun up for you!\p"
	.string "Who does not have a bonus stage in\n"
	.string "in Pokemon Pinball?$"

Quiz_5B_Option_1:
	.string "Gastly$"

Quiz_5B_Option_2:
	.string "Meowth$"

Quiz_5B_Option_3:
	.string "Pikachu$"

Quiz_5B_Option_4:
	.string "Seel$"

Fifth_Trick_House_Quiz_2::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fifth_TrickHousePuzzle2_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_5B_Option_1, 0
	dynmultipush Quiz_5B_Option_2, 1
	dynmultipush Quiz_5B_Option_3, 2
	dynmultipush Quiz_5B_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_Two
	case 1, Randomize_Quiz_House_Male_Battle_Two
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Male_Battle_Two
	releaseall
	end

Fifth_TrickHousePuzzle3_Text:
	.string "Question three was made for thee!\p"
	.string "Who is the Grandmaster of All\n"
	.string "Things Bad?$"

Quiz_5C_Option_1:
	.string "Clefable$"

Quiz_5C_Option_2:
	.string "Darkrai$"

Quiz_5C_Option_3:
	.string "Giratina$"

Quiz_5C_Option_4:
	.string "Wigglytuff$"

Fifth_Trick_House_Quiz_3::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fifth_TrickHousePuzzle3_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_5C_Option_1, 0
	dynmultipush Quiz_5C_Option_2, 1
	dynmultipush Quiz_5C_Option_3, 2
	dynmultipush Quiz_5C_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_Two
	case 1, Randomize_Quiz_House_Female_Battle_Two
	case 2, Randomize_Quiz_House_Female_Battle_Two
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Fifth_TrickHousePuzzle4_Text:
	.string "You'll be wiped on the floor\n"
	.string "after question four!\p"
	.string "Which Spin Off was the first pokemon\n"
	.string "game ever released for Nintendo DS?$"

Quiz_5D_Option_1:
	.string "Pokemon Dash$"

Quiz_5D_Option_2:
	.string "Pokemon Picross$"

Quiz_5D_Option_3:
	.string "Pokemon Ranger$"

Quiz_5D_Option_4:
	.string "Pokemon Trozei$"

Fifth_Trick_House_Quiz_4::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fifth_TrickHousePuzzle4_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_5D_Option_1, 0
	dynmultipush Quiz_5D_Option_2, 1
	dynmultipush Quiz_5D_Option_3, 2
	dynmultipush Quiz_5D_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Male_Battle_Two
	case 2, Randomize_Quiz_House_Male_Battle_Two
	case 3, Randomize_Quiz_House_Male_Battle_Two
	releaseall
	end

Fifth_TrickHousePuzzle5_Text:
	.string "Show me your drive to answer\n"
	.string "question five!\p"
	.string "Who is not a member of the\n"
	.string "Go-Rock Quads?$"

Quiz_5E_Option_1:
	.string "Billy$"

Quiz_5E_Option_2:
	.string "Clyde$"

Quiz_5E_Option_3:
	.string "Garret$"

Quiz_5E_Option_4:
	.string "Gordor$"

Quiz_5E_Option_5:
	.string "Tiffany$"	

Fifth_Trick_House_Quiz_5::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fifth_TrickHousePuzzle5_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_5E_Option_1, 0
	dynmultipush Quiz_5E_Option_2, 1
	dynmultipush Quiz_5E_Option_3, 2
	dynmultipush Quiz_5E_Option_4, 3
	dynmultipush Quiz_5E_Option_5, 4
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_Two
	case 1, Randomize_Quiz_House_Female_Battle_Two
	case 2, Randomize_Quiz_House_Female_Battle_Two
	case 3, Quiz_House_Correct_Proceed
	case 4, Randomize_Quiz_House_Female_Battle_Two
	releaseall
	end

Fifth_TrickHousePuzzle6_Text:
	.string "Hope your knowledge sticks with\n"
	.string "question six!\p"
	.string "Which of these shinies is not\n"
	.string "available in Pokemon Rumble U?$"

Quiz_5F_Option_1:
	.string "Genesect$"

Quiz_5F_Option_2:
	.string "Oshawott$"

Quiz_5F_Option_3:
	.string "Snivy$"

Quiz_5F_Option_4:
	.string "Tepig$"

Fifth_Trick_House_Quiz_6::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fifth_TrickHousePuzzle6_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_5F_Option_1, 0
	dynmultipush Quiz_5F_Option_2, 1
	dynmultipush Quiz_5F_Option_3, 2
	dynmultipush Quiz_5F_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_Two
	case 1, Randomize_Quiz_House_Male_Battle_Two
	case 2, Randomize_Quiz_House_Male_Battle_Two
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Fifth_TrickHousePuzzle7_Text:
	.string "You'll need help from the heavens\n"
	.string "to get question seven!\p"
	.string "Which of these pokemon takes\n"
	.string "more than one loop to catch\l"
	.string "in Pokemon Ranger?$"

Quiz_5G_Option_1:
	.string "Goldeen$"

Quiz_5G_Option_2:
	.string "Magikarp$"

Quiz_5G_Option_3:
	.string "Ninjask$"

Quiz_5G_Option_4:
	.string "Ralts$"

Fifth_Trick_House_Quiz_7::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fifth_TrickHousePuzzle7_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_5G_Option_1, 0
	dynmultipush Quiz_5G_Option_2, 1
	dynmultipush Quiz_5G_Option_3, 2
	dynmultipush Quiz_5G_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_Two
	case 1, Randomize_Quiz_House_Female_Battle_Two
	case 2, Randomize_Quiz_House_Female_Battle_Two
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Fifth_TrickHousePuzzle8_Text:
	.string "You'll need to be great to\n"
	.string "answer question eight!\p"
	.string "Which exploration rule is:\n"
	.string "Before you explore, try to think\l"
	.string "about the moves you should link?$"

Quiz_5H_Option_1:
	.string "4$"

Quiz_5H_Option_2:
	.string "5$"

Quiz_5H_Option_3:
	.string "6$"

Quiz_5H_Option_4:
	.string "7$"

Fifth_Trick_House_Quiz_8::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fifth_TrickHousePuzzle8_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_5H_Option_1, 0
	dynmultipush Quiz_5H_Option_2, 1
	dynmultipush Quiz_5H_Option_3, 2
	dynmultipush Quiz_5H_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_Two
	case 1, Randomize_Quiz_House_Male_Battle_Two
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Male_Battle_Two
	releaseall
	end

Fifth_TrickHousePuzzle9_Text:
	.string "You must be mighty fine to\n"
	.string "answer question nine!\p"
	.string "Which spinoff game introduced a\n"
	.string "new set of exclusive abilities?$"

Quiz_5I_Option_1:
	.string "Pokemon Conquest$"

Quiz_5I_Option_2:
	.string "Pokemon Mystery Dungeon$"

Quiz_5I_Option_3:
	.string "Pokemon Picross$"

Quiz_5I_Option_4:
	.string "Pokemon Ranger$"

Fifth_Trick_House_Quiz_9::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fifth_TrickHousePuzzle9_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_5I_Option_1, 0
	dynmultipush Quiz_5I_Option_2, 1
	dynmultipush Quiz_5I_Option_3, 2
	dynmultipush Quiz_5I_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Male_Battle_Two
	case 2, Randomize_Quiz_House_Male_Battle_Two
	case 3, Randomize_Quiz_House_Male_Battle_Two
	releaseall
	end

Fifth_TrickHousePuzzle10_Text:
	.string "To reach the end you must\n"
	.string "answer question ten!\p"
	.string "What is the last island unlocked\n"
	.string "in the new Pokemon Snap?$"

Quiz_5J_Option_1:
	.string "Aurus Island$"

Quiz_5J_Option_2:
	.string "Belusylva Island$"

Quiz_5J_Option_3:
	.string "Durice Island$"

Quiz_5J_Option_4:
	.string "Voluca Island$"

Fifth_Trick_House_Quiz_10::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fifth_TrickHousePuzzle10_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_5J_Option_1, 0
	dynmultipush Quiz_5J_Option_2, 1
	dynmultipush Quiz_5J_Option_3, 2
	dynmultipush Quiz_5J_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Male_Battle_Two
	case 2, Randomize_Quiz_House_Male_Battle_Two
	case 3, Randomize_Quiz_House_Male_Battle_Two
	releaseall
	end

Route110_TrickHousePuzzle5_Movement_MechadollShake:
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_left
	delay_2
	face_right
	delay_2
	face_down
	step_end

