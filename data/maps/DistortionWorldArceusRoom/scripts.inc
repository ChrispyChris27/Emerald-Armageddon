DistortionWorldArceusRoom_MapScripts::
	.byte 0

RogueUltraBeastsScript6::
	lockall
	playmoncry SPECIES_NECROZMA_DUSK_MANE, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_NECROZMA_DAWN_WINGS, CRY_MODE_ENCOUNTER
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_RIGHT, 2, 2, 2, 2, 2
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 2, 2, 2, 2
	setwildbattle SPECIES_NECROZMA_DUSK_MANE, 94, ITEM_MUSCLE_BAND, SPECIES_NECROZMA_DAWN_WINGS, 94, ITEM_WISE_GLASSES
	waitse
	playmoncry SPECIES_NECROZMA_DUSK_MANE, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_NECROZMA_DAWN_WINGS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RougeUltraBeastDefeated6
	releaseall
	end

RougeUltraBeastDefeated6::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_NECRO_DUSK
	removeobject LOCALID_NECRO_DAWN
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	addvar VAR_DISTORTION_WORLD_STATE, 1
	fadescreenswapbuffers FADE_FROM_BLACK
	special HealPlayerParty
	releaseall
	end
