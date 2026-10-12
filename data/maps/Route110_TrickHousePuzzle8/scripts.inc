Route110_TrickHousePuzzle8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle8_OnTransition
	.byte 0

Route110_TrickHousePuzzle8_OnTransition::
	call_if_eq VAR_TRICK_HOUSE_QUIZ_STATUS, 80, Set_Final_Trick_House_Trainer
	releaseall
	end

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER I love.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Final_TrickHousePuzzle1_Text:
	.string "Welcome to the Trick House!\p"
	.string "Answer all of our questions\n"
	.string "and earn some fabulous prizes!\p"
	.string "Each time you get a question wrong\n"
	.string "though, one of your prizes will be\l"
	.string "taken away and you'll have to\l"
	.string "fight a battle!\p"
	.string "Today's theme is...\p"
	.string "Who's that pokemon?!\p"
	.string "Here's your first question:\p"
	.string "First comes Relicanth.\p"
	.string "Last comes Wailord.\p"
	.string "What comes in the middle?$"

Final_Trick_House_Quiz_1::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Final_TrickHousePuzzle1_Text, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRICK_HOUSE
	call Common_ShowEasyChatScreen
	goto_if_eq VAR_RESULT, 0, Randomize_Quiz_House_Female_Battle_Two
	specialvar VAR_RESULT, IsTrickHouseAnswer1Correct
	switch VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Randomize_Quiz_House_Female_Battle_Two
	goto_if_eq VAR_RESULT, TRUE, Quiz_House_Correct_Proceed
	releaseall
	end

Final_TrickHousePuzzle2_Text:
	.string "Nine questions left!\n"
	.string "Are you ready for the next?\p"
	.string "What pokemon has the lowest\n"
	.string "base stat total?$"

Final_Trick_House_Quiz_2::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Final_TrickHousePuzzle2_Text, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRICK_HOUSE
	call Common_ShowEasyChatScreen
	goto_if_eq VAR_RESULT, 0, Randomize_Quiz_House_Female_Battle_Two
	specialvar VAR_RESULT, IsTrickHouseAnswer2Correct
	switch VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Randomize_Quiz_House_Female_Battle_Two
	goto_if_eq VAR_RESULT, TRUE, Quiz_House_Correct_Proceed
	releaseall
	end

Final_TrickHousePuzzle3_Text:
	.string "Eight questions remain!\n"
	.string "Let's keep playing this game!\p"
	.string "If you purchased an E-Reader in the\n"
	.string "US, you also received a minigame\l"
	.string "featuring which pokemon?$"

Final_Trick_House_Quiz_3::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Final_TrickHousePuzzle3_Text, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRICK_HOUSE
	call Common_ShowEasyChatScreen
	goto_if_eq VAR_RESULT, 0, Randomize_Quiz_House_Female_Battle_Two
	specialvar VAR_RESULT, IsTrickHouseAnswer3Correct
	switch VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Randomize_Quiz_House_Female_Battle_Two
	goto_if_eq VAR_RESULT, TRUE, Quiz_House_Correct_Proceed
	releaseall
	end

Final_TrickHousePuzzle4_Text:
	.string "Seven questions to go!\n"
	.string "Are you going with the flow?\p"
	.string "Name either of the two TCG sets that\n"
	.string "are named after pokemon.$"

Final_Trick_House_Quiz_4::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Final_TrickHousePuzzle4_Text, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRICK_HOUSE
	call Common_ShowEasyChatScreen
	goto_if_eq VAR_RESULT, 0, Randomize_Quiz_House_Male_Battle_Two
	specialvar VAR_RESULT, IsTrickHouseAnswer4ACorrect
	goto_if_eq VAR_RESULT, TRUE, Quiz_House_Correct_Proceed
	specialvar VAR_RESULT, IsTrickHouseAnswer4BCorrect
	goto_if_eq VAR_RESULT, FALSE, Randomize_Quiz_House_Male_Battle_Two
	goto_if_eq VAR_RESULT, TRUE, Quiz_House_Correct_Proceed
	releaseall
	end

Final_TrickHousePuzzle5_Text:
	.string "Six questions until you're done!\n"
	.string "Hope you're still having lots of fun!\p"
	.string "What is the only pokemon that learns\n"
	.string "Extrasensory by level-up in Gen III?$"

Final_Trick_House_Quiz_5::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Final_TrickHousePuzzle5_Text, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRICK_HOUSE
	call Common_ShowEasyChatScreen
	goto_if_eq VAR_RESULT, 0, Randomize_Quiz_House_Male_Battle_Two
	specialvar VAR_RESULT, IsTrickHouseAnswer5Correct
	switch VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Randomize_Quiz_House_Male_Battle_Two
	goto_if_eq VAR_RESULT, TRUE, Quiz_House_Correct_Proceed
	releaseall
	end

