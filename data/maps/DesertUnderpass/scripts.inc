DesertUnderpass_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
	.byte 0

DesertUnderpass_OnTransition:
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
	end

MeetBombTutor:
	.string "What...what are you doing here?\p"
	.string "Me? I'm trying to turn over a new\n"
	.string "leaf by looking for fossils with\l"
	.string "my brother.\p"
	.string "Back in the days of the war I fought\n"
	.string "alongside LT. SURGE from KANTO.\p"
	.string "I was a bomb maker and my devices\n"
	.string "made sure that the war ended swiftly.\p"
	.string "But...at what cost?\p"
	.string "I would appreciate it if you kept this\n"
	.string "story and location to yourself so that\l"
	.string "I can continue to dig with my brother\l"
	.string "in peace.\p"
	.string "In exchange, I can teach your POKéMON\n"
	.string "Some of the techniques I learned in\l"
	.string "the army.\p"
	.string "POKéMON learn many moves associated\n"
	.string "with bombs, and I promise you it is\p"
	.string "totally safe.$"
	
BombTutorTeachMove:
	.string "Which move should I teach your POKéMON?$"

BombTutorShouldTeach:
	.string "Shall I teach one of your POKéMON\n"
	.string "how to diffuse a bomb?$"

BombTutorChooseMon:
	.string "Which POKéMON should learn an\n"
	.string "explosive move?$"

BombTutorDontTeachText:
	.string "I understand your hesitation.\n"
	.string "If you change your mind let me know.$"

BombTutorTaughtMove:
	.string "Your POKéMON is now an\n"
	.string "explosives expert.\p"
	.string "I would be happy to teach another\n"
	.string "of your POKéMON in the future.$"

BombTutorScript::
	lock
	faceplayer
	goto_if_unset FLAG_MET_BOMB_TUTOR, MeetBombTutorScript
	goto BombTutorTeachMoveScript
	release
	end

MeetBombTutorScript::
	msgbox MeetBombTutor, MSGBOX_DEFAULT
	setflag FLAG_MET_BOMB_TUTOR
	goto BombTutorTeachMoveScript
	release
	end

BombTutorSuccess::
	msgbox BombTutorTaughtMove, MSGBOX_DEFAULT
	release
	end

BombTutorTeachMoveScript::
	msgbox BombTutorShouldTeach, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BombTutorDeclined
	msgbox BombTutorTeachMove, MSGBOX_DEFAULT
	waitmessage
	multichoice 20, 0, MULTI_BOMB_TUTOR, FALSE
	switch VAR_RESULT
	case 0, TeachEggBomb
	case 1, TeachMagnetBomb
	case 2, TeachMudBomb
	case 3, TeachSludgeBomb
	case 4, TeachSeedBomb
	case 5, TeachSyrupBomb
	case MULTI_B_PRESSED, BombTutorDeclined
	release
	end

BombTutorDeclined::
	msgbox BombTutorDontTeachText, MSGBOX_AUTOCLOSE
	release
	end

TeachEggBomb::
	msgbox BombTutorChooseMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_EGG_BOMB
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BombTutorDeclined
	goto BombTutorSuccess
	release
	end

TeachMagnetBomb::
	msgbox BombTutorChooseMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_MAGNET_BOMB
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BombTutorDeclined
	goto BombTutorSuccess
	release
	end

TeachMudBomb::
	msgbox BombTutorChooseMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_MUD_BOMB
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BombTutorDeclined
	goto BombTutorSuccess
	release
	end

TeachSludgeBomb::
	msgbox BombTutorChooseMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SLUDGE_BOMB
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BombTutorDeclined
	goto BombTutorSuccess
	release
	end

TeachSeedBomb::
	msgbox BombTutorChooseMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SEED_BOMB
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BombTutorDeclined
	goto BombTutorSuccess
	release
	end

TeachSyrupBomb::
	msgbox BombTutorChooseMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SYRUP_BOMB
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, BombTutorDeclined
	goto BombTutorSuccess
	release
	end

@ Unused
DesertUnderpass_Text_FoundRootFossil::
	.string "{PLAYER} found the ROOT FOSSIL.$"

@ Unused
DesertUnderpass_Text_FoundClawFossil::
	.string "{PLAYER} found the CLAW FOSSIL.$"

