RubyVilla_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RubyVilla_OnFrame
	.byte 0

RubyVilla_OnFrame::
	map_script_2 VAR_RUBY_LEGEND_STATE, 2, TellRubyLegendOutside
	.2byte 0

TellRubyLegendOutside:
lockall
applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
waitmovement
msgbox RubyLegendPart1, MSGBOX_AUTOCLOSE
applymovement LOCALID_RUBY_LK_OUTSIDE, RLKMovement1
applymovement LOCALID_PLAYER, RLegendMovement1
waitmovement
msgbox RubyLegendPart2, MSGBOX_AUTOCLOSE
applymovement LOCALID_RUBY_LK_OUTSIDE, RLKMovement2
applymovement LOCALID_PLAYER, RLegendMovement2
waitmovement
msgbox RubyLegendPart3, MSGBOX_AUTOCLOSE
applymovement LOCALID_RUBY_LK_OUTSIDE, RLKMovement3
applymovement LOCALID_PLAYER, RLegendMovement3
waitmovement
msgbox RubyLegendPart4, MSGBOX_AUTOCLOSE
applymovement LOCALID_RUBY_LK_OUTSIDE, RLKMovement3
applymovement LOCALID_PLAYER, RLegendMovement4
waitmovement
msgbox RubyLegendPart5, MSGBOX_AUTOCLOSE
applymovement LOCALID_RUBY_LK_OUTSIDE, RLKMovement5
applymovement LOCALID_PLAYER, RLegendMovement5
waitmovement
msgbox RubyLegendPart6, MSGBOX_AUTOCLOSE
applymovement LOCALID_RUBY_LK_OUTSIDE, RLKMovement6
applymovement LOCALID_PLAYER, RLegendMovement6
waitmovement
msgbox RubyLegendPart7, MSGBOX_AUTOCLOSE
applymovement LOCALID_RUBY_LK_OUTSIDE, RLKMovement7
waitmovement
removeobject LOCALID_RUBY_LK_OUTSIDE
playse SE_DOOR
waitse
setvar VAR_RUBY_LEGEND_STATE, 3
clearflag FLAG_LK_TEMP
releaseall
end

RubyLegendPart1:
	.string "Thousands of years ago, all of\n"
	.string "eastern Hoenn was ocean as far\l"
	.string "as the eye could see.\p"
	.string "Island cities like Mossdeep and\n"
	.string "Sootopolis didn't yet exist.\p"
	.string "All human civilization lived in a\n"
	.string "castle in what is now Meteor Falls.$"

RubyLegendPart2:
	.string "The desert that nowadays exists only\n"
	.string "on Route 111 spread from what is now\l"
	.string "Fallarbor Town all the way to the\l"
	.string "edge of the ocean.\p"
	.string "It was impossible for humans in those\n"
	.string "times to traverse the desert.\p"
	.string "Groudon, while able to manipulate\n"
	.string "the land, could do nothing about the\l"
	.string "intense heat of the desert.$"

RubyLegendPart3:
	.string "One day, a pokémon from another\n"
	.string "dimension entered into our world and\l"
	.string "sought to destroy the Hoenn region,\l"
	.string "plunging it into chaos.\p"
	.string "Those living in Meteor Falls were able\n"
	.string "to secure this pokémon deep within\l"
	.string "the confines of their castle, however\l"
	.string "their old home became uninhabitable\l"
	.string "as a result of trapping the pokémon\l"
	.string "from another dimension inside.$"

RubyLegendPart4:
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
	.string "surrounding routes.$"

RubyLegendPart5:
	.string "During this time however, Groudon\n"
	.string "encountered Kyogre, who was unhappy\l"
	.string "to have its ocean disturbed.\p"
	.string "Groudon and Kyogre fought, while\n"
	.string "Regigigas continued to pull land\l"
	.string "across the oceans to allow humans\l"
	.string "to survive.$"

RubyLegendPart6:
	.string "Eventually, the conflict between\n"
	.string "Kyogre and Groudon resolved, and\l"
	.string "Regigigas, exhausted from pulling\l"
	.string "so much land across the oceans, went\l"
	.string "into a deep slumber and hasn't been\l"
	.string "seen since.$"

RubyLegendPart7:
	.string "This is the Ruby Legend.\p" 
	.string "Every island in all of Hoenn was made\n"
	.string "by Groudon and moved by Regigigas to\l"
	.string "allow for humans to survive after\l"
	.string "a pokémon from another dimension\l"
	.string "destroyed their home in Meteor Falls.$"

RLKMovement1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	face_down
	step_end

RLegendMovement1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

RLKMovement2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

RLegendMovement2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RLKMovement3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_left
	step_end

RLegendMovement3:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RLegendMovement4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RLKMovement5:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_up
	step_end

RLegendMovement5:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RLKMovement6:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_right
	step_end

RLegendMovement6:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RLKMovement7:
	walk_up
	step_end


