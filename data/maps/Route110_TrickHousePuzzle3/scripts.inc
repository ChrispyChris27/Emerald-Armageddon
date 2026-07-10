Route110_TrickHousePuzzle3_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle3_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle3_OnTransition
	.byte 0

Route110_TrickHousePuzzle3_OnResume:
	call_if_eq VAR_TEMP_9, 0, Route110_TrickHousePuzzle3_EventScript_SetDoorsState0
	call_if_eq VAR_TEMP_9, 1, Route110_TrickHousePuzzle3_EventScript_SetDoorsState1
	end

Route110_TrickHousePuzzle3_OnTransition:
	setvar VAR_TEMP_9, 0
	end

Route110_TrickHousePuzzle3_EventScript_SetDoorsState0::
	setmetatile 0, 6, METATILE_TrickHousePuzzle_Button_Up, FALSE
	setmetatile 13, 6, METATILE_TrickHousePuzzle_Button_Up, FALSE
	setmetatile 0, 10, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 7, 9, METATILE_TrickHousePuzzle_Button_Up, FALSE
	setmetatile 5, 10, METATILE_TrickHousePuzzle_Button_Up, FALSE
	setmetatile 14, 6, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 1, 6, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 2, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
	setmetatile 3, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
	setmetatile 2, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, TRUE
	setmetatile 3, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, TRUE
	setmetatile 2, 5, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
	setmetatile 3, 5, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
	setmetatile 2, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, TRUE
	setmetatile 3, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, TRUE
	setmetatile 6, 5, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
	setmetatile 7, 5, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
	setmetatile 6, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, TRUE
	setmetatile 7, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, TRUE
	setmetatile 2, 9, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
	setmetatile 3, 9, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
	setmetatile 2, 8, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
	setmetatile 3, 8, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
	setmetatile 11, 5, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
	setmetatile 12, 5, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
	setmetatile 11, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
	setmetatile 12, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
	setmetatile 8, 6, METATILE_TrickHousePuzzle_RedDoorV_Open1, TRUE
	setmetatile 8, 5, METATILE_TrickHousePuzzle_RedDoorV_Open0, TRUE
	return

Route110_TrickHousePuzzle3_EventScript_SetDoorsState1::
	setmetatile 0, 6, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 13, 6, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 5, 10, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 0, 10, METATILE_TrickHousePuzzle_Button_Up, FALSE
	setmetatile 7, 9, METATILE_TrickHousePuzzle_Button_Pressed, FALSE
	setmetatile 14, 6, METATILE_TrickHousePuzzle_Button_Up, FALSE
	setmetatile 1, 6, METATILE_TrickHousePuzzle_Button_Up, FALSE
	setmetatile 2, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
	setmetatile 3, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
	setmetatile 2, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
	setmetatile 3, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
	setmetatile 2, 5, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
	setmetatile 3, 5, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
	setmetatile 2, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
	setmetatile 3, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
	setmetatile 6, 5, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, FALSE
	setmetatile 7, 5, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, FALSE
	setmetatile 6, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, FALSE
	setmetatile 7, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, FALSE
	setmetatile 2, 9, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
	setmetatile 3, 9, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
	setmetatile 2, 8, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, TRUE
	setmetatile 3, 8, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, TRUE
	setmetatile 11, 5, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, TRUE
	setmetatile 12, 5, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, TRUE
	setmetatile 11, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, TRUE
	setmetatile 12, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, TRUE
	setmetatile 8, 5, METATILE_TrickHousePuzzle_RedDoorV_Retracted, TRUE
	setmetatile 8, 6, METATILE_TrickHousePuzzle_Floor_ShadowTop_Alt, FALSE
	return

Route110_TrickHousePuzzle3_EventScript_Press_Button::
	lockall
	switch VAR_TEMP_9
	case 0, Route110_TrickHousePuzzle3_EventScript_PressButton1
	case 1, Route110_TrickHousePuzzle3_EventScript_PressButton2

Route110_TrickHousePuzzle3_EventScript_PressButton1::
	playse SE_PIN
	call Route110_TrickHousePuzzle3_EventScript_SetDoorsState1
	special DrawWholeMapView
	setvar VAR_TEMP_9, 1
	releaseall
	end

Route110_TrickHousePuzzle3_EventScript_PressButton2::
	playse SE_PIN
	call Route110_TrickHousePuzzle3_EventScript_SetDoorsState0
	special DrawWholeMapView
	setvar VAR_TEMP_9, 0
	releaseall
	end

