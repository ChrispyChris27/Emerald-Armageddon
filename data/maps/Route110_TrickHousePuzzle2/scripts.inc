Route110_TrickHousePuzzle2_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle2_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle2_OnTransition
	.byte 0

Route110_TrickHousePuzzle2_OnResume:
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHousePuzzle2_EventScript_PressButton1
	call_if_eq VAR_TEMP_2, 1, Route110_TrickHousePuzzle2_EventScript_PressButton2
	end

Route110_TrickHousePuzzle2_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	end

Route110_TrickHousePuzzle2_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0, Route110_TrickHousePuzzle2_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle2_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle2_EventScript_Button1::
	lockall
	setvar VAR_TEMP_1, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton1
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_Button2::
	lockall
	setvar VAR_TEMP_2, 1
	playse SE_PIN
	call Route110_TrickHousePuzzle2_EventScript_PressButton2
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_PressButton1::
	setmetatile 0, 3, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 10, 21, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
	return

Route110_TrickHousePuzzle2_EventScript_PressButton2::
	setmetatile 14, 21, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 6, 9, METATILE_TrickHousePuzzle_Door_Shuttered, FALSE
	return

Route110_TrickHousePuzzle2_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is smart.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Second_TrickHousePuzzle1_Text:
	.string "Welcome to the Trick House!\p"
	.string "Answer all of our questions\n"
	.string "and earn some fabulous prizes!\p"
	.string "Each time you get a question wrong\n"
	.string "though, one of your prizes will be\l"
	.string "taken away and you'll have to\l"
	.string "fight a battle!\p"
	.string "Today's theme is...\p"
	.string "Obscure Game Knowledge!\p"
	.string "Here's your first question:\p"
	.string "Which of these moves will not\n"
	.string "hit a flying target?$"

Quiz_2A_Option_1:
	.string "Razor Wind$"

Quiz_2A_Option_2:
	.string "Smack Down$"

Quiz_2A_Option_3:
	.string "Thousand Arrows$"

Quiz_2A_Option_4:
	.string "Twister$"

Second_Trick_House_Quiz_1::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Second_TrickHousePuzzle1_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_2A_Option_1, 0
	dynmultipush Quiz_2A_Option_2, 1
	dynmultipush Quiz_2A_Option_3, 2
	dynmultipush Quiz_2A_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Female_Battle_One
	case 2, Randomize_Quiz_House_Female_Battle_One
	case 3, Randomize_Quiz_House_Female_Battle_One
	releaseall
	end

Second_TrickHousePuzzle2_Text:
	.string "Just for you, here's question two!\p"
	.string "Which of these is not a real berry?$"

Quiz_2B_Option_1:
	.string "Drash Berry$"

Quiz_2B_Option_2:
	.string "Eggant Berry$"

Quiz_2B_Option_3:
	.string "Nutpea Berry$"

Quiz_2B_Option_4:
	.string "Snipar Berry$"

Second_Trick_House_Quiz_2::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Second_TrickHousePuzzle2_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_2B_Option_1, 0
	dynmultipush Quiz_2B_Option_2, 1
	dynmultipush Quiz_2B_Option_3, 2
	dynmultipush Quiz_2B_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_One
	case 1, Randomize_Quiz_House_Female_Battle_One
	case 2, Randomize_Quiz_House_Female_Battle_One
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Second_TrickHousePuzzle3_Text:
	.string "A gift from me!\n"
	.string "Here's question three!\p"
	.string "Which of these types is not\n"
	.string "also an egg group?$"

Quiz_2C_Option_1:
	.string "Dragon$"

Quiz_2C_Option_2:
	.string "Fairy$"

Quiz_2C_Option_3:
	.string "Grass$"

Quiz_2C_Option_4:
	.string "Ground$"

Second_Trick_House_Quiz_3::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Second_TrickHousePuzzle3_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_2C_Option_1, 0
	dynmultipush Quiz_2C_Option_2, 1
	dynmultipush Quiz_2C_Option_3, 2
	dynmultipush Quiz_2C_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Randomize_Quiz_House_Male_Battle_One
	case 2, Randomize_Quiz_House_Male_Battle_One
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Second_TrickHousePuzzle4_Text:
	.string "But wait, there's more!\n"
	.string "Here's question four!\p"
	.string "Which of these pokemon requires the\n"
	.string "most experience to reach level 100?$"

Quiz_2D_Option_1:
	.string "Glalie$"

Quiz_2D_Option_2:
	.string "Lunatone$"

Quiz_2D_Option_3:
	.string "Seviper$"

Quiz_2D_Option_4:
	.string "Zangoose$"

Second_Trick_House_Quiz_4::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Second_TrickHousePuzzle4_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_2D_Option_1, 0
	dynmultipush Quiz_2D_Option_2, 1
	dynmultipush Quiz_2D_Option_3, 2
	dynmultipush Quiz_2D_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Randomize_Quiz_House_Male_Battle_One
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Male_Battle_One
	releaseall
	end

Second_TrickHousePuzzle5_Text:
	.string "I like your drive!\n"
	.string "Here's question five!\p"
	.string "Which of these pokemon has NEVER\n"
	.string "been shiny locked?$"

Quiz_2E_Option_1:
	.string "Female Kabuto$"

Quiz_2E_Option_2:
	.string "Jirachi$"

Quiz_2E_Option_3:
	.string "Male Clefairy$"

Quiz_2E_Option_4:
	.string "Unown S$"

