DistortionWorldRoom6_MapScripts::
	.byte 0

RogueUltraBeastsScript3::
	lockall
	clearflag FLAG_ROGUE_ULTRA_BEAST1
	clearflag FLAG_ROGUE_ULTRA_BEAST2
	addobject LOCALID_NAGANADEL
	addobject LOCALID_NIHILEGO
	playmoncry SPECIES_NAGANADEL, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_NIHILEGO, CRY_MODE_ENCOUNTER
	applymovement LOCALID_NAGANADEL, NaganadelMovement
	applymovement LOCALID_NIHILEGO, NihilegoMovement
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_RIGHT, 2, 2, 2, 2, 2
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 2, 2, 2, 2
	setwildbattle SPECIES_NAGANADEL, 94, ITEM_WHITE_HERB, SPECIES_NIHILEGO, 94, ITEM_POWER_HERB
	waitse
	playmoncry SPECIES_NAGANADEL, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_NIHILEGO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RougeUltraBeastDefeated3
	releaseall
	end

RougeUltraBeastDefeated3::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_NIHILEGO
	removeobject LOCALID_NAGANADEL
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	addvar VAR_DISTORTION_WORLD_STATE, 1
	fadescreenswapbuffers FADE_FROM_BLACK
	special HealPlayerParty
	releaseall
	end

NaganadelMovement:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NihilegoMovement:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
