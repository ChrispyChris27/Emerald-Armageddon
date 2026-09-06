MeteorCastleThroneRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MeteorCastleThroneRoom_OnFrame
	.byte 0

MeteorCastleThroneRoom_OnFrame::
	map_script_2 VAR_DISTORTION_WORLD_STATE, 11, Arceus_Event_Script_Castle
	map_script_2 VAR_STEVEN_MF_STATE, 4, Cyrus_Event_Script
	.2byte 0

Cyrus_Event_Script::
	lockall
	msgbox StevenStop, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_GIRATINA, CRY_MODE_NORMAL
	waitmoncry
	applymovement OBJ_EVENT_ID_PLAYER, PlayerApproach
	waitmovement 0
	playmoncry SPECIES_DIALGA, CRY_MODE_NORMAL
	playmoncry SPECIES_PALKIA, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_CYRUS, Common_Movement_FaceDown
	waitmovement 0
	msgbox Cyrus_Text1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MF_STEVEN5, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox ThroneRoomStevenText1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CYRUS, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Cyrus_Text2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CYRUS, CyrusDeffeat1
	playbgm MUS_NCASTLE, FALSE
	msgbox Cyrus_Text3, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_M_DETECT
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	fadescreenswapbuffers FADE_TO_WHITE
	removeobject LOCALID_DIALGA_A
	removeobject LOCALID_PALKIA_A
	removeobject LOCALID_TINA_A
	clearflag FLAG_ORIGIN_FORMS
	addobject LOCALID_DIALGA_O
	addobject LOCALID_PALKIA_O
	addobject LOCALID_TINA_O
	applymovement LOCALID_MF_STEVEN5, StevenEscape
	waitmovement 0
	special HealPlayerParty
	delay 180
	fadescreenswapbuffers FADE_FROM_WHITE
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 24  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 120
	special StopMapMusic
	playmoncry SPECIES_DIALGA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_PALKIA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox ThroneRoomStevenText2, MSGBOX_AUTOCLOSE
	goto ThroneRoomPickMulti
	
	end

ThroneRoomDoMulti::
	multi_2_vs_1 TRAINER_CYRUS_DOUBLE, CyrusDefeat2, PARTNER_STEVEN2
	switch VAR_RESULT
	case 1, CyrusDefeated
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut

ThroneRoomPickMulti::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_ne VAR_RESULT, 0, ThroneRoomDoMulti
	special LoadPlayerParty
	goto StevenReadyBattle

StevenReadyBattle::
	msgbox StevenReadyPrompt, MSGBOX_AUTOCLOSE
	closemessage
	goto ThroneRoomPickMulti

CyrusDefeated::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox Cyrus_Text4, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	msgbox Steven_Throne_Text1, MSGBOX_DEFAULT
	closemessage
	warpteleport MAP_DISTORTION_WORLD_ENTRANCE, 0, 18
	waitstate
	end

StevenStop:
.string "{PLAYER}! Help!$"

PlayerApproach:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Cyrus_Text1:
	.string "???: And who might you be?\p"
	.string ". . .\p"
	.string "So your name is {PLAYER}.\p"
	.string "Your friend Steven warned me\n"
	.string "somebody else would be coming.\p"
	.string "My name is Cyrus.\p"
	.string "Long ago I led Team Galactic in\n"
	.string "the Sinnoh region until I entered\l"
	.string "another dimension in my quest to\l"
	.string "form a new world.\p"
	.string "At long last, I have escaped from\n"
	.string "that prison back into this world!\p"
	.string "I hear that I have two mad scientists\n"
	.string "to thank for that stroke of luck.\p"
	.string "While the ancient pokémon fought,\n"
	.string "the fabric connecting my reality and\l"
	.string "yours was weakened enough for me to\l"
	.string "cross back into this world.\p"
	.string "It would seem my exit from the space\n"
	.string "time distortion I previously inhabited\l"
	.string "may have had the unintended side effect\l"
	.string "of allowing Ultra Necrozma back into\l"
	.string "this world as well, but thanks to you\l"
	.string "Necrozma is no longer an issue.\p"
	.string "Now I can finally begin anew my quest\n"
	.string "to create my ideal world!\p"
	.string "With the aid of the pokémon that I\n"
	.string "captured over the years, I shall\l"
	.string "shape this reality as I see fit!\p"
	.string "Fwahahaha!$"

