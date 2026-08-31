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
	msgbox StevenArceusRoomText1, MSGBOX_AUTOCLOSE
	releaseall
	end

ArceusRogueFight::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 2, 2, 2, 2
	random 17
	switch VAR_RESULT
	case 0, ArceusNormalBattle
	case 1, ArceusBattleFighting
	case 2, ArceusBattlePoison
	case 3, ArceusBattleGround
	case 4, ArceusBattleRock
	case 5, ArceusBattleBug
	case 6, ArceusBattleGhost
	case 7, ArceusBattleSteel
	case 8, ArceusBattleFire
	case 9, ArceusBattleWater
	case 10, ArceusBattleGrass
	case 11, ArceusBattleElectric
	case 12, ArceusBattleIce
	case 13, ArceusBattlePsychic
	case 14, ArceusBattleDark
	case 15, ArceusBattleDragon
	case 16, ArceusBattleFairy
	releaseall
	end

ArceusBattleFairy::
	setwildbattle SPECIES_ARCEUS_FAIRY, 100, ITEM_PIXIE_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusBattleDragon::
	setwildbattle SPECIES_ARCEUS_DRAGON, 100, ITEM_DRACO_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusBattleDark::
	setwildbattle SPECIES_ARCEUS_DARK, 100, ITEM_DREAD_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusBattlePsychic::
	setwildbattle SPECIES_ARCEUS_PSYCHIC, 100, ITEM_MIND_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusBattleIce::
	setwildbattle SPECIES_ARCEUS_ICE, 100, ITEM_ICICLE_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusBattleElectric::
	setwildbattle SPECIES_ARCEUS_ELECTRIC, 100, ITEM_ZAP_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusBattleGrass::
	setwildbattle SPECIES_ARCEUS_GRASS, 100, ITEM_MEADOW_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusBattleWater::
	setwildbattle SPECIES_ARCEUS_WATER, 100, ITEM_SPLASH_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusBattleFire::
	setwildbattle SPECIES_ARCEUS_FIRE, 100, ITEM_FLAME_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusNormalBattle::
	setwildbattle SPECIES_ARCEUS, 100, ITEM_SILK_SCARF
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusBattleFighting::
	setwildbattle SPECIES_ARCEUS_FIGHTING, 100, ITEM_FIST_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusBattlePoison::
	setwildbattle SPECIES_ARCEUS_POISON, 100, ITEM_TOXIC_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusBattleGround::
	setwildbattle SPECIES_ARCEUS_GROUND, 100, ITEM_EARTH_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusBattleRock::
	setwildbattle SPECIES_ARCEUS_ROCK, 100, ITEM_STONE_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusBattleBug::
	setwildbattle SPECIES_ARCEUS_BUG, 100, ITEM_INSECT_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusBattleGhost::
	setwildbattle SPECIES_ARCEUS_GHOST, 100, ITEM_SPOOKY_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusBattleSteel::
	setwildbattle SPECIES_ARCEUS_STEEL, 100, ITEM_IRON_PLATE
	special BattleSetup_StartRogueWildBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArceusCalmedDown
	releaseall
	end

ArceusCalmedDown::
	removeobject LOCALID_ARCEUS_DISTORTION
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	releaseall
	end

StevenArceusRoomText1:
	.string "Necrozma seems to have guarding\n"
	.string "another pokemon.\p"
	.string "I've never seen it before so we\n"
	.string "better be careful.$"

ArceusText1:
	.string "???: Humans…\n"
	.string "What have you wrought…$"

StevenArceusRoomText2:
	.string "Steven: {PLAYER}, did you\n"
	.string "something?\p"
	.string "… … …\p"
	.string "But if you didn't say anything…\n"
	.string "it must have been this pokemon.\p"
	.string "I've never seen a pokemon that\n"
	.string "could speak before.$"

ArceusText2:
	.string "???: What… have you done?\p"
	.string "Why… is there disarray?\p"
	.string "Who… trapped me?\p"
	.string "Where… is Giratina?$"

StevenArceusRoomText3:
	.string "Steven: Giratina was one of the\n"
	.string "pokemon Cyrus battled us with.\p"
	.string "That's the pokemon that sent us\n"
	.string "here.$"

ArceusText3:
	.string "???: Giratina…\n"
	.string "What… have you done with Giratina?\p"
	.string "Where… have you taken it?\p"
	.string "Why… have you taken it?$"

StevenArceusRoomText3:
	.string "Steven: We didn't do anything\n"
	.string "to Giratina, it sent us here!$"

ArceusText3:
	.string "???: You… have taken Giratina!?!\p"
	.string "You… are responsible!?!\p"
	.string "Ultra Space… is closing in…\p"
	.string "Palkia… has lost control…\p"
	.string "Dialga… is also gone…\p"
	.string "Time itself may soon collapse.\p"
	.string "Because of you… chaos is coming…$"

StevenArceusRoomText4:
	.string "Steven: {PLAYER} if what this pokemon\n"
	.string "is saying is true, Cyrus has taken\l"
	.string "the Creation Trio from out their\l"
	.string "proper places in the universe.\p"
	.string "If we can't set them free then\n"
	.string "all of existence could be in danger!\p"
	.string "We have to get this pokemon to\n"
	.string "understand!$"

ArceusText4:
	.string "???: I understand…\p"
	.string "I… understand the damage you\n"
	.string "have caused!\p"
	.string "You must… pay!\p"
	.string "The time… has come…\n"
	.string "Prepare for justice!$"

