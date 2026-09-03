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
	facefollowernpc
	waitmovement
	msgbox StevenArceusRoomText1, MSGBOX_NPC
	msgbox ArceusText1, MSGBOX_AUTOCLOSE
	waitmessage
	delay 45
	playse SE_PIN
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_ExclamationMark
	waitmovement
	delay 45
	msgbox StevenArceusRoomText2, MSGBOX_AUTOCLOSE
	waitmessage
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, CameraPantoArceus
	waitmovement
	msgbox ArceusText2, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement LOCALID_CAMERA, CameraPanFromArceus
	waitmovement
	waitmessage
	msgbox StevenArceusRoomText3, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement
	applymovement LOCALID_CAMERA, CameraPantoArceus
	waitmovement
	msgbox ArceusText3, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement LOCALID_CAMERA, CameraPanFromArceus
	waitmovement
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_FaceUp
	waitmovement
	msgbox StevenArceusRoomText4, MSGBOX_AUTOCLOSE
	applymovement LOCALID_CAMERA, CameraPantoArceus
	waitmovement
	msgbox ArceusText4, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement LOCALID_CAMERA, CameraPanFromArceus
	waitmovement
	facefollowernpc
	waitmessage
	msgbox StevenArceusRoomText5, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement
	applymovement LOCALID_CAMERA, CameraPantoArceus
	waitmovement
	msgbox ArceusText5, MSGBOX_AUTOCLOSE
	waitmessage
	applymovement LOCALID_ARCEUS_DISTORTION, ArceusDistortionMovement
	waitmovement
	special RemoveCameraObject
	call ArceusRogueFight1
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, CameraPanFromArceus
	waitmovement
	msgbox ArceusDefeatText1, MSGBOX_AUTOCLOSE
	waitmessage
	call ArceusRogueFight2
	msgbox ArceusDefeatText2, MSGBOX_AUTOCLOSE
	waitmessage
	call ArceusRogueFight3
	msgbox ArceusDefeatText3, MSGBOX_AUTOCLOSE
	msgbox StevenPostArceusBattleText1, MSGBOX_AUTOCLOSE
	msgbox ArceusDefeatText4, MSGBOX_AUTOCLOSE
	msgbox StevenPostArceusBattleText2, MSGBOX_AUTOCLOSE
	msgbox ArceusDefeatText5, MSGBOX_AUTOCLOSE
	warp MAP_ULTRA_SPACE, 10, 20
	waitstate
	end


ArceusRogueFight1::
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
	return

ArceusRogueFight2::
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1
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

ArceusRogueFight3::
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

StevenArceusRoomText1:
	.string "Steven: Necrozma seems to have been\n"
	.string "guarding another pokemon.\p"
	.string "I've never seen it before so we\n"
	.string "better be careful.$"

ArceusText1:
	.string "???: Humans…\n"
	.string "What have you wrought…$"

StevenArceusRoomText2:
	.string "Steven: {PLAYER}, did you\n"
	.string "say something?\p"
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
	.string "here.\p"
	.string "I wonder what this pokemon wants\n"
	.string "with it?$"

ArceusText3:
	.string "???: Giratina…\n"
	.string "What… have you done with Giratina?\p"
	.string "Where… have you taken it?\p"
	.string "Why… have you taken it?$"

StevenArceusRoomText4:
	.string "Steven: We didn't do anything\n"
	.string "to Giratina, it sent us here!$"

ArceusText4:
	.string "???: You… have taken Giratina!?!\p"
	.string "You… are responsible!?!\p"
	.string "Ultra Space… is closing in…\p"
	.string "Palkia… has lost control…\p"
	.string "Dialga… is also gone…\p"
	.string "Time itself may soon collapse.\p"
	.string "Because of you… chaos is coming…$"

StevenArceusRoomText5:
	.string "Steven: {PLAYER} if what this pokemon\n"
	.string "is saying is true, Cyrus has taken\l"
	.string "the Creation Trio from out their\l"
	.string "proper places in the universe.\p"
	.string "If we can't set them free then\n"
	.string "all of existence could be in danger!\p"
	.string "We have to get this pokemon to\n"
	.string "understand!$"