ThroneRoomStevenText1:
	.string "Steven: {PLAYER}, I'm trapped by\n"
	.string "Dialga, Palkia, and Giratina!\p"
	.string "You'll have to do something!$"

Cyrus_Text2:
	.string "Cyrus: Just as the super ancient\n"
	.string "pokémon of Hoenn created this world,\l"
	.string "I shall use the super ancient pokémon\l"
	.string "of Sinnoh to create a better one!\p"
	.string "Dialga, creator of time.\p"
	.string "Palkia, creator of space.\p"
	.string "Giratina, the antimatter that will\n"
	.string "bring about this world's end!\p"
	.string "Just as Regigigas helped Kyogre and\n"
	.string "Groudon form this world in ancient\l"
	.string "times, I too shall make use of its\l"
	.string "power to tear this world apart!\p"
	.string "Resistance is futile!\p"
	.string "Anyone who dares to try and stop\n"
	.string "me shall be plunged into an enternal\l"
	.string "slumber of horrifying nightmares!\p"
	.string ". . .\n"
	.string ". . .\p"
	.string "You are unafraid of my power!?!?\p"
	.string "You wish to stop my plans?\p"
	.string "I've been hardened by the vast\n"
	.string "expanse of nothingness and have\l"
	.string "nothing left to lose.\p"
	.string "Nothing in this world has any\n"
	.string "meaning to me, yet soon all of it\l"
	.string "shall be mine!\p"
	.string "My ideal world . . .\p"
	.string "I have waited so long to escape the\n"
	.string "void, you will not stop me now!$"

CyrusDeffeat1:
	.string "No! I have come too far for\n"
	.string "this to be the end!$"

Cyrus_Text3:
	.string "Cyrus: . . .\n"
	.string ". . .\p"
	.string "Ha. . .\p"
	.string "Hahaha!\p"
	.string "Fwahahahaha!\p"
	.string "You think that just because you\n"
	.string "defeated me once this is over?\p"
	.string "I am relentless!\p"
	.string "I am inevitable!\p"
	.string "I have been hardened by the void of\n"
	.string "nothingness!\p"
	.string "I have gained powers unimaginable\n"
	.string "by staring into the origins of the\l"
	.string "universe itself!\p"
	.string "Dialga!\p"
	.string "Palkia!\p"
	.string "Giratina!\p"
	.string "These three created everything in\n"
	.string "this universe!\p"
	.string "Now my pokémon!\p"
	.string "It is time to show off the origins of\n"
	.string "your power!\p"
	.string "Your unlimited power!$"

ThroneRoomStevenText2:
	.string "Steven: {PLAYER}, this is bad.\p"
	.string "Palkia, Dialga, and Giratina have\n"
	.string "reverted to their origin forms.\p"
	.string "They have the power to turn Cyrus'S\n"
	.string "dreams into reality.\p"
	.string "We have to free them from his control\n"
	.string "before irreparable damage is caused!\p"
	.string "Fortunately I was able to escape while\n"
	.string "they transformed, so I can provide you\l"
	.string "with some assistance now.\p"
	.string "It's time that we teamed up again to\n"
	.string "save the creation trio and stop Cyrus.\p"
	.string "There's no time to waste!\p" 
	.string "I'll heal your pokémon but I hope\n"
	.string "you're ready!$"

StevenEscape:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	face_right
	step_end

CyrusDefeat2:
	.string "Impossible! You defeated the\n"
	.string "creators of the universe!$"

StevenReadyPrompt:
	.string "There's no time to waste!\p"
	.string "I've healed your POKéMON, time\n"
	.string "to get ready!$"

Cyrus_Text4:
	.string "Cyrus: . . .\n"
	.string ". . .\p"
	.string "This can't be real!\p"
	.string "I must turn this world into my\n"
	.string "ideal place to thrive!\p"
	.string "If you two won't back down then\n"
	.string "I have no choice!\p"
	.string "Giratina!\p"
	.string "Send them to the Distortion World!$"

Steven_Throne_Text1:
	.string "{PLAYER}!\p"
	.string "Look out!$"

ArceusEnters:
walk_up
walk_up
walk_up
walk_up
walk_up
walk_up
walk_up
step_end

Cyrus_Text5:
	.string "Arceus...\p"
	.string "Dialga, Palkia, and Giratina\n"
	.string "may have created the universe,\l"
	.string "but you created them.\p"
	.string "Arceus!\p"
	.string "You alone will help me realize my\n"
	.string "dream of creating my ideal world!\p"
	.string "With you under my control I shall\n"
	.string "become truly unstoppable!$"