Final_TrickHousePuzzle6_Text:
	.string "Halfway through this final quiz!\n"
	.string "So far you have the knowledge of a whiz!\p"
	.string "What is the only pokemon with a\n"
	.string "base stat total of 501?$"

Final_Trick_House_Quiz_6::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Final_TrickHousePuzzle6_Text, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRICK_HOUSE
	call Common_ShowEasyChatScreen
	goto_if_eq VAR_RESULT, 0, Randomize_Quiz_House_Male_Battle_Two
	specialvar VAR_RESULT, IsTrickHouseAnswer6Correct
	switch VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Randomize_Quiz_House_Male_Battle_Two
	goto_if_eq VAR_RESULT, TRUE, Quiz_House_Correct_Proceed
	releaseall
	end

Final_TrickHousePuzzle7_Text:
	.string "The number of questions left is four!\n"
	.string "How are you liking this slippery floor?\p"
	.string "What is the only non ghost type\n"
	.string "that can walk through walls in\l"
	.string "Pokemon Mystery Dungeon?$"

Final_Trick_House_Quiz_7::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Final_TrickHousePuzzle7_Text, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRICK_HOUSE
	call Common_ShowEasyChatScreen
	goto_if_eq VAR_RESULT, 0, Randomize_Quiz_House_Male_Battle_Two
	specialvar VAR_RESULT, IsTrickHouseAnswer7Correct
	switch VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Randomize_Quiz_House_Male_Battle_Two
	goto_if_eq VAR_RESULT, TRUE, Quiz_House_Correct_Proceed
	releaseall
	end

Final_TrickHousePuzzle8_Text:
	.string "Three more questions on the way!\n"
	.string "Hope you have a lovely day!\p"
	.string "What is the heaviest pokemon that\n"
	.string "does not take the maximum damage\l"
	.string "from Low Kick and Grass Knot?$"

Final_Trick_House_Quiz_8::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Final_TrickHousePuzzle8_Text, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRICK_HOUSE
	call Common_ShowEasyChatScreen
	goto_if_eq VAR_RESULT, 0, Randomize_Quiz_House_Female_Battle_Two
	specialvar VAR_RESULT, IsTrickHouseAnswer8Correct
	switch VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Randomize_Quiz_House_Female_Battle_Two
	goto_if_eq VAR_RESULT, TRUE, Quiz_House_Correct_Proceed
	releaseall
	end

Final_TrickHousePuzzle9_Text:
	.string "The penultimate question comes from me!\n"
	.string "I shall now deliver it to thee.\p"
	.string "What is the only non baby pokemon with\n"
	.string "a worse catch rate than its evolution?$"

Final_Trick_House_Quiz_9::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Final_TrickHousePuzzle9_Text, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRICK_HOUSE
	call Common_ShowEasyChatScreen
	goto_if_eq VAR_RESULT, 0, Randomize_Quiz_House_Female_Battle_Two
	specialvar VAR_RESULT, IsTrickHouseAnswer9Correct
	switch VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Randomize_Quiz_House_Female_Battle_Two
	goto_if_eq VAR_RESULT, TRUE, Quiz_House_Correct_Proceed
	releaseall
	end

Final_TrickHousePuzzle10_Text:
	.string "The final question is in my possession.\n"
	.string "I hope trivia's your new obsession!\p"
	.string "What pokemon did Professor Birch\n"
	.string "send out at the start of the game?$"

Final_Trick_House_Quiz_10::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Final_TrickHousePuzzle10_Text, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRICK_HOUSE
	call Common_ShowEasyChatScreen
	goto_if_eq VAR_RESULT, 0, Randomize_Quiz_House_Male_Battle_Two
	specialvar VAR_RESULT, IsTrickHouseAnswer10Correct
	switch VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Randomize_Quiz_House_Male_Battle_Two
	goto_if_eq VAR_RESULT, TRUE, Quiz_House_Final_Question_Proceed
	releaseall
	end

Quiz_House_Final_Question_Proceed::
	msgbox Quiz_House_Correct_text, MSGBOX_AUTOCLOSE
	addvar VAR_TRICK_HOUSE_QUIZ_STATUS, 1
	call Move_Final_Trick_House_Trainer
	releaseall
	end

Move_Final_Trick_House_Trainer::
	applymovement LOCALID_TRICK_HOUSE_LAST_TRAINER, Common_Movement_WalkLeft
	waitmovement
	applymovement LOCALID_TRICK_HOUSE_LAST_TRAINER, Common_Movement_FaceRight
	waitmovement
	return

Set_Final_Trick_House_Trainer::
	setobjectxyperm LOCALID_TRICK_HOUSE_LAST_TRAINER, 12, 2
	setobjectmovementtype LOCALID_TRICK_HOUSE_LAST_TRAINER, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

