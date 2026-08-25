MeteorCastle2_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MeteorCastle2_OnFrame
	.byte 0

MeteorCastle2_OnFrame::
	map_script_2 VAR_STEVEN_MF_STATE, 3, MeteorCastle2_EventSCript
	.2byte 0

MeteorCastle2_EventSCript::
	lockall
	msgbox MC_Steven1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MCPlayerUp
	waitmovement 0
	applymovement LOCALID_MF_STEVEN4, Common_Movement_FaceDown
	msgbox MC_Steven2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MF_STEVEN4, StevenMoveAround
	waitmovement 0
	msgbox MC_Steven3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MF_STEVEN4, StevenLeave
	waitmovement 0
	removeobject LOCALID_MF_STEVEN4
	setvar VAR_STEVEN_MF_STATE, 4
	releaseall
	end

StevenMoveAround:
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

StevenLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MCPlayerUp:
	walk_up
	walk_up
	step_end

MC_Steven1:
	.string "Well would you look at that...\p"
	.string "It's even more impressive in person.$"

MC_Steven2:
	.string "{PLAYER}, welcome to Meteor Castle.\p"
	.string "This is the castle that protected\n"
	.string "the ancient citizens of Hoenn from\l"
	.string "pokémon of another world.\p"
	.string "I imagine that long ago this castle\n"
	.string "and its many rooms functioned as a\l"
	.string "small city for its inhabitants.\p"
	.string "At the very top of this cliff is\n"
	.string "the throne room where the pokémon\l"
	.string "were sealed away all those years ago.\p"
	.string "I would bet that if they are trying\n"
	.string "to return they will come from there.$"

MC_Steven3:
	.string "Exactly what I thought.\p"
	.string "The energy readings are coming from\n"
	.string "the top of Meteor Castle.\p"
	.string "It's a long ways up from here,\n"
	.string "I'll meet you at the top.\p"
	.string "Be careful of any more rogue pokémon\n"
	.string "that pop up along the way.$"

MeteorCastle_Aero_Enter::
	lockall
	playmoncry SPECIES_AERODACTYL_MEGA, CRY_MODE_ENCOUNTER
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	waitfieldeffect FLDEFF_NPCFLY_OUT
	addobject LOCALID_TOTEM_AERO
	goto MeteorCastleAeroBattle

MeteorCastleAeroBattle::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 2, 1, 0, 2
	setwildbattle SPECIES_AERODACTYL_MEGA, 94, ITEM_MUSCLE_BAND
	waitse
	playmoncry SPECIES_AERODACTYL_MEGA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartRogueWildBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Aerodactyl_Defeated
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	releaseall
	end

Aerodactyl_Defeated::
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setvar VAR_ROGUE_STATE, 20 
	playmoncry SPECIES_AERODACTYL_MEGA, CRY_MODE_ENCOUNTER
	waitmoncry
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_TOTEM_AERO
	waitfieldeffect FLDEFF_NPCFLY_OUT
	releaseall
	end