Player_run:
walk_fast_right
walk_fast_right
walk_fast_right
face_left
step_end

Steven_run:
walk_fast_left
walk_fast_left
face_right
step_end

TinaMove:
walk_down
walk_down
step_end

PalkiaMove:
walk_left
walk_down
walk_down
walk_down
face_right
step_end

DialgaMove:
walk_right
walk_down
walk_down
walk_down
face_left
step_end

Legendary_Exit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Steven_walk:
walk_left
walk_left
step_end

Player_walk:
walk_right
walk_right
walk_right
step_end

Arceus_Event_Script_Castle::
	lockall 
	playbgm MUS_EMOTIONS, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement
	setobjectxyperm LOCALID_MF_STEVEN5, 14, 14
	setobjectmovementtype LOCALID_MF_STEVEN5, MOVEMENT_TYPE_FACE_RIGHT
	applymovement LOCALID_CYRUS, Common_Movement_FaceLeft
	waitmovement
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, CameraPanToCyrus
	waitmovement
	msgbox Cyrus_Text4, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	msgbox Steven_Throne_Text1, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_FEMALE_PLAYER_CLONE, PlayerSpinIntoWarpMovement
	applymovement LOCALID_MALE_PLAYER_CLONE, PlayerSpinIntoWarpMovement
	waitmovementall
	playse SE_THUNDER
	removeobject LOCALID_FEMALE_PLAYER_CLONE
	removeobject LOCALID_MALE_PLAYER_CLONE
	playse SE_M_COSMIC_POWER
	waitse
	msgbox StevenWherePlayerText, MSGBOX_DEFAULT
	delay 60
	msgbox CyrusSendStevenText, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_MF_STEVEN5, PlayerSpinIntoWarpMovement
	waitmovement
	playse SE_THUNDER
	removeobject LOCALID_MF_STEVEN5
	playse SE_M_COSMIC_POWER
	waitse
	applymovement LOCALID_CYRUS, Common_Movement_FaceUp
	waitmovement
	msgbox CyrusLetUsBeginText, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_DIALGA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_PALKIA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	applymovement LOCALID_CAMERA, CameraPanFromCyrus
	waitmovement
	special RemoveCameraObject
	applymovement LOCALID_STEVEN_DIS, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement
	msgbox StevenThatsUsText, MSGBOX_AUTOCLOSE
	delay 30
	applymovement LOCALID_ARCEUS, Common_Movement_FaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement
	setvar VAR_0x8004, 4  @ vertical pan
	setvar VAR_0x8005, 4  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox ArceusTimeCollapsingText, MSGBOX_AUTOCLOSE
	closemessage
	applymovement LOCALID_ARCEUS, StevenArceusPlayerWalkMovement
	applymovement LOCALID_STEVEN_DIS, StevenArceusPlayerWalkMovement
	delay 15
	applymovement LOCALID_PLAYER, StevenArceusPlayerWalkMovement
	waitmovementall
	delay 30
	playse SE_PIN
	applymovement LOCALID_CYRUS, Common_Movement_ExclamationMark
	waitmovement
	applymovement LOCALID_CYRUS, Common_Movement_FaceDown
	waitmovement
	delay 15
	msgbox CyrusYouReturnedText, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	msgbox StevenCyrusStopText, MSGBOX_AUTOCLOSE
	delay 30
	msgbox CyrusWhatDoYouMeanText, MSGBOX_AUTOCLOSE
	setvar VAR_0x8004, 5  @ vertical pan
	setvar VAR_0x8005, 5  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 15
	msgbox ArceusExplainCollapseText, MSGBOX_AUTOCLOSE
	setvar VAR_0x8004, 6  @ vertical pan
	setvar VAR_0x8005, 6  @ horizontal pan
	setvar VAR_0x8006, 6  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox CyrusWhatSayTrueText, MSGBOX_AUTOCLOSE
	delay 30
	msgbox StevenDontDoThisText, MSGBOX_AUTOCLOSE
	setvar VAR_0x8004, 7  @ vertical pan
	setvar VAR_0x8005, 7  @ horizontal pan
	setvar VAR_0x8006, 7  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 15
	msgbox CyrusTrappedTooLongText, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_DIALGA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_PALKIA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	applymovement LOCALID_TINA_O, TinaMove
	applymovement LOCALID_DIALGA_O, DialgaMove
	applymovement LOCALID_PALKIA_O, PalkiaMove
	applymovement LOCALID_CYRUS, CyrusMoveOutOfTinaway
	waitmovement 0
	setvar VAR_0x8004, 8  @ vertical pan
	setvar VAR_0x8005, 8  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 15
	setobjectmovementtype LOCALID_TINA_O, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	setobjectmovementtype LOCALID_DIALGA_O, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
	setobjectmovementtype LOCALID_PALKIA_O, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	waitmovement 0
	msgbox ArceusAttackChains, MSGBOX_AUTOCLOSE
	applymovement LOCALID_ARCEUS, Common_Movement_FaceRight
	applymovement LOCALID_STEVEN_DIS, Common_Movement_FaceLeft
	waitmovement
	playmoncry SPECIES_DIALGA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_PALKIA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	delay 15
	msgbox PlayerMonAttackChainText, MSGBOX_AUTOCLOSE
	delay 15
	playse SE_M_CUT
	waitse
	playse SE_ICE_BREAK
	waitse
	playse SE_M_CUT
	waitse
	playse SE_ICE_BREAK
	waitse
	playse SE_M_CUT
	waitse
	playse SE_ICE_BREAK
	waitse
	msgbox RedChainShattered, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_DIALGA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_PALKIA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	msgbox CyrusRedChainGoneText, MSGBOX_AUTOCLOSE
	delay 30
	msgbox ArceusPreForJusticeText, MSGBOX_AUTOCLOSE
	applymovement LOCALID_TINA_O, Common_Movement_FaceUp
	applymovement LOCALID_DIALGA_O, DialgaMoveBack
	applymovement LOCALID_PALKIA_O, PalkiaMoveBack
	playmoncry SPECIES_DIALGA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_PALKIA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	waitmovementall
	setobjectmovementtype LOCALID_TINA_O, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	setobjectmovementtype LOCALID_DIALGA_O, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	setobjectmovementtype LOCALID_PALKIA_O, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
	waitmovement 0
	msgbox CyrusPleadText, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_DIALGA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_PALKIA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	setvar VAR_0x8004, 5  @ vertical pan
	setvar VAR_0x8005, 5  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	applymovement LOCALID_CYRUS, PlayerSpinIntoWarpMovement
	waitmovement
	playse SE_THUNDER
	removeobject LOCALID_CYRUS
	playse SE_M_COSMIC_POWER
	waitse
	playmoncry SPECIES_DIALGA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_PALKIA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	setvar VAR_0x8004, 5  @ vertical pan
	setvar VAR_0x8005, 5  @ horizontal pan
	setvar VAR_0x8006, 5  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	applymovement LOCALID_DIALGA_O, PalkiaDialgaLeave
	applymovement LOCALID_PALKIA_O, PalkiaDialgaLeave
	waitmovement
	delay 15
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	delay 15
	playse SE_THUNDER
	removeobject LOCALID_TINA_O
	removeobject LOCALID_PALKIA_O
	removeobject LOCALID_DIALGA_O
	playse SE_M_COSMIC_POWER
	waitse
	fadeoutbgm 1
	playbgm MUS_FAREWELL, TRUE
	applymovement LOCALID_ARCEUS, Common_Movement_FaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_STEVEN_DIS, Common_Movement_FaceRight
	waitmovement
	msgbox ArceusThanksText, MSGBOX_AUTOCLOSE
	giveitem ITEM_MASTER_BALL
	msgbox ArceusDepartText, MSGBOX_AUTOCLOSE
	playse SE_THUNDER
	removeobject LOCALID_ARCEUS
	playse SE_M_COSMIC_POWER
	waitse
	delay 30
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement
	msgbox StevenDepartCastleText, MSGBOX_AUTOCLOSE
	applymovement LOCALID_STEVEN_DIS, StevenExitCastleMovement
	waitmovement
	removeobject LOCALID_STEVEN_DIS
	addvar VAR_DISTORTION_WORLD_STATE, 1
	setvar VAR_STEVEN_MF_STATE, 6
	clearflag FLAG_STEVEN_HARBOR
	setflag FLAG_MAGIKARP_WF
	clearflag FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL
	clearflag FLAG_NECROZMA_CASTLE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement
	addobject LOCALID_NECRO_THRONE
	applymovement LOCALID_NECRO_THRONE, NecrozmaMoveDown
	waitmovement
	playmoncry SPECIES_NECROZMA, CRY_MODE_NORMAL
	waitmoncry
	msgbox NecrozmaThanksText, MSGBOX_AUTOCLOSE
	givemon SPECIES_NECROZMA, 90, ITEM_LIGHT_CLAY, BALL_BEAST
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, SendNecrozmaParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, SendNecrozmaPC
	releaseall
	end

