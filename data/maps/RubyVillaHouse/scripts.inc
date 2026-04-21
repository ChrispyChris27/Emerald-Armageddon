RubyVillaHouse_MapScripts::
	.byte 0

RubyVillaHouseLoreKeeper::
	lockall
	applymovement LOCALID_RUBY_LK, Common_Movement_FacePlayer
	goto_if_eq VAR_RUBY_LEGEND_STATE, 3, RetellRubyLegend
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
	msgbox RubyLorekeeperPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_RUBY_LEGEND
	setvar VAR_RUBY_LEGEND_STATE, 2
	clearflag FLAG_RUBY_LK_OUTSIDE
	goto LeaveToTellRubyLegendOutside

TellRubyLegend::
	msgbox RubyLorekeeperLegend, MSGBOX_DEFAULT
	releaseall
	end

RetellRubyLegend::
	msgbox TellRubyLegendAgainText, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TellRubyLegend
	releaseall
	end

LeaveToTellRubyLegendOutside::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	call_if_eq VAR_RESULT, DIR_NORTH, MovePlayerOutofLKWay
	applymovement LOCALID_RUBY_LK, LK_Leave_Building
	waitmovement
	removeobject LOCALID_RUBY_LK
	playse SE_DOOR
	waitse
	specialvar VAR_RESULT, GetPlayerFacingDirection
	call_if_eq VAR_RESULT, DIR_EAST, MovePlayerRightAndDownRuby
	call_if_eq VAR_RESULT, DIR_WEST, MovePlayerDownRuby
	applymovement LOCALID_PLAYER, Player_Leave_Building
	waitmovement
	warp MAP_RUBY_VILLA, 11, 21
	waitstate
	end

MovePlayerOutofLKWay::
	applymovement LOCALID_PLAYER, MovePlayerRight
	waitmovement
	return

MovePlayerRightAndDownRuby::
	applymovement LOCALID_PLAYER, MovePlayerRightAndDown
	waitmovement
	return

MovePlayerDownRuby::
	applymovement LOCALID_PLAYER, MovePlayerDown
	waitmovement
	return

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
	.string "my ancestors entrusted it to me.\p"
	.string "Please follow me outside.$"

RubyLorekeeperLegend:
	.string "Thousands of years ago, all of\n"
	.string "eastern Hoenn was ocean as far\l"
	.string "as the eye could see.\p"
	.string "Island cities like Mossdeep and\n"
	.string "Sootopolis didn't yet exist.\p"
	.string "All human civilization lived in a\n"
	.string "castle in what is now Meteor Falls.\p"
	.string "The desert that nowadays exists only\n"
	.string "on Route 111 spread from what is now\l"
	.string "Fallarbor Town all the way to the\l"
	.string "edge of the ocean.\p"
	.string "It was impossible for humans in those\n"
	.string "times to traverse the desert.\p"
	.string "Groudon, while able to manipulate\n"
	.string "the land, could do nothing about the\l"
	.string "intense heat of the desert.\p"
	.string "One day, a pokémon from another\n"
	.string "dimension entered into our world and\l"
	.string "sought to destroy the Hoenn region,\l"
	.string "plunging it into chaos.\p"
	.string "Those living in Meteor Falls were able\n"
	.string "to secure this pokémon deep within\l"
	.string "the confines of their castle, however\l"
	.string "their old home became uninhabitable\l"
	.string "as a result of trapping the pokémon\l"
	.string "from another dimension inside.\p"
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
	.string "seen since.$"

TellRubyLegendAgainText:
	.string "Would you like to hear the Ruby\n"
	.string "Legend once again?$"

MovePlayerRight:
	walk_right
	face_down
	step_end

MovePlayerRightAndDown:
	walk_right
	walk_down
	step_end

MovePlayerDown:
	walk_down
	step_end

LK_Leave_Building:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Player_Leave_Building:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
