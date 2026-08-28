DistortionWorldRoom8_MapScripts::
	.byte 0

RogueUltraBeastsScript5::
	lockall
	clearflag FLAG_ROGUE_ULTRA_BEAST1
	clearflag FLAG_ROGUE_ULTRA_BEAST2
	addobject LOCALID_PHEROMOSA
	addobject LOCALID_CELESTEELA
	playmoncry SPECIES_PHEROMOSA, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_CELESTEELA, CRY_MODE_ENCOUNTER
	applymovement LOCALID_PHEROMOSA, KartanaMovement
	applymovement LOCALID_CELESTEELA, BuzzwoleMovement
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_RIGHT, 2, 2, 2, 2, 2
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 2, 2, 2, 2
	setwildbattle SPECIES_PHEROMOSA, 94, ITEM_COBA_BERRY, SPECIES_CELESTEELA, 94, ITEM_WEAKNESS_POLICY
	waitse
	playmoncry SPECIES_PHEROMOSA, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_CELESTEELA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RougeUltraBeastDefeated5
	releaseall
	end

RougeUltraBeastDefeated5::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_CELESTEELA
	removeobject LOCALID_PHEROMOSA
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	addvar VAR_DISTORTION_WORLD_STATE, 1
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end