CameraPanToCyrus:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

CameraPanFromCyrus:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

PlayerSpinIntoWarpMovement:
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	step_end

StevenWherePlayerText:
	.string "Steven: Where did {PLAYER} go?\p"
	.string "What have you done?$"

CyrusSendStevenText:
	.string "Cyrus: Fwahahaha!\p"
	.string "Your precious friend has been\n"
	.string "sent to the Distortion World!\p"
	.string "Now it's your turn!\p"
	.string "Send him to the Distortion World\n"
	.string "as well Giratina!$"

CyrusLetUsBeginText:
	.string "Cyrus: Now that those two are out\n"
	.string "of the way we can begin reshaping\l"
	.string "the world as I see fit.\p"
	.string "Come my creation trio!\n"
	.string "Let us begin creating a new world\l"
	.string "where I am in control!$"

StevenThatsUsText:
	.string "Steven: What did we just watch?\p"
	.string "We're right here…\n"
	.string "But we were also right there…\p"
	.string "How could that happen?$"

ArceusTimeCollapsingText:
	.string "Arceus: Time must be starting to\n"
	.string "collapse…\p"
	.string "What we just witnessed has already\n"
	.string "happened…\p"
	.string "Multiple events in time are starting\n"
	.string "to happen at once…\p"
	.string "We must hurry before it is too late.\p"
	.string "The red chains around Dialga, Palkia,\n"
	.string "and Giratina must be destroyed.\p"
	.string "If they are, Cyrus will lose control\n"
	.string "over them and the world will be saved.\p"
	.string "Let us make haste…$"