ArceusText5:
	.string "???: I understand…\p"
	.string "I… understand the damage you\n"
	.string "have caused!\p"
	.string "You must understand…\n"
	.string "I am Arceus… creator of all…\p"
	.string "For disrupting the world…\n"
	.string "You… shall pay!\p"
	.string "The time… has come…\n"
	.string "Prepare for justice!$"

ArceusDefeatText1:
	.string "Arceus: You… have much… power\p"
	.string "I can feel… energy weakening…\p"
	.string "What… have you done with the\n"
	.string "creation trio…\p"
	.string "You must… tell me…\p"
	.string "There must be… Justice!$"

ArceusDefeatText2:
	.string "Arceus: You… do not harbor evil\n"
	.string "within you…\p"
	.string "Yet you take the creation trio\n"
	.string "and throw the universe into chaos.\p"
	.string "Why…\p"
	.string "Why do you do this?\p"
	.string "Explain this to me!\p"
	.string "Allow me to deliver… true justice!$"

ArceusDistortionMovement:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

ArceusTextIfPlayerKOd:
	.string "The time… has come…\n"
	.string "Prepare for justice!$"

ArceusRogueFight::
	lockall
	msgbox ArceusTextIfPlayerKOd, MSGBOX_AUTOCLOSE
	waitmessage
	call ArceusRogueFight1
	msgbox ArceusDefeatText1, MSGBOX_AUTOCLOSE
	waitmessage
	call ArceusRogueFight2
	msgbox ArceusDefeatText2, MSGBOX_AUTOCLOSE
	waitmessage
	call ArceusRogueFight3
	msgbox ArceusDefeatText3, MSGBOX_AUTOCLOSE
	msgbox StevenPostArceusBattleText1, MSGBOX_AUTOCLOSE
	msgbox ArceusDefeatText4, MSGBOX_AUTOCLOSE
	msgbox StevenPostArceusBattleText2, MSGBOX_AUTOCLOSE
	msgbox ArceusDefeatText5, MSGBOX_AUTOCLOSE
	warp MAP_ULTRA_SPACE, 10, 20
	waitstate
	end

CameraPantoArceus:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

CameraPanFromArceus:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

ArceusDefeatText3:
	.string "Arceus: You… are not the ones\n"
	.string "responsible for this.\p"
	.string "I remember now.\n"
	.string "It was the blue haired man…\p"
	.string "He trapped me here… with the\n"
	.string "red chain…\p"
	.string "He captured Giratina in the\n"
	.string "same way…\p"
	.string "Presumably he has taken Dialga\n"
	.string "and Palkia as well…\p"
	.string "Normally the Distortion World\n"
	.string "is held stable by Giratina…\p"
	.string "Without it… this location may\n"
	.string "soon cease to exist.\p"
	.string "Ultra Space… is colliding with\n"
	.string "this world and yours…\p"
	.string "Palkia cannot control space from\n"
	.string "where it is right now…\p"
	.string "Next to go will be time…\p"
	.string "Pokemon will begin to disappear\n"
	.string "as if they had never been born…\p"
	.string "Eventually, the universe will\n"
	.string "collapse…$"

StevenPostArceusBattleText1:
	.string "Steven: Surely there's something\n"
	.string "we can do about this?\p"
	.string "If we could get back to our world\n"
	.string "we could free the creation trio\l"
	.string "from under Cyrus's control.\p"
	.string "Unfortunately as far as I can tell\n"
	.string "our journey here was one way only.$"

ArceusDefeatText4:
	.string "Arceus: Steven…\n"
	.string "{PLAYER}…\p"
	.string "Ultra Space has invaded both this\n"
	.string "world and yours.\p"
	.string "However this means they also must\n"
	.string "be linked together.\p"
	.string "I shall follow the flow of energy\n"
	.string "of Ultra Space and return you to\l"
	.string "Hoenn.\p"
	.string "Then we shall free the creation trio.$"

StevenPostArceusBattleText2:
	.string "Steven: Can you actually do that?\p"
	.string "What if we end up trapped in\n"
	.string "here or Ultra Space?$"

ArceusDefeatText5:
	.string "Arceus: If we do nothing…\n"
	.string "the universe will collapse…\p"
	.string "The winds of time will not\n"
	.string "blow for much longer.\p"
	.string "We must act quickly…\p"
	.string "Let us begin our journey…$"
	
