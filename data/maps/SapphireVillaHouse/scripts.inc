SapphireVillaHouse_MapScripts::
	.byte 0

SapphireVillaHouseLoreKeeper::
	lockall
	applymovement LOCALID_SAPPHIRE_LK, Common_Movement_FacePlayer
	goto_if_eq VAR_SAPPHIRE_LEGEND_STATE, 3, RetellSapphireLegend
	goto_if_eq VAR_SAPPHIRE_LEGEND_STATE, 1, SapphireVillaShouldBattle
	msgbox SapphireLorekeeperPreBattle, MSGBOX_DEFAULT
	setvar VAR_SAPPHIRE_LEGEND_STATE, 1
	goto SapphireVillaShouldBattle

SapphireVillaShouldBattle::
	msgbox SapphireLorekeeperPrepForBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, StartSapphireVillaBattle
	msgbox SapphireLorekeeperReturnLater, MSGBOX_DEFAULT
	releaseall
	end

StartSapphireVillaBattle::
	setstartingstatus STARTING_STATUS_TRICK_ROOM
	msgbox SapphireLorekeeperBattleStart, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LK_SAPPHIRE, SapphireLorekeeperDefeat
	msgbox SapphireLorekeeperPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAPPHIRE_LEGEND
	setvar VAR_SAPPHIRE_LEGEND_STATE, 2
	clearflag FLAG_SAPPHIRE_LK_OUTSIDE
	goto LeaveToTellSapphireLegendOutside

TellSapphireLegend::
	msgbox SapphireLorekeeperLegend, MSGBOX_DEFAULT
	releaseall
	end

RetellSapphireLegend::
	msgbox TellSapphireLegendAgainText, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TellSapphireLegend
	releaseall
	end

LeaveToTellSapphireLegendOutside::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	call_if_eq VAR_RESULT, DIR_NORTH, MovePlayerOutofLKWay
	applymovement LOCALID_SAPPHIRE_LK, LK_Leave_Building
	waitmovement
	removeobject LOCALID_SAPPHIRE_LK
	playse SE_DOOR
	waitse
	specialvar VAR_RESULT, GetPlayerFacingDirection
	call_if_eq VAR_RESULT, DIR_EAST, MovePlayerRightAndDownRuby
	call_if_eq VAR_RESULT, DIR_WEST, MovePlayerDownRuby
	applymovement LOCALID_PLAYER, Player_Leave_Building
	waitmovement
	warp MAP_SAPPHIRE_VILLA, 11, 21
	waitstate
	end

SapphireLorekeeperPreBattle:
	.string "It has been a long time since I\n"
	.string "had a visitor to the Sapphire Villa.\p"
	.string "This villa has been under an intense\n"
	.string "rainstorm for thousands of years.\p"
	.string "Only those that Kyogre fully trusts\n"
	.string "are able to find their way here.\p"
	.string "If you are here now, then Kyogre\n"
	.string "must have deemed you worthy of\l"
	.string "hearing the Sapphire Legend.\p"
	.string "Long ago, Kyogre and Groudon fought\n"
	.string "across the Hoenn region.\p"
	.string "Kyogre had the help of many slow\n"
	.string "aquatic pokémon, and so sought out\l"
	.string "areas where it was these pokémon that\l"
	.string "were able to act first in battle.\p"
	.string "This very villa was constructed on\n"
	.string "one of these locations.$"

SapphireLorekeeperPrepForBattle:
	.string "Kyogre may have deemed you worthy,\n"
	.string "but before I explain more I must see\l"
	.string "for myself if you are deserving.\p"
	.string "Are you prepared for a battle where\n"
	.string "speed is a detrement?$"

SapphireLorekeeperBattleStart:
	.string "Slow your expectations and prove to me\n"
	.string "you are worthy of the Sapphire Legend!$"

SapphireLorekeeperDefeat:
	.string "Kyogre was correct to trust you.$"

SapphireLorekeeperReturnLater:
	.string "Please return when you are ready\n"
	.string "for me to test your skills.$"

SapphireLorekeeperPostBattle:
	.string "Very well, I shall entrust to you the\n"
	.string "knowledge of the Sapphire Legend just\l"
	.string "as my ancestors entrusted it to me.\p"
	.string "Please follow me outside.$"

SapphireLorekeeperLegend:
	.string "Thousands of years ago Hoenn looked\n"
	.string "much different than it did now.\p"
	.string "What is now the eastern part of\n"
	.string "mainland Hoenn was at the time a\l"
	.string "deserted wasteland.\p"
	.string "Sandstorms and intense heat raged\n"
	.string "from what is now Fallarbor Town all\l"
	.string "the way to the edge of the sea.\p"
	.string "At the time, all of civilization\n"
	.string "inhabited a castle within Meteor Falls.\p"
	.string "One day, a pokémon from another\n"
	.string "dimension entered into our world and\l"
	.string "sought to plunge Hoenn into chaos.\p"
	.string "With the help of their pokémon, the\n"
	.string "humans were able to trap this pokémon\l"
	.string "within their castle and return it to\l"
	.string "its own dimension; however their home\l"
	.string "was largely destroyed in the process.\p"
	.string "With the power to summon rain, Kyogre\n"
	.string "was able to cool the heat of the\l"
	.string "desert and bring rain to the region,\l"
	.string "allowing plants and vegetation to grow\l"
	.string "and humans to move east towards the sea.\p"
	.string "Kyogre had the help of two other\n"
	.string "pokémon, Wailord and Relicanth, to\l"
	.string "spread water across mainland Hoenn.\p"
	.string "Wailord, a large pokémon in its own\n"
	.string "right, created spouts of water near the\l"
	.string "ocean that Kyogre funneled inland.\p"
	.string "Relicanth, regarded as the ultimate\n"
	.string "lifeform, was able to travel upstream\l"
	.string "through even the muddiest rivers as\l"
	.string "Kyogre created them and route them\l"
	.string "where they would best serve people.\p"
	.string "This is how the rivers you see in\n"
	.string "modern Hoenn first came to be.\p"
	.string "Unfortunately, Groudon felt threatened\n"
	.string "by Kyogre as the rivers and storms grew\l"
	.string "closer to the cavern it called home.\p"
	.string "Kyogre proceeded to get into a conflict\n"
	.string "with Groudon and left the job of\l"
	.string "spreading water to Relicanth and Wailord.\p"
	.string "Eventually, the conflict between\n"
	.string "Kyogre and Groudon subsided, at which\l"
	.string "time the Wailord and Relicanth also\l"
	.string "returned to the open ocean.\p"

TellSapphireLegendAgainText:
	.string "Would you like to hear the Sapphire\n"
	.string "Legend once again?$"