StevenArceusPlayerWalkMovement:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CyrusYouReturnedText:
	.string "Cyrus: Impossible!\p"
	.string "I just disposed of you two, how\n"
	.string "have you returned at all, let\l"
	.string "alone so quickly!\p"
	.string "… … …\p"
	.string "Arceus… … …\p"
	.string "So you've been freed from your prison\n"
	.string "within the Distortion World as well.\p"
	.string "No matter!\p"
	.string "I still have Giratina so I shall\n"
	.string "simply send you back to the void!$"

StevenCyrusStopText:
	.string "Steven: Cyrus!\n"
	.string "You have to stop this!\p"
	.string "By removing Palkia, Dialga, and\n"
	.string "Giratina from their normal domain\l"
	.string "you've jeopardized the universe!$"

CyrusWhatDoYouMeanText:
	.string "Cyrus: Preposterous!\n"
	.string "What on earth do you mean!?!?$"

ArceusExplainCollapseText:
	.string "Arceus: First you removed Giratina\n"
	.string "from the Distortion World, causing\l"
	.string "it to fall into disarray…\p"
	.string "Next you captured Palkia, causing\n"
	.string "Ultra Space to bleed into this world\l"
	.string "and the Distortion World.\p"
	.string "Ultra Necrozma nearly escaped as a\n"
	.string "result of that choice…\p"
	.string "Last you located Dialga jeopardizing\n"
	.string "time itself…\p"
	.string "If you do not return the creation trio\n"
	.string "soon there will be no more world for\l"
	.string "you to shape!\p"
	.string "Time is starting to collapse, and\n"
	.string "soon will cease to exist all together…$"

CyrusWhatSayTrueText:
	.string "Cyrus: … … …\p"
	.string "If what you say is true… … …\p"
	.string "… … …\p"
	.string "Ha…\p"
	.string "Ha ha ha…\p"
	.string "Fwahahaha!\p"
	.string "Perhaps I have aimed too small!\p"
	.string "Rather than just shaping this world\n"
	.string "as I see fit, I have the opportunity\l"
	.string "to shape an entirely new universe!\p"
	.string "All that stands in my way now is you!$"

StevenDontDoThisText:
	.string "Steven: You can't do this Cyrus!\p"
	.string "We may all cease to exist soon,\n"
	.string "including you!$"

