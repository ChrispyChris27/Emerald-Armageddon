DistortionWorldRoom5_MapScripts::
	.byte 0

RogueUltraBeastsScript2::
	lockall
	clearflag FLAG_ROGUE_ULTRA_BEAST1
	clearflag FLAG_ROGUE_ULTRA_BEAST2
	addobject LOCALID_STAKATAKA
	addobject LOCALID_BLACEPHALON
	playmoncry SPECIES_STAKATAKA, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_BLACEPHALON, CRY_MODE_ENCOUNTER
	applymovement LOCALID_STAKATAKA, StakatakaMovement
	applymovement LOCALID_BLACEPHALON, BlacephalonMovement
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_RIGHT, 2, 2, 2, 2, 2
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 2, 2, 2, 2
	setwildbattle SPECIES_STAKATAKA, 94, ITEM_WEAKNESS_POLICY, SPECIES_BLACEPHALON, 94, ITEM_SITRUS_BERRY
	waitse
	playmoncry SPECIES_STAKATAKA, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_BLACEPHALON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RougeUltraBeastDefeated2
	releaseall
	end

RougeUltraBeastDefeated2::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_BLACEPHALON
	removeobject LOCALID_STAKATAKA
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	addvar VAR_DISTORTION_WORLD_STATE, 1
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

StakatakaMovement:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

BlacephalonMovement:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end
