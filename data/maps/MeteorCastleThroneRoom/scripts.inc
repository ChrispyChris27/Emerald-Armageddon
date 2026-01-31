MeteorCastleThroneRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MeteorCastleThroneRoom_OnFrame
	.byte 0

MeteorCastleThroneRoom_OnFrame::
	map_script_2 VAR_STEVEN_MF_STATE, 4, Cyrus_Event_Script
	.2byte 0

Cyrus_Event_Script::
	lockall
	setflag FLAG_ORIGIN_FORMS
	setflag FLAG_ARCEUS
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
	special HealPlayerParty
	delay 180
	fadescreen FADE_FROM_WHITE
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
	waitstate

ThroneRoomPickMulti::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
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
	applymovement OBJ_EVENT_ID_PLAYER, Player_run
	applymovement LOCALID_MF_STEVEN5, Steven_run
	waitmovement 0
	playmoncry SPECIES_ARCEUS_NORMAL, CRY_MODE_NORMAL
	waitmoncry
	addobject LOCALID_ARCEUS
	applymovement LOCALID_ARCEUS, ArceusEnters
	waitmovement 0
	setobjectmovementtype LOCALID_ARCEUS, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	waitmovement 0
	msgbox Cyrus_Text5, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_ARCEUS_NORMAL, CRY_MODE_NORMAL
	waitmoncry
	delay 30
	playmoncry SPECIES_DIALGA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_PALKIA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_TINA_O, TinaMove
	applymovement LOCALID_DIALGA_O, DialgaMove
	applymovement LOCALID_PALKIA_O, PalkiaMove
	waitmovement 0
	setobjectmovementtype LOCALID_TINA_O, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	setobjectmovementtype LOCALID_DIALGA_O, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
	setobjectmovementtype LOCALID_PALKIA_O, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	waitmovement 0
	playmoncry SPECIES_DIALGA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_PALKIA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	msgbox Cyrus_Text6, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_ARCEUS_NORMAL, CRY_MODE_NORMAL
	waitmoncry
	delay 30
	playmoncry SPECIES_DIALGA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_PALKIA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	fadescreen FADE_TO_BLACK
	msgbox Cyrus_Text7, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	playse SE_THUNDER
	waitse
	delay 16
	playse SE_M_COSMIC_POWER
	waitse
	delay 16
	playmoncry SPECIES_GIRATINA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	delay 16
	playse SE_M_COSMIC_POWER
	waitse
	delay 16
	removeobject LOCALID_CYRUS
	removeobject LOCALID_TINA_O
	fadescreen FADE_FROM_BLACK
	setvar VAR_STEVEN_MF_STATE, 5
	playmoncry SPECIES_ARCEUS_NORMAL, CRY_MODE_NORMAL
	waitmoncry
	delay 30
	playmoncry SPECIES_DIALGA_ORIGIN, CRY_MODE_NORMAL
	playmoncry SPECIES_PALKIA_ORIGIN, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_ARCEUS, Legendary_Exit
	applymovement LOCALID_DIALGA_O, Legendary_Exit
	applymovement LOCALID_PALKIA_O, Legendary_Exit
	waitmovement 0
	removeobject LOCALID_DIALGA_O
	removeobject LOCALID_PALKIA_O
	removeobject LOCALID_ARCEUS
	applymovement OBJ_EVENT_ID_PLAYER, Steven_walk
	applymovement LOCALID_MF_STEVEN5, Player_walk
	waitmovement 0
	msgbox ThroneRoomStevenText3, MSGBOX_AUTOCLOSE
	applymovement LOCALID_MF_STEVEN5, Legendary_Exit
	waitmovement 0
	removeobject LOCALID_MF_STEVEN5
	clearflag FLAG_STEVEN_HARBOR
	setflag FLAG_MAGIKARP_WF
	clearflag FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL
	releaseall
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
	.string ". . .\n"
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
	.string "{PLAYER}, this is bad.\p"
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
	.string ". . .\n"
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
	.string "Get out of the way!$"

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
step_end

DialgaMove:
walk_down
walk_down
face_right
step_end

PalkiaMove:
walk_down
walk_down
face_left
step_end

Cyrus_Text6:
	.string "Dialga!\p"
	.string "Palkia!\p"
	.string "Giratina!\p"
	.string "What are you doing!?!?!\p"
	.string "You work for me!\n"
	.string "Send them to the Distortion World!$"

Cyrus_Text7:
	.string "No!\p"
	.string "Don't do this to me!\p"
	.string "I will not go back!\p"
	.string "After all these years of endless\n"
	.string "darkness you can't send me back!\p"
	.string "NOOOOO!!!!!$"

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

ThroneRoomStevenText3:
	.string "It would seem Giratina has returned\n"
	.string "to the Distortion World and taken\l"
	.string "Cyrus with it.\p"
	.string "Fortunately Arceus was able to calm\n"
	.string "the creation trio and break whatever\l"
	.string "control Cyrus had over them.\p"
	.string "I suppose that Palkia, Dialga, and\n"
	.string "Arceus also returned from where they\l"
	.string "came from.\p"
	.string ". . .\p"
	.string "The energy readings have returned to\n"
	.string "normal, and the dimensional rift\l"
	.string "has also been closed.\p"
	.string "It would seem that when Cyrus entered\n"
	.string "our dimension, several other pokémon\l"
	.string "also entered into this world.\p"
	.string "While Ultra Necrozma was sent back,\n"
	.string "the others remain here.\p"
	.string "Perhaps that's what brought Arceus\n"
	.string "to Meteor Castle.\p"
	.string "Just like in ancient times, the \n"
	.string "pokémon from another dimension have\l"
	.string "been sealed in this throne room.\p"
	.string "While we can pass back and forth freely,\n"
	.string "Arceus seems to have set up a barrier to\l"
	.string "to keep the pokémon confined in here.\p"
	.string "This will keep Hoenn safe.\p"
	.string "{PLAYER}, thanks again\n"
	.string "for your help.\p"
	.string "With the energy surges finally gone\n"
	.string "the Magikarp should go back to their\l"
	.string "normal swimming patterns.\p"
	.string "I would like to offer you one more\n"
	.string "gift to assist you in challenging\l"
	.string "the Pokémon League.\p"
	.string "When you have a chance, meet me at\n"
	.string "the Lilycove Harbor.\p"
	.string "I'll be waiting for you.$"

