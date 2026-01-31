MeteorCastleTopFloor_MapScripts::
	.byte 0

MeteorCastle_Fossils_Enter::
	lockall
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_OMASTAR, CRY_MODE_ENCOUNTER
	applymovement LOCALID_TOTEM_KABU, Kabutops_Movement1
	applymovement LOCALID_TOTEM_HELIX, Omastar_Movement1
	waitmovement
	setweather WEATHER_RAIN
	doweather
	delay 60
	applymovement LOCALID_TOTEM_KABU, Kabutops_Movement2
	applymovement LOCALID_TOTEM_HELIX, Omastar_Movement2
	goto MeteorCastleFossilsBattle

MeteorCastleFossilsBattle::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 2, 1, 2, 1
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 2, 1, 2, 1
	setwildbattle SPECIES_KABUTOPS, 90, ITEM_MUSCLE_BAND, SPECIES_OMASTAR, 90, ITEM_WISE_GLASSES
	waitse
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_OMASTAR, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RogueFossilsDefeated
	releaseall
	end

RogueFossilsDefeated::
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setvar VAR_ROGUE_STATE, 21
	resetweather
	doweather
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_OMASTAR, CRY_MODE_ENCOUNTER
	applymovement LOCALID_TOTEM_KABU, Kabutops_Movement3
	applymovement LOCALID_TOTEM_HELIX, Omastar_Movement3
	waitmovement
	waitmovement
	removeobject LOCALID_TOTEM_KABU
	removeobject LOCALID_TOTEM_HELIX
	releaseall
	end

Kabutops_Movement1:
	walk_down
	walk_down
	walk_left
	delay_16
	delay_8
	walk_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_up
	delay_16
	delay_8
	face_right
	delay_16
	delay_8
	face_down
	step_end

Omastar_Movement1:
	walk_down
	walk_down
	walk_right
	delay_16
	delay_8
	walk_left
	delay_16
	delay_8
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	step_end

Kabutops_Movement2:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

Omastar_Movement2:
	walk_down
	walk_down
	walk_down
	face_left
	step_end

Kabutops_Movement3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Omastar_Movement3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
