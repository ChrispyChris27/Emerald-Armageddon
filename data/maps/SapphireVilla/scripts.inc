SapphireVilla_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SapphireVilla_OnFrame
	.byte 0

SapphireVilla_OnFrame::
	map_script_2 VAR_SAPPHIRE_LEGEND_STATE, 2, TellSapphireLegendOutside
	.2byte 0

TellSapphireLegendOutside:
lockall
applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
waitmovement
msgbox SapphireLegendPart1, MSGBOX_AUTOCLOSE
applymovement LOCALID_SAPPHIRE_LK_OUTSIDE, SLKMovement1
applymovement LOCALID_PLAYER, SLegendMovement1
waitmovement
msgbox SapphireLegendPart2, MSGBOX_AUTOCLOSE
applymovement LOCALID_SAPPHIRE_LK_OUTSIDE, SLKMovement2
applymovement LOCALID_PLAYER, SLegendMovement2
waitmovement
msgbox SapphireLegendPart3, MSGBOX_AUTOCLOSE
applymovement LOCALID_SAPPHIRE_LK_OUTSIDE, SLKMovement3
applymovement LOCALID_PLAYER, SLegendMovement3
waitmovement
msgbox SapphireLegendPart4, MSGBOX_AUTOCLOSE
applymovement LOCALID_SAPPHIRE_LK_OUTSIDE, SLKMovement4
applymovement LOCALID_PLAYER, SLegendMovement4
waitmovement
msgbox SapphireLegendPart5, MSGBOX_AUTOCLOSE
applymovement LOCALID_SAPPHIRE_LK_OUTSIDE, SLKMovement5
applymovement LOCALID_PLAYER, SLegendMovement5
waitmovement
msgbox SapphireLegendPart6, MSGBOX_AUTOCLOSE
applymovement LOCALID_SAPPHIRE_LK_OUTSIDE, SLKMovement6
applymovement LOCALID_PLAYER, SLegendMovement6
waitmovement
msgbox SapphireLegendPart7, MSGBOX_AUTOCLOSE
applymovement LOCALID_SAPPHIRE_LK_OUTSIDE, SLKMovement7
waitmovement
removeobject LOCALID_SAPPHIRE_LK_OUTSIDE
playse SE_DOOR
waitse
setvar VAR_SAPPHIRE_LEGEND_STATE, 3
clearflag FLAG_LK_TEMP
releaseall
end

SapphireLegendPart1:
	.string "Thousands of years ago Hoenn looked\n"
	.string "much different than it did now.\p"
	.string "What is now the eastern part of\n"
	.string "mainland Hoenn was at the time a\l"
	.string "deserted wasteland.\p"
	.string "Sandstorms and intense heat raged\n"
	.string "from what is now Fallarbor Town all\l"
	.string "the way to the edge of the sea.$"

SapphireLegendPart2:
	.string "At the time, all of civilization\n"
	.string "inhabited a castle within Meteor Falls.\p"
	.string "One day, a pokémon from another\n"
	.string "dimension entered into our world and\l"
	.string "sought to plunge Hoenn into chaos.\p"
	.string "With the help of their pokémon, the\n"
	.string "humans were able to trap this pokémon\l"
	.string "within their castle and return it to\l"
	.string "its own dimension; however their home\l"
	.string "was largely destroyed in the process.$"

SapphireLegendPart3:
	.string "With the power to summon rain, Kyogre\n"
	.string "was able to cool the heat of the\l"
	.string "desert and bring rain to the region,\l"
	.string "allowing plants and vegetation to grow\l"
	.string "and humans to move east towards the sea.\p"
	.string "Kyogre had the help of two other\n"
	.string "pokémon, Wailord and Relicanth, to\l"
	.string "spread water across mainland Hoenn.$"

SapphireLegendPart4:
	.string "Wailord, a large pokémon in its own\n"
	.string "right, created spouts of water near the\l"
	.string "ocean that Kyogre funneled inland.\p"
	.string "Relicanth, regarded as the ultimate\n"
	.string "lifeform, was able to travel upstream\l"
	.string "through even the muddiest rivers as\l"
	.string "Kyogre created them and route them\l"
	.string "where they would best serve people.\p"
	.string "This is how the rivers you see in\n"
	.string "modern Hoenn first came to be.$"

SapphireLegendPart5:
	.string "Unfortunately, Groudon felt threatened\n"
	.string "by Kyogre as the rivers and storms grew\l"
	.string "closer to the cavern it called home.\p"
	.string "Kyogre proceeded to get into a conflict\n"
	.string "with Groudon and left the job of\l"
	.string "spreading water to Relicanth and Wailord.$"

SapphireLegendPart6:
	.string "Eventually, the conflict between\n"
	.string "Kyogre and Groudon subsided, at which\l"
	.string "time the Wailord and Relicanth also\l"
	.string "returned to the open ocean.$"

SapphireLegendPart7:
	.string "This is the Sapphire Legend.\p"
	.string "Every river in Hoenn was made by\n"
	.string "Kyogre with the help of Wailord \l"
	.string "and Relicanth to allow vegetation to\l"
	.string "grow and civilization to survive\l"
	.string "outside the castle within Meteor Falls.$"

SLKMovement1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	face_down
	step_end

SLKMovement2:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_left
	step_end

SLKMovement3:
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	face_left
	step_end

SLKMovement4:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	face_left
	step_end

SLKMovement5:
	walk_down
	walk_down
	walk_down
	walk_down
	face_up
	step_end

SLKMovement6:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_right
	step_end

SLKMovement7:
	walk_up
	step_end

SLegendMovement1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

SLegendMovement2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

SLegendMovement3:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

SLegendMovement4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	step_end

SLegendMovement5:
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

SLegendMovement6:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
