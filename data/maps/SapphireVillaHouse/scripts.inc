SapphireVillaHouse_MapScripts::
	.byte 0

SapphireVillaHouseLoreKeeper::
	lockall
	applymovement LOCALID_SAPPHIRE_LK, Common_Movement_FacePlayer
	goto_if_eq VAR_SAPPHIRE_LEGEND_STATE, 2, RetellSapphireLegend
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
	msgbox SapphireLorekeeperPostBattle, MSGBOX_DEFAULT
	setflag FLAG_SAPPHIRE_LEGEND
	setvar VAR_SAPPHIRE_LEGEND_STATE, 2
	goto TellSapphireLegend

TellSapphireLegend::
	msgbox SapphireLorekeeperLegend, MSGBOX_DEFAULT
	releaseall
	end

RetellSapphireLegend::
	msgbox TellSapphireLegendAgainText, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TellSapphireLegend
	releaseall
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
	.string "as my ancestors entrusted it to me...$"

SapphireLorekeeperLegend:
	.string "Thousands of years ago Hoenn looked\n"
	.string "much different than it did now.\p"
	.string "What is now the eastern part of\n"
	.string "mainland Hoenn was at the time a\l"
	.string "deserted wasteland.\p"
	.string "Sandstorms and intense heat raged\n"
	.string "from what is now Fallarbor Town all\l"
	.string "the way to the edge of the sea."
	.string "At the time, all of civilization\n"
	.string "inhabited a castle within Meteor Falls.\p"
	.string "As their population grew, the castle\n"
	.string "became overcrowded to the point that\l"
	.string "there was no choice but to seek another\l"
	.string "place to live.\p"
	.string "With the power to summon rain, Kyogre was\n"
	.string "able to cool the heat of the desert and\l"
	.string "bring rain to the region, allowing plants\l"
	.string "and vegetation to grow and the humans\l"
	.string "to begin traveling east towards the sea.\p"
	.string "Kyogre had the help of two other\n"
	.string "pokémon, Wailord and Relicanth, to spread\l"
	.string "water across mainland Hoenn.\p"
	.string "Wailord, a large pokémon in its own right,\n"
	.string "created spouts of water near the ocean\l"
	.string "that Kyogre funneled inland.\p"
	.string "Relicanth, regarded as the ultimate\n"
	.string "lifeform, was able to travel upstream\l"
	.string "through even the muddiest rivers as Kyogre\l"
	.string "created them and route them where they\l"
	.string "would best serve people.\p"
	.string "This is how the rivers you see in modern\n"
	.string "Hoenn first came to be.\p"
	.string "Unfortunately, Groudon felt threatened\n"
	.string "by Kyogre as the rivers and storms grew\l"
	.string "closer to the cavern it called home.\p"
	.string "Kyogre proceeded to get into a conflict\n"
	.string "with Groudon and left the job of spreading\l"
	.string "water to humans to Relicanth and Wailord.\p"
	.string "Eventually, the conflict between Kyogre\n"
	.string "and Groudon subsided, at which time\l"
	.string "the Wailord and Relicanth also returned\l"
	.string "to the open ocean.\p"
	.string "This is the Sapphire Legend.\p"
	.string "Every river in Hoenn was made by Kyogre\n"
	.string "with the help of Wailord and Relicanth\l"
	.string "to allow vegetation to grow and human\l"
	.string "civilization to survive outside the\l"
	.string "castle within Meteor Falls.$"

TellSapphireLegendAgainText:
	.string "Would you like to hear the Sapphire\n"
	.string "Legend once again?$"
