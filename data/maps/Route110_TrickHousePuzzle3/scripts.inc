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
	call Route110_TrickHousePuzzle3_EventScript_SetDoorsState1
	special DrawWholeMapView
	setvar VAR_TEMP_9, 1
	releaseall
	end

Route110_TrickHousePuzzle3_EventScript_PressButton2::
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

