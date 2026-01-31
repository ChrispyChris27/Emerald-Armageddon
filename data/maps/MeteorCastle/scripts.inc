MeteorCastle_MapScripts::
	.byte 0

MeteorCastle_Steven_Script::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_MF_STEVEN3, Common_Movement_FaceRight
	waitmovement 0
	msgbox MeteorCastle_Steven_Text, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MF_STEVEN3, MeteorCastle_Steven_Movement
	waitmovement 0
	removeobject LOCALID_MF_STEVEN3
	playse SE_DOOR
	setvar VAR_STEVEN_MF_STATE, 3
	releaseall
	end

MeteorCastle_Steven_Text:
	.string "{PLAYER}{KUN}...\p"
	.string "I believe this should be the\n"
	.string "entrance to Meteor Castle.\p"
	.string "The energy readings continue to\n"
	.string "grow stronger.\p"
	.string "We must be getting closer to the\n"
	.string "cause of all of this.\p"
	.string "It's time to see what remains of\n"
	.string "the ancient castle.\p"
	.string "I'll see you on the inside.$"

MeteorCastle_Steven_Movement:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MeteorCastle_GyaraMilo_Enter::
	lockall
	playmoncry SPECIES_MILOTIC, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_GYARADOS_MEGA, CRY_MODE_ENCOUNTER
	applymovement LOCALID_TOTEM_MILO, Milotic_Movement1
	applymovement LOCALID_TOTEM_GARY, Gary_Movement1
	goto MeteorCastleRogueBattle

MeteorCastleRogueBattle::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 2, 1, 2, 1
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 2, 1, 2, 1
	setwildbattle SPECIES_MILOTIC, 90, ITEM_THROAT_SPRAY, SPECIES_GYARADOS_MEGA, 90, ITEM_LEFTOVERS
	waitse
	playmoncry SPECIES_GYARADOS_MEGA, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_MILOTIC, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, GaryMiloRogueDefeated
	releaseall
	end

GaryMiloRogueDefeated::
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setvar VAR_ROGUE_STATE, 19 
	playmoncry SPECIES_MILOTIC, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_GYARADOS_MEGA, CRY_MODE_ENCOUNTER
	applymovement LOCALID_TOTEM_GARY, Gary_Movement2
	applymovement LOCALID_TOTEM_MILO, Milotic_Movement2
	waitmovement
	removeobject LOCALID_TOTEM_MILO
	removeobject LOCALID_TOTEM_GARY
	playse SE_M_DIVE
	releaseall
	end


Milotic_Movement1:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

Gary_Movement1:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

Gary_Movement2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

Milotic_Movement2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end
	