Route110_TrickHousePuzzle3_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_3_STATE, 0, Route110_TrickHousePuzzle3_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle3_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_3_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle3_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is coveted.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Third_TrickHousePuzzle1_Text:
	.string "Welcome to the Trick House!\p"
	.string "Answer all of our questions\n"
	.string "and earn some fabulous prizes!\p"
	.string "Each time you get a question wrong\n"
	.string "though, one of your prizes will be\l"
	.string "taken away and you'll have to\l"
	.string "fight a battle!\p"
	.string "Today's theme is...\p"
	.string "Anime and Manga!\p"
	.string "Here's your first question:\p"
	.string "Which legendary trio killed Hunter J\n"
	.string "in the anime?$"

Quiz_3A_Option_1:
	.string "Aura Trio$"

Quiz_3A_Option_2:
	.string "Creation Trio$"

Quiz_3A_Option_3:
	.string "Lake Trio$"

Quiz_3A_Option_4:
	.string "Regi Trio$"

Third_Trick_House_Quiz_1::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Third_TrickHousePuzzle1_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_3A_Option_1, 0
	dynmultipush Quiz_3A_Option_2, 1
	dynmultipush Quiz_3A_Option_3, 2
	dynmultipush Quiz_3A_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_One
	case 1, Randomize_Quiz_House_Female_Battle_One
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Female_Battle_One
	releaseall
	end

Third_TrickHousePuzzle2_Text:
	.string "Question two is made for you!\p"
	.string "What is the name of the winning\n"
	.string "Magikarp in the anime's Magikarp\l"
	.string "high jump competition?$"

Quiz_3B_Option_1:
	.string "Gika$"

Quiz_3B_Option_2:
	.string "Goldeenlocks$"

Quiz_3B_Option_3:
	.string "Maggie$"

Quiz_3B_Option_4:
	.string "Shinegoldie$"

Third_Trick_House_Quiz_2::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Third_TrickHousePuzzle2_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_3B_Option_1, 0
	dynmultipush Quiz_3B_Option_2, 1
	dynmultipush Quiz_3B_Option_3, 2
	dynmultipush Quiz_3B_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Randomize_Quiz_House_Male_Battle_One
	case 2, Randomize_Quiz_House_Male_Battle_One
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Third_TrickHousePuzzle3_Text:
	.string "Question three is made for thee!\p"
	.string "An anime episode featured an island\n"
	.string "where every pokemon was what color?$"

Quiz_3C_Option_1:
	.string "Blue$"

Quiz_3C_Option_2:
	.string "Green$"

Quiz_3C_Option_3:
	.string "Orange$"

Quiz_3C_Option_4:
	.string "Pink$"

Third_Trick_House_Quiz_3::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Third_TrickHousePuzzle3_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_3C_Option_1, 0
	dynmultipush Quiz_3C_Option_2, 1
	dynmultipush Quiz_3C_Option_3, 2
	dynmultipush Quiz_3C_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Randomize_Quiz_House_Male_Battle_One
	case 2, Randomize_Quiz_House_Male_Battle_One
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Third_TrickHousePuzzle4_Text:
	.string "Question four, it is now yours!\p"
	.string "Which Team Magma member was killed\n"
	.string "by a Tentacruel in the Ruby and\l"
	.string "Sapphire arc of Pokemon Adventures?$"

Quiz_3D_Option_1:
	.string "Blaise$"

Quiz_3D_Option_2:
	.string "Courtney$"

Quiz_3D_Option_3:
	.string "Maxie$"

Quiz_3D_Option_4:
	.string "Tabitha$"

Third_Trick_House_Quiz_4::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Third_TrickHousePuzzle4_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_3D_Option_1, 0
	dynmultipush Quiz_3D_Option_2, 1
	dynmultipush Quiz_3D_Option_3, 2
	dynmultipush Quiz_3D_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Quiz_House_Correct_Proceed
	case 2, Randomize_Quiz_House_Male_Battle_One
	case 3, Randomize_Quiz_House_Female_Battle_One
	releaseall
	end

Third_TrickHousePuzzle5_Text:
	.string "Question five will make you feel alive!\p"
	.string "Which of these moves from Generation I\n"
	.string "has yet to be used in the anime?$"

Quiz_3E_Option_1:
	.string "Barrage$"

Quiz_3E_Option_2:
	.string "Pay Day$"

Quiz_3E_Option_3:
	.string "Spike Cannon$"

Quiz_3E_Option_4:
	.string "Thrash$"

Third_Trick_House_Quiz_5::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Third_TrickHousePuzzle5_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_3E_Option_1, 0
	dynmultipush Quiz_3E_Option_2, 1
	dynmultipush Quiz_3E_Option_3, 2
	dynmultipush Quiz_3E_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Female_Battle_One
	case 2, Randomize_Quiz_House_Female_Battle_One
	case 3, Randomize_Quiz_House_Female_Battle_One
	releaseall
	end

Third_TrickHousePuzzle6_Text:
	.string "Question six contains some tricks!\p"
	.string "What was the first Pokemon to die\n"
	.string "in the anime outside of movies?$"

