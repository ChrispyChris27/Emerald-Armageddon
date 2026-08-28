DistortionWorldRoom7_MapScripts::
	.byte 0

RogueUltraBeastsScript4::
	lockall
	clearflag FLAG_ROGUE_ULTRA_BEAST1
	clearflag FLAG_ROGUE_ULTRA_BEAST2
	addobject LOCALID_KARTANA
	addobject LOCALID_BUZZWOLE
	playmoncry SPECIES_KARTANA, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_BUZZWOLE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_KARTANA, KartanaMovement
	applymovement LOCALID_BUZZWOLE, BuzzwoleMovement
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_RIGHT, 2, 2, 2, 2, 2
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 2, 2, 2, 2
	setwildbattle SPECIES_KARTANA, 94, ITEM_SHUCA_BERRY, SPECIES_BUZZWOLE, 94, ITEM_ROSELI_BERRY
	waitse
	playmoncry SPECIES_KARTANA, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_BUZZWOLE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RougeUltraBeastDefeated4
	releaseall
	end

RougeUltraBeastDefeated4::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_BUZZWOLE
	removeobject LOCALID_KARTANA
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	addvar VAR_DISTORTION_WORLD_STATE, 1
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

BuzzwoleMovement:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

KartanaMovement:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
