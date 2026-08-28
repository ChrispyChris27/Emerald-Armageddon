DistortionWorldRoom4_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DistortionWorldRoom4_OnFrame
	.byte 0

DistortionWorldRoom4_OnFrame::
	map_script_2 VAR_DISTORTION_WORLD_STATE, 3, DistortionWorldRoom4_StartStevenFollower
	.2byte 0

DistortionWorldRoom4_StartStevenFollower::
	lockall
	setrespawn HEAL_LOCATION_DISTORTION_WORLD_ROOM4
	applymovement LOCALID_STEVEN_DIST1, Common_Movement_ExclamationMark
	waitmovement
	applymovement LOCALID_STEVEN_DIST1, Common_Movement_FaceUp
	waitmovement
	msgbox StevenDistortionWorld1, MSGBOX_AUTOCLOSE
	setfollowernpc LOCALID_STEVEN_DIST1, FNPC_ALL, StevenDistortionHeal, PARTNER_STEVEN3
	setvar VAR_DISTORTION_WORLD_STATE, 4
	releaseall
	end

StevenDistortionWorld1:
	.string "{PLAYER}, we're not in Kansas anymore.\p"
	.string "This must be the Distortion World.\p"
	.string "This is where Cyrus was trapped for\n"
	.string "all those years.\p"
	.string "This room seems to be a bit more stable\n"
	.string "than the other ones I've gone through.\p"
	.string "The good news is I seem to still be able\n"
	.string "to access my PC from here.\p"
	.string "That must mean that there's still some\n"
	.string "link between our world and here.\p"
	.string "If we can find that link, we might be\n"
	.string "able to return home and stop Cyrus.\p"
	.string "Who knows what pokémon we may\n"
	.string "find in here.\p"
	.string "{PLAYER}, it's best to stick together\n"
	.string "in this void.\p"
	.string "Let me know if you need me to heal\n"
	.string "your pokémon.$"

StevenDistortionHeal::
	msgbox DistortionStevenHealText, MSGBOX_NPC
	waitmessage
	special HealPlayerParty
	end

DistortionStevenHealText:
	.string "Here, let me heal your pokémon.$"

RogueUltraBeastsScript1::
	lockall
	clearflag FLAG_ROGUE_ULTRA_BEAST1
	clearflag FLAG_ROGUE_ULTRA_BEAST2
	addobject LOCALID_XURKITREE
	addobject LOCALID_GUZZLORD
	playmoncry SPECIES_XURKITREE, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_GUZZLORD, CRY_MODE_ENCOUNTER
	applymovement LOCALID_XURKITREE, XurkitreeMovement
	applymovement LOCALID_GUZZLORD, GuzzlordMovement
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	setrespawn HEAL_LOCATION_DISTORTION_WORLD_ROOM4
	settotemboost B_POSITION_OPPONENT_RIGHT, 2, 2, 2, 2, 2
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 2, 2, 2, 2
	setwildbattle SPECIES_XURKITREE, 94, ITEM_SHUCA_BERRY, SPECIES_GUZZLORD, 94, ITEM_ROSELI_BERRY
	waitse
	playmoncry SPECIES_XURKITREE, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_GUZZLORD, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RougeUltraBeastDefeated1
	releaseall
	end

RougeUltraBeastDefeated1::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_GUZZLORD
	removeobject LOCALID_XURKITREE
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	addvar VAR_DISTORTION_WORLD_STATE, 1
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

XurkitreeMovement:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GuzzlordMovement:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

