.set LOCALID_GRUNTM, 4
.set LOCALID_GRUNTF, 5

MtPyre_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtPyre_1F_OnFrame
	.byte 0

MtPyre_1F_OnFrame::
	map_script_2 VAR_PYRE_GRUNTS, 1, MtPyre_1F_EventScript_GruntBattles
	.2byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "All sorts of beings wander the slopes\n"
	.string "of MT. PYRE…\p"
	.string "There is no telling what may happen.\n"
	.string "Take this. It's for your own good.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Have a POKéMON hold that\n"
	.string "CLEANSE TAG.\p"
	.string "It will help ward off wild POKéMON.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Did you come to pay your respect\n"
	.string "to the spirits of departed POKéMON?\p"
	.string "You must care for your POKéMON a lot.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "This is the final resting place of my\n"
	.string "ZIGZAGOON. I cherished it…$"

MtPyre_1F_Text_Grunt1:
	.string "TEAM MAGMA beat us to the summit,\n"
	.string "but nobody else will reach it!$"

MtPyre_1F_Text_Grunt2:
	.string "Nobody except TEAM AQUA can be\n"
	.string "allowed past here!\p"
	.string "Explore MT. PYRE to your heart's\n"
	.string "content but leave the summit to us!$"

MtPyre_1F_Text_Grunts1:
	.string "Hey!\p"
	.string "How did you get over there?\p"
	.string "Nobody is allowed to reach the\n"
	.string "summit until the boss has finished\l"
	.string "his business!\p"
	.string "We'll have to stop you from getting\n"
	.string "any closer!$"

MtPyre_1F_Text_Grunts2:
	.string "The kid's been weakened, time\n"
	.string "for you to have a go!$"

MtPyre_1F_Text_Grunts3:
	.string "I'm stronger than my partner here.\p"
	.string "You're weaker than when you battled\n"
	.string "him.\p"
	.string "This doesn't end well for you!$"

MtPyre_1F_Text_Grunts4:
	.string "The boss!\p"
	.string "We have to warn the boss!$"

Pyre_Grunt1_Defeat:
	.string "At least I've softened you up!$"

Pyre_Grunt2_Defeat:
	.string "I hope the boss's business is\n"
	.string "finished!$"

MtPyre_1F_EventScript_Grunt1::
	msgbox MtPyre_1F_Text_Grunt1, MSGBOX_NPC
	end

GruntPyreMovement:
	walk_left
	face_up
	step_end

GruntPyreMovement2:
	walk_down
	step_end

GruntsPyreExit:
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

MtPyre_1F_EventScript_Grunt2::
	msgbox MtPyre_1F_Text_Grunt2, MSGBOX_NPC
	end

MtPyre_1F_EventScript_GruntBattles::
	lockall
	setvar VAR_PYRE_GRUNTS, 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNTM, Common_Movement_ExclamationMark
	applymovement LOCALID_GRUNTF, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNTM, Common_Movement_FaceLeft
	applymovement LOCALID_GRUNTF, Common_Movement_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox MtPyre_1F_Text_Grunts1, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_AQUA_PYRE_1, Pyre_Grunt1_Defeat
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox MtPyre_1F_Text_Grunts2, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNTF, GruntPyreMovement
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox MtPyre_1F_Text_Grunts3, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_AQUA_PYRE_2, Pyre_Grunt2_Defeat
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox MtPyre_1F_Text_Grunts4, MSGBOX_AUTOCLOSE
	applymovement LOCALID_GRUNTM, GruntPyreMovement2
	waitmovement 0
	applymovement LOCALID_GRUNTF, GruntsPyreExit
	applymovement LOCALID_GRUNTM, GruntsPyreExit
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GRUNTM
	removeobject LOCALID_GRUNTF
	setvar VAR_PYRE_GRUNTS, 2
	fadedefaultbgm
	releaseall
	end


