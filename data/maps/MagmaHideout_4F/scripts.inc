MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 0
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FaceLeft
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	giveitem ITEM_CAMERUPTITE
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setflag FLAG_HIDEOUT_MAXIE
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "I want to see GROUDON, too, but they\n"
	.string "won't let me see even its tail…\p"
	.string "It's got me feeling really frustrated.\p"
	.string "Oh, no!\n"
	.string "I blabbed about GROUDON!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "I guess it's impossible to win if one\n"
	.string "doesn't have a calm mind…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "I wonder if GROUDON even has a tail?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha!\n"
	.string "Soon! Very soon!\l"
	.string "Our grand objective will be achieved!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr…\n"
	.string "I've come so far, but now this?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "MAXIE, sir!\n"
	.string "An intruder is headed your way!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "You're not finished yet!\n"
	.string "You're not getting by me easily!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "Was I that easy to knock down?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "C-come on, one more match…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Hehehe!\n"
	.string "You made it this far, so I'll tell you!\p"
	.string "That's right!\n"
	.string "Up ahead, GROUDON is sleeping!\p"
	.string "MAXIE went to GROUDON just seconds\n"
	.string "ago!\p"
	.string "It's going to awaken real soon!\n"
	.string "Hehe! Hehehe!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Taken down again…\n"
	.string "Hehe…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…And while you wasted time with me,\n"
	.string "MAXIE should have awakened GROUDON…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAXIE: GROUDON…\p"
	.string "Nothing could awaken you from your\n"
	.string "sleep bathed in magma…\p"
	.string "This RED ORB is what you sought.\n"
	.string "Wasn't it?\p"
	.string "I have brought you the RED ORB.\n"
	.string "Let its shine awaken you!\p"
	.string "And show me…\n"
	.string "Show me the full extent of your power!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAXIE: GROUDON!\n"
	.string "I knew it!\p"
	.string "The RED ORB was the key!\p"
	.string "GROUDON!\p"
	.string "Join me and together we shall expand\n"
	.string "HOENN's landmass and realize my dream!$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "You!\p"
	.string "I've seen you poking around uninvited\n"
	.string "here and there…\p"
	.string "I get it now!\n"
	.string "You must be trying to shatter my dreams!\p"
	.string "You interrupted my plans on MT. CHIMNEY,\n"
	.string "then again in NEW MAUVILLE.\p"
	.string "But you were too late then and you're\n"
	.string "too late again now!\p"
	.string "Now that GROUDON is under my control,\n"
	.string "there is nothing you can do to stop me!\p"
	.string "Fwahahaha!\p"
	.string "Come GROUDON!\p"
	.string "With your power we shall crush this\n"
	.string "child once and for all!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "Even with GROUDON I still lost?$"

MagmaHideout_4F_Text_MaxieGroudon:
	.string "GROUDON!\p"
	.string "GROUDON where have you gone!?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "You!\p"
	.string "Did you pull a cheap stunt?\p"
	.string "Are you the reason why GROUDON fled?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Humph…\p"
	.string "With the RED ORB I should have been\n"
	.string "able to control GROUDON.\p"
	.string "How were you able to shatter that\n" 
	.string "control?\p"
	.string "Is it because we were defeated in\n"
	.string "battle?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Perhaps GROUDON deemed me unworthy to\n"
	.string "wield its power.\p"
	.string "With GROUDON gone, there is no longer\n"
	.string "any need for this blasted volcano.\p"
	.string "Is this...the end of my dream?\p"
	.string "No!\p"
	.string "As long as I hold the RED ORB, I can\n"
	.string "find GROUDON again!\p"
	.string "One way or another I will achieve my\n"
	.string "dream!\p"
	.string "I am going after GROUDON, so this\n"
	.string "is where we part!\p"
	.string "Consider this a bribe not to follow me!$"

MagmaHideout_4F_EventScript_RealTabitha::
	trainerbattle_single TRAINER_TABITHA_DOUBLE, MagmaHideout_4F_Text_RealTabithaIntro, MagmaHideout_4F_Text_RealTabithaDefeat
	msgbox MagmaHideout_4F_Text_RealTabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_RealTabithaIntro:
	.string "With the Red Orb, Maxie will be able\n"
	.string "to awaken Groudon's true power!\p"
	.string "Finally our mission will be complete!\p"
	.string "I'm sure Maxie could handle you himself\n"
	.string "but we're both itching for revenge.\p"
	.string "We'll do him a favor and take you\n"
	.string "out ourselves!$"

MagmaHideout_4F_Text_RealTabithaDefeat:
	.string "I can't believe it.\n"
	.string "We lost again!?!$"

MagmaHideout_4F_Text_RealTabithaPostBattle:
	.string "You're too late!\p"
	.string "Maxie has already reached Groudon!\p"
	.string "By now it should be under his control.$"
