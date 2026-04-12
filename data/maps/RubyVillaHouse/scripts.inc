RubyVillaHouse_MapScripts::
	.byte 0

RubyVillaHouseLoreKeeper::
	lockall
	applymovement LOCALID_RUBY_LK, Common_Movement_FacePlayer
	goto_if_eq VAR_RUBY_LEGEND_STATE, 2, RetellRubyLegend
	goto_if_eq VAR_RUBY_LEGEND_STATE, 1, RubyVillaShouldBattle
	msgbox RubyLorekeeperPreBattle, MSGBOX_DEFAULT
	setvar VAR_RUBY_LEGEND_STATE, 1
	goto RubyVillaShouldBattle

RubyVillaShouldBattle::
	msgbox RubyLorekeeperPrepForBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, StartRubyVillaBattle
	msgbox RubyLorekeeperReturnLater, MSGBOX_DEFAULT
	releaseall
	end

StartRubyVillaBattle::
	setflag FLAG_INVERSE_BATTLES
	msgbox RubyLorekeeperBattleStart, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LK_RUBY, RubyLorekeeperDefeat
	clearflag FLAG_INVERSE_BATTLES
	msgbox RubyLorekeeperPostBattle, MSGBOX_DEFAULT
	setflag FLAG_RUBY_LEGEND
	setvar VAR_RUBY_LEGEND_STATE, 2
	goto TellRubyLegend

TellRubyLegend::
	msgbox RubyLorekeeperLegend, MSGBOX_DEFAULT
	releaseall
	end

RetellRubyLegend::
	msgbox TellRubyLegendAgainText, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TellRubyLegend
	releaseall
	end


RubyLorekeeperPreBattle:
	.string "It has been a long time since I\n"
	.string "had a visitor to the Ruby Villa.\p"
	.string "This villa has been under intense\n"
	.string "sunlight for thousands of years.\p"
	.string "Only those that Groudon fully trusts\n"
	.string "are able to find their way here.\p"
	.string "If you are here now, then Groudon\n"
	.string "must have deemed you worthy of\l"
	.string "hearing the Ruby Legend.\p"
	.string "Long ago, Groudon and Kyogre fought\n"
	.string "across the Hoenn region.\p"
	.string "With Groudon being a ground type, it\n"
	.string "was weak to Kyogre's attacks, however\l"
	.string "a few areas of Hoenn had a strange\l"
	.string "property that flipped this type\l"
	.string "matchup on its head.\p"
	.string "Groudon sought out these areas to give\n"
	.string "itself the best chance at emerging\l"
	.string "victorious in its battle.\p"
	.string "This very villa was constructed on\n"
	.string "one of these locations.$"

RubyLorekeeperPrepForBattle:
	.string "Groudon may have deemed you worthy,\n"
	.string "but before I tell you more I intend\l"
	.string "to make my own judgement.\p"
	.string "Are you prepared for an inverse battle?$"

RubyLorekeeperBattleStart:
	.string "Invert your expectations and prove to\n"
	.string "me you are worthy of the Ruby Legend!$"

RubyLorekeeperDefeat:
	.string "Groudon was correct to trust you.$"

RubyLorekeeperReturnLater:
	.string "Please return when you are ready\n"
	.string "for me to test your skills.$"

RubyLorekeeperPostBattle:
	.string "Very well, I shall entrust to you the\n"
	.string "knowledge of the Ruby Legend just as\l"
	.string "my ancestors entrusted it to me...$"

RubyLorekeeperLegend:
	.string "Thousands of years ago Hoenn looked\n"
	.string "much different than it did now.\p"
	.string "All of eastern Hoenn was ocean as\n"
	.string "far as the eye could see.\p"
	.string "Cities like Mossdeep and Sootopolis\n"
	.string "didn't even exist.\p"
	.string "All human civilization lived in what\n"
	.string "is now Meteor Falls and the nearby\l"
	.string "towns and villages.\p"
	.string "The desert that nowadays exists only\n"
	.string "on Route 111 spread from what is now\l"
	.string "Fallarbor Town all the way to the\l"
	.string "edge of the ocean.\p"
	.string "It was impossible for humans in those\n"
	.string "times to traverse the desert.\p"
	.string "Groudon, while able to manipulate\n"
	.string "the land, could do nothing about the\l"
	.string "intense heat of the desert.\p"
	.string "As civilization grew, Meteor Falls\n"
	.string "was no longer large enough for all\l"
	.string "humans to live peacefully.\p"
	.string "In response, Groudon created land\n"
	.string "in the ocean to the south as travel\l"
	.string "to the east was impossible.\p"
	.string "As humans had yet to fully conquer\n"
	.string "oceanic travel, Groudon needed help\l"
	.string "from another pokémon, Regigigas.\p"
	.string "Regigigas pulled the newly formed\n"
	.string "land with the humans still on it\l"
	.string "across the sea, forming the land\l"
	.string "that is now Dewford Town, as well\l"
	.string "as the islands and inlets on the\l"
	.string "surrounding routes.\p"
	.string "During this time however, Groudon\n"
	.string "encountered Kyogre, who was unhappy\l"
	.string "to have its ocean disturbed.\p"
	.string "Groudon and Kyogre fought, while\n"
	.string "Regigigas continued to pull land\l"
	.string "across the oceans to allow humans\l"
	.string "to survive.\p"
	.string "Eventually, the conflict between\n"
	.string "Kyogre and Groudon resolved, and\l"
	.string "Regigigas, exhausted from pulling\l"
	.string "so much land across the oceans, went\l"
	.string "into a deep slumber and hasn't been\l"
	.string "seen since.\p"
	.string "This is the Ruby Legend.\p" 
	.string "every island in all of Hoenn was made\n"
	.string "by Groudon and moved by Regigigas to\l"
	.string "allow for humans to expand their\l"
	.string "civilization beyond Meteor Falls.$"

TellRubyLegendAgainText:
	.string "Would you like to hear the Ruby\n"
	.string "Legend once again?$"