Quiz_3F_Option_1:
	.string "Cleffa$"

Quiz_3F_Option_2:
	.string "Marowak$"

Quiz_3F_Option_3:
	.string "Stoutland$"

Quiz_3F_Option_4:
	.string "Torracat$"

Third_Trick_House_Quiz_6::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Third_TrickHousePuzzle6_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_3F_Option_1, 0
	dynmultipush Quiz_3F_Option_2, 1
	dynmultipush Quiz_3F_Option_3, 2
	dynmultipush Quiz_3F_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Randomize_Quiz_House_Male_Battle_One
	case 2, Quiz_House_Correct_Proceed
	case 3, Randomize_Quiz_House_Male_Battle_One
	releaseall
	end

Third_TrickHousePuzzle7_Text:
	.string "Question seven takes it to eleven!\p"
	.string "Members of the Pokemon Daisuki Club\n"
	.string "received exclusive online access to a\l"
	.string "manga based on the events of which\l"
	.string "spin off game?$"

Quiz_3G_Option_1:
	.string "Pokemon Detective Pikachu$"

Quiz_3G_Option_2:
	.string "Pokemon Mystery Dungeon$"

Quiz_3G_Option_3:
	.string "Pokemon PokePark$"

Quiz_3G_Option_4:
	.string "Pokemon Ranger$"

Third_Trick_House_Quiz_7::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Third_TrickHousePuzzle7_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_3G_Option_1, 0
	dynmultipush Quiz_3G_Option_2, 1
	dynmultipush Quiz_3G_Option_3, 2
	dynmultipush Quiz_3G_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Randomize_Quiz_House_Male_Battle_One
	case 2, Randomize_Quiz_House_Male_Battle_One
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Third_TrickHousePuzzle8_Text:
	.string "Question eight is for you, mate!\p"
	.string "Which of these berries is not\n"
	.string "anime exclusive?$"

Quiz_3H_Option_1:
	.string "Melody Berry$"

Quiz_3H_Option_2:
	.string "Mirage Berry$"

Quiz_3H_Option_3:
	.string "Pinkan Berry$"

Quiz_3H_Option_4:
	.string "Rinka Berry$"

Third_Trick_House_Quiz_8::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Third_TrickHousePuzzle8_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_3H_Option_1, 0
	dynmultipush Quiz_3H_Option_2, 1
	dynmultipush Quiz_3H_Option_3, 2
	dynmultipush Quiz_3H_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Male_Battle_One
	case 1, Quiz_House_Correct_Proceed
	case 2, Randomize_Quiz_House_Male_Battle_One
	case 3, Randomize_Quiz_House_Male_Battle_One
	releaseall
	end

Third_TrickHousePuzzle9_Text:
	.string "Question nine is just in time!\p"
	.string "Who is the only character in the\n"
	.string "anime canonically confirmed to\l"
	.string "have committed murder?$"

Quiz_3I_Option_1:
	.string "Argus Steel$"

Quiz_3I_Option_2:
	.string "Grings Kodai$"

Quiz_3I_Option_3:
	.string "Doctor Fuji$"

Quiz_3I_Option_4:
	.string "Doctor Zed$"

Third_Trick_House_Quiz_9::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Third_TrickHousePuzzle9_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_3I_Option_1, 0
	dynmultipush Quiz_3I_Option_2, 1
	dynmultipush Quiz_3I_Option_3, 2
	dynmultipush Quiz_3I_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Randomize_Quiz_House_Female_Battle_One
	case 1, Randomize_Quiz_House_Female_Battle_One
	case 2, Randomize_Quiz_House_Female_Battle_One
	case 3, Quiz_House_Correct_Proceed
	releaseall
	end

Third_TrickHousePuzzle10_Text:
	.string "Question ten means it's the end!\p"
	.string "Which of these Kanto Gym Leaders\n"
	.string "was not a member of Team Rocket in\l"
	.string "the Pokemon Adventures manga?$"

Quiz_3J_Option_1:
	.string "Erika$"

Quiz_3J_Option_2:
	.string "Koga$"

Quiz_3J_Option_3:
	.string "Lt. Surge$"

Quiz_3J_Option_4:
	.string "Sabrina$"

Third_Trick_House_Quiz_10::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox Third_TrickHousePuzzle10_Text, MSGBOX_DEFAULT
	dynmultipush Quiz_3J_Option_1, 0
	dynmultipush Quiz_3J_Option_2, 1
	dynmultipush Quiz_3J_Option_3, 2
	dynmultipush Quiz_3J_Option_4, 3
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Quiz_House_Correct_Proceed
	case 1, Randomize_Quiz_House_Female_Battle_One
	case 2, Randomize_Quiz_House_Female_Battle_One
	case 3, Randomize_Quiz_House_Female_Battle_One
	releaseall
	end