CyrusTrappedTooLongText:
	.string "Cyrus: I have been trapped for far\n"
	.string "too long in the Distortion World!\p"
	.string "You were gone for mere seconds!\p"
	.string "I spent years wasting away in that\n"
	.string "twisted dimension!\p"
	.string "If reality must suffer as I have\n"
	.string "so be it!\p"
	.string "I would rather cease to have existed\n"
	.string "than risk returning to the void!\p"
	.string "And if I succeed… the universe\n"
	.string "itself is mine!\p"
	.string "Dialga!\p"
	.string "Palkia!\p"
	.string "Giratina!\p"
	.string "Lend me your power!\p"
	.string "Return these three to the ethernal\n"
	.string "void of the Distortion World!$"

ArceusAttackChains:
	.string "Arceus: Steven!\n"
	.string "{PLAYER}!\p"
	.string "We have one shot at this!\p"
	.string "Attack the red chains!$"

PlayerMonAttackChainText:
	.string "Your pokemon attacked the red\n"
	.string "chain around Giratina…$"

RedChainShattered:
	.string "The red chains shattered…$"

CyrusMoveOutOfTinaway:
	walk_right
	walk_up
	walk_up
	walk_left
	face_down
	step_end

CyrusRedChainGoneText:
	.string "Cyrus: No!\n"
	.string "It can't be!\p"
	.string "The red chains!\p"
	.string "What have you done!?!?!$"

ArceusPreForJusticeText:
	.string "Arceus: We have saved the universe\n"
	.string "from your evil, foolish desires.\p"
	.string "Now only one more thing remains\n"
	.string "to be done.\p"
	.string "Dialga!\p"
	.string "Palkia!\p"
	.string "Giratina!\p"
	.string "The time has come!\n"
	.string "Prepare for justice!$"

DialgaMoveBack:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

PalkiaMoveBack:
	walk_up
	walk_up
	walk_up
	face_right
	step_end

CyrusPleadText:
	.string "Cyrus: No!\n"
	.string "Please don't send me back!\p"
	.string "This wasn't supposed to happen!\p"
	.string "NOOOOOO!!!!!!!$"

PalkiaDialgaLeave:
	face_down
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

ArceusThanksText:
	.string "Arceus: Steven…\n"
	.string "{PLAYER}…\p"
	.string "Thank you for rescuing the\n"
	.string "creation trio…\p"
	.string "This is my thanks for helping save\n"
	.string "the universe and deliver justice…$"

ArceusDepartText:
	.string "I must now return from whence I came.\p"
	.string "I shall help Giratina watch over Cyrus\n"
	.string "and ensure he can do no further harm.\p"
	.string "I shall make sure justice is served…\p"
	.string "Until we meet again Steven and {PLAYER}…$"

StevenDepartCastleText:
	.string "Steven: I had no idea what we were\n"
	.string "getting ourselves into, did I {PLAYER}…\p"
	.string "Still, we traveled across the galaxy\n"
	.string "and into another world to calm all of\l"
	.string "the rogue pokémon and save the world.\p"
	.string "Thank you for everything {PLAYER}.\p"
	.string "The universe could be over right now\n"
	.string "if it wasn't for you.\p"
	.string "With the energy surges finally gone\n"
	.string "the Magikarp should go back to their\l"
	.string "normal swimming patterns.\p"
	.string "I would like to offer you one more\n"
	.string "gift to assist you in challenging\l"
	.string "the Pokémon League.\p"
	.string "When you have a chance, meet me at\n"
	.string "the Lilycove Harbor.\p"
	.string "I'll be waiting for you.$"

StevenExitCastleMovement:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NecrozmaThanksText:
	.string "Necrozma seems to have stayed behind\n"
	.string "rather than returning to Ultra Space.\p"
	.string "You sense Necrozma wishes to thank you\n"
	.string "for calming it while it was enraged.\p"
	.string "Necrozma wishes to help you take\n"
	.string "on the Pokémon League.$"

NecrozmaMoveDown:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

SendNecrozmaParty::
	call ReceivedNecrozmaFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ReceivedNecrozma
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto ReceivedNecrozma
	end

ReceivedNecrozmaFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_NECROZMA
	removeobject LOCALID_NECRO_THRONE
	playfanfare MUS_OBTAIN_ITEM
	message NecrozmaJoinsTeam
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_NECROZMA
	return

SendNecrozmaPC::
	call ReceivedNecrozmaFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NecrozmaTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto NecrozmaTransferredToPC
	end

NecrozmaTransferredToPC::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_NECROZMA
	call Common_EventScript_TransferredToPC
	goto ReceivedNecrozma
	end

NecrozmaJoinsTeam:
	.string "Necrozma joined your team!$"

ReceivedNecrozma::
	releaseall
	end