Second_Trick_House_Quiz_5::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Second_TrickHousePuzzle5_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_2E_Option_1, 0
	dynmultipush Quiz_2E_Option_2, 1
	dynmultipush Quiz_2E_Option_3, 2
	dynmultipush Quiz_2E_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Randomize_Quiz_House_Male_Battle_One
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Male_Battle_One
	releaseall
	end

Second_TrickHousePuzzle6_Text:
	.string "Holy shit!\n"
	.string "It's question six!\p"
	.string "Which of these pokemon is not in\n"
	.string "the Water 3 egg group?$"

Quiz_2F_Option_1:
	.string "Archeops$"

Quiz_2F_Option_2:
	.string "Clamperl$"

Quiz_2F_Option_3:
	.string "Lileep$"

Quiz_2F_Option_4:
	.string "Skorupi$"

Second_Trick_House_Quiz_6::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Second_TrickHousePuzzle6_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_2F_Option_1, 0
	dynmultipush Quiz_2F_Option_2, 1
	dynmultipush Quiz_2F_Option_3, 2
	dynmultipush Quiz_2F_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_One
	case 1, Quiz_House_Correct_Proceed
	case 2, Randomize_Quiz_House_Female_Battle_One
	case 3, Randomize_Quiz_House_Female_Battle_One
	releaseall
	end

Second_TrickHousePuzzle7_Text:
	.string "Looks like you're sweatin'!\n"
	.string "Here's question seven!\p"
	.string "In Pokemon Emerald, if there's\n"
	.string "no active weather and you have a\l"
	.string "pokemon with stench out, which\l"
	.string "weather setting move will the AI\l"
	.string "refuse to use?$"

Quiz_2G_Option_1:
	.string "Hail$"

Quiz_2G_Option_2:
	.string "Rain Dance$"

Quiz_2G_Option_3:
	.string "Sandstorm$"

Quiz_2G_Option_4:
	.string "Sunny Day$"

Second_Trick_House_Quiz_7::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Second_TrickHousePuzzle7_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_2G_Option_1, 0
	dynmultipush Quiz_2G_Option_2, 1
	dynmultipush Quiz_2G_Option_3, 2
	dynmultipush Quiz_2G_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Quiz_House_Correct_Proceed
	case 2, Randomize_Quiz_House_Male_Battle_One
	case 3, Randomize_Quiz_House_Male_Battle_One
	releaseall
	end

Second_TrickHousePuzzle8_Text:
	.string "Pressing that button would be great.\n"
	.string "Before you can, you must answer\l"
	.string "question eight!\p"
	.string "Bug types have the lowest average\n"
	.string "stat for every stat except which one?$"

Quiz_2H_Option_1:
	.string "Attack$"

Quiz_2H_Option_2:
	.string "Defense$"

Quiz_2H_Option_3:
	.string "HP$"

Quiz_2H_Option_4:
	.string "Special Attack$"

Quiz_2H_Option_5:
	.string "Special Defense$"

Quiz_2H_Option_6:
	.string "Speed$"

Second_Trick_House_Quiz_8::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Second_TrickHousePuzzle8_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_2H_Option_1, 0
	dynmultipush Quiz_2H_Option_2, 1
	dynmultipush Quiz_2H_Option_3, 2
	dynmultipush Quiz_2H_Option_4, 3
	dynmultipush Quiz_2H_Option_5, 4
	dynmultipush Quiz_2H_Option_6, 5
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_One
	case 1, Quiz_House_Correct_Proceed
	case 2, Randomize_Quiz_House_Female_Battle_One
	case 3, Randomize_Quiz_House_Female_Battle_One
	case 4, Randomize_Quiz_House_Female_Battle_One
	case 5, Randomize_Quiz_House_Female_Battle_One
	releaseall
	end

Second_TrickHousePuzzle9_Text:
	.string "You look like you're dying to\n"
	.string "answer question nine!\p"
	.string "Which of these pokemon does not\n"
	.string "have a pokdex entry that describes\l"
	.string "their death?$"

Quiz_2I_Option_1:
	.string "Jumpluff$"

Quiz_2I_Option_2:
	.string "Klang$"

Quiz_2I_Option_3:
	.string "Primeape$"

Quiz_2I_Option_4:
	.string "Yamask$"

Second_Trick_House_Quiz_9::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Second_TrickHousePuzzle9_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_2I_Option_1, 0
	dynmultipush Quiz_2I_Option_2, 1
	dynmultipush Quiz_2I_Option_3, 2
	dynmultipush Quiz_2I_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_One
	case 1, Randomize_Quiz_House_Female_Battle_One
	case 2, Randomize_Quiz_House_Female_Battle_One
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Second_TrickHousePuzzle10_Text:
	.string "You've made it the end!\n"
	.string "Are you ready for question ten?\p"
	.string "To stop the Pokemon Platinum AI \n"
	.string "from using bide, which evolution\l"
	.string "stone should your pokemon hold?$"

Quiz_2J_Option_1:
	.string "Dawn Stone$"

Quiz_2J_Option_2:
	.string "Moon Stone$"

Quiz_2J_Option_3:
	.string "Shiny Stone$"

Quiz_2J_Option_4:
	.string "Sun Stone$"

Second_Trick_House_Quiz_10::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Second_TrickHousePuzzle10_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_2J_Option_1, 0
	dynmultipush Quiz_2J_Option_2, 1
	dynmultipush Quiz_2J_Option_3, 2
	dynmultipush Quiz_2J_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_One
	case 1, Randomize_Quiz_House_Female_Battle_One
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Female_Battle_One
	releaseall
	end

