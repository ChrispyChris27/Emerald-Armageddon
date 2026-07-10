Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is cool.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Fourth_TrickHousePuzzle1_Text:
	.string "Welcome to the Trick House!\p"
	.string "Answer all of our questions\n"
	.string "and earn some fabulous prizes!\p"
	.string "Each time you get a question wrong\n"
	.string "though, one of your prizes will be\l"
	.string "taken away and you'll have to\l"
	.string "fight a battle!\p"
	.string "Today's theme is...\p"
	.string "Pokemon Numbers!\p"
	.string "Here's your first question:\p"
	.string "Excluding Shedinja, what is the\n"
	.string "lowest max HP a pokemon can have?$"

Quiz_4A_Option_1:
	.string "2$"

Quiz_4A_Option_2:
	.string "5$"

Quiz_4A_Option_3:
	.string "10$"

Quiz_4A_Option_4:
	.string "11$"

Fourth_Trick_House_Quiz_1::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fourth_TrickHousePuzzle1_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_4A_Option_1, 0
	dynmultipush Quiz_4A_Option_2, 1
	dynmultipush Quiz_4A_Option_3, 2
	dynmultipush Quiz_4A_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_One
	case 1, Randomize_Quiz_House_Female_Battle_One
	case 2, Randomize_Quiz_House_Female_Battle_One
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Fourth_TrickHousePuzzle2_Text:
	.string "How do you do?\n"
	.string "I've got question two!\p"
	.string "How many different species of\n"
	.string "Magikarp are in Magikarp Jump?$"

Quiz_4B_Option_1:
	.string "15$"

Quiz_4B_Option_2:
	.string "24$"

Quiz_4B_Option_3:
	.string "33$"

Quiz_4B_Option_4:
	.string "40$"

Fourth_Trick_House_Quiz_2::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fourth_TrickHousePuzzle2_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_4B_Option_1, 0
	dynmultipush Quiz_4B_Option_2, 1
	dynmultipush Quiz_4B_Option_3, 2
	dynmultipush Quiz_4B_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_One
	case 1, Randomize_Quiz_House_Female_Battle_One
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Female_Battle_One
	releaseall
	end

Fourth_TrickHousePuzzle3_Text:
	.string "Look at me!\n"
	.string "I've got question three!\p"
	.string "What is the most common\n"
	.string "base stat total?$"

Quiz_4C_Option_1:
	.string "405$"

Quiz_4C_Option_2:
	.string "500$"

Quiz_4C_Option_3:
	.string "580$"

Quiz_4C_Option_4:
	.string "600$"

Fourth_Trick_House_Quiz_3::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fourth_TrickHousePuzzle3_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_4C_Option_1, 0
	dynmultipush Quiz_4C_Option_2, 1
	dynmultipush Quiz_4C_Option_3, 2
	dynmultipush Quiz_4C_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Randomize_Quiz_House_Male_Battle_One
	case 2, Randomize_Quiz_House_Male_Battle_One
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Fourth_TrickHousePuzzle4_Text:
	.string "I won't be a bore!\n"
	.string "I've got question four!\p"
	.string "What is the 67th card in the\n"
	.string "English TCG Base Set?$"

Quiz_4D_Option_1:
	.string "Bill$"

Quiz_4D_Option_2:
	.string "Drowzee$"

Quiz_4D_Option_3:
	.string "Machoke$"

Quiz_4D_Option_4:
	.string "Voltorb$"

Fourth_Trick_House_Quiz_4::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fourth_TrickHousePuzzle4_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_4D_Option_1, 0
	dynmultipush Quiz_4D_Option_2, 1
	dynmultipush Quiz_4D_Option_3, 2
	dynmultipush Quiz_4D_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_One
	case 1, Randomize_Quiz_House_Female_Battle_One
	case 2, Randomize_Quiz_House_Female_Battle_One
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Fourth_TrickHousePuzzle5_Text:
	.string "I'm feeling alive!\n"
	.string "I've got question five!\p"
	.string "What is the only Ultra Beast\n"
	.string "with a base stat that isn't\l"
	.string "a prime number?$"

Quiz_4E_Option_1:
	.string "Blacephalon$"

Quiz_4E_Option_2:
	.string "Naganadel$"

Quiz_4E_Option_3:
	.string "Poiple$"

Quiz_4E_Option_4:
	.string "Stakataka$"

Fourth_Trick_House_Quiz_5::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fourth_TrickHousePuzzle5_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_4E_Option_1, 0
	dynmultipush Quiz_4E_Option_2, 1
	dynmultipush Quiz_4E_Option_3, 2
	dynmultipush Quiz_4E_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Quiz_House_Correct_Proceed
	case 2, Randomize_Quiz_House_Male_Battle_One
	case 3, Randomize_Quiz_House_Male_Battle_One
	releaseall
	end

