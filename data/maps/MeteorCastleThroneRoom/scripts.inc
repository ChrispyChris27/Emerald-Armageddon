MeteorCastleThroneRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MeteorCastleThroneRoom_OnFrame
	.byte 0

MeteorCastleThroneRoom_OnFrame::
	map_script_2 VAR_STEVEN_MF_STATE, 4, Cyrus_Event_Script
	.2byte 0

Cyrus_Event_Script::
	lockall
	setflag FLAG_ORIGIN_FORMS
	special StopMapMusic
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
	msgbox Cyrus_Text3, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_M_DETECT
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	fadescreen FADE_TO_WHITE
	removeobject LOCALID_DIALGA_A
	removeobject LOCALID_PALKIA_A
	removeobject LOCALID_TINA_A
	clearflag FLAG_ORIGIN_FORMS
	addobject LOCALID_DIALGA_O
	addobject LOCALID_PALKIA_O
	addobject LOCALID_TINA_O
	applymovement LOCALID_MF_STEVEN5, StevenEscape
	waitmovement 0
	delay 200
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 24  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 150
	special StopMapMusic
	playmoncry SPECIES_DIALGA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_PALKIA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox ThroneRoomStevenText2, MSGBOX_AUTOCLOSE
	special HealPlayerParty
	goto ThroneRoomPickMulti
	end

ThroneRoomDoMulti::
	special StopMapMusic
	multi_2_vs_1 TRAINER_CYRUS_DOUBLE, CyrusDefeat2, PARTNER_STEVEN2
	switch VAR_RESULT
	case 1, CyrusDefeated
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

ThroneRoomPickMulti::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, ThroneRoomDoMulti
	special LoadPlayerParty
	special StopMapMusic
	goto StevenReadyBattle

StevenReadyBattle::
	msgbox StevenReadyPrompt, MSGBOX_AUTOCLOSE
	closemessage
	goto ThroneRoomPickMulti

CyrusDefeated::
	end


StevenStop:
.string "{PLAYER}! Look out!$"

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
	.string "And who might you be?\p"
	.string ". . .\p"
	.string "So your name is {PLAYER}.\p"
	.string "Your friend STEVEN warned me\n"
	.string "somebody else would be coming.\p"
	.string "My name is CYRUS.\p"
	.string "Long ago I led TEAM GALACTIC in\n"
	.string "the SINNOH region until I entered\l"
	.string "another dimension in my quest to\l"
	.string "form a new world.\p"
	.string "At long last, I have escaped from\n"
	.string "that prison back into this world!\p"
	.string "I hear that I have two mad scientists\n"
	.string "to thank for that stroke of luck.\p"
	.string "While the ancient POKéMON fought,\n"
	.string "the fabric connecting my reality and\l"
	.string "yours was weakened enough for me to\l"
	.string "cross back into this world.\p"
	.string "Now I can finally begin anew my quest\n"
	.string "to create my ideal world!\p"
	.string "With the aid of the POKéMON that I\n"
	.string "captured over the years, I shall\l"
	.string "shape this reality as I see fit!\p"
	.string "Fwahahaha!$"

ThroneRoomStevenText1:
	.string "{PLAYER}, I'm trapped by\n"
	.string "DIALGA, PALKIA, and GIRATINA!\p"
	.string "You'll have to do something!$"

Cyrus_Text2:
	.string "You wish to stop my plans?\p"
	.string "I've been hardened by the vast\n"
	.string "expanse of nothingness and have\l"
	.string "nothing left to lose.\p"
	.string "Nothing in this world has any\n"
	.string "meaning to me, yet soon all of it\l"
	.string "shall be mine!\p"
	.string "My ideal world. . .\p"
	.string "I have waited so long to escape the\n"
	.string "void, you will not stop me now!$"

CyrusDeffeat1:
	.string "No! I have come too far for\n"
	.string "this to be the end!$"

Cyrus_Text3:
	.string ". . .\n"
	.string ". . .\p"
	.string "Hah...\p"
	.string "Hahaha\p"
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
	.string "DIALGA!\p"
	.string "PALKIA!\p"
	.string "GIRATINA!\p"
	.string "These three created everything in\n"
	.string "this universe!\p"
	.string "Now my POKéMON!\p"
	.string "It is time to show off the origins of\n"
	.string "your power!\p"
	.string "Your unlimited power!$"

ThroneRoomStevenText2:
	.string "{PLAYER}, this is bad.\p"
	.string "PALKIA, DIALGA, and GIRATINA have\n"
	.string "reverted to their ORIGIN FORMS.\p"
	.string "They have the power to turn CYRUS'S\n"
	.string "dreams into reality.\p"
	.string "We have to free them from his control\n"
	.string "before irreparable damage is caused!\p"
	.string "Fortunately I was able to escape while\n"
	.string "they transformed, so I can provide you\l"
	.string "with some assistance now.\p"
	.string "It's time that we teamed up again to\n"
	.string "save the creation trio and stop CYRUS.\p"
	.string "There's no time to waste!\p" 
	.string "I'll heal your POKéMON but I hope\n"
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