Fourth_TrickHousePuzzle6_Text:
	.string "Hope you're ready for a gauntlet!\n"
	.string "I've got question six!\p"
	.string "What is the only experience group\n"
	.string "whose total exp to reach level 100\l"
	.string "is not divisible by 100?$"

Quiz_4F_Option_1:
	.string "Erratic$"

Quiz_4F_Option_2:
	.string "Fast$"

Quiz_4F_Option_3:
	.string "Fluctuating$"

Quiz_4F_Option_4:
	.string "Medium Fast$"

Quiz_4F_Option_5:
	.string "Medium Slow$"

Quiz_4F_Option_6:
	.string "Slow$"

Fourth_Trick_House_Quiz_6::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fourth_TrickHousePuzzle6_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_4F_Option_1, 0
	dynmultipush Quiz_4F_Option_2, 1
	dynmultipush Quiz_4F_Option_3, 2
	dynmultipush Quiz_4F_Option_4, 3
	dynmultipush Quiz_4F_Option_5, 4
	dynmultipush Quiz_4F_Option_6, 5
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_One
	case 1, Randomize_Quiz_House_Female_Battle_One
	case 2, Randomize_Quiz_House_Female_Battle_One
	case 3, Randomize_Quiz_House_Female_Battle_One
	case 4, Quiz_House_Correct_Proceed
	case 5, Randomize_Quiz_House_Female_Battle_One
	releaseall
	end

Fourth_TrickHousePuzzle7_Text:
	.string "Down a ledge you've fallen!\n"
	.string "I've got question seven!\p"
	.string "How many legendary pokemon\n"
	.string "can evolve?$"

Quiz_4G_Option_1:
	.string "2$"

Quiz_4G_Option_2:
	.string "3$"

Quiz_4G_Option_3:
	.string "4$"

Quiz_4G_Option_4:
	.string "5$"

Fourth_Trick_House_Quiz_7::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fourth_TrickHousePuzzle7_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_4G_Option_1, 0
	dynmultipush Quiz_4G_Option_2, 1
	dynmultipush Quiz_4G_Option_3, 2
	dynmultipush Quiz_4G_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Randomize_Quiz_House_Male_Battle_One
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Male_Battle_One
	releaseall
	end

Fourth_TrickHousePuzzle8_Text:
	.string "Aren't ledges great?\n"
	.string "I've got question eight!\p"
	.string "How many different pokemon\n"
	.string "can mega evolve?$"

Quiz_4H_Option_1:
	.string "87$"

Quiz_4H_Option_2:
	.string "93$"

Quiz_4H_Option_3:
	.string "95$"

Quiz_4H_Option_4:
	.string "96$"

Fourth_Trick_House_Quiz_8::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fourth_TrickHousePuzzle8_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_4H_Option_1, 0
	dynmultipush Quiz_4H_Option_2, 1
	dynmultipush Quiz_4H_Option_3, 2
	dynmultipush Quiz_4H_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Male_Battle_One
	case 2, Randomize_Quiz_House_Male_Battle_One
	case 3, Randomize_Quiz_House_Male_Battle_One
	releaseall
	end

Fourth_TrickHousePuzzle9_Text:
	.string "That scroll is mighty fine!\n"
	.string "I've got question nine!\p"
	.string "How much damage does Kabutops ex's\n"
	.string "Sprial Drain attack do?$"

Quiz_4I_Option_1:
	.string "65$"

Quiz_4I_Option_2:
	.string "70$"

Quiz_4I_Option_3:
	.string "75$"

Quiz_4I_Option_4:
	.string "80$"

Fourth_Trick_House_Quiz_9::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fourth_TrickHousePuzzle9_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_4I_Option_1, 0
	dynmultipush Quiz_4I_Option_2, 1
	dynmultipush Quiz_4I_Option_3, 2
	dynmultipush Quiz_4I_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Quiz_House_Correct_Proceed
	case 2, Randomize_Quiz_House_Male_Battle_One
	case 3, Randomize_Quiz_House_Male_Battle_One
	releaseall
	end

Fourth_TrickHousePuzzle10_Text:
	.string "You're finally at the end!\n"
	.string "I've got question ten!\p"
	.string "Which of these numbers is\n"
	.string "not the same?$"

Quiz_4J_Option_1:
	.string "Base PP of Splash$"

Quiz_4J_Option_3:
	.string "Damage of Hitmonchan's 'Special Punch'$"

Quiz_4J_Option_2:
	.string "Catch rate of Reuniclus$"

Quiz_4J_Option_4:
	.string "Original Pokemon Go Max Level$"

Fourth_Trick_House_Quiz_10::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Fourth_TrickHousePuzzle10_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_4J_Option_1, 0
	dynmultipush Quiz_4J_Option_2, 1
	dynmultipush Quiz_4J_Option_3, 2
	dynmultipush Quiz_4J_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Quiz_House_Correct_Proceed
	case 2, Randomize_Quiz_House_Male_Battle_One
	case 3, Randomize_Quiz_House_Male_Battle_One
	releaseall
	end
